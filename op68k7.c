#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "qlmem.h"
#include "exe68k.h"
#include "op68ktbl.h"
void op_7000(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	U32 src = srcreg;
{	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
