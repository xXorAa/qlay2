#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "qlmem.h"
#include "exe68k.h"
#include "op68ktbl.h"
void op_c000(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = regs.d[srcreg];
{	S8 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_c010(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_c018(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	S8 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}}
void op_c020(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}}
void op_c028(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_c030(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}}
void op_c038(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_c039(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_c03a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}}
void op_c03b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}}
void op_c03c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	S8 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_c040(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	S16 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_c050(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_c058(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	S16 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}}
void op_c060(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}}
void op_c068(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_c070(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}}
void op_c078(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_c079(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_c07a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}}
void op_c07b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}}
void op_c07c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	S16 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_c080(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
{	S32 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_c090(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_c098(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	S32 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}}
void op_c0a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}}
void op_c0a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_c0b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}}
void op_c0b8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_c0b9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_c0ba(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}}
void op_c0bb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}}
void op_c0bc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = nextilong();
{	S32 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_c0c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	S16 dst = regs.d[dstreg];
{	U32 newv = (U32)(U16)dst * (U32)(U16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}
void op_c0d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (U32)(U16)dst * (U32)(U16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}
void op_c0d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	S16 dst = regs.d[dstreg];
{	U32 newv = (U32)(U16)dst * (U32)(U16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}}
void op_c0e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (U32)(U16)dst * (U32)(U16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}}
void op_c0e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (U32)(U16)dst * (U32)(U16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}
void op_c0f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (U32)(U16)dst * (U32)(U16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}}
void op_c0f8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (U32)(U16)dst * (U32)(U16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}
void op_c0f9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (U32)(U16)dst * (U32)(U16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}
void op_c0fa(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (U32)(U16)dst * (U32)(U16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}}
void op_c0fb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (U32)(U16)dst * (U32)(U16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}}
void op_c0fc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	S16 dst = regs.d[dstreg];
{	U32 newv = (U32)(U16)dst * (U32)(U16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}
void op_c100(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = regs.d[srcreg];
{	S8 dst = regs.d[dstreg];
{	U16 newv_lo = (src & 0xF) + (dst & 0xF) + regs.x;
	U16 newv_hi = (src & 0xF0) + (dst & 0xF0);
	U16 newv;
	if (newv_lo > 9) { newv_lo +=6; }
	newv = newv_hi + newv_lo;	CFLG = regs.x = (newv & 0x1F0) > 0x90;
	if (CFLG) newv += 0x60;
	if (((S8)(newv)) != 0) ZFLG = 0;
	NFLG = ((S8)(newv)) < 0;
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}
void op_c108(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	U16 newv_lo = (src & 0xF) + (dst & 0xF) + regs.x;
	U16 newv_hi = (src & 0xF0) + (dst & 0xF0);
	U16 newv;
	if (newv_lo > 9) { newv_lo +=6; }
	newv = newv_hi + newv_lo;	CFLG = regs.x = (newv & 0x1F0) > 0x90;
	if (CFLG) newv += 0x60;
	if (((S8)(newv)) != 0) ZFLG = 0;
	NFLG = ((S8)(newv)) < 0;
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}}
void op_c110(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_c118(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_c120(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_c128(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_c130(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_c138(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_c139(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_c140(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	S32 dst = regs.d[dstreg];
	regs.d[srcreg] = (dst);
	regs.d[dstreg] = (src);
}}}}
void op_c148(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.a[srcreg];
{	S32 dst = regs.a[dstreg];
	regs.a[srcreg] = (dst);
	regs.a[dstreg] = (src);
}}}}
void op_c150(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_c158(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{	regs.a[dstreg] += 2;
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_c160(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_c168(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_c170(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S16 dst = get_word(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_c178(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S16 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_c179(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S16 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	S16 dst = get_word(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_c188(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	S32 dst = regs.a[dstreg];
	regs.d[srcreg] = (dst);
	regs.a[dstreg] = (src);
}}}}
void op_c190(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_c198(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{	regs.a[dstreg] += 4;
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_c1a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_c1a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_c1b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S32 dst = get_long(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_c1b8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S32 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_c1b9(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S32 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	S32 dst = get_long(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_c1c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	S16 dst = regs.d[dstreg];
{	U32 newv = (S32)(S16)dst * (S32)(S16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}
void op_c1d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (S32)(S16)dst * (S32)(S16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}
void op_c1d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	S16 dst = regs.d[dstreg];
{	U32 newv = (S32)(S16)dst * (S32)(S16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}}
void op_c1e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (S32)(S16)dst * (S32)(S16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}}
void op_c1e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (S32)(S16)dst * (S32)(S16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}
void op_c1f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (S32)(S16)dst * (S32)(S16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}}
void op_c1f8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (S32)(S16)dst * (S32)(S16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}
void op_c1f9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (S32)(S16)dst * (S32)(S16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}
void op_c1fa(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (S32)(S16)dst * (S32)(S16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}}
void op_c1fb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{	U32 newv = (S32)(S16)dst * (S32)(S16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}}
void op_c1fc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	S16 dst = regs.d[dstreg];
{	U32 newv = (S32)(S16)dst * (S32)(S16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(newv)) == 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}
