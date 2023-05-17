#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "qlmem.h"
#include "exe68k.h"
#include "op68ktbl.h"
void op_b000(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = regs.d[srcreg];
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
void op_b010(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
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
void op_b018(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
{	S8 dst = regs.d[dstreg];
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b020(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b028(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
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
void op_b030(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b038(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
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
void op_b039(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
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
void op_b03a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b03b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
{	S8 dst = regs.d[dstreg];
{{U32 newv = ((S8)(dst)) - ((S8)(src));
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	ZFLG = ((S8)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b03c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
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
void op_b040(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
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
void op_b048(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.a[srcreg];
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
void op_b050(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
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
void op_b058(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	S16 dst = regs.d[dstreg];
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b060(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b068(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
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
void op_b070(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b078(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
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
void op_b079(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
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
void op_b07a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b07b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S16 dst = regs.d[dstreg];
{{U32 newv = ((S16)(dst)) - ((S16)(src));
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	ZFLG = ((S16)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b07c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
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
void op_b080(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
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
void op_b088(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.a[srcreg];
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
void op_b090(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
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
void op_b098(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	S32 dst = regs.d[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b0a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b0a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
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
void op_b0b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b0b8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
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
void op_b0b9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
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
void op_b0ba(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b0bb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	S32 dst = regs.d[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b0bc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
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
void op_b0c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_b0c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.a[srcreg];
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_b0d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_b0d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b0e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b0e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_b0f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b0f8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_b0f9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_b0fa(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b0fb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b0fc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_b100(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	S8 dst = regs.d[dstreg];
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (src) & 0xff;
}}}}
void op_b108(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
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
}}}}}}}}}
void op_b110(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_b118(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	regs.a[dstreg] += areg_byteinc[dstreg];
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_b120(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_b128(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_b130(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S8 dst = get_byte(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}}
void op_b138(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	S8 dst = get_byte(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_b139(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	S8 dst = get_byte(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S8)(src)) == 0;
	NFLG = ((S8)(src)) < 0;
	put_byte(dsta,src);
}}}}
void op_b140(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	S16 dst = regs.d[dstreg];
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (src) & 0xffff;
}}}}
void op_b148(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
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
}}}}}}}}}
void op_b150(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_b158(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{	regs.a[dstreg] += 2;
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_b160(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_b168(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_b170(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S16 dst = get_word(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}}
void op_b178(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S16 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	S16 dst = get_word(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_b179(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S16 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	S16 dst = get_word(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(src)) == 0;
	NFLG = ((S16)(src)) < 0;
	put_word(dsta,src);
}}}}
void op_b180(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	S32 dst = regs.d[dstreg];
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	regs.d[dstreg] = (src);
}}}}
void op_b188(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
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
}}}}}}}}}
void op_b190(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_b198(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{	regs.a[dstreg] += 4;
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_b1a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_b1a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg] + (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_b1b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
{	A32 dsta = regs.a[dstreg];
	dsta = get_disp_ea (dsta, nextiword());
{	S32 dst = get_long(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}}
void op_b1b8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S32 src = regs.d[srcreg];
{	A32 dsta = (S32)(S16)nextiword();
	S32 dst = get_long(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_b1b9(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S32 src = regs.d[srcreg];
{	A32 dsta = nextilong();
	S32 dst = get_long(dsta);
	src ^= dst;
	VFLG = CFLG = 0;
	ZFLG = ((S32)(src)) == 0;
	NFLG = ((S32)(src)) < 0;
	put_long(dsta,src);
}}}}
void op_b1c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_b1c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.a[srcreg];
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_b1d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_b1d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b1e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b1e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_b1f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b1f8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_b1f9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
void op_b1fa(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b1fb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}}
void op_b1fc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = nextilong();
{	S32 dst = regs.a[dstreg];
{{U32 newv = ((S32)(dst)) - ((S32)(src));
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	ZFLG = ((S32)(newv)) == 0;
	VFLG = (flgs != flgo) && (flgn != flgo);
	CFLG = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
}}}}}}}
