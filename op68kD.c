#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "qlmem.h"
#include "exe68k.h"
#include "op68ktbl.h"
void op_d000(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = regs.d[srcreg];
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
void op_d010(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
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
void op_d018(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[srcreg] += areg_byteinc[srcreg];
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
}}}}}}}}
void op_d020(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
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
}}}}}}}}
void op_d028(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S8 src = get_byte(srca);
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
void op_d030(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
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
}}}}}}}}
void op_d038(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S8 src = get_byte(srca);
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
void op_d039(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S8 src = get_byte(srca);
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
void op_d03a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S8 src = get_byte(srca);
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
}}}}}}}}
void op_d03b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S8 src = get_byte(srca);
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
}}}}}}}}
void op_d03c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
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
void op_d040(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
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
void op_d048(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.a[srcreg];
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
void op_d050(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
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
void op_d058(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
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
}}}}}}}}
void op_d060(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
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
}}}}}}}}
void op_d068(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
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
void op_d070(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
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
}}}}}}}}
void op_d078(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
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
void op_d079(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
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
void op_d07a(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
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
}}}}}}}}
void op_d07b(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
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
}}}}}}}}
void op_d07c(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
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
void op_d080(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
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
void op_d088(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.a[srcreg];
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
void op_d090(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
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
void op_d098(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
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
}}}}}}}}
void op_d0a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
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
}}}}}}}}
void op_d0a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
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
void op_d0b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
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
}}}}}}}}
void op_d0b8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
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
void op_d0b9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
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
void op_d0ba(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
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
}}}}}}}}
void op_d0bb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
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
}}}}}}}}
void op_d0bc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
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
void op_d0c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
void op_d0c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.a[srcreg];
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
void op_d0d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
void op_d0d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_d0e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_d0e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
void op_d0f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_d0f8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
void op_d0f9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
void op_d0fa(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_d0fb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_d0fc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
void op_d100(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = regs.d[srcreg];
{	S8 dst = regs.d[dstreg];
{	U32 newv = dst + src + (regs.x ? 1 : 0);
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	VFLG = (flgs && flgo && !flgn) || (!flgs && !flgo && flgn);
	regs.x = CFLG = (flgs && flgo) || (!flgn && (flgo || flgs));
	if (((S8)(newv)) != 0) ZFLG = 0;
	NFLG = ((S8)(newv)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}
void op_d108(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	U32 newv = dst + src + (regs.x ? 1 : 0);
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	VFLG = (flgs && flgo && !flgn) || (!flgs && !flgo && flgn);
	regs.x = CFLG = (flgs && flgo) || (!flgn && (flgo || flgs));
	if (((S8)(newv)) != 0) ZFLG = 0;
	NFLG = ((S8)(newv)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}}
void op_d110(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
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
void op_d118(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
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
void op_d120(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
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
void op_d128(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
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
void op_d130(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
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
void op_d138(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
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
void op_d139(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
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
void op_d140(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	S16 dst = regs.d[dstreg];
{	U32 newv = dst + src + (regs.x ? 1 : 0);
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	VFLG = (flgs && flgo && !flgn) || (!flgs && !flgo && flgn);
	regs.x = CFLG = (flgs && flgo) || (!flgn && (flgo || flgs));
	if (((S16)(newv)) != 0) ZFLG = 0;
	NFLG = ((S16)(newv)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}
void op_d148(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{	U32 newv = dst + src + (regs.x ? 1 : 0);
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	VFLG = (flgs && flgo && !flgn) || (!flgs && !flgo && flgn);
	regs.x = CFLG = (flgs && flgo) || (!flgn && (flgo || flgs));
	if (((S16)(newv)) != 0) ZFLG = 0;
	NFLG = ((S16)(newv)) < 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)dsta,(U16)newv);
}}}}}}}}
void op_d150(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
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
void op_d158(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
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
void op_d160(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
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
void op_d168(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
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
void op_d170(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
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
void op_d178(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S16 src = regs.d[srcreg];
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
void op_d179(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S16 src = regs.d[srcreg];
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
void op_d180(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
{	S32 dst = regs.d[dstreg];
{	U32 newv = dst + src + (regs.x ? 1 : 0);
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	VFLG = (flgs && flgo && !flgn) || (!flgs && !flgo && flgn);
	regs.x = CFLG = (flgs && flgo) || (!flgn && (flgo || flgs));
	if (((S32)(newv)) != 0) ZFLG = 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}}
void op_d188(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{	U32 newv = dst + src + (regs.x ? 1 : 0);
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	VFLG = (flgs && flgo && !flgn) || (!flgs && !flgo && flgn);
	regs.x = CFLG = (flgs && flgo) || (!flgn && (flgo || flgs));
	if (((S32)(newv)) != 0) ZFLG = 0;
	NFLG = ((S32)(newv)) < 0;
	put_long(dsta,newv);
}}}}}}}}
void op_d190(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
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
void op_d198(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
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
void op_d1a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
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
void op_d1a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
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
void op_d1b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
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
void op_d1b8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S32 src = regs.d[srcreg];
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
void op_d1b9(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S32 src = regs.d[srcreg];
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
void op_d1c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
void op_d1c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.a[srcreg];
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
void op_d1d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
void op_d1d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_d1e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_d1e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
void op_d1f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_d1f8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
void op_d1f9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
void op_d1fa(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_d1fb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_d1fc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = nextilong();
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst + src;
	regs.a[dstreg] = (newv);
}}}}}
