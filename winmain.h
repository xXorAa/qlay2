/*
	QLAY - Sinclair QL emulator
	Copyright Jan Venema 1998
	Win95 menus and functions
*/

#include "qlayw.h"
#include <windows.h>

extern void			 write_box(char*);
/*
extern __inline void win32_plotp8(int,int,U8*);  // Jimmy - 093 - __inline for speed up
extern __inline void repaint_screen(void); // Jimmy - 093 - __inline for speed up
extern __inline void q_check_message(void); // Jimmy - 095 - __inline for speed up
*/

extern void win32_plotp8(int,int,U8*);  // Jimmy - 093 - __inline for speed up
extern void repaint_screen(void); // Jimmy - 093 - __inline for speed up
extern void q_check_message(void); // Jimmy - 095 - __inline for speed up

extern void open_serial(int,int,int);
extern void close_serial(int);
extern void send_serial_char(int);
extern int rcv_serial_string(char*);

extern int mouse_xpos;
extern int mouse_ypos;
extern int mouse_button;
extern int emul_running;

// Jimmy 093 - Used only for Draw_LED function
extern HWND SuperHwnd;
