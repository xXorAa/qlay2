#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "qlmem.h"
#include "exe68k.h"
#include "op68ktbl.h"
void op_1000(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = regs.d[srcreg];
{	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_1010(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_1018(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}}
void op_1020(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}}
void op_1028(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_1030(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}}
void op_1038(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_1039(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_103a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S8 src = get_byte(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}}
void op_103b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}}
void op_103c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_1080(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_1090(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_1098(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_10a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_10a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_10b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_10b8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_10b9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_10ba(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_10bb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_10bc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_10c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += areg_byteinc[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_10d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += areg_byteinc[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_10d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += areg_byteinc[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}}
void op_10e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += areg_byteinc[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}}
void op_10e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += areg_byteinc[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_10f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += areg_byteinc[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}}
void op_10f8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += areg_byteinc[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_10f9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += areg_byteinc[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_10fa(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += areg_byteinc[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}}
void op_10fb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += areg_byteinc[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}}
void op_10fc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += areg_byteinc[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_1100(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = regs.d[srcreg];
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_1110(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_1118(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}}
void op_1120(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}}
void op_1128(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_1130(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}}
void op_1138(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_1139(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_113a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S8 src = get_byte(srca);
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}}
void op_113b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}}
void op_113c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_1140(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_1150(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_1158(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_1160(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_1168(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_1170(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_1178(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_1179(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_117a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_117b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_117c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_1180(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_1190(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_1198(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_11a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_11a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_11b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_11b8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_11b9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_11ba(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_11bb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_11bc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_11c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_11d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_11d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_11e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_11e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_11f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_11f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_11f9(U32 opcode)
{
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_11fa(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S8 src = get_byte(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_11fb(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_11fc(U32 opcode)
{
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_13c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_13d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_13d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_13e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_13e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_13f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_13f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_13f9(U32 opcode)
{
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_13fa(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S8 src = get_byte(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_13fb(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_13fc(U32 opcode)
{
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
