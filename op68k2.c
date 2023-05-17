#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "qlmem.h"
#include "exe68k.h"
#include "op68ktbl.h"
void op_2000(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
{	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_2008(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.a[srcreg];
{	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_2010(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_2018(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}}
void op_2020(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}}
void op_2028(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_2030(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}}
void op_2038(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_2039(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_203a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}}
void op_203b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}}
void op_203c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = nextilong();
{	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_2040(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
{	regs.a[dstreg] = (src);
}}}}
void op_2048(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.a[srcreg];
{	regs.a[dstreg] = (src);
}}}}
void op_2050(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[dstreg] = (src);
}}}}
void op_2058(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	regs.a[dstreg] = (src);
}}}}}
void op_2060(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[dstreg] = (src);
}}}}}
void op_2068(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	regs.a[dstreg] = (src);
}}}}
void op_2070(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	regs.a[dstreg] = (src);
}}}}}
void op_2078(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	regs.a[dstreg] = (src);
}}}}
void op_2079(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	regs.a[dstreg] = (src);
}}}}
void op_207a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
{	regs.a[dstreg] = (src);
}}}}}
void op_207b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	regs.a[dstreg] = (src);
}}}}}
void op_207c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = nextilong();
{	regs.a[dstreg] = (src);
}}}}
void op_2080(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_2088(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.a[srcreg];
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_2090(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_2098(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_20a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_20a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_20b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_20b8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_20b9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_20ba(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_20bb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_20bc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_20c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 4;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_20c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.a[srcreg];
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 4;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_20d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 4;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_20d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 4;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}}
void op_20e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 4;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}}
void op_20e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 4;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_20f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 4;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}}
void op_20f8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 4;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_20f9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 4;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_20fa(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 4;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}}
void op_20fb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 4;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}}
void op_20fc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
{	regs.a[dstreg] += 4;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_2100(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_2108(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.a[srcreg];
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_2110(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_2118(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}}
void op_2120(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}}
void op_2128(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_2130(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}}
void op_2138(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_2139(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_213a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}}
void op_213b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}}
void op_213c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = nextilong();
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_2140(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_2148(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.a[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_2150(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_2158(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_2160(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_2168(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_2170(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_2178(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_2179(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_217a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_217b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_217c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_2180(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_2188(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.a[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_2190(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_2198(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_21a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_21a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_21b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_21b8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_21b9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_21ba(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_21bb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_21bc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_21c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S32 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_21c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S32 src = regs.a[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_21d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_21d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_21e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_21e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_21f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_21f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_21f9(U32 opcode)
{
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_21fa(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_21fb(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_21fc(U32 opcode)
{
{{	S32 src = nextilong();
{	A32 dsta = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_23c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S32 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_23c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S32 src = regs.a[srcreg];
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_23d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_23d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_23e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_23e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_23f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_23f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_23f9(U32 opcode)
{
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_23fa(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_23fb(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_23fc(U32 opcode)
{
{{	S32 src = nextilong();
{	A32 dsta = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
