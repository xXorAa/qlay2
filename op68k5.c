#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "qlmem.h"
#include "exe68k.h"
#include "op68ktbl.h"
void op_5000(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5010(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5018(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5020(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5028(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5030(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5038(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
{{	U32 src = srcreg;
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
void op_5039(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
{{	U32 src = srcreg;
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
void op_5040(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5048(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
void op_5050(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
}}}}}}}
void op_5058(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5060(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5068(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5070(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5078(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
{{	U32 src = srcreg;
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
void op_5079(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
{{	U32 src = srcreg;
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
void op_5080(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5088(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
void op_5090(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5098(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_50a0(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_50a8(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_50b0(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_50b8(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
{{	U32 src = srcreg;
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
void op_50b9(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
{{	U32 src = srcreg;
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
void op_50c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(0) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_50c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(0)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_50d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(0) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_50d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(0) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_50e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(0) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_50e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(0) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_50f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(0) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_50f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(0) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_50f9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(0) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5100(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5110(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5118(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5120(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5128(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5130(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5138(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
{{	U32 src = srcreg;
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
void op_5139(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
{{	U32 src = srcreg;
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
void op_5140(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5148(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
void op_5150(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5158(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5160(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5168(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5170(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5178(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
{{	U32 src = srcreg;
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
void op_5179(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
{{	U32 src = srcreg;
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
void op_5180(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5188(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
void op_5190(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_5198(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_51a0(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_51a8(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_51b0(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 src = srcreg;
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
void op_51b8(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
{{	U32 src = srcreg;
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
void op_51b9(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
{{	U32 src = srcreg;
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
void op_51c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(1) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_51c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(1)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_51d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(1) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_51d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(1) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_51e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(1) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_51e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(1) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_51f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(1) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_51f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(1) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_51f9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(1) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_52c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(2) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_52c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(2)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_52d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(2) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_52d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(2) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_52e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(2) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_52e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(2) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_52f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(2) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_52f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(2) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_52f9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(2) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_53c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(3) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_53c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(3)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_53d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(3) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_53d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(3) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_53e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(3) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_53e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(3) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_53f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(3) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_53f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(3) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_53f9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(3) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_54c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(4) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_54c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(4)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_54d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(4) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_54d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(4) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_54e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(4) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_54e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(4) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_54f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(4) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_54f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(4) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_54f9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(4) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_55c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(5) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_55c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(5)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_55d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(5) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_55d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(5) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_55e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(5) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_55e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(5) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_55f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(5) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_55f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(5) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_55f9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(5) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_56c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(6) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_56c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(6)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_56d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(6) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_56d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(6) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_56e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(6) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_56e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(6) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_56f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(6) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_56f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(6) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_56f9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(6) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_57c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(7) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_57c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(7)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_57d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(7) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_57d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(7) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_57e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(7) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_57e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(7) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_57f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(7) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_57f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(7) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_57f9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(7) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_58c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(8) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_58c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(8)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_58d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(8) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_58d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(8) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_58e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(8) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_58e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(8) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_58f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(8) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_58f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(8) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_58f9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(8) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_59c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(9) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_59c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(9)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_59d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(9) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_59d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(9) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_59e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(9) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_59e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(9) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_59f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(9) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_59f8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(9) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_59f9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(9) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5ac0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(10) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_5ac8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(10)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_5ad0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(10) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5ad8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(10) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_5ae0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(10) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_5ae8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(10) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5af0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(10) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5af8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(10) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5af9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(10) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5bc0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(11) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_5bc8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(11)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_5bd0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(11) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5bd8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(11) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_5be0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(11) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_5be8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(11) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5bf0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(11) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5bf8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(11) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5bf9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(11) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5cc0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(12) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_5cc8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(12)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_5cd0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(12) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5cd8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(12) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_5ce0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(12) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_5ce8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(12) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5cf0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(12) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5cf8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(12) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5cf9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(12) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5dc0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(13) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_5dc8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(13)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_5dd0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(13) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5dd8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(13) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_5de0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(13) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_5de8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(13) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5df0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(13) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5df8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(13) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5df9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(13) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5ec0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(14) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_5ec8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(14)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_5ed0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(14) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5ed8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(14) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_5ee0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(14) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_5ee8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(14) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5ef0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(14) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5ef8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(14) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5ef9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(14) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5fc0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{{	int val = cctrue(15) ? 0xff : 0;
	regs.d[srcreg] &= ~0xff; regs.d[srcreg] |= (val) & 0xff;
}}}}
void op_5fc8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	S16 src = regs.d[srcreg];
{	S16 offs = nextiword();
	if (!cctrue(15)) {
	if (src--) regs.pc_p = (U16 *)((char *)regs.pc_p + (S32)offs - 2);
	regs.d[srcreg] &= ~0xffff; regs.d[srcreg] |= (src) & 0xffff;
	}
}}}}
void op_5fd0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	int val = cctrue(15) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5fd8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	int val = cctrue(15) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_5fe0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
{	int val = cctrue(15) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}}
void op_5fe8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
{	int val = cctrue(15) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5ff0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	int val = cctrue(15) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5ff8(U32 opcode)
{
{{	A32 srca = (S32)(S16)nextiword();
{	int val = cctrue(15) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
void op_5ff9(U32 opcode)
{
{{	A32 srca = nextilong();
{	int val = cctrue(15) ? 0xff : 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)srca,(U8)val);
}}}}
