#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "qlmem.h"
#include "exe68k.h"
#include "op68ktbl.h"
void op_8000(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = regs.d[srcreg];
{	S8 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_8010(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_8018(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	S8 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}}
void op_8020(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}}
void op_8028(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_8030(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}}
void op_8038(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_8039(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_803a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}}
void op_803b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}}
void op_803c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	S8 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_8040(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	S16 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_8050(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_8058(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	S16 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}}
void op_8060(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}}
void op_8068(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_8070(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}}
void op_8078(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_8079(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_807a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}}
void op_807b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}}
void op_807c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	S16 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_8080(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
{	S32 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_8090(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_8098(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	S32 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}}
void op_80a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}}
void op_80a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_80b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}}
void op_80b8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_80b9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_80ba(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}}
void op_80bb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}}
void op_80bc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = nextilong();
{	S32 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_80c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	U32 newv = (U32)dst / (U16)src;
	U32 rem = (U32)dst % (U16)src;
	if (newv > 0xffff) { VFLG = NFLG = 1; } else
	{
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}
void op_80d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	U32 newv = (U32)dst / (U16)src;
	U32 rem = (U32)dst % (U16)src;
	if (newv > 0xffff) { VFLG = NFLG = 1; } else
	{
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}
void op_80d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	U32 newv = (U32)dst / (U16)src;
	U32 rem = (U32)dst % (U16)src;
	if (newv > 0xffff) { VFLG = NFLG = 1; } else
	{
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}}
void op_80e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	U32 newv = (U32)dst / (U16)src;
	U32 rem = (U32)dst % (U16)src;
	if (newv > 0xffff) { VFLG = NFLG = 1; } else
	{
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}}
void op_80e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	U32 newv = (U32)dst / (U16)src;
	U32 rem = (U32)dst % (U16)src;
	if (newv > 0xffff) { VFLG = NFLG = 1; } else
	{
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}
void op_80f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	U32 newv = (U32)dst / (U16)src;
	U32 rem = (U32)dst % (U16)src;
	if (newv > 0xffff) { VFLG = NFLG = 1; } else
	{
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}}
void op_80f8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	U32 newv = (U32)dst / (U16)src;
	U32 rem = (U32)dst % (U16)src;
	if (newv > 0xffff) { VFLG = NFLG = 1; } else
	{
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}
void op_80f9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	U32 newv = (U32)dst / (U16)src;
	U32 rem = (U32)dst % (U16)src;
	if (newv > 0xffff) { VFLG = NFLG = 1; } else
	{
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}
void op_80fa(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	U32 newv = (U32)dst / (U16)src;
	U32 rem = (U32)dst % (U16)src;
	if (newv > 0xffff) { VFLG = NFLG = 1; } else
	{
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}}
void op_80fb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	U32 newv = (U32)dst / (U16)src;
	U32 rem = (U32)dst % (U16)src;
	if (newv > 0xffff) { VFLG = NFLG = 1; } else
	{
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}}
void op_80fc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	U32 newv = (U32)dst / (U16)src;
	U32 rem = (U32)dst % (U16)src;
	if (newv > 0xffff) { VFLG = NFLG = 1; } else
	{
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}
void op_8100(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = regs.d[srcreg];
{	S8 dst = regs.d[dstreg];
{	U16 newv_lo = (dst & 0xF) - (src & 0xF) - regs.x;
	U16 newv_hi = (dst & 0xF0) - (src & 0xF0);
	U16 newv;
	if (newv_lo > 9) { newv_lo-=6; newv_hi-=0x10; }
	newv = newv_hi + (newv_lo & 0xF);	CFLG = regs.x = (newv_hi & 0x1F0) > 0x90;
	if (CFLG) newv -= 0x60;
	if (((S8)(newv)) != 0) ZFLG = 0;
	NFLG = ((S8)(newv)) < 0;
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}
void op_8108(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	U16 newv_lo = (dst & 0xF) - (src & 0xF) - regs.x;
	U16 newv_hi = (dst & 0xF0) - (src & 0xF0);
	U16 newv;
	if (newv_lo > 9) { newv_lo-=6; newv_hi-=0x10; }
	newv = newv_hi + (newv_lo & 0xF);	CFLG = regs.x = (newv_hi & 0x1F0) > 0x90;
	if (CFLG) newv -= 0x60;
	if (((S8)(newv)) != 0) ZFLG = 0;
	NFLG = ((S8)(newv)) < 0;
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}}
void op_8110(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_8118(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_8120(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_8128(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_8130(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_8138(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_8139(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_8150(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_8158(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{	regs.a[dstreg] += 2;
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_8160(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_8168(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_8170(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S16 dst = get_word(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_8178(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S16 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_8179(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S16 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	S16 dst = get_word(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_8190(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_8198(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{	regs.a[dstreg] += 4;
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_81a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_81a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_81b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S32 dst = get_long(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_81b8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S32 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_81b9(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S32 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	S32 dst = get_long(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_81c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	S32 newv = (S32)dst / (S16)src;
	U16 rem = (S32)dst % (S16)src;
	if ((newv & 0xffff0000) && (newv & 0xffff0000) != 0xffff0000) { VFLG = NFLG = 1; } else
	{
	if (((S16)rem < 0) != ((S32)dst < 0)) rem = -rem;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}
void op_81d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	S32 newv = (S32)dst / (S16)src;
	U16 rem = (S32)dst % (S16)src;
	if ((newv & 0xffff0000) && (newv & 0xffff0000) != 0xffff0000) { VFLG = NFLG = 1; } else
	{
	if (((S16)rem < 0) != ((S32)dst < 0)) rem = -rem;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}
void op_81d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	S32 newv = (S32)dst / (S16)src;
	U16 rem = (S32)dst % (S16)src;
	if ((newv & 0xffff0000) && (newv & 0xffff0000) != 0xffff0000) { VFLG = NFLG = 1; } else
	{
	if (((S16)rem < 0) != ((S32)dst < 0)) rem = -rem;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}}
void op_81e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	S32 newv = (S32)dst / (S16)src;
	U16 rem = (S32)dst % (S16)src;
	if ((newv & 0xffff0000) && (newv & 0xffff0000) != 0xffff0000) { VFLG = NFLG = 1; } else
	{
	if (((S16)rem < 0) != ((S32)dst < 0)) rem = -rem;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}}
void op_81e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	S32 newv = (S32)dst / (S16)src;
	U16 rem = (S32)dst % (S16)src;
	if ((newv & 0xffff0000) && (newv & 0xffff0000) != 0xffff0000) { VFLG = NFLG = 1; } else
	{
	if (((S16)rem < 0) != ((S32)dst < 0)) rem = -rem;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}
void op_81f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	S32 newv = (S32)dst / (S16)src;
	U16 rem = (S32)dst % (S16)src;
	if ((newv & 0xffff0000) && (newv & 0xffff0000) != 0xffff0000) { VFLG = NFLG = 1; } else
	{
	if (((S16)rem < 0) != ((S32)dst < 0)) rem = -rem;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}}
void op_81f8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	S32 newv = (S32)dst / (S16)src;
	U16 rem = (S32)dst % (S16)src;
	if ((newv & 0xffff0000) && (newv & 0xffff0000) != 0xffff0000) { VFLG = NFLG = 1; } else
	{
	if (((S16)rem < 0) != ((S32)dst < 0)) rem = -rem;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}
void op_81f9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	S32 newv = (S32)dst / (S16)src;
	U16 rem = (S32)dst % (S16)src;
	if ((newv & 0xffff0000) && (newv & 0xffff0000) != 0xffff0000) { VFLG = NFLG = 1; } else
	{
	if (((S16)rem < 0) != ((S32)dst < 0)) rem = -rem;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}
void op_81fa(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	S32 newv = (S32)dst / (S16)src;
	U16 rem = (S32)dst % (S16)src;
	if ((newv & 0xffff0000) && (newv & 0xffff0000) != 0xffff0000) { VFLG = NFLG = 1; } else
	{
	if (((S16)rem < 0) != ((S32)dst < 0)) rem = -rem;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}}
void op_81fb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	S32 newv = (S32)dst / (S16)src;
	U16 rem = (S32)dst % (S16)src;
	if ((newv & 0xffff0000) && (newv & 0xffff0000) != 0xffff0000) { VFLG = NFLG = 1; } else
	{
	if (((S16)rem < 0) != ((S32)dst < 0)) rem = -rem;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}}
void op_81fc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	S32 dst = regs.d[dstreg];
	if(src == 0) Exception(5,0); else {
	S32 newv = (S32)dst / (S16)src;
	U16 rem = (S32)dst % (S16)src;
	if ((newv & 0xffff0000) && (newv & 0xffff0000) != 0xffff0000) { VFLG = NFLG = 1; } else
	{
	if (((S16)rem < 0) != ((S32)dst < 0)) rem = -rem;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(newv)) == 0;
	NFLG = ((S16)(newv)) < 0;
	newv = (newv & 0xffff) | ((U32)rem << 16);
	regs.d[dstreg] = (newv);
	}
	}
}}}}
