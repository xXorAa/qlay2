#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "qlmem.h"
#include "exe68k.h"
#include "op68ktbl.h"
void op_3000(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_3008(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.a[srcreg];
{	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_3010(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_3018(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}}
void op_3020(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}}
void op_3028(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_3030(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}}
void op_3038(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_3039(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_303a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}}
void op_303b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}}
void op_303c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_3040(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	regs.a[dstreg] = (S32)(S16)(src);
}}}}
void op_3048(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.a[srcreg];
{	regs.a[dstreg] = (S32)(S16)(src);
}}}}
void op_3050(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[dstreg] = (S32)(S16)(src);
}}}}
void op_3058(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	regs.a[dstreg] = (S32)(S16)(src);
}}}}}
void op_3060(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[dstreg] = (S32)(S16)(src);
}}}}}
void op_3068(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	regs.a[dstreg] = (S32)(S16)(src);
}}}}
void op_3070(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	regs.a[dstreg] = (S32)(S16)(src);
}}}}}
void op_3078(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	regs.a[dstreg] = (S32)(S16)(src);
}}}}
void op_3079(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	regs.a[dstreg] = (S32)(S16)(src);
}}}}
void op_307a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	regs.a[dstreg] = (S32)(S16)(src);
}}}}}
void op_307b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	regs.a[dstreg] = (S32)(S16)(src);
}}}}}
void op_307c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	regs.a[dstreg] = (S32)(S16)(src);
}}}}
void op_3080(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_3088(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.a[srcreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_3090(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_3098(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_30a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_30a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_30b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_30b8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_30b9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_30ba(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_30bb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_30bc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_30c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 2;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_30c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.a[srcreg];
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 2;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_30d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 2;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_30d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 2;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}}
void op_30e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 2;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}}
void op_30e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 2;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_30f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 2;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}}
void op_30f8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 2;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_30f9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 2;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_30fa(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 2;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}}
void op_30fb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 2;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}}
void op_30fc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 2;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_3100(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_3108(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.a[srcreg];
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_3110(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_3118(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}}
void op_3120(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}}
void op_3128(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_3130(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}}
void op_3138(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_3139(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_313a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}}
void op_313b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}}
void op_313c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_3140(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_3148(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.a[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_3150(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_3158(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_3160(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_3168(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_3170(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_3178(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_3179(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_317a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_317b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_317c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_3180(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_3188(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.a[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_3190(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_3198(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_31a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_31a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_31b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_31b8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_31b9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_31ba(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_31bb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_31bc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_31c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_31c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.a[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_31d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_31d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_31e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_31e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_31f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_31f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_31f9(U32 opcode)
{
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_31fa(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_31fb(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_31fc(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_33c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_33c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.a[srcreg];
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_33d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_33d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_33e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_33e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_33f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_33f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_33f9(U32 opcode)
{
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_33fa(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_33fb(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_33fc(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
