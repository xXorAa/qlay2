/*
	QLAY - Sinclair QL emulator
	Copyright Jan Venema 1998

    QLAY2 configuration dialog

	QLAY2 - Sinclair QL emulator port of QLAY GPL
	Copyright Jimmy Montesinos 2003
	Copyright Raphael Zhou 2003

      ( Some parts are from QL2K but released as GPL )

*/

#define STRICT
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>
#include <commdlg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "winmain.h"
#include "cfg-win.h"
#include "spc-os.h"
#include "resource.h"

static HINSTANCE hInstance;

static int iSitCancelButton;

static HBITMAP	hBmp, hBtnBmp;
static HDC		hDC, hMemDC;
static BOOL		bShowFlag;

static void addstring(HWND hWnd, int box, char* str)
{
	SendDlgItemMessage(hWnd, box, CB_ADDSTRING, 0, (LPARAM) ((LPSTR) str));
}

static __inline void QL2K_as(HWND hWnd, int box, char* str) // AddString
{
	SetDlgItemText(hWnd, box, ((LPSTR) str));
}

static void QL2K_Change_Language(HWND hWnd, int iLang)
{
	switch (iLang)
	{
		case UI_LANG_FR:
			QL2K_as ( hWnd, IDC_MemSize, "Taille mémoire" );		//IDC_MemSize
			QL2K_as ( hWnd, IDC_ScreenSize, "Taille écran" );		//IDC_ScreenSize
			QL2K_as ( hWnd, IDC_KeybLayout, "Langue clavier" );		//IDC_KeybLayout
			QL2K_as ( hWnd, IDC_Speed, "Vitesse" );					//IDC_Speed
			QL2K_as ( hWnd, IDC_Delay, "Délai" );					//IDC_Delay
			QL2K_as ( hWnd, IDC_RomBox, "ROM" );					//IDC_RomBox
			QL2K_as ( hWnd, IDC_RomBoot, "BOOT" );					//IDC_RomBoot
			QL2K_as ( hWnd, IDC_Rom1, "ROM1" );						//IDC_Rom1
			QL2K_as ( hWnd, IDC_Rom2, "ROM2" );						//IDC_Rom2
			QL2K_as ( hWnd, ID_CHK_MOUSE, "Pas de souris" );		//ID_CHK_MOUSE
			QL2K_as ( hWnd, ID_CHK_ALTKEY, "Pas de touches ALT" );	//ID_CHK_ALTKEY
			QL2K_as ( hWnd, IDC_DIRECTDRAW, "DirectDraw" );			//IDC_DIRECTDRAW
			QL2K_as ( hWnd, IDC_FULLSCREEN, "Plein Ecran" );		//IDC_FULLSCREEN
																	//ID_MDVWIN - Nothing to DO !!! ;-)
			QL2K_as ( hWnd, ID_SAVE, "Enregistrer" );				//ID_SAVE
			QL2K_as ( hWnd, ID_CANCEL, "Annuler" );					//ID_CANCEL
			QL2K_as ( hWnd, ID_OK, "OK" );							//ID_OK
			QL2K_as ( hWnd, IDC_GDIFULLSCREEN, "Plein écran GDI" );	//IDC_GDIFULLSCREEN
			QL2K_as ( hWnd, ID_CHK_CorrectBL, "Correction lignes noires" );// ID_CHK_CorrectBL
			return;

		case UI_LANG_UK:	
			QL2K_as ( hWnd, IDC_MemSize, "Memory size" );			//IDC_MemSize
			QL2K_as ( hWnd, IDC_ScreenSize, "Screen size" );		//IDC_ScreenSize
			QL2K_as ( hWnd, IDC_KeybLayout, "Keyboard country" );	//IDC_KeybLayout
			QL2K_as ( hWnd, IDC_Speed, "Speed" );					//IDC_Speed
			QL2K_as ( hWnd, IDC_Delay, "Delay" );					//IDC_Delay
			QL2K_as ( hWnd, IDC_RomBox, "ROM" );					//IDC_RomBox
			QL2K_as ( hWnd, IDC_RomBoot, "BOOT" );					//IDC_RomBoot
			QL2K_as ( hWnd, IDC_Rom1, "ROM1" );						//IDC_Rom1
			QL2K_as ( hWnd, IDC_Rom2, "ROM2" );						//IDC_Rom2
			QL2K_as ( hWnd, ID_CHK_MOUSE, "No mouse" );				//ID_CHK_MOUSE
			QL2K_as ( hWnd, ID_CHK_ALTKEY, "No alt key" );			//ID_CHK_ALTKEY
			QL2K_as ( hWnd, IDC_DIRECTDRAW, "DirectDraw" );			//IDC_DIRECTDRAW
			QL2K_as ( hWnd, IDC_FULLSCREEN, "Full screen" );		//IDC_FULLSCREEN
																	//ID_MDVWIN - Nothing to DO !!! ;-)
			QL2K_as ( hWnd, ID_SAVE, "Save" );						//ID_SAVE
			QL2K_as ( hWnd, ID_CANCEL, "Cancel" );					//ID_CANCEL
			QL2K_as ( hWnd, ID_OK, "OK" );							//ID_OK
			QL2K_as ( hWnd, IDC_GDIFULLSCREEN, "Full screen GDI" );	//IDC_GDIFULLSCREEN
			QL2K_as ( hWnd, ID_CHK_CorrectBL, "Black lines adjust" );// ID_CHK_CorrectBL
			return;

		case UI_LANG_SP:	
			QL2K_as ( hWnd, IDC_MemSize, "Tamaño de memoria" );			//IDC_MemSize
			QL2K_as ( hWnd, IDC_ScreenSize, "Tamaño de pantalla" );		//IDC_ScreenSize
			QL2K_as ( hWnd, IDC_KeybLayout, "Selección de teclado" );	//IDC_KeybLayout
			QL2K_as ( hWnd, IDC_Speed, "Velocidad" );					//IDC_Speed
			QL2K_as ( hWnd, IDC_Delay, "Retardo" );						//IDC_Delay
			QL2K_as ( hWnd, IDC_RomBox, "ROM" );						//IDC_RomBox
			QL2K_as ( hWnd, IDC_RomBoot, "Arranque" );					//IDC_RomBoot
			QL2K_as ( hWnd, IDC_Rom1, "ROM1" );							//IDC_Rom1
			QL2K_as ( hWnd, IDC_Rom2, "ROM2" );							//IDC_Rom2
			QL2K_as ( hWnd, ID_CHK_MOUSE, "Sin ratón" );				//ID_CHK_MOUSE
			QL2K_as ( hWnd, ID_CHK_ALTKEY, "Sin tecla ALT" );			//ID_CHK_ALTKEY
			QL2K_as ( hWnd, IDC_DIRECTDRAW, "DirectDraw" );				//IDC_DIRECTDRAW
			QL2K_as ( hWnd, IDC_FULLSCREEN, "Pantalla completa" );		//IDC_FULLSCREEN
																		//ID_MDVWIN - Nothing to DO !!! ;-)
			QL2K_as ( hWnd, ID_SAVE, "Guardar" );						//ID_SAVE
			QL2K_as ( hWnd, ID_CANCEL, "Cancelar" );					//ID_CANCEL
			QL2K_as ( hWnd, ID_OK, "Aceptar" );							//ID_OK
			QL2K_as ( hWnd, IDC_GDIFULLSCREEN, "Pantalla completa GDI" );	//IDC_GDIFULLSCREEN
			QL2K_as ( hWnd, ID_CHK_CorrectBL, "Black lines adjust" );// ID_CHK_CorrectBL
			return;

		case UI_LANG_GE:
			// Jimmy 096 - Translation done.
			QL2K_as ( hWnd, IDC_MemSize, "Speichergröße" );			//IDC_MemSize
			QL2K_as ( hWnd, IDC_ScreenSize, "Bildschirmgröße" );		//IDC_ScreenSize
			QL2K_as ( hWnd, IDC_KeybLayout, "Tastatur-Belegung" );	//IDC_KeybLayout
			QL2K_as ( hWnd, IDC_Speed, "Geschwindigkeit" );					//IDC_Speed
			QL2K_as ( hWnd, IDC_Delay, "Verzögerung" );					//IDC_Delay
			QL2K_as ( hWnd, IDC_RomBox, "ROM" );					//IDC_RomBox
			QL2K_as ( hWnd, IDC_RomBoot, "BOOT" );					//IDC_RomBoot
			QL2K_as ( hWnd, IDC_Rom1, "ROM1" );						//IDC_Rom1
			QL2K_as ( hWnd, IDC_Rom2, "ROM2" );						//IDC_Rom2
			QL2K_as ( hWnd, ID_CHK_MOUSE, "Keine Maus" );				//ID_CHK_MOUSE
			QL2K_as ( hWnd, ID_CHK_ALTKEY, "Keine Taste ALT" );			//ID_CHK_ALTKEY
			QL2K_as ( hWnd, IDC_DIRECTDRAW, "DirectDraw" );			//IDC_DIRECTDRAW
			QL2K_as ( hWnd, IDC_FULLSCREEN, "Gesamtes Bild" );		//IDC_FULLSCREEN
																	//ID_MDVWIN - Nothing to DO !!! ;-)
			QL2K_as ( hWnd, ID_SAVE, "Speichern" );						//ID_SAVE
			QL2K_as ( hWnd, ID_CANCEL, "Abbrechen" );					//ID_CANCEL
			QL2K_as ( hWnd, ID_OK, "OK" );							//ID_OK			
			QL2K_as ( hWnd, IDC_GDIFULLSCREEN, "GDI Gesamtes Bild" );	//IDC_GDIFULLSCREEN
			QL2K_as ( hWnd, ID_CHK_CorrectBL, "Black lines adjust" );// ID_CHK_CorrectBL
			return;

		case UI_LANG_IT:	
			QL2K_as ( hWnd, IDC_MemSize, "Dimensione della memoria" );		//IDC_MemSize
			QL2K_as ( hWnd, IDC_ScreenSize, "Dimensione dello schermo" );	//IDC_ScreenSize
			QL2K_as ( hWnd, IDC_KeybLayout, "Nazionalità della tastiera" );	//IDC_KeybLayout
			QL2K_as ( hWnd, IDC_Speed, "Velocità" );						//IDC_Speed
			QL2K_as ( hWnd, IDC_Delay, "Ritardo" );							//IDC_Delay
			QL2K_as ( hWnd, IDC_RomBox, "ROM" );							//IDC_RomBox
			QL2K_as ( hWnd, IDC_RomBoot, "BOOT" );							//IDC_RomBoot
			QL2K_as ( hWnd, IDC_Rom1, "ROM1" );								//IDC_Rom1
			QL2K_as ( hWnd, IDC_Rom2, "ROM2" );								//IDC_Rom2
			QL2K_as ( hWnd, ID_CHK_MOUSE, "Nessun MOUSE" );					//ID_CHK_MOUSE
			QL2K_as ( hWnd, ID_CHK_ALTKEY, "No Alt Key" );					//ID_CHK_ALTKEY
			QL2K_as ( hWnd, IDC_DIRECTDRAW, "DirectDraw" );					//IDC_DIRECTDRAW
			QL2K_as ( hWnd, IDC_FULLSCREEN, "Schermo pieno" );				//IDC_FULLSCREEN
																			//ID_MDVWIN - Nothing to DO !!! ;-)
			QL2K_as ( hWnd, ID_SAVE, "Salva" );								//ID_SAVE
			QL2K_as ( hWnd, ID_CANCEL, "Annulla" );							//ID_CANCEL
			QL2K_as ( hWnd, ID_OK, "OK" );									//ID_OK
			QL2K_as ( hWnd, IDC_GDIFULLSCREEN, "Schermo pieno" );			//IDC_GDIFULLSCREEN
			QL2K_as ( hWnd, ID_CHK_CorrectBL, "Black lines adjust" );		// ID_CHK_CorrectBL
			return;
	}
		
	
}

static void init_options(HWND hWnd)
{
int opt;
int mso[]={1,0,2,3,-1,4,-1,-1,-1,5};
	
	/* default screen size */ // Jimmy 095 - Adding Screen Sizes
	opt=screen_res;
	SendDlgItemMessage(hWnd, ID_CBX_SS, CB_RESETCONTENT, 0, 0);
	addstring(hWnd,ID_CBX_SS, "1: 512x256");
	addstring(hWnd,ID_CBX_SS, "2: 512x341");
	addstring(hWnd,ID_CBX_SS, "3: 768x512");
	addstring(hWnd,ID_CBX_SS, "4: 1024x683");
	addstring(hWnd,ID_CBX_SS, "5: 1024x512");
	addstring(hWnd,ID_CBX_SS, "6: 1024x768");
	addstring(hWnd,ID_CBX_SS, "7: 1280x640");
	addstring(hWnd,ID_CBX_SS, "8: 1280x1024");
	SendDlgItemMessage(hWnd, ID_CBX_SS, CB_SETCURSEL, opt-1, 0);

	/* memory size */
	opt=ram_size; /* valid options -1, 0, 1, 2, 4, 8 */
	if (mso[opt+1]==-1) opt=-1;	/* default to 640k */
	SendDlgItemMessage(hWnd, ID_CBX_MS, CB_RESETCONTENT, 0, 0);
	addstring(hWnd,ID_CBX_MS, "128k");
	addstring(hWnd,ID_CBX_MS, "640k");
	addstring(hWnd,ID_CBX_MS, "1M");
	addstring(hWnd,ID_CBX_MS, "2M");
	addstring(hWnd,ID_CBX_MS, "4M");
	addstring(hWnd,ID_CBX_MS, "8M");
	SendDlgItemMessage(hWnd, ID_CBX_MS, CB_SETCURSEL, mso[opt+1], 0);

	/* default keyb language */
	opt=opt_keyb;
	SendDlgItemMessage(hWnd, ID_CBX_KBD, CB_RESETCONTENT, 0, 0);
	addstring(hWnd,ID_CBX_KBD, "US");
	addstring(hWnd,ID_CBX_KBD, "UK");
	addstring(hWnd,ID_CBX_KBD, "GE");
	addstring(hWnd,ID_CBX_KBD, "FR");
	addstring(hWnd,ID_CBX_KBD, "IT");
//	addstring(hWnd,ID_CBX_KBD, "SE");
	SendDlgItemMessage(hWnd, ID_CBX_KBD, CB_SETCURSEL, opt, 0);

	/* NFA addresses */
	opt=0;
	if(opt_cartaddr[0]==0x0c000)opt=0;
	if(opt_cartaddr[0]==0x10000)opt=1;
	if(opt_cartaddr[0]==0xc0000)opt=2;
	if(opt_cartaddr[0]==0xc4000)opt=3;
	if(opt_cartaddr[0]==0xc8000)opt=4;
	if(opt_cartaddr[0]==0xcc000)opt=5;
	SendDlgItemMessage(hWnd, ID_ADR_NFA, CB_RESETCONTENT, 0, 0);
	addstring(hWnd,ID_ADR_NFA, "0c000");
	addstring(hWnd,ID_ADR_NFA, "10000");
	addstring(hWnd,ID_ADR_NFA, "c0000");
	addstring(hWnd,ID_ADR_NFA, "c4000");
	addstring(hWnd,ID_ADR_NFA, "c8000");
	addstring(hWnd,ID_ADR_NFA, "cc000");
	SendDlgItemMessage(hWnd, ID_ADR_NFA, CB_SETCURSEL, opt, 0);

	/* other addresses */
	opt=1;
	if(opt_cartaddr[1]==0x0c000)opt=0;
	if(opt_cartaddr[1]==0x10000)opt=1;
	if(opt_cartaddr[1]==0xc0000)opt=2;
	if(opt_cartaddr[1]==0xc4000)opt=3;
	if(opt_cartaddr[1]==0xc8000)opt=4;
	if(opt_cartaddr[1]==0xcc000)opt=5;
	SendDlgItemMessage(hWnd, ID_ADR_OTHER, CB_RESETCONTENT, 0, 0);
	addstring(hWnd,ID_ADR_OTHER, "0c000");
	addstring(hWnd,ID_ADR_OTHER, "10000");
	addstring(hWnd,ID_ADR_OTHER, "c0000");
	addstring(hWnd,ID_ADR_OTHER, "c4000");
	addstring(hWnd,ID_ADR_OTHER, "c8000");
	addstring(hWnd,ID_ADR_OTHER, "cc000");
	SendDlgItemMessage(hWnd, ID_ADR_OTHER, CB_SETCURSEL, opt, 0);

	/* ROM files */
	SetDlgItemText(hWnd, ID_ROM_BOOT, romfile);
	SetDlgItemText(hWnd, ID_ROM_NFA, opt_cartfn[0]);
	SetDlgItemText(hWnd, ID_ROM_OTHER, opt_cartfn[1]);


	/* check boxes */
	// Jimmy 093 - Mouse support
	opt=0;
	if (opt_use_mouse==0) opt=1;
	CheckDlgButton(hWnd, ID_CHK_MOUSE, opt);
	opt=0;

	// Jimmy 093 - No ALT Key
	if (opt_use_altkey==0) opt=1;
	CheckDlgButton(hWnd, ID_CHK_ALTKEY, opt);

	// Jimmy 093 - GDI Full Screen
	opt=GDI_NORMAL;
	if ( opt_GDI_FullScreen == GDI_MAXIMISE) opt = GDI_MAXIMISE;
	CheckDlgButton(hWnd, IDC_GDIFULLSCREEN, opt);

	// Jimmy 095 - Black Line Correction
	opt = 0;
	if ( opt_CorrectBL == 1 ) opt = 1;
	CheckDlgButton(hWnd, ID_CHK_CorrectBL, opt);


	/* text edit boxes */
	SetDlgItemInt(hWnd, ID_SPEED, qlay1msec, FALSE);
	SetDlgItemInt(hWnd, ID_DELAY, opt_busy_wait, FALSE);
}
static void init_options2(HWND hWnd)
{
	
	/* MDV files */
	SetDlgItemText(hWnd, ID_MDV1, mdvfn[0]);
	SetDlgItemText(hWnd, ID_MDV2, mdvfn[1]);
	SetDlgItemText(hWnd, ID_MDV3, mdvfn[2]);
	SetDlgItemText(hWnd, ID_MDV4, mdvfn[3]);
	SetDlgItemText(hWnd, ID_MDV5, mdvfn[4]);
	SetDlgItemText(hWnd, ID_MDV6, mdvfn[5]);
	SetDlgItemText(hWnd, ID_MDV7, mdvfn[6]);
	SetDlgItemText(hWnd, ID_MDV8, mdvfn[7]);

	/* WIN files */
	SetDlgItemText(hWnd, ID_WIN1, winfn[0]);
	SetDlgItemText(hWnd, ID_WIN2, winfn[1]);
	SetDlgItemText(hWnd, ID_WIN3, winfn[2]);
	SetDlgItemText(hWnd, ID_WIN4, winfn[3]);
	SetDlgItemText(hWnd, ID_WIN5, winfn[4]);
	SetDlgItemText(hWnd, ID_WIN6, winfn[5]);
	SetDlgItemText(hWnd, ID_WIN7, winfn[6]);
	SetDlgItemText(hWnd, ID_WIN8, winfn[7]);

}

char szDirName[256];

static LPCTSTR gcd(char *fn)
{
char	*s;
	strcpy(szDirName,fn);
	s = szDirName + strlen(szDirName);
	while (s > szDirName && *--s != '\\');
	*s = '\0';
	return (LPCTSTR) szDirName;
}

static BOOL CALLBACK Dialog2(HWND hWnd, UINT wMsg, WPARAM wPar, LPARAM lPar)
{

static char szFile[256];
static char szDirName[256];

// Jimmy 093 - For managing Dialog Box for WINx
static char szTmpFile[256];
int isAWinDrive;

OPENFILENAME ofn;
int id, bRet;

	switch (wMsg) {
        case WM_INITDIALOG:
			init_options2(hWnd);
		return TRUE;

	case WM_COMMAND:
//		fpr("wcmd1 def, %d, %d, %ld\n",wMsg,wPar&0xffff,lPar);
		switch(wPar) {

		case ID_OK:

			GetDlgItemText(hWnd, ID_MDV1, mdvfn[0], 256);
			GetDlgItemText(hWnd, ID_MDV2, mdvfn[1], 256);
			GetDlgItemText(hWnd, ID_MDV3, mdvfn[2], 256);
			GetDlgItemText(hWnd, ID_MDV4, mdvfn[3], 256);
			GetDlgItemText(hWnd, ID_MDV5, mdvfn[4], 256);
			GetDlgItemText(hWnd, ID_MDV6, mdvfn[5], 256);
			GetDlgItemText(hWnd, ID_MDV7, mdvfn[6], 256);
			GetDlgItemText(hWnd, ID_MDV8, mdvfn[7], 256);

			GetDlgItemText(hWnd, ID_WIN1, winfn[0], 256);
			GetDlgItemText(hWnd, ID_WIN2, winfn[1], 256);
			GetDlgItemText(hWnd, ID_WIN3, winfn[2], 256);
			GetDlgItemText(hWnd, ID_WIN4, winfn[3], 256);
			GetDlgItemText(hWnd, ID_WIN5, winfn[4], 256);
			GetDlgItemText(hWnd, ID_WIN6, winfn[5], 256);
			GetDlgItemText(hWnd, ID_WIN7, winfn[6], 256);
			GetDlgItemText(hWnd, ID_WIN8, winfn[7], 256);

			EndDialog(hWnd, TRUE);
			return TRUE;

		case ID_CANCEL:
			EndDialog(hWnd, FALSE);
			return TRUE;

		case ID_BRW_WIN1:
		case ID_BRW_WIN2:
		case ID_BRW_WIN3:
		case ID_BRW_WIN4:
		case ID_BRW_WIN5:
		case ID_BRW_WIN6:
		case ID_BRW_WIN7:
		case ID_BRW_WIN8:
		case ID_BRW_MDV1:
		case ID_BRW_MDV2:
		case ID_BRW_MDV3:
		case ID_BRW_MDV4:
		case ID_BRW_MDV5:
		case ID_BRW_MDV6:
		case ID_BRW_MDV7:
		case ID_BRW_MDV8:

			// Jimmy 093 - Adding update on TEXT Box before opening dialog Boxes...
			GetDlgItemText(hWnd, ID_MDV1, mdvfn[0], 256);
			GetDlgItemText(hWnd, ID_MDV2, mdvfn[1], 256);
			GetDlgItemText(hWnd, ID_MDV3, mdvfn[2], 256);
			GetDlgItemText(hWnd, ID_MDV4, mdvfn[3], 256);
			GetDlgItemText(hWnd, ID_MDV5, mdvfn[4], 256);
			GetDlgItemText(hWnd, ID_MDV6, mdvfn[5], 256);
			GetDlgItemText(hWnd, ID_MDV7, mdvfn[6], 256);
			GetDlgItemText(hWnd, ID_MDV8, mdvfn[7], 256);

			GetDlgItemText(hWnd, ID_WIN1, winfn[0], 256);
			GetDlgItemText(hWnd, ID_WIN2, winfn[1], 256);
			GetDlgItemText(hWnd, ID_WIN3, winfn[2], 256);
			GetDlgItemText(hWnd, ID_WIN4, winfn[3], 256);
			GetDlgItemText(hWnd, ID_WIN5, winfn[4], 256);
			GetDlgItemText(hWnd, ID_WIN6, winfn[5], 256);
			GetDlgItemText(hWnd, ID_WIN7, winfn[6], 256);
			GetDlgItemText(hWnd, ID_WIN8, winfn[7], 256);

			// Jimmy 093 - isAWinDrive
			isAWinDrive = 0;

			if (! *szDirName){
				szDirName[0]='.';
				szDirName[1]='\0';
			}

			*szFile = '\0';
			*szTmpFile = '\0';
			memset(&ofn, 0, sizeof(ofn));

			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = hWnd;
			ofn.hInstance = hInstance;
			ofn.nFilterIndex = 1;
			ofn.lpstrFile = szFile;
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrInitialDir = szDirName;
			ofn.Flags = OFN_HIDEREADONLY |
				OFN_FILEMUSTEXIST |
				OFN_NOCHANGEDIR;	/* come back in cwd */
									// ofn.Flags = OFN_SHOWHELP | OFN_FILEMUSTEXIST;

			if (wPar == ID_BRW_WIN1) {
				// Jimmy - Ajout de qlay.dir
				sprintf(szTmpFile,"%sqlay.dir",winfn[0]);
				strcpy(ofn.lpstrFile,szTmpFile);
				ofn.lpstrInitialDir = gcd(szTmpFile);
				ofn.lpstrFilter = "QLAY.DIR Files (qlay.dir)\0qlay.dir\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select QLAY.DIR file";
				id = ID_WIN1;
				isAWinDrive = 1;
				bRet = GetOpenFileName(&ofn);
			}
			else if (wPar == ID_BRW_WIN2) {
				// Jimmy - Ajout de qlay.dir
				sprintf(szTmpFile,"%sqlay.dir",winfn[1]);
				strcpy(ofn.lpstrFile,szTmpFile);
				ofn.lpstrInitialDir = gcd(szTmpFile);
				ofn.lpstrFilter = "QLAY.DIR Files (qlay.dir)\0qlay.dir\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select QLAY.DIR file";
				id = ID_WIN2;
				isAWinDrive = 1;
				bRet = GetOpenFileName(&ofn);
			}
			else if (wPar == ID_BRW_WIN3) {
				// Jimmy - Ajout de qlay.dir
				sprintf(szTmpFile,"%sqlay.dir",winfn[2]);
				strcpy(ofn.lpstrFile,szTmpFile);
				ofn.lpstrInitialDir = gcd(szTmpFile);
				ofn.lpstrFilter = "QLAY.DIR Files (qlay.dir)\0qlay.dir\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select QLAY.DIR file";
				id = ID_WIN3;
				isAWinDrive = 1;
				bRet = GetOpenFileName(&ofn);
			}
			else if (wPar == ID_BRW_WIN4) {
				// Jimmy - Ajout de qlay.dir
				sprintf(szTmpFile,"%sqlay.dir",winfn[3]);
				strcpy(ofn.lpstrFile,szTmpFile);
				ofn.lpstrInitialDir = gcd(szTmpFile);
				ofn.lpstrFilter = "QLAY.DIR Files (qlay.dir)\0qlay.dir\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select QLAY.DIR file";
				id = ID_WIN4;
				isAWinDrive = 1;
				bRet = GetOpenFileName(&ofn);
			}
			else if (wPar == ID_BRW_WIN5) {
				// Jimmy - Ajout de qlay.dir
				sprintf(szTmpFile,"%sqlay.dir",winfn[4]);
				strcpy(ofn.lpstrFile,szTmpFile);
				ofn.lpstrInitialDir = gcd(szTmpFile);
				ofn.lpstrFilter = "QLAY.DIR Files (qlay.dir)\0qlay.dir\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select QLAY.DIR file";
				id = ID_WIN5;
				isAWinDrive = 1;
				bRet = GetOpenFileName(&ofn);
			}
			else if (wPar == ID_BRW_WIN6) {
				// Jimmy - Ajout de qlay.dir
				sprintf(szTmpFile,"%sqlay.dir",winfn[5]);
				strcpy(ofn.lpstrFile,szTmpFile);
				ofn.lpstrInitialDir = gcd(szTmpFile);
				ofn.lpstrFilter = "QLAY.DIR Files (qlay.dir)\0qlay.dir\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select QLAY.DIR file";
				id = ID_WIN6;
				isAWinDrive = 1;
				bRet = GetOpenFileName(&ofn);
			}
			else if (wPar == ID_BRW_WIN7) {
				// Jimmy - Ajout de qlay.dir
				sprintf(szTmpFile,"%sqlay.dir",winfn[6]);
				strcpy(ofn.lpstrFile,szTmpFile);
				ofn.lpstrInitialDir = gcd(szTmpFile);
				ofn.lpstrFilter = "QLAY.DIR Files (qlay.dir)\0qlay.dir\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select QLAY.DIR file";
				id = ID_WIN7;
				isAWinDrive = 1;
				bRet = GetOpenFileName(&ofn);
			}
			else if (wPar == ID_BRW_WIN8) {
				// Jimmy - Ajout de qlay.dir
				sprintf(szTmpFile,"%sqlay.dir",winfn[7]);
				strcpy(ofn.lpstrFile,szTmpFile);
				ofn.lpstrInitialDir = gcd(szTmpFile);
				ofn.lpstrFilter = "QLAY.DIR Files (qlay.dir)\0qlay.dir\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select QLAY.DIR file";
				id = ID_WIN8;
				isAWinDrive = 1;
				bRet = GetOpenFileName(&ofn);
			}
												
			else if (wPar == ID_BRW_MDV1) {
				strcpy(ofn.lpstrFile,mdvfn[0]);
				ofn.lpstrInitialDir = gcd(mdvfn[0]);
				ofn.lpstrFilter = "MDV Files (*.mdv)\0*.mdv\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select MDV file";
				id = ID_MDV1;
				bRet = GetOpenFileName(&ofn);
			}
			else if (wPar == ID_BRW_MDV2) {
				strcpy(ofn.lpstrFile,mdvfn[1]);
				ofn.lpstrInitialDir = gcd(mdvfn[1]);
				ofn.lpstrFilter = "MDV Files (*.mdv)\0*.mdv\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select MDV file";
				id = ID_MDV2;
				bRet = GetOpenFileName(&ofn);
			}
			else if (wPar == ID_BRW_MDV3) {
				strcpy(ofn.lpstrFile,mdvfn[2]);
				ofn.lpstrInitialDir = gcd(mdvfn[2]);
				ofn.lpstrFilter = "MDV Files (*.mdv)\0*.mdv\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select MDV file";
				id = ID_MDV3;
				bRet = GetOpenFileName(&ofn);
			}
			else if (wPar == ID_BRW_MDV4) {
				strcpy(ofn.lpstrFile,mdvfn[3]);
				ofn.lpstrInitialDir = gcd(mdvfn[3]);
				ofn.lpstrFilter = "MDV Files (*.mdv)\0*.mdv\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select MDV file";
				id = ID_MDV4;
				bRet = GetOpenFileName(&ofn);
			}
			else if (wPar == ID_BRW_MDV5) {
				strcpy(ofn.lpstrFile,mdvfn[4]);
				ofn.lpstrInitialDir = gcd(mdvfn[4]);
				ofn.lpstrFilter = "MDV Files (*.mdv)\0*.mdv\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select MDV file";
				id = ID_MDV5;
				bRet = GetOpenFileName(&ofn);
			}
			else if (wPar == ID_BRW_MDV6) {
				strcpy(ofn.lpstrFile,mdvfn[5]);
				ofn.lpstrInitialDir = gcd(mdvfn[5]);
				ofn.lpstrFilter = "MDV Files (*.mdv)\0*.mdv\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select MDV file";
				id = ID_MDV6;
				bRet = GetOpenFileName(&ofn);
			}
			else if (wPar == ID_BRW_MDV7) {
				strcpy(ofn.lpstrFile,mdvfn[6]);
				ofn.lpstrInitialDir = gcd(mdvfn[6]);
				ofn.lpstrFilter = "MDV Files (*.mdv)\0*.mdv\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select MDV file";
				id = ID_MDV7;
				bRet = GetOpenFileName(&ofn);
			}
			else /*if (wPar == ID_BRW_MDV8) */{
				strcpy(ofn.lpstrFile,mdvfn[7]);
				ofn.lpstrInitialDir = gcd(mdvfn[7]);
				ofn.lpstrFilter = "MDV Files (*.mdv)\0*.mdv\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select MDV file";
				id = ID_MDV8;
				bRet = GetOpenFileName(&ofn);
			}


			if (bRet) {
				char *s;


				// Jimmy 093 - Well if it is isAWinDrive = 1; Remove QLAY.DIR at end else nothing to do. 093
				strcpy(szFile, ofn.lpstrFile);
				if (isAWinDrive == 1)
				{
					// It's a WIN drive so I remove qlay.dir and I add a backslash
					sprintf(szFile,"%s\\",gcd(ofn.lpstrFile));
				}
				
				/* display browsed file */
				SetDlgItemText(hWnd, id, szFile);

				/* set standard Directory Path */
				strcpy(szDirName, szFile);
				s = szDirName + strlen(szDirName);
				while (s > szDirName && *--s != '\\')
				    ;
				*s = '\0';
			}
			return TRUE;

		default:
			return FALSE;


            } /* switch (wPar) */

        case WM_SYSCOMMAND :
            if (wPar == SC_CLOSE) {
		EndDialog(hWnd, FALSE);
		return TRUE;
            }
            else
		return FALSE;

        default:
            return FALSE;

    } /* switch (wMsg)*/

}

int wincfg2_main(HINSTANCE hInst, HINSTANCE hInst2)
{
DLGPROC	qlcfg2_dialog;

	hInstance = hInst;
	qlcfg2_dialog = (DLGPROC) MakeProcInstance((FARPROC) Dialog2, hInst);
	DialogBox(hInst, (LPSTR) "CFG_WIN", (HWND)hInst2, qlcfg2_dialog);
	FreeProcInstance((FARPROC) qlcfg2_dialog);

	return 0;
}



static BOOL CALLBACK Dialog(HWND hWnd, UINT wMsg, WPARAM wPar, LPARAM lPar)
{
static char szFile[256];
static char szDirName[256];
char tmpfield[256];
OPENFILENAME ofn;
int id, bRet;
int writefile,opt;

	writefile=0;
	switch (wMsg) {

// XPZ - 05/06/2003 - Begin of Tiny flag buttons management
	case WM_DRAWITEM:
		{
			LPDRAWITEMSTRUCT	pDrawItemStruct = (LPDRAWITEMSTRUCT)lPar;
			HBITMAP				hBmp, hOldBmp;
			HDC					hMemDC;

			if (!(pDrawItemStruct->itemState & ODS_SELECTED))
			{
				switch (((NMHDR *)lPar)->idFrom)
				{
				case IDC_BTN_FRENCH:
					hBmp = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BMP_FRENCH));
					break;
				case IDC_BTN_ENGLISH:
					hBmp = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BMP_ENGLISH));
					break;
				case IDC_BTN_GERMAN:
					hBmp = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BMP_GERMAN));
					break;
				case IDC_BTN_ITALIAN:
					hBmp = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BMP_ITALIAN));
					break;
				case IDC_BTN_SPANISH:
					hBmp = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BMP_SPANISH));
					break;
				}
			}
			else
			{
				switch (((NMHDR *)lPar)->idFrom)
				{
				case IDC_BTN_FRENCH:
					hBmp = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BMP_FRENCH_S));
					break;
				case IDC_BTN_ENGLISH:
					hBmp = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BMP_ENGLISH_S));
					break;
				case IDC_BTN_GERMAN:
					hBmp = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BMP_GERMAN_S));
					break;
				case IDC_BTN_ITALIAN:
					hBmp = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BMP_ITALIAN_S));
					break;
				case IDC_BTN_SPANISH:
					hBmp = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BMP_SPANISH_S));
					break;
				}
			}

			hMemDC	= CreateCompatibleDC(pDrawItemStruct->hDC);
			hOldBmp	= SelectObject(hMemDC, hBmp);
			BitBlt(pDrawItemStruct->hDC, 0, 0, 23, 13, hMemDC, 0, 0, SRCCOPY);
			SelectObject(hMemDC, hOldBmp);
			DeleteObject(hMemDC);
			DeleteObject(hBmp);
		}

		return 0;
// XPZ - 05/06/2003 - End of Tiny flag buttons management
		
	case WM_INITDIALOG:

			init_options(hWnd);
			
			QL2K_Change_Language(hWnd, opt_ui_lang);

			return TRUE;

	
	case WM_COMMAND:
//		fpr("wcmd1 def, %d, %d, %ld\n",wMsg,wPar&0xffff,lPar);
		switch(wPar) {
// XPZ
		case IDC_DIRECTDRAW:
			if (IsDlgButtonChecked(hWnd, IDC_DIRECTDRAW) != BST_CHECKED)
				CheckDlgButton(hWnd, IDC_FULLSCREEN, BST_UNCHECKED);
			break;
// XPZ

		case ID_SAVE:
			writefile=1;
			opt_use_altkey = 1 - IsDlgButtonChecked(hWnd, ID_CHK_ALTKEY);
			opt_use_mouse = 1 - IsDlgButtonChecked(hWnd, ID_CHK_MOUSE);

			GetDlgItemText(hWnd, ID_ROM_BOOT, romfile, 256);
			GetDlgItemText(hWnd, ID_ROM_NFA, opt_cartfn[0], 256);
			GetDlgItemText(hWnd, ID_ADR_NFA, tmpfield, 256);
			sscanf(tmpfield,"%x",&opt_cartaddr[0]);
			GetDlgItemText(hWnd, ID_ROM_OTHER, opt_cartfn[1], 256);
			GetDlgItemText(hWnd, ID_ADR_OTHER, tmpfield, 256);
			sscanf(tmpfield,"%x",&opt_cartaddr[1]);

			GetDlgItemText(hWnd, ID_CBX_SS, tmpfield, 256);
			screen_res=tmpfield[0]-'0';

			opt=-1;
			GetDlgItemText(hWnd, ID_CBX_MS, tmpfield, 256);
			tmpfield[2]='\0';
			if (strcmp(tmpfield,"12")==0) opt=0;
			if (strcmp(tmpfield,"64")==0) opt=-1;
			if (strcmp(tmpfield,"1M")==0) opt=1;
			if (strcmp(tmpfield,"2M")==0) opt=2;
			if (strcmp(tmpfield,"4M")==0) opt=4;
			if (strcmp(tmpfield,"8M")==0) opt=8;
			ram_size=opt;

			opt=-1;
			GetDlgItemText(hWnd, ID_CBX_KBD, tmpfield, 256);
			tmpfield[2]='\0';
			if (strcmp(tmpfield,"US")==0) opt=KEYB_US;
			if (strcmp(tmpfield,"UK")==0) opt=KEYB_UK;
			if (strcmp(tmpfield,"GE")==0) opt=KEYB_GE;
			if (strcmp(tmpfield,"FR")==0) opt=KEYB_FR;
			if (strcmp(tmpfield,"IT")==0) opt=KEYB_IT;
			if (strcmp(tmpfield,"SE")==0) opt=KEYB_SE;
			opt_keyb=opt;

			GetDlgItemText(hWnd, ID_SPEED, tmpfield, 256);
			sscanf(tmpfield,"%d",&qlay1msec);
			GetDlgItemText(hWnd, ID_DELAY, tmpfield, 256);
			sscanf(tmpfield,"%d",&opt_busy_wait);

			// Jimmy 093 - GDI Full Screen
			opt_GDI_FullScreen = IsDlgButtonChecked(hWnd, IDC_GDIFULLSCREEN);

			// Jimmy 095 - Black Line Correction
			opt_CorrectBL = IsDlgButtonChecked(hWnd, ID_CHK_CorrectBL);


			write_options();
			break;
			/* fall through */
		case ID_MDVWIN:
			/** Boite de dialogue de configuration des lecteurs **/
			wincfg2_main((HINSTANCE)hInstance, (HINSTANCE)hWnd); /* hInstance */
			break;

		case ID_OK:
			opt_use_altkey = 1 - IsDlgButtonChecked(hWnd, ID_CHK_ALTKEY);
			opt_use_mouse = 1 - IsDlgButtonChecked(hWnd, ID_CHK_MOUSE);

			GetDlgItemText(hWnd, ID_ROM_BOOT, romfile, 256);
			GetDlgItemText(hWnd, ID_ROM_NFA, opt_cartfn[0], 256);
			GetDlgItemText(hWnd, ID_ADR_NFA, tmpfield, 256);
			sscanf(tmpfield,"%x",&opt_cartaddr[0]);
			GetDlgItemText(hWnd, ID_ROM_OTHER, opt_cartfn[1], 256);
			GetDlgItemText(hWnd, ID_ADR_OTHER, tmpfield, 256);
			sscanf(tmpfield,"%x",&opt_cartaddr[1]);

			GetDlgItemText(hWnd, ID_CBX_SS, tmpfield, 256);
			screen_res=tmpfield[0]-'0';

			opt=-1;
			GetDlgItemText(hWnd, ID_CBX_MS, tmpfield, 256);
			tmpfield[2]='\0';
			if (strcmp(tmpfield,"12")==0) opt=0;
			if (strcmp(tmpfield,"64")==0) opt=-1;
			if (strcmp(tmpfield,"1M")==0) opt=1;
			if (strcmp(tmpfield,"2M")==0) opt=2;
			if (strcmp(tmpfield,"4M")==0) opt=4;
			if (strcmp(tmpfield,"8M")==0) opt=8;
			ram_size=opt;

			opt=-1;
			GetDlgItemText(hWnd, ID_CBX_KBD, tmpfield, 256);
			tmpfield[2]='\0';
			if (strcmp(tmpfield,"US")==0) opt=KEYB_US;
			if (strcmp(tmpfield,"UK")==0) opt=KEYB_UK;
			if (strcmp(tmpfield,"GE")==0) opt=KEYB_GE;
			if (strcmp(tmpfield,"FR")==0) opt=KEYB_FR;
			if (strcmp(tmpfield,"IT")==0) opt=KEYB_IT;
			if (strcmp(tmpfield,"SE")==0) opt=KEYB_SE;
			opt_keyb=opt;

			GetDlgItemText(hWnd, ID_SPEED, tmpfield, 256);
			sscanf(tmpfield,"%d",&qlay1msec);
			GetDlgItemText(hWnd, ID_DELAY, tmpfield, 256);
			sscanf(tmpfield,"%d",&opt_busy_wait);

			// Jimmy 093 - GDI Full Screen
			opt_GDI_FullScreen = IsDlgButtonChecked(hWnd, IDC_GDIFULLSCREEN);

			// Jimmy 095 - Black Line Correction
			opt_CorrectBL = IsDlgButtonChecked(hWnd, ID_CHK_CorrectBL);

			EndDialog(hWnd, TRUE);
			return TRUE;

		case ID_LOAD:

		case ID_CANCEL:
			iSitCancelButton = 1;
			EndDialog(hWnd, FALSE);
			return TRUE;

		case ID_BRW_BOOT:
		case ID_BRW_NFA:
		case ID_BRW_OTHER:
		case ID_BRW_WIN1:
		case ID_BRW_WIN2:
		case ID_BRW_MDV1:
		case ID_BRW_MDV2:

			if (! *szDirName){
				szDirName[0]='.';
				szDirName[1]='\0';
			}

			*szFile = '\0';
			memset(&ofn, 0, sizeof(ofn));

			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = hWnd;
			ofn.hInstance = hInstance;
			ofn.nFilterIndex = 1;
			ofn.lpstrFile = szFile;
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrInitialDir = szDirName;
//			ofn.Flags = OFN_SHOWHELP | OFN_FILEMUSTEXIST;
			ofn.Flags = OFN_HIDEREADONLY |
				OFN_FILEMUSTEXIST |
				OFN_NOCHANGEDIR;	/* come back in cwd */
			if (wPar == ID_BRW_BOOT) {
				strcpy(ofn.lpstrFile,romfile);
				ofn.lpstrInitialDir = gcd(romfile);
				ofn.lpstrFilter = "ROM Files (*.rom)\0*.rom\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select Boot ROM File";
				id = ID_ROM_BOOT;
				bRet = GetOpenFileName(&ofn);
			}
			else if (wPar == ID_BRW_NFA) {
				strcpy(ofn.lpstrFile,opt_cartfn[0]);
				ofn.lpstrInitialDir = gcd(opt_cartfn[0]);
				ofn.lpstrFilter = "ROM Files (*.rom)\0*.rom\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select NFA ROM file";
				id = ID_ROM_NFA;
				bRet = GetOpenFileName(&ofn);
			}
			else /* (wPar == ID_BRW_OTHER) */
			{
				strcpy(ofn.lpstrFile,opt_cartfn[1]);
				ofn.lpstrInitialDir = gcd(opt_cartfn[1]);
				ofn.lpstrFilter = "ROM Files (*.rom)\0*.rom\0All files (*.*)\0*.*\0";
				ofn.lpstrTitle = "Select other ROM filename";
				id = ID_ROM_OTHER;
				bRet = GetOpenFileName(&ofn);
			}

			if (bRet) {
				char *s;

				/* display browsed file */
				SetDlgItemText(hWnd, id, szFile);

				/* set standard Directory Path */
				strcpy(szDirName, szFile);
				s = szDirName + strlen(szDirName);
				while (s > szDirName && *--s != '\\')
				    ;
				*s = '\0';
			}
			return TRUE;

		// Jimmy 093 - Multi language support Hit Flag Button Management
		case IDC_BTN_FRENCH:
			opt_ui_lang = UI_LANG_FR;
			// QL2K_init_flag_buttons(hWnd);
			QL2K_Change_Language(hWnd, UI_LANG_FR);
			return TRUE;

		case IDC_BTN_ENGLISH:
			opt_ui_lang = UI_LANG_UK;
			// QL2K_init_flag_buttons(hWnd);
			QL2K_Change_Language(hWnd, UI_LANG_UK);
			return TRUE;

		case IDC_BTN_SPANISH:
			opt_ui_lang = UI_LANG_SP;
			// QL2K_init_flag_buttons(hWnd);
			QL2K_Change_Language(hWnd, UI_LANG_SP);
			return TRUE;

		case IDC_BTN_GERMAN:
			opt_ui_lang = UI_LANG_GE;
			// QL2K_init_flag_buttons(hWnd);
			QL2K_Change_Language(hWnd, UI_LANG_GE);
			return TRUE;

		case IDC_BTN_ITALIAN:
			opt_ui_lang = UI_LANG_IT;
			// QL2K_init_flag_buttons(hWnd);
			QL2K_Change_Language(hWnd, UI_LANG_IT);
			return TRUE;
		// Jimmy 093 - end Multi language support Hit Flag Button Management

		default:
			return FALSE;


            } /* switch (wPar) */

        case WM_SYSCOMMAND :
            if (wPar == SC_CLOSE) {
					EndDialog(hWnd, FALSE);
					return TRUE;
					}
            else
					return FALSE;

        default:
            return FALSE;

    } /* switch (wMsg)*/

}

int wincfg_main(HINSTANCE hInst)
{
DLGPROC	qlcfg_dialog;

	bShowFlag = FALSE;
	hInstance = hInst;
	iSitCancelButton = 0;
	qlcfg_dialog = (DLGPROC) MakeProcInstance((FARPROC) Dialog, hInst);
	DialogBox(hInst, (LPSTR) ID_CFG_DLG, NULL, qlcfg_dialog);
	FreeProcInstance((FARPROC) qlcfg_dialog);

	return iSitCancelButton; // 0
}

