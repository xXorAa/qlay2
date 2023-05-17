/*
	QLAY - Sinclair QL emulator
	Copyright Jan Venema 1998
	Main and cmdline parsing

	QLAY2 - Sinclair QL emulator port of QLAY for Windows 2000 and XP
	Copyright Raphael Zhou & Jimmy Montesinos.

    ( Some parts are from QL2K but released as GPL )

*/

#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "qlmem.h"
#include "qldisk.h"
#include "exe68k.h"
#include "debug.h"
#include "os.h"
#include "keybuf.h"
#include "spc-os.h"
#include "qlvers.h"
#include "qlio.h"
// XPZ - 091
#include <windows.h>
// XPZ - 091

int		opt_ui_lang = UI_LANG_FR; // Jimmy 093 - Multi language support definition

int		ram_size = -1;
int		use_debugger = 0;
int		opt_use_mouse = 1;
int		opt_use_altkey = 1;
int		produce_sound = 1;
int		fake_joystick = 0;
T_KEYB	opt_keyb = KEYB_US;
U32		qlay1msec=400; /*0.82c*/
int		fakeF1=0;
int		iatrace=0;
int		screen_res = 2; // Jimmy 095 - Adding Screen Sizes
int		opt_busy_wait = 0;
int		opt_new_gfx = 1;

// Jimmy 093 - GDI Full Screen
int		opt_GDI_FullScreen = GDI_NORMAL;

// Jimmy 095 - Black Line Correction
int		opt_CorrectBL = 0;

#define MAXCART	4
#define MAXWIN	8
#define MAXMDV	8
#define MAXSER	2

#define QLRCFILE "QLAY2.INI" // Definition of name of preference INI file. (Jimmy 093)

// Jimmy 095 - Changing default ROM name.
char	romfile[256] = "MINERVA198.ROM";
char	opt_cartfn[MAXCART][256] = {"", "", "", ""};	/* not a flexible solution */
U32		opt_cartaddr[MAXCART]  = {0, 0, 0, 0};
int		currcart=0;
char	mdvfn[MAXMDV][256] = {"", "", "", "", "", "", "", ""};
char	winfn[MAXWIN][256] = {"", "", "", "", "", "", "", ""};
char	sername[MAXSER][256] = {"", ""};

/* 089a: not used - Jimmy -> Je ne comprends pas ... */
int	winpresent[8] = {1,0,0,0,0,0,0,0};	/* win1_ default in curr.dir */

char prtname[256] = "LPT1:";

// Jimmy 093 - To Remove
// rsxntdj
//#if defined(__QLWIN32__) && defined(__DJGPP__)
//#define optarg _optarg
    //extern char *optarg;
//#endif

//
// Jimmy 093 : QL2K_ChangeToPipe
//
// This function change space to | character
// This is useful to write space in filepath ini INI File
//
// 27/05/2003
//

LPCTSTR QL2K_ChangeToPipe(char *fn)
{

char	s[256];
UINT		i;

	s[0]='\0';
	for (i=0; i < strlen(fn); i++)
	{	
		if ( fn[i] == ' ')
				s[i] = '|';
		else
				s[i] = fn[i];
	}
	s[i] = '\0';
	fn = _strdup(s);
	return (LPCTSTR) fn;
}
//
// Jimmy 093 : end QL2K_ChangeToPipe
//

//
// Jimmy 093 : QL2K_ChangePipeToSpc
//
// Define in "options.h"
//
// This function change  | character to space
// This is useful to read space from filepath ini INI File
//
// 27/05/2003
//

LPCTSTR QL2K_ChangePipeToSpc(char *fn)
{

char	s[256];
UINT		i;

	s[0]='\0';
	for (i=0; i < strlen(fn); i++)
	{	
		if ( fn[i] == '|')
				s[i] = ' ';
		else
				s[i] = fn[i];
	}
	s[i] = '\0';
	fn = _strdup(s);
	return (LPCTSTR) fn;
}
//
// Jimmy 093 : end QL2K_ChangePipeToSpc
//


//XXX
static void parse_cmdline(int argc, char **argv)
{
int c;
	// Jimmy 093 - Attention les : (deux-points) servent a donné un argument
	while(((c = getopt(argc, argv,
		"Al:L:Df:gd:hxF:ac:SJm:M0:1:2:3:4:5:6:7:8:r:H:op:w:ik:u:sGC")) != EOF)) {

	switch(c) {
	
	case 'G':		// Jimmy 093 - G : GDI Full Screen
		opt_GDI_FullScreen = GDI_MAXIMISE;
		break;

	case 'C':		// Jimmy 095 - C : Black Line Correction
		opt_CorrectBL = 1;
		break;

	case 'u':		// Jimmy 093 - u : Default Interface language. ( Multi language support definition )
	opt_ui_lang = atoi(optarg); 
	if (!(opt_ui_lang >= 1 && opt_ui_lang <= 5))
		{
			epr("Bad language selected. Using default (French).\n");
			opt_ui_lang = UI_LANG_FR;
		}
	break;

	case 'h':
		// Usage remove by Jimmy 093
		exit(0);
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
		strncpy(mdvfn[c-'1'], optarg, 255);
		mdvfn[c-'1'][255] = 0;
		break;

	case 'l':
		if (strncmp(optarg,"win",3)==0) {
			c=optarg[3]-'1';
			if ((c>=0)&&(c<8)) {
				strncpy(winfn[c], &optarg[5], 255);
if(0)				{int l;
					l=strlen(winfn[c]);
					if (winfn[c][l-1]!='\\') {
						winfn[c][l]='\\';
						winfn[c][l+1]=0;
					}
				}
				winfn[c][255] = 0;
//089a				winpresent[c]=1;
			} else {
				epr("Option error: -l %s\n",optarg);
			}
		} else if (strncmp(optarg,"mdv",3)==0) {
			c=optarg[3]-'1';
			if ((c>=0)&&(c<8)) {
				strncpy(mdvfn[c], &optarg[5], 255);
				mdvfn[c][255] = 0;
			} else {
				epr("Option error: -l %s\n",optarg);
			}
		} else if (strncmp(optarg,"ser",3)==0) {
			c=optarg[3]-'1';
			if ((c>=0)&&(c<2)) {
				strncpy(sername[c], &optarg[5], 255);
				sername[c][255] = 0;
			} else {
				epr("Option error: -l %s\n",optarg);
			}
		} else {
			epr("Option error: -l %s\n",optarg);
		}
		break;
	case 'p':
		strncpy(prtname, optarg, 255);
		prtname[255] = 0;
		break;
	case 'r':
		strncpy(romfile, optarg, 255);
		romfile[255] = 0;
		break;
	case 'c':
		if (currcart>=MAXCART) {
			epr("Cartridge option error: too many. %d > %d\n",currcart+1,MAXCART);
		} else {
			char tmpstr[256];
			strncpy(tmpstr,optarg,255);
			c=sscanf(tmpstr,"%x@%s",&opt_cartaddr[currcart],opt_cartfn[currcart]);
			if (c!=2) {
				epr("Cartridge option error: %d, %s\n",c,optarg);
				opt_cartfn[currcart][0] = '\0';
			}
			opt_cartfn[currcart][255] = 0;
			currcart++;
		}
		break;
	case 'S':
		produce_sound = 0;
		break;
	case 'f':
		qlay1msec = atoi(optarg);
		break;
	case 'D':
		use_debugger = 1;
		break;
	case 'J':
		fake_joystick = 1;
		break;
	case 'M':
		opt_use_mouse = 0;
		break;
	case 'A':
		opt_use_altkey = 0;
		break;
	case 'm':
		ram_size=atoi(optarg);
		break;
	case 'F':
		fakeF1=atoi(optarg);
		break;
	case 'L':
	        strupr(optarg);
		if		(!strcmp(optarg, "US")) opt_keyb = KEYB_US;
		else if (!strcmp(optarg, "UK")) opt_keyb = KEYB_UK;
		else if (!strcmp(optarg, "GE")) opt_keyb = KEYB_GE;
		else if (!strcmp(optarg, "FR")) opt_keyb = KEYB_FR;
		else if (!strcmp(optarg, "IT")) opt_keyb = KEYB_IT;
//		else if (!strcmp(optarg, "SE")) opt_keyb = KEYB_SE;
		break;
	case 'd': // Jimmy 095 - Adding Screen Sizes
		screen_res = atoi(optarg);
		if (!(screen_res >= 1 && screen_res <= 8)) {
			epr("Bad video mode selected. Using default.\n");
			screen_res = 3;
		}
		break;
	case 'x':
	    	iatrace=1;
		break;
	case 'w':
		opt_busy_wait = atoi(optarg);
		break;
	case 'o':
		opt_new_gfx=0;
		break;
	default: 
		epr("Invalid option: %c, exiting in INI File",c);
	    break;
	} /* end switch */
	} /* end while */

//
// Jimmy 093 - Correcting all FileNames now... Changing Pipe to Space
//

	// Win NFA Drives (winfn[])
	strncpy(winfn[0], QL2K_ChangePipeToSpc(winfn[0]), strlen(winfn[0]));
	strncpy(winfn[1], QL2K_ChangePipeToSpc(winfn[1]), strlen(winfn[1]));
	strncpy(winfn[2], QL2K_ChangePipeToSpc(winfn[2]), strlen(winfn[2]));
	strncpy(winfn[3], QL2K_ChangePipeToSpc(winfn[3]), strlen(winfn[3]));
	strncpy(winfn[4], QL2K_ChangePipeToSpc(winfn[4]), strlen(winfn[4]));
	strncpy(winfn[5], QL2K_ChangePipeToSpc(winfn[5]), strlen(winfn[5]));
	strncpy(winfn[6], QL2K_ChangePipeToSpc(winfn[6]), strlen(winfn[6]));
	strncpy(winfn[7], QL2K_ChangePipeToSpc(winfn[7]), strlen(winfn[7]));

	// MDV Cartridges Drives (mdvfn[])
	strncpy(mdvfn[0], QL2K_ChangePipeToSpc(mdvfn[0]), strlen(mdvfn[0]));
	strncpy(mdvfn[1], QL2K_ChangePipeToSpc(mdvfn[1]), strlen(mdvfn[1]));
	strncpy(mdvfn[2], QL2K_ChangePipeToSpc(mdvfn[2]), strlen(mdvfn[2]));
	strncpy(mdvfn[3], QL2K_ChangePipeToSpc(mdvfn[3]), strlen(mdvfn[3]));
	strncpy(mdvfn[4], QL2K_ChangePipeToSpc(mdvfn[4]), strlen(mdvfn[4]));
	strncpy(mdvfn[5], QL2K_ChangePipeToSpc(mdvfn[5]), strlen(mdvfn[5]));
	strncpy(mdvfn[6], QL2K_ChangePipeToSpc(mdvfn[6]), strlen(mdvfn[6]));
	strncpy(mdvfn[7], QL2K_ChangePipeToSpc(mdvfn[7]), strlen(mdvfn[7]));
	
	// ROM Cartridges (opt_cartfn[])
	strncpy(opt_cartfn[0], QL2K_ChangePipeToSpc(opt_cartfn[0]), strlen(opt_cartfn[0]));
	strncpy(opt_cartfn[1], QL2K_ChangePipeToSpc(opt_cartfn[1]), strlen(opt_cartfn[1]));
	strncpy(opt_cartfn[2], QL2K_ChangePipeToSpc(opt_cartfn[2]), strlen(opt_cartfn[2]));
	strncpy(opt_cartfn[3], QL2K_ChangePipeToSpc(opt_cartfn[3]), strlen(opt_cartfn[3]));

	// Main ROM File (romfile)
	strncpy(romfile, QL2K_ChangePipeToSpc(romfile), strlen(romfile));

//
// Jimmy 093 - end Correcting all FileNames now... Changing Pipe to Space
//

}



static void parse_cmdline_and_init_file(int argc, char **argv)
{
FILE *f;
char file[256];
char *buffer,*tmpbuf, *token;
unsigned int bufsiz;
int n_args;
char **new_argv;
int new_argc;

	strcpy(file,"");

    strcat(file, QLRCFILE);
	f = fopen(file,"rb"); // Win32
	if (f == NULL) {
	// XPZ - 091 Correction Parse_cmdline
		if (argc > 1)
			parse_cmdline(argc, argv);
	// XPZ - 091 Correction Parse_cmdline
		return;
	}

	fseek(f, 0, SEEK_END);
	bufsiz = ftell(f);
	fseek(f, 0, SEEK_SET);

	buffer = (char *)malloc(bufsiz+1);
	buffer[bufsiz] = 0;
	if (fread(buffer, 1, bufsiz, f) < bufsiz) {
		epr("Error reading configuration file\n");
		fclose(f);
		parse_cmdline(argc, argv);
		return;
	}
	fclose(f);


	{char *tmp;
		while ((tmp = strchr(buffer, 0x0d)))
			*tmp = ' ';
		while ((tmp = strchr(buffer, 0x0a)))
			*tmp = ' ';
		while (buffer[0] == ' ')
			strcpy(buffer, buffer+1);
		while ((strlen(buffer) > 0) && (buffer[strlen(buffer) - 1] == ' '))
			buffer[strlen(buffer) - 1] = '\0';
		while ((tmp = strstr(buffer, "  ")))
			strcpy(tmp, tmp+1);
	}

	tmpbuf = my_strdup (buffer);
	n_args = 0;
	if (strtok(tmpbuf, "\n ") != NULL) {
		do {
			n_args++;
		} while (strtok(NULL, "\n ") != NULL);
	}
	free (tmpbuf);

	new_argv = (char **)malloc ((1 + n_args + argc) * sizeof (char **));
	new_argv[0] = argv[0];
	new_argc = 1;

	token = strtok(buffer, "\n ");
	while (token != NULL) {
		new_argv[new_argc] = my_strdup (token);
		new_argc++;
		token = strtok(NULL, "\n ");
	}
	for (n_args = 1; n_args < argc; n_args++)
		new_argv[new_argc++] = argv[n_args];
	new_argv[new_argc] = NULL;
	parse_cmdline(new_argc, new_argv);
}

int ql_main1(int argc, char **argv)
{

	epr("Initialization...\n");
	parse_cmdline_and_init_file(argc, argv);
	return 0;
}

int ql_main2()
{
	if (produce_sound && !init_sound()) {
		epr("Sound driver unavailable: Sound output disabled\n");
		produce_sound = 0;
	}

	// Jimmy 095 - init_debug();
	init_joystick();
	init_keybuf();
	init_memory();
	init_qldisk();
	init_QL();
	init_m68k();

	if (!use_debugger) {
//		epr("Going graphics mode\n");
		if (!init_graphics()) {
			epr("Could not initialize graphics, exiting.\n");
			exit(1);
		}
	}
	MC68000_reset();
	epr("Sinclair QL Pret.\n");

	return 0;
}

int ql_exit()
{
	exit_qldisk();
	return 0;
}


//
// 090 : write_options
// This function Write all options in INI File defined in QLRCFILE
//
// 27/05/2003 : Adding QL2K_ChangeToPipe to write string with spaces
//

void write_options(void)
{
FILE	*f;
int	i;
char	*kb;


	fpr("Writing INI File\n");
	
	f=fopen(QLRCFILE,"w");
	if (f==NULL) {
		fpr("Cannot open %s for writing\n", QLRCFILE);
		return;
	}
	// Jimmy 093 - Writing the ROM Filename
	fprintf(f,"-r %s\n",QL2K_ChangeToPipe(romfile));

	// Jimmy 093 - Writing the Cartridges ( Additionnal ROM ) Filenames
	i=0;
	while (strlen(opt_cartfn[i])) {
		fprintf(f,"-c %08x@%s\n",opt_cartaddr[i],QL2K_ChangeToPipe(opt_cartfn[i]));
		i++;
	}
	
	// Jimmy 093 - Writing the WIN NFA Directory names
	for (i=0;i<MAXWIN;i++) {
		if (strlen(winfn[i])) fprintf(f,"-l win%d@%s\n",i+1,QL2K_ChangeToPipe(winfn[i]));
	}
	
	// Jimmy 093 - Writing the MDV Microdrive image file names.
	for (i=0;i<MAXMDV;i++) {
		if (strlen(mdvfn[i])) fprintf(f,"-l mdv%d@%s\n",i+1,QL2K_ChangeToPipe(mdvfn[i]));
	}
	
	// Jimmy 093 - Writing the Serial port names
	for (i=0;i<MAXSER;i++) {
		if (strlen(sername[i])) fprintf(f,"-l ser%d@%s\n",i+1,sername[i]);
	}

	// Jimmy 093 - Writing the Parrallel port names
	if (strlen(prtname)) fprintf(f,"-p %s\n",prtname);

	// Jimmy 093 - Writing the Screen resolution // Jimmy 095 - Adding Screen Sizes
	if (screen_res>0) fprintf(f,"-d %d\n",screen_res);
	
	// Jimmy 093 - Writing the Keyboard layout definition
	kb="USUKGEFRITSE";
	if (opt_keyb!=0) fprintf(f,"-L %c%c\n",kb[2*opt_keyb],kb[2*opt_keyb+1]);
	
	// Jimmy 093 - Writing the Speed information
	fprintf(f,"-f %d\n",qlay1msec);
	
	if (opt_busy_wait) fprintf(f,"-w %d\n",opt_busy_wait);
	
	// Jimmy 093 - Writing the Automatic F1 key for monitor mode under QL at startup
	if (fakeF1) fprintf(f,"-F %d\n",fakeF1);
	
	// Jimmy 093 - Writing the RAM Size information	
	if (ram_size!=-1) fprintf(f,"-m %d\n",ram_size);
	
	// Jimmy 093 - Writing if using debugger
	if (use_debugger) fprintf(f,"-D\n");
	
	// Jimmy 093 - Writing Bolean Mouse option
	if (!opt_use_mouse) fprintf(f,"-M\n");

	// Jimmy 093 - Writing Bolean ALT Key
	if (!opt_use_altkey) fprintf(f,"-A\n");

	// Jimmy 093 - ?????????????????????????????
	if (iatrace) fprintf(f,"-x\n");

	// Jimmy 093 - ?????????????????????????????
	if (!opt_new_gfx) fprintf(f,"-o\n");
	
	// Jimmy 093 - Writing the Language for UI - Multi language support
	if (opt_ui_lang!=1) fprintf(f,"-u %d\n",opt_ui_lang);

	// Jimmy 093 - Writing GDI Full Screen Option
	if (opt_GDI_FullScreen == GDI_MAXIMISE )  fprintf(f,"-G\n");

	// Jimmy 095 - Writing Black line correction Option
	if (opt_CorrectBL == 1 )  fprintf(f,"-C\n");

	fclose(f);
	
	fpr("Options written in %s\n",QLRCFILE);
}
