#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "qlmem.h"
#include "exe68k.h"
#include "op68ktbl.h"
void op_4000(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S8 src = regs.d[srcreg];
{	src += regs.x;
{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (dst) & 0xff;
}}}}}}
void op_4010(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	src += regs.x;
{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}}
void op_4018(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	src += regs.x;
{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}}}
void op_4020(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	src += regs.x;
{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}}}
void op_4028(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	src += regs.x;
{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}}
void op_4030(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	src += regs.x;
{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}}}
void op_4038(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	src += regs.x;
{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}}
void op_4039(U32 opcode)
{
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
{	src += regs.x;
{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}}
void op_4040(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	src += regs.x;
{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (dst) & 0xffff;
}}}}}}
void op_4050(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	src += regs.x;
{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}}
void op_4058(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	src += regs.x;
{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}}}
void op_4060(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	src += regs.x;
{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}}}
void op_4068(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	src += regs.x;
{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}}
void op_4070(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	src += regs.x;
{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}}}
void op_4078(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	src += regs.x;
{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}}
void op_4079(U32 opcode)
{
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	src += regs.x;
{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}}
void op_4080(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S32 src = regs.d[srcreg];
{	src += regs.x;
{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	regs.d[srcreg] = (dst);
}}}}}}
void op_4090(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	src += regs.x;
{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	put_long(srca,dst);
}}}}}}
void op_4098(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	src += regs.x;
{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	put_long(srca,dst);
}}}}}}}
void op_40a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	src += regs.x;
{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	put_long(srca,dst);
}}}}}}}
void op_40a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	src += regs.x;
{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	put_long(srca,dst);
}}}}}}
void op_40b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	src += regs.x;
{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	put_long(srca,dst);
}}}}}}}
void op_40b8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	src += regs.x;
{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	put_long(srca,dst);
}}}}}}
void op_40b9(U32 opcode)
{
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	src += regs.x;
{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	put_long(srca,dst);
}}}}}}
void op_40c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	MakeSR();
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (regs.sr) & 0xffff;
}}}
void op_40d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	MakeSR();
	put_word(srca,regs.sr);
}}}
void op_40d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += 2;
	MakeSR();
	put_word(srca,regs.sr);
}}}}
void op_40e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	MakeSR();
	put_word(srca,regs.sr);
}}}}
void op_40e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	MakeSR();
	put_word(srca,regs.sr);
}}}
void op_40f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
	MakeSR();
	put_word(srca,regs.sr);
}}}
void op_40f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	MakeSR();
	put_word(srca,regs.sr);
}}}
void op_40f9(U32 opcode)
{
{{	A32 srca = nextilong();
	MakeSR();
	put_word(srca,regs.sr);
}}}
void op_4180(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	S16 dst = regs.d[dstreg];
	if ((S16)dst < 0) { NFLG=1; Exception(6,0); }
	else if ((S16)dst > (S16)src) { NFLG=0; Exception(6,0); }
}}}}
void op_4188(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.a[srcreg];
{	S16 dst = regs.d[dstreg];
	if ((S16)dst < 0) { NFLG=1; Exception(6,0); }
	else if ((S16)dst > (S16)src) { NFLG=0; Exception(6,0); }
}}}}
void op_4190(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	if ((S16)dst < 0) { NFLG=1; Exception(6,0); }
	else if ((S16)dst > (S16)src) { NFLG=0; Exception(6,0); }
}}}}
void op_4198(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	S16 dst = regs.d[dstreg];
	if ((S16)dst < 0) { NFLG=1; Exception(6,0); }
	else if ((S16)dst > (S16)src) { NFLG=0; Exception(6,0); }
}}}}}
void op_41a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	if ((S16)dst < 0) { NFLG=1; Exception(6,0); }
	else if ((S16)dst > (S16)src) { NFLG=0; Exception(6,0); }
}}}}}
void op_41a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	if ((S16)dst < 0) { NFLG=1; Exception(6,0); }
	else if ((S16)dst > (S16)src) { NFLG=0; Exception(6,0); }
}}}}
void op_41b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	if ((S16)dst < 0) { NFLG=1; Exception(6,0); }
	else if ((S16)dst > (S16)src) { NFLG=0; Exception(6,0); }
}}}}}
void op_41b8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	if ((S16)dst < 0) { NFLG=1; Exception(6,0); }
	else if ((S16)dst > (S16)src) { NFLG=0; Exception(6,0); }
}}}}
void op_41b9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	if ((S16)dst < 0) { NFLG=1; Exception(6,0); }
	else if ((S16)dst > (S16)src) { NFLG=0; Exception(6,0); }
}}}}
void op_41ba(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	if ((S16)dst < 0) { NFLG=1; Exception(6,0); }
	else if ((S16)dst > (S16)src) { NFLG=0; Exception(6,0); }
}}}}}
void op_41bb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
	if ((S16)dst < 0) { NFLG=1; Exception(6,0); }
	else if ((S16)dst > (S16)src) { NFLG=0; Exception(6,0); }
}}}}}
void op_41bc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	S16 dst = regs.d[dstreg];
	if ((S16)dst < 0) { NFLG=1; Exception(6,0); }
	else if ((S16)dst > (S16)src) { NFLG=0; Exception(6,0); }
}}}}
void op_41d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
{	regs.a[dstreg] = (srca);
}}}}
void op_41d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += 4;
{	regs.a[dstreg] = (srca);
}}}}}
void op_41e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
{	regs.a[dstreg] = (srca);
}}}}}
void op_41e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	regs.a[dstreg] = (srca);
}}}}
void op_41f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	regs.a[dstreg] = (srca);
}}}}
void op_41f8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
{	regs.a[dstreg] = (srca);
}}}}
void op_41f9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
{	regs.a[dstreg] = (srca);
}}}}
void op_41fa(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	regs.a[dstreg] = (srca);
}}}}
void op_41fb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	regs.a[dstreg] = (srca);
}}}}
void op_4200(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	VFLG = CFLG = 0;
	ZFLG = ((S8)(0)) == 0;
	NFLG = ((S8)(0)) < 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (0) & 0xff;
}}}
void op_4210(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(0)) == 0;
	NFLG = ((S8)(0)) < 0;
	put_byte(srca,0);
}}}
void op_4218(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(0)) == 0;
	NFLG = ((S8)(0)) < 0;
	put_byte(srca,0);
}}}}
void op_4220(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(0)) == 0;
	NFLG = ((S8)(0)) < 0;
	put_byte(srca,0);
}}}}
void op_4228(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(0)) == 0;
	NFLG = ((S8)(0)) < 0;
	put_byte(srca,0);
}}}
void op_4230(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S8)(0)) == 0;
	NFLG = ((S8)(0)) < 0;
	put_byte(srca,0);
}}}
void op_4238(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(0)) == 0;
	NFLG = ((S8)(0)) < 0;
	put_byte(srca,0);
}}}
void op_4239(U32 opcode)
{
{{	A32 srca = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S8)(0)) == 0;
	NFLG = ((S8)(0)) < 0;
	put_byte(srca,0);
}}}
void op_4240(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	VFLG = CFLG = 0;
	ZFLG = ((S16)(0)) == 0;
	NFLG = ((S16)(0)) < 0;
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (0) & 0xffff;
}}}
void op_4250(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(0)) == 0;
	NFLG = ((S16)(0)) < 0;
	put_word(srca,0);
}}}
void op_4258(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += 2;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(0)) == 0;
	NFLG = ((S16)(0)) < 0;
	put_word(srca,0);
}}}}
void op_4260(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(0)) == 0;
	NFLG = ((S16)(0)) < 0;
	put_word(srca,0);
}}}}
void op_4268(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(0)) == 0;
	NFLG = ((S16)(0)) < 0;
	put_word(srca,0);
}}}
void op_4270(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S16)(0)) == 0;
	NFLG = ((S16)(0)) < 0;
	put_word(srca,0);
}}}
void op_4278(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(0)) == 0;
	NFLG = ((S16)(0)) < 0;
	put_word(srca,0);
}}}
void op_4279(U32 opcode)
{
{{	A32 srca = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S16)(0)) == 0;
	NFLG = ((S16)(0)) < 0;
	put_word(srca,0);
}}}
void op_4280(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	VFLG = CFLG = 0;
	ZFLG = ((S32)(0)) == 0;
	NFLG = ((S32)(0)) < 0;
	regs.d[srcreg] = (0);
}}}
void op_4290(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(0)) == 0;
	NFLG = ((S32)(0)) < 0;
	put_long(srca,0);
}}}
void op_4298(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += 4;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(0)) == 0;
	NFLG = ((S32)(0)) < 0;
	put_long(srca,0);
}}}}
void op_42a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(0)) == 0;
	NFLG = ((S32)(0)) < 0;
	put_long(srca,0);
}}}}
void op_42a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(0)) == 0;
	NFLG = ((S32)(0)) < 0;
	put_long(srca,0);
}}}
void op_42b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
	VFLG = CFLG = 0;
	ZFLG = ((S32)(0)) == 0;
	NFLG = ((S32)(0)) < 0;
	put_long(srca,0);
}}}
void op_42b8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(0)) == 0;
	NFLG = ((S32)(0)) < 0;
	put_long(srca,0);
}}}
void op_42b9(U32 opcode)
{
{{	A32 srca = nextilong();
	VFLG = CFLG = 0;
	ZFLG = ((S32)(0)) == 0;
	NFLG = ((S32)(0)) < 0;
	put_long(srca,0);
}}}
void op_4400(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S8 src = regs.d[srcreg];
{{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (dst) & 0xff;
}}}}}}
void op_4410(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}}
void op_4418(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}}}
void op_4420(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}}}
void op_4428(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}}
void op_4430(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}}}
void op_4438(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}}
void op_4439(U32 opcode)
{
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
{{U32 dst = ((S8)(0)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(0)) < 0;
	int flgn = ((S8)(dst)) < 0;
	ZFLG = ((S8)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U8)(src)) > ((U8)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}}
void op_4440(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (dst) & 0xffff;
}}}}}}
void op_4450(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}}
void op_4458(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}}}
void op_4460(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}}}
void op_4468(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}}
void op_4470(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}}}
void op_4478(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}}
void op_4479(U32 opcode)
{
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{{U32 dst = ((S16)(0)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(0)) < 0;
	int flgn = ((S16)(dst)) < 0;
	ZFLG = ((S16)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U16)(src)) > ((U16)(0));
	NFLG = flgn != 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}}
void op_4480(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S32 src = regs.d[srcreg];
{{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	regs.d[srcreg] = (dst);
}}}}}}
void op_4490(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	put_long(srca,dst);
}}}}}}
void op_4498(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	put_long(srca,dst);
}}}}}}}
void op_44a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	put_long(srca,dst);
}}}}}}}
void op_44a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	put_long(srca,dst);
}}}}}}
void op_44b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	put_long(srca,dst);
}}}}}}}
void op_44b8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	put_long(srca,dst);
}}}}}}
void op_44b9(U32 opcode)
{
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{{U32 dst = ((S32)(0)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(0)) < 0;
	int flgn = ((S32)(dst)) < 0;
	ZFLG = ((S32)(dst)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = regs.x = ((U32)(src)) > ((U32)(0));
	NFLG = flgn != 0;
	put_long(srca,dst);
}}}}}}
void op_44c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}
void op_44d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}
void op_44d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}}
void op_44e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}}
void op_44e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}
void op_44f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}}
void op_44f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}
void op_44f9(U32 opcode)
{
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}
void op_44fa(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}}
void op_44fb(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}}
void op_44fc(U32 opcode)
{
{{	S16 src = nextiword();
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}
void op_4600(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S8 src = regs.d[srcreg];
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(dst)) == 0;
	NFLG = ((S8)(dst)) < 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (dst) & 0xff;
}}}}
void op_4610(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(dst)) == 0;
	NFLG = ((S8)(dst)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}
void op_4618(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(dst)) == 0;
	NFLG = ((S8)(dst)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}
void op_4620(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(dst)) == 0;
	NFLG = ((S8)(dst)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}
void op_4628(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(dst)) == 0;
	NFLG = ((S8)(dst)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}
void op_4630(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(dst)) == 0;
	NFLG = ((S8)(dst)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}
void op_4638(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(dst)) == 0;
	NFLG = ((S8)(dst)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}
void op_4639(U32 opcode)
{
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(dst)) == 0;
	NFLG = ((S8)(dst)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}
void op_4640(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(dst)) == 0;
	NFLG = ((S16)(dst)) < 0;
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (dst) & 0xffff;
}}}}
void op_4650(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(dst)) == 0;
	NFLG = ((S16)(dst)) < 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}
void op_4658(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(dst)) == 0;
	NFLG = ((S16)(dst)) < 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}
void op_4660(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(dst)) == 0;
	NFLG = ((S16)(dst)) < 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}
void op_4668(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(dst)) == 0;
	NFLG = ((S16)(dst)) < 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}
void op_4670(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(dst)) == 0;
	NFLG = ((S16)(dst)) < 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}}
void op_4678(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(dst)) == 0;
	NFLG = ((S16)(dst)) < 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}
void op_4679(U32 opcode)
{
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(dst)) == 0;
	NFLG = ((S16)(dst)) < 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)srca,(U16)dst);
}}}}
void op_4680(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S32 src = regs.d[srcreg];
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(dst)) == 0;
	NFLG = ((S32)(dst)) < 0;
	regs.d[srcreg] = (dst);
}}}}
void op_4690(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(dst)) == 0;
	NFLG = ((S32)(dst)) < 0;
	put_long(srca,dst);
}}}}
void op_4698(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(dst)) == 0;
	NFLG = ((S32)(dst)) < 0;
	put_long(srca,dst);
}}}}}
void op_46a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(dst)) == 0;
	NFLG = ((S32)(dst)) < 0;
	put_long(srca,dst);
}}}}}
void op_46a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(dst)) == 0;
	NFLG = ((S32)(dst)) < 0;
	put_long(srca,dst);
}}}}
void op_46b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(dst)) == 0;
	NFLG = ((S32)(dst)) < 0;
	put_long(srca,dst);
}}}}}
void op_46b8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(dst)) == 0;
	NFLG = ((S32)(dst)) < 0;
	put_long(srca,dst);
}}}}
void op_46b9(U32 opcode)
{
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	U32 dst = ~src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(dst)) == 0;
	NFLG = ((S32)(dst)) < 0;
	put_long(srca,dst);
}}}}
void op_46c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{{	S16 src = regs.d[srcreg];
	regs.sr = src;
	MakeFromSR();
}}}}
void op_46d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
	regs.sr = src;
	MakeFromSR();
}}}}
void op_46d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
	regs.sr = src;
	MakeFromSR();
}}}}}
void op_46e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
	regs.sr = src;
	MakeFromSR();
}}}}}
void op_46e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
	regs.sr = src;
	MakeFromSR();
}}}}
void op_46f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
	regs.sr = src;
	MakeFromSR();
}}}}}
void op_46f8(U32 opcode)
{
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
	regs.sr = src;
	MakeFromSR();
}}}}
void op_46f9(U32 opcode)
{
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
	regs.sr = src;
	MakeFromSR();
}}}}
void op_46fa(U32 opcode)
{
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
	regs.sr = src;
	MakeFromSR();
}}}}}
void op_46fb(U32 opcode)
{
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
	regs.sr = src;
	MakeFromSR();
}}}}}
void op_46fc(U32 opcode)
{
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{{	S16 src = nextiword();
	regs.sr = src;
	MakeFromSR();
}}}}
void op_4800(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S8 src = regs.d[srcreg];
{	U16 newv_lo = - (src & 0xF) - regs.x;
	U16 newv_hi = - (src & 0xF0);
	U16 newv;
	if (newv_lo > 9) { newv_lo-=6; newv_hi-=0x10; }
	newv = newv_hi + (newv_lo & 0xF);	CFLG = regs.x = (newv_hi & 0x1F0) > 0x90;
	if (CFLG) newv -= 0x60;
	if (newv != 0) ZFLG = 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (newv) & 0xff;
}}}}
void op_4810(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	U16 newv_lo = - (src & 0xF) - regs.x;
	U16 newv_hi = - (src & 0xF0);
	U16 newv;
	if (newv_lo > 9) { newv_lo-=6; newv_hi-=0x10; }
	newv = newv_hi + (newv_lo & 0xF);	CFLG = regs.x = (newv_hi & 0x1F0) > 0x90;
	if (CFLG) newv -= 0x60;
	if (newv != 0) ZFLG = 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)newv);
}}}}
void op_4818(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	U16 newv_lo = - (src & 0xF) - regs.x;
	U16 newv_hi = - (src & 0xF0);
	U16 newv;
	if (newv_lo > 9) { newv_lo-=6; newv_hi-=0x10; }
	newv = newv_hi + (newv_lo & 0xF);	CFLG = regs.x = (newv_hi & 0x1F0) > 0x90;
	if (CFLG) newv -= 0x60;
	if (newv != 0) ZFLG = 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)newv);
}}}}}
void op_4820(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	U16 newv_lo = - (src & 0xF) - regs.x;
	U16 newv_hi = - (src & 0xF0);
	U16 newv;
	if (newv_lo > 9) { newv_lo-=6; newv_hi-=0x10; }
	newv = newv_hi + (newv_lo & 0xF);	CFLG = regs.x = (newv_hi & 0x1F0) > 0x90;
	if (CFLG) newv -= 0x60;
	if (newv != 0) ZFLG = 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)newv);
}}}}}
void op_4828(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	U16 newv_lo = - (src & 0xF) - regs.x;
	U16 newv_hi = - (src & 0xF0);
	U16 newv;
	if (newv_lo > 9) { newv_lo-=6; newv_hi-=0x10; }
	newv = newv_hi + (newv_lo & 0xF);	CFLG = regs.x = (newv_hi & 0x1F0) > 0x90;
	if (CFLG) newv -= 0x60;
	if (newv != 0) ZFLG = 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)newv);
}}}}
void op_4830(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	U16 newv_lo = - (src & 0xF) - regs.x;
	U16 newv_hi = - (src & 0xF0);
	U16 newv;
	if (newv_lo > 9) { newv_lo-=6; newv_hi-=0x10; }
	newv = newv_hi + (newv_lo & 0xF);	CFLG = regs.x = (newv_hi & 0x1F0) > 0x90;
	if (CFLG) newv -= 0x60;
	if (newv != 0) ZFLG = 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)newv);
}}}}}
void op_4838(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	U16 newv_lo = - (src & 0xF) - regs.x;
	U16 newv_hi = - (src & 0xF0);
	U16 newv;
	if (newv_lo > 9) { newv_lo-=6; newv_hi-=0x10; }
	newv = newv_hi + (newv_lo & 0xF);	CFLG = regs.x = (newv_hi & 0x1F0) > 0x90;
	if (CFLG) newv -= 0x60;
	if (newv != 0) ZFLG = 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)newv);
}}}}
void op_4839(U32 opcode)
{
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
{	U16 newv_lo = - (src & 0xF) - regs.x;
	U16 newv_hi = - (src & 0xF0);
	U16 newv;
	if (newv_lo > 9) { newv_lo-=6; newv_hi-=0x10; }
	newv = newv_hi + (newv_lo & 0xF);	CFLG = regs.x = (newv_hi & 0x1F0) > 0x90;
	if (CFLG) newv -= 0x60;
	if (newv != 0) ZFLG = 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)newv);
}}}}
void op_4840(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S32 src = regs.d[srcreg];
{	U32 dst = ((src >> 16)&0xFFFF) | ((src&0xFFFF)<<16);
	VFLG = CFLG = 0;
	ZFLG = ((S32)(dst)) == 0;
	NFLG = ((S32)(dst)) < 0;
	regs.d[srcreg] = (dst);
}}}}
void op_4850(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[7] -= 4;
{	A32 dsta = regs.a[7];
	put_long(dsta,srca);
}}}}}
void op_4858(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += 4;
{	regs.a[7] -= 4;
{	A32 dsta = regs.a[7];
	put_long(dsta,srca);
}}}}}}
void op_4860(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
{	regs.a[7] -= 4;
{	A32 dsta = regs.a[7];
	put_long(dsta,srca);
}}}}}}
void op_4868(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	regs.a[7] -= 4;
{	A32 dsta = regs.a[7];
	put_long(dsta,srca);
}}}}}
void op_4870(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	regs.a[7] -= 4;
{	A32 dsta = regs.a[7];
	put_long(dsta,srca);
}}}}}
void op_4878(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	regs.a[7] -= 4;
{	A32 dsta = regs.a[7];
	put_long(dsta,srca);
}}}}}
void op_4879(U32 opcode)
{
{{	A32 srca = nextilong();
{	regs.a[7] -= 4;
{	A32 dsta = regs.a[7];
	put_long(dsta,srca);
}}}}}
void op_487a(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	regs.a[7] -= 4;
{	A32 dsta = regs.a[7];
	put_long(dsta,srca);
}}}}}
void op_487b(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	regs.a[7] -= 4;
{	A32 dsta = regs.a[7];
	put_long(dsta,srca);
}}}}}
void op_4880(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	U32 dst = (S32)(S8)src;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(dst)) == 0;
	NFLG = ((S16)(dst)) < 0;
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (dst) & 0xffff;
}}}}
void op_4890(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg];
{	int i, bitcnt = 0;
	U32 rd[8], ra[8];
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { rd[i] = regs.d[i]; ra[i] = regs.a[i]; }
	// Jimmy - type cast put_byte (A32) & (U16)
	for(i=0;i<8;i++) { if (mask & 1) { put_word((A32)srca,(U16) rd[i]); srca += 2; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { put_word((A32)srca,(U16) ra[i]); srca += 2; } mask >>= 1; }
}}}}
void op_4898(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg];
{	int i, bitcnt = 0;
	U32 rd[8], ra[8];
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { rd[i] = regs.d[i]; ra[i] = regs.a[i]; }
	// Jimmy - type cast put_byte (A32) & (U16)
	for(i=0;i<8;i++) { if (mask & 1) { put_word((A32)srca, (U16)rd[i]); srca += 2; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { put_word((A32)srca, (U16)ra[i]); srca += 2; } mask >>= 1; }
}}}}
void op_48a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{{	A32 srca = regs.a[srcreg];
{	int i, bitcnt = 0;
	U32 rd[8], ra[8];
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { rd[i] = regs.d[i]; ra[i] = regs.a[i]; }
	srca -= 2*bitcnt;
	regs.a[srcreg] = srca;
	// Jimmy - type cast put_byte (A32) & (U16)
	for(i=0;i<8;i++) { if (mask & 32768) { put_word((A32)srca, (U16)rd[i]); srca += 2; } mask <<= 1; }
	for(i=0;i<8;i++) { if (mask & 32768) { put_word((A32)srca, (U16)ra[i]); srca += 2; } mask <<= 1; }
}}}}}
void op_48a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int i, bitcnt = 0;
	U32 rd[8], ra[8];
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { rd[i] = regs.d[i]; ra[i] = regs.a[i]; }
	// Jimmy - type cast put_byte (A32) & (U16)
	for(i=0;i<8;i++) { if (mask & 1) { put_word((A32)srca, (U16)rd[i]); srca += 2; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { put_word((A32)srca, (U16)ra[i]); srca += 2; } mask >>= 1; }
}}}}
void op_48b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int i, bitcnt = 0;
	U32 rd[8], ra[8];
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { rd[i] = regs.d[i]; ra[i] = regs.a[i]; }
	// Jimmy - type cast put_byte (A32) & (U16)
	for(i=0;i<8;i++) { if (mask & 1) { put_word((A32)srca, (U16)rd[i]); srca += 2; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { put_word((A32)srca, (U16)ra[i]); srca += 2; } mask >>= 1; }
}}}}
void op_48b8(U32 opcode)
{
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = (S32)(S16)nextiword();
{	int i, bitcnt = 0;
	U32 rd[8], ra[8];
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { rd[i] = regs.d[i]; ra[i] = regs.a[i]; }
	// Jimmy - type cast put_byte (A32) & (U16)
	for(i=0;i<8;i++) { if (mask & 1) { put_word((A32)srca, (U16)rd[i]); srca += 2; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { put_word((A32)srca, (U16)ra[i]); srca += 2; } mask >>= 1; }
}}}}
void op_48b9(U32 opcode)
{
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = nextilong();
{	int i, bitcnt = 0;
	U32 rd[8], ra[8];
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { rd[i] = regs.d[i]; ra[i] = regs.a[i]; }
	// Jimmy - type cast put_byte (A32) & (U16)
	for(i=0;i<8;i++) { if (mask & 1) { put_word((A32)srca, (U16)rd[i]); srca += 2; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { put_word((A32)srca, (U16)ra[i]); srca += 2; } mask >>= 1; }
}}}}
void op_48c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S32 src = regs.d[srcreg];
{	U32 dst = (S32)(S16)src;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(dst)) == 0;
	NFLG = ((S32)(dst)) < 0;
	regs.d[srcreg] = (dst);
}}}}
void op_48d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg];
{	int i, bitcnt = 0;
	U32 rd[8], ra[8];
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { rd[i] = regs.d[i]; ra[i] = regs.a[i]; }
	for(i=0;i<8;i++) { if (mask & 1) { put_long(srca, rd[i]); srca += 4; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { put_long(srca, ra[i]); srca += 4; } mask >>= 1; }
}}}}
void op_48d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg];
{	int i, bitcnt = 0;
	U32 rd[8], ra[8];
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { rd[i] = regs.d[i]; ra[i] = regs.a[i]; }
	for(i=0;i<8;i++) { if (mask & 1) { put_long(srca, rd[i]); srca += 4; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { put_long(srca, ra[i]); srca += 4; } mask >>= 1; }
}}}}
void op_48e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{{	A32 srca = regs.a[srcreg];
{	int i, bitcnt = 0;
	U32 rd[8], ra[8];
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { rd[i] = regs.d[i]; ra[i] = regs.a[i]; }
	srca -= 4*bitcnt;
	regs.a[srcreg] = srca;
	for(i=0;i<8;i++) { if (mask & 32768) { put_long(srca, rd[i]); srca += 4; } mask <<= 1; }
	for(i=0;i<8;i++) { if (mask & 32768) { put_long(srca, ra[i]); srca += 4; } mask <<= 1; }
}}}}}
void op_48e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int i, bitcnt = 0;
	U32 rd[8], ra[8];
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { rd[i] = regs.d[i]; ra[i] = regs.a[i]; }
	for(i=0;i<8;i++) { if (mask & 1) { put_long(srca, rd[i]); srca += 4; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { put_long(srca, ra[i]); srca += 4; } mask >>= 1; }
}}}}
void op_48f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int i, bitcnt = 0;
	U32 rd[8], ra[8];
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { rd[i] = regs.d[i]; ra[i] = regs.a[i]; }
	for(i=0;i<8;i++) { if (mask & 1) { put_long(srca, rd[i]); srca += 4; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { put_long(srca, ra[i]); srca += 4; } mask >>= 1; }
}}}}
void op_48f8(U32 opcode)
{
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = (S32)(S16)nextiword();
{	int i, bitcnt = 0;
	U32 rd[8], ra[8];
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { rd[i] = regs.d[i]; ra[i] = regs.a[i]; }
	for(i=0;i<8;i++) { if (mask & 1) { put_long(srca, rd[i]); srca += 4; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { put_long(srca, ra[i]); srca += 4; } mask >>= 1; }
}}}}
void op_48f9(U32 opcode)
{
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = nextilong();
{	int i, bitcnt = 0;
	U32 rd[8], ra[8];
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { rd[i] = regs.d[i]; ra[i] = regs.a[i]; }
	for(i=0;i<8;i++) { if (mask & 1) { put_long(srca, rd[i]); srca += 4; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { put_long(srca, ra[i]); srca += 4; } mask >>= 1; }
}}}}
void op_4a00(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S8 src = regs.d[srcreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
}}}
void op_4a10(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
}}}
void op_4a18(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
}}}}
void op_4a20(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
}}}}
void op_4a28(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
}}}
void op_4a30(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
}}}}
void op_4a38(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
}}}
void op_4a39(U32 opcode)
{
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
}}}
void op_4a40(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
}}}
void op_4a48(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.a[srcreg];
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
}}}
void op_4a50(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
}}}
void op_4a58(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
}}}}
void op_4a60(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
}}}}
void op_4a68(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
}}}
void op_4a70(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
}}}}
void op_4a78(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
}}}
void op_4a79(U32 opcode)
{
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
}}}
void op_4a80(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S32 src = regs.d[srcreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
}}}
void op_4a88(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S32 src = regs.a[srcreg];
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
}}}
void op_4a90(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
}}}
void op_4a98(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
}}}}
void op_4aa0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
}}}}
void op_4aa8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
}}}
void op_4ab0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
}}}}
void op_4ab8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
}}}
void op_4ab9(U32 opcode)
{
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
}}}
void op_4ac0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S8 src = regs.d[srcreg];
{	U32 dst = 0x80 | src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (dst) & 0xff;
}}}}
void op_4ad0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	U32 dst = 0x80 | src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}
void op_4ad8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	U32 dst = 0x80 | src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}
void op_4ae0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	U32 dst = 0x80 | src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}
void op_4ae8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	U32 dst = 0x80 | src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}
void op_4af0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	U32 dst = 0x80 | src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}}
void op_4af8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
{	U32 dst = 0x80 | src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}
void op_4af9(U32 opcode)
{
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
{	U32 dst = 0x80 | src;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)dst);
}}}}
void op_4c90(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg];
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
}}}}
void op_4c98(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg];
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
	regs.a[srcreg] = srca;
}}}}
void op_4ca0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{{	A32 srca = regs.a[srcreg];
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
}}}}}
void op_4ca8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
}}}}
void op_4cb0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
}}}}
void op_4cb8(U32 opcode)
{
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = (S32)(S16)nextiword();
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
}}}}
void op_4cb9(U32 opcode)
{
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = nextilong();
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
}}}}
void op_4cba(U32 opcode)
{
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
}}}}
void op_4cbb(U32 opcode)
{
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = (S32)(S16)get_word(srca); srca += 2; } mask >>= 1; }
}}}}
void op_4cd0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg];
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = get_long(srca); srca += 4; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = get_long(srca); srca += 4; } mask >>= 1; }
}}}}
void op_4cd8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg];
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = get_long(srca); srca += 4; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = get_long(srca); srca += 4; } mask >>= 1; }
	regs.a[srcreg] = srca;
}}}}
void op_4ce0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{{	A32 srca = regs.a[srcreg];
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = get_long(srca); srca += 4; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = get_long(srca); srca += 4; } mask >>= 1; }
}}}}}
void op_4ce8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = get_long(srca); srca += 4; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = get_long(srca); srca += 4; } mask >>= 1; }
}}}}
void op_4cf0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = get_long(srca); srca += 4; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = get_long(srca); srca += 4; } mask >>= 1; }
}}}}
void op_4cf8(U32 opcode)
{
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = (S32)(S16)nextiword();
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = get_long(srca); srca += 4; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = get_long(srca); srca += 4; } mask >>= 1; }
}}}}
void op_4cf9(U32 opcode)
{
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = nextilong();
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = get_long(srca); srca += 4; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = get_long(srca); srca += 4; } mask >>= 1; }
}}}}
void op_4cfa(U32 opcode)
{
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = get_long(srca); srca += 4; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = get_long(srca); srca += 4; } mask >>= 1; }
}}}}
void op_4cfb(U32 opcode)
{
{	U16 mask = nextiword(), bitmask = mask;
{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	int i, bitcnt = 0;
	for(i=0;i<16;i++) { bitcnt += bitmask & 1; bitmask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.d[i] = get_long(srca); srca += 4; } mask >>= 1; }
	for(i=0;i<8;i++) { if (mask & 1) { regs.a[i] = get_long(srca); srca += 4; } mask >>= 1; }
}}}}
void op_4e40(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 15) >> 0);
{{	U32 src = srcreg;
	Exception(src+32,0);
}}}
void op_4e50(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[7] -= 4;
{	A32 olda = regs.a[7];
{	S32 src = regs.a[srcreg];
	put_long(olda,src);
	regs.a[srcreg] = (regs.a[7]);
{	S16 offs = nextiword();
	regs.a[7] += offs;
}}}}}}
void op_4e58(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S32 src = regs.a[srcreg];
	regs.a[7] = src;
{	A32 olda = regs.a[7];
	S32 old = get_long(olda);
{	regs.a[7] += 4;
	regs.a[srcreg] = (old);
}}}}}
void op_4e60(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{{	S32 src = regs.a[srcreg];
	regs.usp = src;
}}}}
void op_4e68(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{{	regs.a[srcreg] = (regs.usp);
}}}}
void op_4e70(U32 opcode)
{
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{	// Remove by Jimmy - 093 -> m68k_reset();
}}}
void op_4e71(U32 opcode)
{
{}}
void op_4e72(U32 opcode)
{
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{{	S16 src = nextiword();
	regs.sr = src;
	MakeFromSR();
	m68k_setstopped(1);
}}}}
void op_4e73(U32 opcode)
{
{if (!regs.s) { regs.pc_p--; Exception(8,0); } else
{{	A32 sra = regs.a[7];
	S16 sr = get_word(sra);
{	regs.a[7] += 2;
{	A32 pca = regs.a[7];
	S32 pc = get_long(pca);
{	regs.a[7] += 4;
	regs.sr = sr; m68k_setpc(pc);
	MakeFromSR();
}}}}}}}
void op_4e74(U32 opcode)
{
{}}
void op_4e75(U32 opcode)
{
{{	A32 pca = regs.a[7];
	S32 pc = get_long(pca);
{	regs.a[7] += 4;
	m68k_setpc(pc);
}}}}
void op_4e76(U32 opcode)
{
{	if(VFLG) Exception(7,0);
}}
void op_4e77(U32 opcode)
{
{	MakeSR();
{	A32 sra = regs.a[7];
	S16 sr = get_word(sra);
{	regs.a[7] += 2;
{	A32 pca = regs.a[7];
	S32 pc = get_long(pca);
{	regs.a[7] += 4;
	regs.sr &= 0xFF00; sr &= 0xFF;
	regs.sr |= sr; m68k_setpc(pc);
	MakeFromSR();
}}}}}}
void op_4e90(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[7] -= 4;
{	A32 spa = regs.a[7];
	put_long(spa,m68k_getpc());
	m68k_setpc(srca);
}}}}}
void op_4e98(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += 4;
{	regs.a[7] -= 4;
{	A32 spa = regs.a[7];
	put_long(spa,m68k_getpc());
	m68k_setpc(srca);
}}}}}}
void op_4ea0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
{	regs.a[7] -= 4;
{	A32 spa = regs.a[7];
	put_long(spa,m68k_getpc());
	m68k_setpc(srca);
}}}}}}
void op_4ea8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	regs.a[7] -= 4;
{	A32 spa = regs.a[7];
	put_long(spa,m68k_getpc());
	m68k_setpc(srca);
}}}}}
void op_4eb0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	regs.a[7] -= 4;
{	A32 spa = regs.a[7];
	put_long(spa,m68k_getpc());
	m68k_setpc(srca);
}}}}}
void op_4eb8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	regs.a[7] -= 4;
{	A32 spa = regs.a[7];
	put_long(spa,m68k_getpc());
	m68k_setpc(srca);
}}}}}
void op_4eb9(U32 opcode)
{
{{	A32 srca = nextilong();
{	regs.a[7] -= 4;
{	A32 spa = regs.a[7];
	put_long(spa,m68k_getpc());
	m68k_setpc(srca);
}}}}}
void op_4eba(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	regs.a[7] -= 4;
{	A32 spa = regs.a[7];
	put_long(spa,m68k_getpc());
	m68k_setpc(srca);
}}}}}
void op_4ebb(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	regs.a[7] -= 4;
{	A32 spa = regs.a[7];
	put_long(spa,m68k_getpc());
	m68k_setpc(srca);
}}}}}
void op_4ed0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	m68k_setpc(srca);
}}}
void op_4ed8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += 4;
	m68k_setpc(srca);
}}}}
void op_4ee0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	m68k_setpc(srca);
}}}}
void op_4ee8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	m68k_setpc(srca);
}}}
void op_4ef0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
	m68k_setpc(srca);
}}}
void op_4ef8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
	m68k_setpc(srca);
}}}
void op_4ef9(U32 opcode)
{
{{	A32 srca = nextilong();
	m68k_setpc(srca);
}}}
void op_4efa(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
	m68k_setpc(srca);
}}}
void op_4efb(U32 opcode)
{
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
	m68k_setpc(srca);
}}}
