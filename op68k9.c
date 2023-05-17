#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "qlmem.h"
#include "exe68k.h"
#include "op68ktbl.h"
void op_9000(U32 opcode)
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
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}}
void op_9010(U32 opcode)
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
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}}
void op_9018(U32 opcode)
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
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}}}
void op_9020(U32 opcode)
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
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}}}
void op_9028(U32 opcode)
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
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}}
void op_9030(U32 opcode)
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
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}}}
void op_9038(U32 opcode)
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
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}}
void op_9039(U32 opcode)
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
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}}
void op_903a(U32 opcode)
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
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}}}
void op_903b(U32 opcode)
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
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}}}
void op_903c(U32 opcode)
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
	CFLG = regs.x = ((U8)(src)) > ((U8)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}}
void op_9040(U32 opcode)
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
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}}
void op_9048(U32 opcode)
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
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}}
void op_9050(U32 opcode)
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
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}}
void op_9058(U32 opcode)
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
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}}}
void op_9060(U32 opcode)
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
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}}}
void op_9068(U32 opcode)
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
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}}
void op_9070(U32 opcode)
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
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}}}
void op_9078(U32 opcode)
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
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}}
void op_9079(U32 opcode)
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
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}}
void op_907a(U32 opcode)
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
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}}}
void op_907b(U32 opcode)
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
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}}}
void op_907c(U32 opcode)
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
	CFLG = regs.x = ((U16)(src)) > ((U16)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}}
void op_9080(U32 opcode)
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
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] = (newv);
}}}}}}}
void op_9088(U32 opcode)
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
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] = (newv);
}}}}}}}
void op_9090(U32 opcode)
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
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] = (newv);
}}}}}}}
void op_9098(U32 opcode)
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
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] = (newv);
}}}}}}}}
void op_90a0(U32 opcode)
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
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] = (newv);
}}}}}}}}
void op_90a8(U32 opcode)
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
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] = (newv);
}}}}}}}
void op_90b0(U32 opcode)
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
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] = (newv);
}}}}}}}}
void op_90b8(U32 opcode)
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
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] = (newv);
}}}}}}}
void op_90b9(U32 opcode)
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
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] = (newv);
}}}}}}}
void op_90ba(U32 opcode)
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
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] = (newv);
}}}}}}}}
void op_90bb(U32 opcode)
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
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] = (newv);
}}}}}}}}
void op_90bc(U32 opcode)
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
	CFLG = regs.x = ((U32)(src)) > ((U32)(dst));
	NFLG = flgn != 0;
	regs.d[dstreg] = (newv);
}}}}}}}
void op_90c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
void op_90c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.a[srcreg];
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
void op_90d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
void op_90d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[srcreg] += 2;
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_90e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_90e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
void op_90f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_90f8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
void op_90f9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
void op_90fa(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_90fb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S16 src = get_word(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_90fc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = nextiword();
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
void op_9100(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S8 src = regs.d[srcreg];
{	S8 dst = regs.d[dstreg];
{	U32 newv = dst - src - (regs.x ? 1 : 0);
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	VFLG = (!flgs && flgo && !flgn) || (flgs && !flgo && flgn);
	regs.x = CFLG = (flgs && !flgo) || (flgn && (!flgo || flgs));
	if (((S8)(newv)) != 0) ZFLG = 0;
	NFLG = ((S8)(newv)) < 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (newv) & 0xff;
}}}}}}
void op_9108(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= areg_byteinc[srcreg];
{	A32 srca = regs.a[srcreg];
	S8 src = get_byte(srca);
{	regs.a[dstreg] -= areg_byteinc[dstreg];
{	A32 dsta = regs.a[dstreg];
	S8 dst = get_byte(dsta);
{	U32 newv = dst - src - (regs.x ? 1 : 0);
{	int flgs = ((S8)(src)) < 0;
	int flgo = ((S8)(dst)) < 0;
	int flgn = ((S8)(newv)) < 0;
	VFLG = (!flgs && flgo && !flgn) || (flgs && !flgo && flgn);
	regs.x = CFLG = (flgs && !flgo) || (flgn && (!flgo || flgs));
	if (((S8)(newv)) != 0) ZFLG = 0;
	NFLG = ((S8)(newv)) < 0;
	// Jimmy - type cast put_byte (A32) & (U8)
	put_byte((A32)dsta,(U8)newv);
}}}}}}}}
void op_9110(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
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
void op_9118(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
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
void op_9120(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
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
void op_9128(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
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
void op_9130(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 src = regs.d[srcreg];
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
void op_9138(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
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
void op_9139(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S8 src = regs.d[srcreg];
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
void op_9140(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S16 src = regs.d[srcreg];
{	S16 dst = regs.d[dstreg];
{	U32 newv = dst - src - (regs.x ? 1 : 0);
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	VFLG = (!flgs && flgo && !flgn) || (flgs && !flgo && flgn);
	regs.x = CFLG = (flgs && !flgo) || (flgn && (!flgo || flgs));
	if (((S16)(newv)) != 0) ZFLG = 0;
	NFLG = ((S16)(newv)) < 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (newv) & 0xffff;
}}}}}}
void op_9148(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 2;
{	A32 srca = regs.a[srcreg];
	S16 src = get_word(srca);
{	regs.a[dstreg] -= 2;
{	A32 dsta = regs.a[dstreg];
	S16 dst = get_word(dsta);
{	U32 newv = dst - src - (regs.x ? 1 : 0);
{	int flgs = ((S16)(src)) < 0;
	int flgo = ((S16)(dst)) < 0;
	int flgn = ((S16)(newv)) < 0;
	VFLG = (!flgs && flgo && !flgn) || (flgs && !flgo && flgn);
	regs.x = CFLG = (flgs && !flgo) || (flgn && (!flgo || flgs));
	if (((S16)(newv)) != 0) ZFLG = 0;
	NFLG = ((S16)(newv)) < 0;
	// Jimmy - type cast put_byte (A32) & (U16)
	put_word((A32)dsta,(U16)newv);
}}}}}}}}
void op_9150(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
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
void op_9158(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
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
void op_9160(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
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
void op_9168(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
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
void op_9170(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 src = regs.d[srcreg];
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
void op_9178(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S16 src = regs.d[srcreg];
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
void op_9179(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S16 src = regs.d[srcreg];
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
void op_9180(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
{	S32 dst = regs.d[dstreg];
{	U32 newv = dst - src - (regs.x ? 1 : 0);
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	VFLG = (!flgs && flgo && !flgn) || (flgs && !flgo && flgn);
	regs.x = CFLG = (flgs && !flgo) || (flgn && (!flgo || flgs));
	if (((S32)(newv)) != 0) ZFLG = 0;
	NFLG = ((S32)(newv)) < 0;
	regs.d[dstreg] = (newv);
}}}}}}
void op_9188(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[dstreg] -= 4;
{	A32 dsta = regs.a[dstreg];
	S32 dst = get_long(dsta);
{	U32 newv = dst - src - (regs.x ? 1 : 0);
{	int flgs = ((S32)(src)) < 0;
	int flgo = ((S32)(dst)) < 0;
	int flgn = ((S32)(newv)) < 0;
	VFLG = (!flgs && flgo && !flgn) || (flgs && !flgo && flgn);
	regs.x = CFLG = (flgs && !flgo) || (flgn && (!flgo || flgs));
	if (((S32)(newv)) != 0) ZFLG = 0;
	NFLG = ((S32)(newv)) < 0;
	put_long(dsta,newv);
}}}}}}}}
void op_9190(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
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
void op_9198(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
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
void op_91a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
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
void op_91a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
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
void op_91b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 src = regs.d[srcreg];
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
void op_91b8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S32 src = regs.d[srcreg];
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
void op_91b9(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
{{	S32 src = regs.d[srcreg];
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
void op_91c0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.d[srcreg];
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
void op_91c8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = regs.a[srcreg];
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
void op_91d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
void op_91d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	regs.a[srcreg] += 4;
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_91e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	regs.a[srcreg] -= 4;
{	A32 srca = regs.a[srcreg];
	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_91e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg] + (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
void op_91f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = regs.a[srcreg];
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_91f8(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = (S32)(S16)nextiword();
	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
void op_91f9(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = nextilong();
	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
void op_91fa(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca += (S32)(S16)nextiword();
{	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_91fb(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	A32 srca = m68k_getpc();
	srca = get_disp_ea (srca, nextiword());
{	S32 src = get_long(srca);
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}}
void op_91fc(U32 opcode)
{
	U32 dstreg = (opcode & 3584) >> 9;
{{	S32 src = nextilong();
{	S32 dst = regs.a[dstreg];
{	U32 newv = dst - src;
	regs.a[dstreg] = (newv);
}}}}}
