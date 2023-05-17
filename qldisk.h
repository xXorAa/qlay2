/*
	QLAY - Sinclair QL emulator
	Copyright Jan Venema 1998
	qldisk defines and functions
*/

extern void init_qldisk(void);
extern void exit_qldisk(void);
extern void wrnfa(A32,U8);
extern U8 rdnfa(A32);
extern int win_avail(void);

extern U8 rdserpar(A32);
extern void wrserpar(A32,U8);


// Led settings. - By Jimmy
#define Power_Led_X		10
#define Power_Led_Y		350
#define First_Led_X		480
#define First_Led_Y		350
#define LED_YELLOW		6
#define LED_RED			2
#define LED_BLACK		0
#define LED_GREEN		4
