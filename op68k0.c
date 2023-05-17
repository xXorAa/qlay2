#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "qlmem.h"
#include "exe68k.h"
#include "op68ktbl.h"
void op_0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	S8 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_10(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_18(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_20(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_28(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_30(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_38(U32 opcode)
{
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_39(U32 opcode)
{
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_3c(U32 opcode)
{
{	MakeSR();
{	S16 src = nextiword();
	src &= 0xFF;
	regs.sr |= src;
	MakeFromSR();
}}}
void op_40(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	S16 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_50(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_58(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{	regs.a[dstreg] += 2;
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_60(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_68(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_70(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S16 dst = get_word(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_78(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_79(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = nextilong();
	S16 dst = get_word(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_7c(U32 opcode)
{
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{	MakeSR();
{	S16 src = nextiword();
	regs.sr |= src;
	MakeFromSR();
}}}}
void op_80(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	S32 dst = regs.d[dstreg];
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_90(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_98(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{	regs.a[dstreg] += 4;
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_a0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_a8(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_b0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S32 dst = get_long(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_b8(U32 opcode)
{
{{	S32 src = nextilong();
{	A32 dsta = (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_b9(U32 opcode)
{
{{	S32 src = nextilong();
{	A32 dsta = nextilong();
	S32 dst = get_long(dsta);
	src |= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_100(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	S32 dst = regs.d[dstreg];
	src &= 31;
	ZFLG = !(dst & (1 << src));
}}}}
void op_108(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{	A32 memp = regs.a[srcreg] + (S32)(S16)nextiword();
{	U16 val = (get_byte(memp) << 8) + get_byte(memp + 2);
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}
void op_110(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}
void op_118(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}}
void op_120(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}}
void op_128(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}
void op_130(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}}
void op_138(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}
void op_139(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}
void op_13a(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (S32)(S8)2;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = m68k_getpc();
	dsta += (S32)(S16)nextiword();
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}}
void op_13b(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (S32)(S8)3;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = m68k_getpc();
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}}
void op_13c(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
{	S8 dst = (S8)nextiword(); // Jimmy 093 - Cast
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}
void op_140(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	S32 dst = regs.d[dstreg];
	src &= 31;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	regs.d[dstreg] = (dst);
}}}}
void op_148(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{	A32 memp = regs.a[srcreg] + (S32)(S16)nextiword();
{	U32 val = (get_byte(memp) << 24) + (get_byte(memp + 2) << 16)
              + (get_byte(memp + 4) << 8) + get_byte(memp + 6);
	regs.d[dstreg] = (val);
}}}
void op_150(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_158(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_160(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_168(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_170(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_178(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_179(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_17a(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (S32)(S8)2;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = m68k_getpc();
	dsta += (S32)(S16)nextiword();
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_17b(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (S32)(S8)3;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = m68k_getpc();
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_180(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	S32 dst = regs.d[dstreg];
	src &= 31;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	regs.d[dstreg] = (dst);
}}}}
void op_188(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
	A32 memp = regs.a[dstreg] + (S32)(S16)nextiword();
	// Jimmy - put_byte types cast
	put_byte((A32)memp, (U8)(src >> 8)); put_byte((A32)(memp + 2),(U8)src);
}}}
void op_190(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}
void op_198(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}}
void op_1a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}}
void op_1a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}
void op_1b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}}
void op_1b8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}
void op_1b9(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}
void op_1ba(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (S32)(S8)2;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = m68k_getpc();
	dsta += (S32)(S16)nextiword();
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}}
void op_1bb(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (S32)(S8)3;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = m68k_getpc();
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}}
void op_1c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	S32 dst = regs.d[dstreg];
	src &= 31;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	regs.d[dstreg] = (dst);
}}}}
void op_1c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
	A32 memp = regs.a[dstreg] + (S32)(S16)nextiword();
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)memp,(U8)( src >> 24 )); put_byte((A32)(memp + 2),(U8)( src >> 16));
	put_byte((A32)(memp + 4),(U8)( src >> 8 )); put_byte((A32)(memp + 6), (U8)src);
}}}
void op_1d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_1d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_1e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_1e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_1f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_1f8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_1f9(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_1fa(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (S32)(S8)2;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = m68k_getpc();
	dsta += (S32)(S16)nextiword();
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_1fb(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (S32)(S8)3;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = m68k_getpc();
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_200(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	S8 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_210(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_218(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_220(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_228(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_230(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_238(U32 opcode)
{
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_239(U32 opcode)
{
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_23c(U32 opcode)
{
{	MakeSR();
{	S16 src = nextiword();
	src |= 0xFF00;
	regs.sr &= src;
	MakeFromSR();
}}}
void op_240(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	S16 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_250(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_258(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{	regs.a[dstreg] += 2;
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_260(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_268(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_270(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S16 dst = get_word(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_278(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_279(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = nextilong();
	S16 dst = get_word(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_27c(U32 opcode)
{
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{	MakeSR();
{	S16 src = nextiword();
	regs.sr &= src;
	MakeFromSR();
}}}}
void op_280(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	S32 dst = regs.d[dstreg];
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_290(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_298(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{	regs.a[dstreg] += 4;
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_2a0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_2a8(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_2b0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S32 dst = get_long(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_2b8(U32 opcode)
{
{{	S32 src = nextilong();
{	A32 dsta = (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_2b9(U32 opcode)
{
{{	S32 src = nextilong();
{	A32 dsta = nextilong();
	S32 dst = get_long(dsta);
	src &= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_400(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	S8 dst = regs.d[dstreg];
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}}
void op_410(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}
void op_418(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}}
void op_420(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}}
void op_428(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}
void op_430(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}}
void op_438(U32 opcode)
{
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}
void op_439(U32 opcode)
{
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}
void op_440(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	S16 dst = regs.d[dstreg];
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}}
void op_450(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)dsta,(U16)newv);
}}}}}}}
void op_458(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{	regs.a[dstreg] += 2;
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)dsta,(U16)newv);
}}}}}}}}
void op_460(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)dsta,(U16)newv);
}}}}}}}}
void op_468(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)dsta,(U16)newv);
}}}}}}}
void op_470(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)dsta,(U16)newv);
}}}}}}}}
void op_478(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)dsta,(U16)newv);
}}}}}}}
void op_479(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = nextilong();
	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)dsta,(U16)newv);
}}}}}}}
void op_480(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	S32 dst = regs.d[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] = (newv);
}}}}}}}
void op_490(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	put_long(dsta,newv);
}}}}}}}
void op_498(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{	regs.a[dstreg] += 4;
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	put_long(dsta,newv);
}}}}}}}}
void op_4a0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	put_long(dsta,newv);
}}}}}}}}
void op_4a8(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	put_long(dsta,newv);
}}}}}}}
void op_4b0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	put_long(dsta,newv);
}}}}}}}}
void op_4b8(U32 opcode)
{
{{	S32 src = nextilong();
{	A32 dsta = (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	put_long(dsta,newv);
}}}}}}}
void op_4b9(U32 opcode)
{
{{	S32 src = nextilong();
{	A32 dsta = nextilong();
	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	put_long(dsta,newv);
}}}}}}}
void op_600(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	S8 dst = regs.d[dstreg];
{{U32 newv = ((S8)(dst)) + ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(~dst)) < ((U8)(src));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}}
void op_610(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) + ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(~dst)) < ((U8)(src));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}
void op_618(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
{{U32 newv = ((S8)(dst)) + ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(~dst)) < ((U8)(src));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}}
void op_620(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) + ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(~dst)) < ((U8)(src));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}}
void op_628(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) + ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(~dst)) < ((U8)(src));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}
void op_630(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) + ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(~dst)) < ((U8)(src));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}}
void op_638(U32 opcode)
{
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) + ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(~dst)) < ((U8)(src));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}
void op_639(U32 opcode)
{
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) + ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(~dst)) < ((U8)(src));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}
void op_640(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	S16 dst = regs.d[dstreg];
{{U32 newv = ((S16)(dst)) + ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(~dst)) < ((U16)(src));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}}
void op_650(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) + ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(~dst)) < ((U16)(src));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_word((A32)dsta,(U8)newv);
}}}}}}}
void op_658(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{	regs.a[dstreg] += 2;
{{U32 newv = ((S16)(dst)) + ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(~dst)) < ((U16)(src));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)dsta,(U16)newv);
}}}}}}}}
void op_660(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) + ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(~dst)) < ((U16)(src));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)dsta,(U16)newv);
}}}}}}}}
void op_668(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) + ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(~dst)) < ((U16)(src));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)dsta,(U16)newv);
}}}}}}}
void op_670(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) + ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(~dst)) < ((U16)(src));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)dsta,(U16)newv);
}}}}}}}}
void op_678(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) + ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(~dst)) < ((U16)(src));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)dsta,(U16)newv);
}}}}}}}
void op_679(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = nextilong();
	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) + ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(~dst)) < ((U16)(src));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)dsta,(U16)newv);
}}}}}}}
void op_680(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	S32 dst = regs.d[dstreg];
{{U32 newv = ((S32)(dst)) + ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(~dst)) < ((U32)(src));
	NFLG = flgn != 0;
	regs.d[dstreg] = (newv);
}}}}}}}
void op_690(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) + ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(~dst)) < ((U32)(src));
	NFLG = flgn != 0;
	put_long(dsta,newv);
}}}}}}}
void op_698(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{	regs.a[dstreg] += 4;
{{U32 newv = ((S32)(dst)) + ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(~dst)) < ((U32)(src));
	NFLG = flgn != 0;
	put_long(dsta,newv);
}}}}}}}}
void op_6a0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) + ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(~dst)) < ((U32)(src));
	NFLG = flgn != 0;
	put_long(dsta,newv);
}}}}}}}}
void op_6a8(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) + ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(~dst)) < ((U32)(src));
	NFLG = flgn != 0;
	put_long(dsta,newv);
}}}}}}}
void op_6b0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) + ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(~dst)) < ((U32)(src));
	NFLG = flgn != 0;
	put_long(dsta,newv);
}}}}}}}}
void op_6b8(U32 opcode)
{
{{	S32 src = nextilong();
{	A32 dsta = (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) + ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(~dst)) < ((U32)(src));
	NFLG = flgn != 0;
	put_long(dsta,newv);
}}}}}}}
void op_6b9(U32 opcode)
{
{{	S32 src = nextilong();
{	A32 dsta = nextilong();
	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) + ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs == flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(~dst)) < ((U32)(src));
	NFLG = flgn != 0;
	put_long(dsta,newv);
}}}}}}}
void op_800(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	S32 dst = regs.d[dstreg];
	src &= 31;
	ZFLG = !(dst & (1 << src));
}}}}
void op_810(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}
void op_818(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}}
void op_820(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}}
void op_828(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}
void op_830(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}}
void op_838(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}
void op_839(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}
void op_83a(U32 opcode)
{
	U32 dstreg = (S32)(S8)2;
{{	S16 src = nextiword();
{	A32 dsta = m68k_getpc();
	dsta += (S32)(S16)nextiword();
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}}
void op_83b(U32 opcode)
{
	U32 dstreg = (S32)(S8)3;
{{	S16 src = nextiword();
{	A32 dsta = m68k_getpc();
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}}
void op_83c(U32 opcode)
{
{{	S16 src = nextiword();
{	S8 dst = (S8)nextiword(); // Jimmy 093 - Cast
	src &= 7;
	ZFLG = !(dst & (1 << src));
}}}}
void op_840(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	S32 dst = regs.d[dstreg];
	src &= 31;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	regs.d[dstreg] = (dst);
}}}}
void op_850(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_858(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_860(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_868(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_870(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_878(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_879(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_87a(U32 opcode)
{
	U32 dstreg = (S32)(S8)2;
{{	S16 src = nextiword();
{	A32 dsta = m68k_getpc();
	dsta += (S32)(S16)nextiword();
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_87b(U32 opcode)
{
	U32 dstreg = (S32)(S8)3;
{{	S16 src = nextiword();
{	A32 dsta = m68k_getpc();
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst ^= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_880(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	S32 dst = regs.d[dstreg];
	src &= 31;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	regs.d[dstreg] = (dst);
}}}}
void op_890(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}
void op_898(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}}
void op_8a0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}}
void op_8a8(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}
void op_8b0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}}
void op_8b8(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}
void op_8b9(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}
void op_8ba(U32 opcode)
{
	U32 dstreg = (S32)(S8)2;
{{	S16 src = nextiword();
{	A32 dsta = m68k_getpc();
	dsta += (S32)(S16)nextiword();
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}}
void op_8bb(U32 opcode)
{
	U32 dstreg = (S32)(S8)3;
{{	S16 src = nextiword();
{	A32 dsta = m68k_getpc();
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst &= ~(1 << src);
	put_byte(dsta,dst);
}}}}}
void op_8c0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	S32 dst = regs.d[dstreg];
	src &= 31;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	regs.d[dstreg] = (dst);
}}}}
void op_8d0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_8d8(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_8e0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_8e8(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_8f0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_8f8(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_8f9(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}
void op_8fa(U32 opcode)
{
	U32 dstreg = (S32)(S8)2;
{{	S16 src = nextiword();
{	A32 dsta = m68k_getpc();
	dsta += (S32)(S16)nextiword();
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_8fb(U32 opcode)
{
	U32 dstreg = (S32)(S8)3;
{{	S16 src = nextiword();
{	A32 dsta = m68k_getpc();
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src &= 7;
	ZFLG = !(dst & (1 << src));
	dst |= (1 << src);
	put_byte(dsta,dst);
}}}}}
void op_a00(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	S8 dst = regs.d[dstreg];
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_a10(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_a18(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_a20(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_a28(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_a30(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_a38(U32 opcode)
{
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_a39(U32 opcode)
{
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_a3c(U32 opcode)
{
{	MakeSR();
{	S16 src = nextiword();
	src &= 0xFF;
	regs.sr ^= src;
	MakeFromSR();
}}}
void op_a40(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	S16 dst = regs.d[dstreg];
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_a50(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_a58(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{	regs.a[dstreg] += 2;
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_a60(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_a68(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_a70(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S16 dst = get_word(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_a78(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_a79(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = nextilong();
	S16 dst = get_word(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_a7c(U32 opcode)
{
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{	MakeSR();
{	S16 src = nextiword();
	regs.sr ^= src;
	MakeFromSR();
}}}}
void op_a80(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	S32 dst = regs.d[dstreg];
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_a90(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_a98(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{	regs.a[dstreg] += 4;
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_aa0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_aa8(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_ab0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S32 dst = get_long(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_ab8(U32 opcode)
{
{{	S32 src = nextilong();
{	A32 dsta = (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_ab9(U32 opcode)
{
{{	S32 src = nextilong();
{	A32 dsta = nextilong();
	S32 dst = get_long(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_c00(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	S8 dst = regs.d[dstreg];
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_c10(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_c18(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_c20(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_c28(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_c30(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_c38(U32 opcode)
{
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_c39(U32 opcode)
{
{{	S8 src = (S8)nextiword(); // Jimmy 093 - Cast
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_c40(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	S16 dst = regs.d[dstreg];
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_c50(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_c58(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{	regs.a[dstreg] += 2;
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_c60(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_c68(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_c70(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = nextiword();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_c78(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_c79(U32 opcode)
{
{{	S16 src = nextiword();
{	A32 dsta = nextilong();
	S16 dst = get_word(dsta);
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_c80(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	S32 dst = regs.d[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_c90(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_c98(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{	regs.a[dstreg] += 4;
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_ca0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_ca8(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_cb0(U32 opcode)
{
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = nextilong();
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_cb8(U32 opcode)
{
{{	S32 src = nextilong();
{	A32 dsta = (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_cb9(U32 opcode)
{
{{	S32 src = nextilong();
{	A32 dsta = nextilong();
	S32 dst = get_long(dsta);
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
