/*
	QLAY - Sinclair QL emulator
	Copyright Jan Venema 1998 

    Win95/98/Me/2000/XP interface functions

	QLAY2 - Sinclair QL emulator port of QLAY
	Copyright Jimmy Montesinos 2003
	Copyright Raphael Zhou 2003.
*/

#define STRICT
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <shellapi.h>
#include <stdlib.h>
#include <string.h>

#include "sysconfig.h"
#include "sysdeps.h"
#include "spc-os.h"
#include "options.h"
#include "qlvers.h"
#include "qlio.h"
#include "qldisk.h"
#include "winmain.h"
#include "cfg-win.h"
#include "debug.h"

// XPZ - ressource Includes
#include "resource.h"
// XPZ

#define WIN32COL 24

#define qscr_w 512
#define qscr_h 256
#define SCREEN_TILES		4	  	// Jimmy 093 Has to stay at 4 !!!

static void init_bmpit(void);
static __inline void make_dirty(void); // Jimmy 093 - __inline for speed up ?
static void update_size(void);
static void resize_screen(int);
static void frame_sizes(int*,int*);
static __inline void dump_screen_wt(void); // Jimmy 093 - __inline for speed up ?
static int win_alt_key(MSG*);
static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

/* externals */
int mouse_xpos;
int mouse_ypos;
int mouse_button;
int emul_running;

int Exiting;			// Jimmy 096 - Quit Dialog Box correction when hitting ALT+F4

/* locals */
static char szAppname[] = "QLAY2";
static HWND globalhwnd;

static char qscr_buf[qscr_w*qscr_h];

LPBITMAPINFO pbmpit;
static char bmpitbuf[sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD)];

U8 qscrt_buf[SCREEN_TILES*SCREEN_TILES][qscr_w*qscr_h/(SCREEN_TILES*SCREEN_TILES)];
U8 dirty[SCREEN_TILES][SCREEN_TILES];

static int win_w, win_h, wino_w, wino_h;

static HINSTANCE hInstance;
static int init_done;
static BOOL hideMouse;
static HCURSOR hCur;

static int i_maybe_bad;	// for atexit()

//def'd in grx-win, last halves don't care??
//int mode4_col[8]={0,249,250,255, 251,252,253,254};
//int mode8_col[16]={0,252,249,253,250,253,254,255 ,250,254,251,255,0,252,249,251};

//windows palette
RGBQUAD wincols16[]={	//blue,green,red,rsvd
	{  0,  0,  0,  0},	//0 black
	{  0,  0,128,  0},	//1 dark red
	{  0,128,  0,  0},	//2 dark green
	{  0,128,128,  0},	//3 dark yellow,brown
	{128,  0,  0,  0},	//4 dark blue
	{128,  0,128,  0},	//5 dark
	{128,128,  0,  0},	//6 dark
	{192,192,192,  0},	//7 lt grey
	{128,128,128,  0},	//248 dark grey
	{  0,  0,255,  0},	//249 red
	{  0,255,  0,  0},	//250 green
	{  0,255,255,  0},	//251 yellow
	{255,  0,  0,  0},	//252 blue
	{255,  0,255,  0},	//253 cyan
	{255,255,  0,  0},	//254 mint
	{255,255,255,  0}	//255 white
};

void init_bmpit(void){
int	i;

	pbmpit = (LPBITMAPINFO) bmpitbuf;
	pbmpit->bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
	pbmpit->bmiHeader.biWidth=qscr_w/SCREEN_TILES;
	pbmpit->bmiHeader.biHeight=qscr_h/SCREEN_TILES;
	pbmpit->bmiHeader.biPlanes=1;
	pbmpit->bmiHeader.biBitCount=8;
	pbmpit->bmiHeader.biCompression=BI_RGB;
	pbmpit->bmiHeader.biSizeImage=0;		//h*w implied
	pbmpit->bmiHeader.biXPelsPerMeter=1;
	pbmpit->bmiHeader.biYPelsPerMeter=1;
	pbmpit->bmiHeader.biClrUsed=256;
	pbmpit->bmiHeader.biClrImportant=0;

	// copy the color table 16 times to get 256 entries, mimic windows palette
	for(i=0;i<16;i++) {
		memcpy((pbmpit->bmiColors+4*sizeof(RGBQUAD)*i), wincols16, sizeof(RGBQUAD) * 16);
	}				//pointer to RGBQUAD: steps of 16 bytes!

}


void __inline make_dirty(void) // This function is needed for Refresh screen in case of lost focus.
{
int x,y;
	// Jimmy : This function is only need for Refresh Screen in case
	// of windows Lost focus.
	for(x=0;x<SCREEN_TILES;x++) for(y=0;y<SCREEN_TILES;y++) dirty[x][y]=1;
}

void frame_sizes(int *x, int *y)
{

	// Jimmy 095 - Adding 2 to X and Y for GDI mode.as it was too short.
	*x=0;
	*x+=2*GetSystemMetrics(SM_CXBORDER);
	*x+=2*GetSystemMetrics(SM_CXFRAME);
	*x+=2;
	*y=0;
	*y+=2*GetSystemMetrics(SM_CYBORDER);
	*y+=2*GetSystemMetrics(SM_CYFRAME);
	*y+=GetSystemMetrics(SM_CYCAPTION);
	*y+=GetSystemMetrics(SM_CYMENU);
	*y+=2;
}

void update_size(void){
RECT	dim;
int x,y;

	frame_sizes(&x,&y);
	wino_w=x;
	wino_h=y;

	GetWindowRect(globalhwnd, &dim);
	win_w=dim.right-dim.left-wino_w;
	win_h=dim.bottom-dim.top-wino_h;

	make_dirty();
}

void resize_screen(int sz){
RECT	dim;

	switch(sz)
	{
		case 1:	 win_w=512;  win_h=256;  break;	//2:1 no jags
		case 2:	 win_w=512;  win_h=341;  break;	//3:2 geo
		case 3:	 win_w=768;  win_h=512;  break; //3:2 geo
		case 4:	 win_w=1024; win_h=683;  break; //3:2 geo
		case 5:  win_w=1024; win_h=512;  break; //2:1 Un grand Ecran rapide.
		case 6:	 win_w=1024; win_h=768;  break; //4:3 no jags
		case 7:	 win_w=1280; win_h=640;  break; //2:1 
		case 8:	 win_w=1280; win_h=1024;  break; //4:3 no jags
		default: win_w=512;  win_h=256;
	}

	GetWindowRect(globalhwnd, &dim);
	// Jimmy 093 - GDI_FullScreen support 
	if ( opt_GDI_FullScreen == 1 )
	{
		opt_GDI_FullScreen = 2;
		ShowWindow(globalhwnd, SW_SHOWMAXIMIZED );
	}
	else
	{
			MoveWindow(globalhwnd,
					(int)((GetSystemMetrics(SM_CXFULLSCREEN)-(win_w+wino_w))/2),
					(int)((GetSystemMetrics(SM_CYFULLSCREEN)-(win_h+wino_h))/2),
					win_w+wino_w, win_h+wino_h, TRUE);

	}
	make_dirty();
}

/* eight at a time */
void __inline win32_plotp8(int x, int y, U8 *p)
{
int i,tx,ty;
U8 *d;

			// Just For information	d=&qscr_buf[x+((qscr_h-1)-y)*qscr_w];
	y=(qscr_h-1)-y;
	tx=x>>7;	// make tiles dependent!!!!
	ty=y>>6;
	d=&qscrt_buf[tx+SCREEN_TILES*ty][ (x & 0x7f)+(y & 0x3f)*qscr_w/(SCREEN_TILES)];
	dirty[tx][ty]=1;
	for(i=0;i<8;i++) *d++=*p++;
}


// Jimmy 093 - __inline for speed up ?
void __inline dump_screen_wt(void)
{
HDC hdc;
int tw,th,thr;

	hdc = GetDC(globalhwnd);

	for (th=0;th<SCREEN_TILES;th++) {
		thr=3-th;
		for (tw=0;tw<SCREEN_TILES;tw++) {
			if (dirty[tw][thr]) {

				StretchDIBits(hdc, tw*win_w/SCREEN_TILES, th*win_h/SCREEN_TILES,
								(win_w+2)/SCREEN_TILES, (win_h+2)/SCREEN_TILES, 0, 0, //(win_w/*+2*/)/SCREEN_TILES, (win_h/*+2*/)/SCREEN_TILES, 0, 0,
								qscr_w/SCREEN_TILES, qscr_h/SCREEN_TILES, qscrt_buf[tw+thr*4],
								pbmpit, DIB_RGB_COLORS, SRCCOPY);
				dirty[tw][thr]=0;
			}
		}
	}
	ReleaseDC(globalhwnd, hdc);
}

void __inline repaint_screen(void)
{
	dump_screen_wt();
}

static BOOL CommandEnabler(HWND hWnd, UINT uiCommandID)
{
	return TRUE;
}

static BOOL CommandChecker(HWND hWnd, UINT uiCommandID)
{
	switch (uiCommandID)
	{
	case IDM_FRENCH:
		return (opt_ui_lang == UI_LANG_FR);

	case IDM_ENGLISH:
		return (opt_ui_lang == UI_LANG_UK);

	case IDM_SPANISH:
		return (opt_ui_lang == UI_LANG_SP);

	case IDM_GERMAN:
		return (opt_ui_lang == UI_LANG_GE);

	case IDM_ITALIAN:
		return (opt_ui_lang == UI_LANG_IT);

	case IDM_SIZE1:
		return (screen_res == 1);

	case IDM_SIZE2:
		return (screen_res == 2);

	case IDM_SIZE3:
		return (screen_res == 3);

	case IDM_SIZE4:
		return (screen_res == 4);

	case IDM_SIZE5:
		return (screen_res == 5);

	case IDM_SIZE6:
		return (screen_res == 6);

// Jimmy 095 - Adding Screen Sizes
	case IDM_SIZE7:
		return (screen_res == 7);

	case IDM_SIZE8:
		return (screen_res == 8);

	}

	return FALSE;
}

static LRESULT EvInitMenuPopup(HWND hWnd, HMENU hMenu,
										 WORD wSubItemPos, BOOL fIsSystemMenu)
{
	int					nMenuItemCount;
	int					nMenuItemIndex;
	UINT				uMenuItemState;
	BOOL				fMenuItemNewStateEnable;
	BOOL				fMenuItemNewStateChecked;
	UINT				uMenuItemID;

	if (fIsSystemMenu)
		return 0L;

	nMenuItemCount = GetMenuItemCount(hMenu);

	for (nMenuItemIndex = 0; nMenuItemIndex < nMenuItemCount;
		  nMenuItemIndex++)
	{
		uMenuItemID = GetMenuItemID(hMenu, nMenuItemIndex);

		if (uMenuItemID == 0xFFFFFFFF)
			continue;

		uMenuItemState = GetMenuState(hMenu, uMenuItemID, MF_BYCOMMAND);

		fMenuItemNewStateEnable = CommandEnabler(hWnd, uMenuItemID);

		if ((uMenuItemState & MF_GRAYED) == MF_GRAYED)
		{
			if (fMenuItemNewStateEnable)
				EnableMenuItem(hMenu, nMenuItemIndex,
									MF_BYPOSITION | MF_ENABLED);
		}
		else
		{
			if (!fMenuItemNewStateEnable)
				EnableMenuItem(hMenu, nMenuItemIndex,
									MF_BYPOSITION | MF_GRAYED);
		}

		fMenuItemNewStateChecked =
			CommandChecker(hWnd, uMenuItemID);

		if ((uMenuItemState & MF_CHECKED) == MF_CHECKED)
		{
			if (!fMenuItemNewStateChecked)
				CheckMenuItem(hMenu, nMenuItemIndex,
								  MF_BYPOSITION | MF_UNCHECKED);
		}
		else
		{
			if (fMenuItemNewStateChecked)
				CheckMenuItem(hMenu, nMenuItemIndex,
								  MF_BYPOSITION | MF_CHECKED);
		}
	}

	return 0L;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
HDC	hdc;
PAINTSTRUCT ps;
int	reply;

// Jimmy 093 - Declation of variable for menu definition

static	HMENU hMenu; // French is the default menu.
static	HMENU hMenu_german;
static  HMENU hMenu_english;
static  HMENU hMenu_spanish;
static  HMENU hMenu_italian;

// Jimmy - Création d'un Timer pour le raffraichissement des LED en Full Screen. // UINT nIDEvent = 1;
UINT nIDEvent = 1;

// Jimmy 093 - Multi language support definition for char for Quit QLAY2 strings
char ChBufQuit1[256];
char ChBufQuit2[256];

	switch (message) {
	case WM_CREATE:
		// Defining the default menu system
		hMenu = GetMenu(hwnd);
        hMenu_english = LoadMenu(hInstance, "MENU_ENGLISH");
		hMenu_spanish = LoadMenu(hInstance, "MENU_SPANISH");
		hMenu_german  = LoadMenu(hInstance, "MENU_GERMAN");
		hMenu_italian = LoadMenu(hInstance, "MENU_ITALIAN");
		//CheckMenuItem(hMenu, IDM_FRENCH, MF_CHECKED | MF_BYPOSITION);


		mouse_xpos=256;
		mouse_ypos=128;
		mouse_button=0;

		// Jimmy 093 - Title of main windows.
		{char t[80];
			sprintf(t,"QLAY2");
			SetWindowText(hwnd, t);
		}
		
		// Jimmy - Création d'un Timer pour le raffraichissement des LED en Full Screen.
		SetTimer( hwnd, nIDEvent, 3000, NULL ); 

		SuperHwnd = hwnd;
		return 0;
	
	case WM_SETFOCUS:
	case WM_SHOWWINDOW:
			// Jimmy 095 - Raffraichissement des bonnes langues au démarrage ou après la
			//             boite de configuration.
			switch (opt_ui_lang)
			{
				case UI_LANG_FR:
					SetMenu(hwnd, hMenu);
					break;

				case UI_LANG_UK:
					SetMenu(hwnd, hMenu_english);
					break;

				case UI_LANG_SP:
					SetMenu(hwnd, hMenu_spanish);
					break;

				case UI_LANG_GE:
					SetMenu(hwnd, hMenu_german);
					break;

				case UI_LANG_IT:
					SetMenu(hwnd, hMenu_italian);
					break;
			}
			return 0;

	case WM_KILLFOCUS:
			return 0;


	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		make_dirty();
		repaint_screen();
		EndPaint(hwnd, &ps);
		return 0;

// XPZ
	case WM_INITMENUPOPUP:
		return EvInitMenuPopup(hwnd, (HMENU)wParam, LOWORD(lParam),
			(BOOL)HIWORD(lParam));

	case WM_SETCURSOR:
		if (!hideMouse)
		{
			hCur = LoadCursor( 0,  IDC_ARROW );
			SetCursor(hCur);
			ShowCursor(TRUE);
		}
		else
		{
			hCur = LoadCursor( 0,  IDC_ARROW );
			SetCursor(hCur);
			ShowCursor(TRUE);
		}

		return DefWindowProc(hwnd, WM_SETCURSOR, wParam, lParam);
// XPZ

	case WM_SIZE:
		update_size();
		return 0;

	case WM_CLOSE:
	case WM_DESTROY:
		// Jimmy 093 - Multi language support QUIT QLAY2
		switch(opt_ui_lang)
		{
		case UI_LANG_FR:
			sprintf(ChBufQuit1,"Etes-vous sûr ?");
			sprintf(ChBufQuit2,"Quitter QLAY2 ?");
			break;
		case UI_LANG_UK:
			sprintf(ChBufQuit1,"Are you sure ?");
			sprintf(ChBufQuit2,"Quit QLAY2 ?");
			break;
		case UI_LANG_SP:
			sprintf(ChBufQuit1,"¿ Está seguro ?");
			sprintf(ChBufQuit2,"¿ Salir de QLAY2 ?");
			break;
		case UI_LANG_GE:
			sprintf(ChBufQuit1,"Beende QLAY2 ?");
			sprintf(ChBufQuit2,"Sicher?");
			break;
		case UI_LANG_IT:
			sprintf(ChBufQuit1,"Sei sicuro ?");
			sprintf(ChBufQuit2,"Esci da QLAY2 ?");
			break;
		default:
			sprintf(ChBufQuit1,"Etes-vous sûr ?");
			sprintf(ChBufQuit2,"Quitter QLAY2 ?");
			break;
		}
		// Jimmy 096 - Quit Dialog Box correction.
		if (Exiting == 0)
		{
			reply=MessageBox(hwnd, ChBufQuit1, ChBufQuit2, MB_YESNO|MB_ICONEXCLAMATION);
			if (reply==IDNO) return 0;
				win_stop_emulation();
				emul_running=0;
				PostQuitMessage(0);
		}
		Exiting = 0;
		return 0;

	case WM_KEYDOWN:
		if (wParam == VK_F12)
			{
			  hideMouse = !hideMouse;
		      ShowCursor(hideMouse);
			  {char t[80];
				  if (!hideMouse)
			  			sprintf(t,"QLAY2 - %s [F12 - Mouse]",qlayversion2());
				  else
			  			sprintf(t,"QLAY2"); // - %s",qlayversion2());

				  SetWindowText(hwnd, t);}

			}

	case WM_KEYUP:
		if (!emul_running) return 0;
		my_kbd_handler(lParam >> 16);
		return 0;

	case WM_MOUSEMOVE:
//	case WM_NCMOUSEMOVE:
	case WM_RBUTTONDOWN:
	case WM_LBUTTONDOWN:
	case WM_RBUTTONUP:
	case WM_LBUTTONUP:
		mouse_xpos=LOWORD(lParam);
		mouse_ypos=HIWORD(lParam);
		mouse_xpos=(mouse_xpos*(512+128))/win_w;	// stay a bit ahead
		mouse_ypos=(mouse_ypos*(256+64))/win_h;
		mouse_button=wParam & 0x03;
		return 0;

	case WM_COMMAND:

		switch (LOWORD(wParam)) {
		case IDM_INIT:
			if (emul_running) {
				MessageBox(hwnd, "Emulation runs", "Error", MB_OK|MB_ICONEXCLAMATION);
				return 0;
			}
			if (init_done) return 0;
			init_done=1;
			return 0;

		case IDM_GO: /* go! */
			if (!init_done) {
				MessageBox(hwnd, "Init first", "Error", MB_OK|MB_ICONEXCLAMATION);
				return 0;
			}
			if (emul_running) return 0;
				emul_running=1;
	
			resize_screen(screen_res);
			debug();
			return 0;

		case IDM_END:
			SendMessage(hwnd, WM_CLOSE, 0, 0L);
			return 0;

		// Jimmy 095 - Resize screen Menu Handle
		case IDM_SIZE1:
				screen_res = 1;
				resize_screen(screen_res);
				return 0;
		case IDM_SIZE2:
				screen_res = 2;
				resize_screen(screen_res);
				return 0;
		case IDM_SIZE3:
				screen_res = 3;
				resize_screen(screen_res);
				return 0;
		case IDM_SIZE4:
				screen_res = 4;
				resize_screen(screen_res);
				return 0;
		case IDM_SIZE5:
				screen_res = 5;
				resize_screen(screen_res);
				return 0;
		case IDM_SIZE6:
				screen_res = 6;
				resize_screen(screen_res);
				return 0;
		case IDM_SIZE7:
				screen_res = 7;
				resize_screen(screen_res);
				return 0;
		case IDM_SIZE8:
				screen_res = 8;
				resize_screen(screen_res);
				return 0;
		// Jimmy 095 - end of Resize screen Menu Handle

		case IDM_HELP:
			{
				FILE *f;
				f=fopen("QLAY2.hlp","r");
				if (f!=NULL)
				{
					fclose(f);
					WinHelp( hwnd, "QLAY2.hlp", HELP_INDEX, 0L );
				}
				else
				{
					f=fopen("QLAY2.html","r");
					if (f!=NULL)
						{
							fclose(f);
							WinHelp( hwnd, "QLAY2.html", HELP_INDEX, 0L );
						}
				}
			}
			return 0;

		case IDM_ABOUT:
			{
			char chbuf[256];
		 			sprintf(chbuf,"QLAY original and source de Jan Venema.\n"
								"Parts modified (c)2000-2003\nJimmy Montesinos et Raphael Zhou\n"
								  "Version : %s.",qlayversion());
					MessageBox(hwnd, chbuf, "A propos de QLAY2", MB_OK|MB_ICONINFORMATION);
			}
			return 0;

		// Jimmy 093 - Menu management system
		case IDM_FRENCH:
			opt_ui_lang = UI_LANG_FR;
			SetMenu(hwnd, hMenu);
			return 0;


		case IDM_ENGLISH:
			opt_ui_lang = UI_LANG_UK;
			SetMenu(hwnd, hMenu_english);
			return 0;

		case IDM_SPANISH:
			opt_ui_lang = UI_LANG_SP;
			SetMenu(hwnd, hMenu_spanish);
			return 0;

		case IDM_GERMAN:
			opt_ui_lang = UI_LANG_GE;
			SetMenu(hwnd, hMenu_german);
			return 0;

		case IDM_ITALIAN:
			opt_ui_lang = UI_LANG_IT;
			SetMenu(hwnd, hMenu_italian);
			return 0;


		case IDM_DLG_CFG:
			wincfg_main(hInstance);
			init_qldisk();
			init_mdvs();
			return 0;

		case IDM_RESET:
			// Jimmy - 093 Commande de Reset du QL 
			handle_reset();
			return 0;
		
		case IDM_InitDisk:
			update_LED();
			return 0;
		}
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void write_box(char *s)
{
static int startposy=0;
HDC hdc;
unsigned int	i;

	for (i=0;i<strlen(s);i++) if (s[i]=='\n') s[i]=' ';

	hdc = GetDC(globalhwnd);
	if (startposy<240) {
		TextOut(hdc,0,startposy,s,strlen(s));
		startposy+=17;
	} else {
		MessageBox(globalhwnd, "Screen full", "QLAY2", MB_OK);
		//clear_screen(0);
		startposy=0;
		TextOut(hdc,0,startposy,s,strlen(s));
	}
	ReleaseDC(globalhwnd, hdc);
}


// Jimmy 093 - Initialisation de argc argv pour la lecture de QLAY2.INI

int argc = 0;
// Jimmy 093 - Ci dessous écriture Microsoft de char **argv = { "" };
char *argv[] = {""};


// XPZ - Définition du Handle de la table des raccourcis.
HACCEL hAccelerator = NULL;
// XPZ

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
HWND	hwnd;
MSG	msg;
WNDCLASS wndclass;

	i_maybe_bad=1;

	open_log();

	init_done=0;
	emul_running=0;

	//ShowCursor(TRUE);

	hInstance = hInst;

	hAccelerator = LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_QLAY2));

	if (!hPrevInstance) {
		wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_BYTEALIGNCLIENT;
		wndclass.lpfnWndProc = WndProc;
		wndclass.cbClsExtra = 0;
		wndclass.cbWndExtra = 0;
		wndclass.hInstance = hInstance;
		wndclass.hIcon = LoadIcon(hInstance, szAppname);
		wndclass.hCursor = LoadCursor(NULL, "IDC_QLAY2_CURSOR");
		wndclass.hbrBackground = GetStockObject(BLACK_BRUSH);
		wndclass.lpszMenuName = szAppname;
		wndclass.lpszClassName = szAppname;
		RegisterClass(&wndclass);
	}

	win_w=512;
	win_h=256;
	wino_w=8;
	wino_h=46;
	frame_sizes(&wino_w,&wino_h);


	// Jimmy 096 - Exit w/ALT+F4 bug correction...
	Exiting = 0;

	hwnd = CreateWindowEx(
						  WS_EX_OVERLAPPEDWINDOW | WS_EX_APPWINDOW,							// extended window style
						  szAppname,														// registered class name
						  "QLAY2",															// window name
						  WS_OVERLAPPEDWINDOW | WS_MAXIMIZE,								// window style
						  (int)((GetSystemMetrics(SM_CXFULLSCREEN)-(win_w+wino_w))/2),		// horizontal position of window
						  (int)((GetSystemMetrics(SM_CYFULLSCREEN)-(win_h+wino_h))/2),		// vertical position of window
						  win_w+wino_w,														// window width
						  win_h+wino_h,														// window height
						  NULL,																// handle to parent or owner window
						  NULL,																// menu handle or child identifier
						  hInstance,														// handle to application instance
						  NULL																// window-creation data
						);

	
			hideMouse=TRUE;
			ShowCursor(TRUE);

	globalhwnd = hwnd;

	init_bmpit();
	make_dirty();

	ql_main1(argc,argv);	/* get options */
	if (wincfg_main(hInstance)!=1)
			{
				ShowWindow(hwnd, nCmdShow);
				UpdateWindow(hwnd);

				ql_main2();
				init_done=1;
				resize_screen(screen_res);

				emul_running=1;
				debug();
				// Jimmy 095 - MC68000_run(); // J'arrive pas à réduire le temps OUINNNN

				// void, but doesn't hurt either
				while (GetMessage(&msg, NULL, 0, 0)) {
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}

				ql_exit();
				close_log();
				i_maybe_bad=0;
			}

	return msg.wParam;
}

// filter all ALT key presses and send to QLAY kbd handler
int win_alt_key(MSG *m)
{

	if ((m->message==WM_SYSKEYDOWN)||(m->message==WM_SYSKEYUP))
		{
				/*
						{int kc;

						if (!emul_running) return 0;
						kc=(m->lParam >> 16) & 0xff;
				if(0)		fpr("wak: %03x %03d %03x %08lx %03d\n",m->message,
							m->wParam,m->wParam,m->lParam,kc);
    						}
				*/
		my_kbd_handler(m->lParam >> 16);
		return 1;
		}
	return 0;
}

//
// Message Loop handler within QLAY2.
//
// check for pending messages for me
__inline void q_check_message(void)
{
MSG	msg;
int	reply;
	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
		/*if (msg.message==WM_KEYDOWN)
		{
			SHORT TheKey;
			CHAR sz[128];

			TheKey = GetAsyncKeyState( VK_LCONTROL ); 
			//sprintf(sz,"Valeur : %d %d %d\n", msg.wParam, msg.lParam, TheKey );
			//MessageBox(NULL, sz, "Code", MB_OK);

			if ((TheKey==1)||(msg.wParam==17))
			{
				//my_kbd_handler(8248);
				// This is AltGr
			}

		}*/

		if (msg.message==WM_SYSKEYDOWN)
		{


			//CHAR sz[128];
			//SHORT TheKey;

			//TheKey = GetAsyncKeyState( VK_LCONTROL ); 
			//sprintf(sz,"Valeur : %d %d\n", msg.wParam, TheKey );
			//MessageBox(NULL, sz, "Code", MB_OK);

			// Intercepte ALT+F4 et quitte.
			// Jimmy
			if (msg.wParam==115)
			{
				// Jimmy 091 - Quitter avec ALT + F4
				char ChBufQuit1[256];
				char ChBufQuit2[256];
					// Jimmy 093 - Multi language support QUIT QLAY2
					switch(opt_ui_lang)
					{
					case UI_LANG_FR:
						sprintf(ChBufQuit1,"Etes-vous sûr ?");
						sprintf(ChBufQuit2,"Quitter QLAY2 ?");
						break;
					case UI_LANG_UK:
						sprintf(ChBufQuit1,"Are you sure ?");
						sprintf(ChBufQuit2,"Quit QLAY2 ?");
						break;
					case UI_LANG_SP:
						sprintf(ChBufQuit1,"¿ Está seguro ?");
						sprintf(ChBufQuit2,"¿ Salir de QLAY2 ?");
						break;
					case UI_LANG_GE:
						sprintf(ChBufQuit1,"Sicher?");
						sprintf(ChBufQuit2,"Beende QLAY2 ?");
						break;
					case UI_LANG_IT:
						sprintf(ChBufQuit1,"Sei sicuro ?");
						sprintf(ChBufQuit2,"Esci da QLAY2 ?");
						break;
					default:
						sprintf(ChBufQuit1,"Etes-vous sûr ?");
						sprintf(ChBufQuit2,"Quitter QLAY2 ?");
						break;
					}
				reply=MessageBox(msg.hwnd, ChBufQuit1, ChBufQuit2, MB_YESNO|MB_ICONEXCLAMATION);
				// Jimmy 096 - Quit Dialog Box correction.
				if (reply==IDNO)
				{
					Exiting = 1;
				}
				if (reply==IDYES)
				{
					win_stop_emulation();
					emul_running=0;
					PostQuitMessage(0);
				}
			}
		}
		if (opt_use_altkey) if (win_alt_key(&msg)) return;
		if (!TranslateAccelerator(globalhwnd, hAccelerator, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}
