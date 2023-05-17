#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "qlmem.h"
#include "exe68k.h"
#include "op68ktbl.h"
void op_e000(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	U32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	CFLG=regs.x=val&1; val = ((U32)val >> 1) | sign;
	}}
	NFLG = sign != 0;
	ZFLG = val == 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e008(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	int carry = 0;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	}
	CFLG = regs.x = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e010(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	int carry = 0;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	if(regs.x) val |= cmask;
	regs.x = carry != 0;
	}
	CFLG = regs.x;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e018(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&1; val = (U32)val >> 1;
	if(carry) val |= cmask;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e020(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 cnt = regs.d[srcreg];
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	U32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	CFLG=regs.x=val&1; val = ((U32)val >> 1) | sign;
	}}
	NFLG = sign != 0;
	ZFLG = val == 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e028(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 cnt = regs.d[srcreg];
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	int carry = 0;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	}
	CFLG = regs.x = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e030(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 cnt = regs.d[srcreg];
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	int carry = 0;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	if(regs.x) val |= cmask;
	regs.x = carry != 0;
	}
	CFLG = regs.x;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e038(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 cnt = regs.d[srcreg];
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&1; val = (U32)val >> 1;
	if(carry) val |= cmask;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e040(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	CFLG=regs.x=val&1; val = ((U32)val >> 1) | sign;
	}}
	NFLG = sign != 0;
	ZFLG = val == 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e048(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	int carry = 0;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	}
	CFLG = regs.x = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e050(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = 0;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	if(regs.x) val |= cmask;
	regs.x = carry != 0;
	}
	CFLG = regs.x;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e058(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&1; val = (U32)val >> 1;
	if(carry) val |= cmask;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e060(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 cnt = regs.d[srcreg];
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	CFLG=regs.x=val&1; val = ((U32)val >> 1) | sign;
	}}
	NFLG = sign != 0;
	ZFLG = val == 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e068(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 cnt = regs.d[srcreg];
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	int carry = 0;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	}
	CFLG = regs.x = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e070(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 cnt = regs.d[srcreg];
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = 0;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	if(regs.x) val |= cmask;
	regs.x = carry != 0;
	}
	CFLG = regs.x;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e078(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 cnt = regs.d[srcreg];
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&1; val = (U32)val >> 1;
	if(carry) val |= cmask;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e080(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	U32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	CFLG=regs.x=val&1; val = ((U32)val >> 1) | sign;
	}}
	NFLG = sign != 0;
	ZFLG = val == 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e088(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	int carry = 0;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	}
	CFLG = regs.x = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e090(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	int carry = 0;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	if(regs.x) val |= cmask;
	regs.x = carry != 0;
	}
	CFLG = regs.x;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e098(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&1; val = (U32)val >> 1;
	if(carry) val |= cmask;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e0a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 cnt = regs.d[srcreg];
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	U32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	CFLG=regs.x=val&1; val = ((U32)val >> 1) | sign;
	}}
	NFLG = sign != 0;
	ZFLG = val == 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e0a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 cnt = regs.d[srcreg];
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	int carry = 0;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	}
	CFLG = regs.x = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e0b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 cnt = regs.d[srcreg];
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	int carry = 0;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&1; val >>= 1;
	if(regs.x) val |= cmask;
	regs.x = carry != 0;
	}
	CFLG = regs.x;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e0b8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 cnt = regs.d[srcreg];
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&1; val = (U32)val >> 1;
	if(carry) val |= cmask;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e0d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
	VFLG = 0;
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	CFLG=regs.x=val&1; val = (val >> 1) | sign;
	NFLG = sign != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void op_e0d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	regs.a[srcreg] += 2;
	VFLG = 0;
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	CFLG=regs.x=val&1; val = (val >> 1) | sign;
	NFLG = sign != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}}
void op_e0e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
	VFLG = 0;
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	CFLG=regs.x=val&1; val = (val >> 1) | sign;
	NFLG = sign != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}}
void op_e0e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 data = get_word(dataa);
	VFLG = 0;
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	CFLG=regs.x=val&1; val = (val >> 1) | sign;
	NFLG = sign != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void op_e0f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	dataa = get_disp_ea (dataa, nextiword());
{	S16 data = get_word(dataa);
	VFLG = 0;
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	CFLG=regs.x=val&1; val = (val >> 1) | sign;
	NFLG = sign != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}}
void op_e0f8(U32 opcode)
{
{{	A32 dataa = (S32)(S16)nextiword();
	S16 data = get_word(dataa);
	VFLG = 0;
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	CFLG=regs.x=val&1; val = (val >> 1) | sign;
	NFLG = sign != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void op_e0f9(U32 opcode)
{
{{	A32 dataa = nextilong();
	S16 data = get_word(dataa);
	VFLG = 0;
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	CFLG=regs.x=val&1; val = (val >> 1) | sign;
	NFLG = sign != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void op_e100(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	U32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else { 	for(;cnt;--cnt){
	CFLG=regs.x=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign)VFLG=1;
	}}
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e108(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	}
	CFLG = regs.x = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e110(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	int carry = 0;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(regs.x) val |= 1;
	regs.x = carry != 0;
	}
	CFLG = regs.x;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e118(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(carry)  val |= 1;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e120(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 cnt = regs.d[srcreg];
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	U32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else { 	for(;cnt;--cnt){
	CFLG=regs.x=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign)VFLG=1;
	}}
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e128(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 cnt = regs.d[srcreg];
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	}
	CFLG = regs.x = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e130(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 cnt = regs.d[srcreg];
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	int carry = 0;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(regs.x) val |= 1;
	regs.x = carry != 0;
	}
	CFLG = regs.x;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e138(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S8 cnt = regs.d[srcreg];
{	S8 data = regs.d[dstreg];
{	U8 val = data;
	U32 cmask = 0x80;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(carry)  val |= 1;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xff; regs.d[dstreg] |= (val) & 0xff;
}}}}}
void op_e140(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else { 	for(;cnt;--cnt){
	CFLG=regs.x=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign)VFLG=1;
	}}
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e148(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	}
	CFLG = regs.x = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e150(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = 0;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(regs.x) val |= 1;
	regs.x = carry != 0;
	}
	CFLG = regs.x;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e158(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(carry)  val |= 1;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e160(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 cnt = regs.d[srcreg];
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else { 	for(;cnt;--cnt){
	CFLG=regs.x=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign)VFLG=1;
	}}
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e168(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 cnt = regs.d[srcreg];
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	}
	CFLG = regs.x = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e170(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 cnt = regs.d[srcreg];
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = 0;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(regs.x) val |= 1;
	regs.x = carry != 0;
	}
	CFLG = regs.x;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e178(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S16 cnt = regs.d[srcreg];
{	S16 data = regs.d[dstreg];
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(carry)  val |= 1;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] &= ~0xffff; regs.d[dstreg] |= (val) & 0xffff;
}}}}}
void op_e180(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	U32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else { 	for(;cnt;--cnt){
	CFLG=regs.x=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign)VFLG=1;
	}}
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e188(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	}
	CFLG = regs.x = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e190(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	int carry = 0;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(regs.x) val |= 1;
	regs.x = carry != 0;
	}
	CFLG = regs.x;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e198(U32 opcode)
{
	U32 srcreg = imm8_table[(opcode & 3584) >> 9];
	U32 dstreg = (opcode & 7) >> 0;
{{	U32 cnt = srcreg;
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(carry)  val |= 1;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e1a0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 cnt = regs.d[srcreg];
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	U32 sign = cmask & val;
	cnt &= 63;
	VFLG = 0;
	if (!cnt) { CFLG = 0; } else { 	for(;cnt;--cnt){
	CFLG=regs.x=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign)VFLG=1;
	}}
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e1a8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 cnt = regs.d[srcreg];
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	}
	CFLG = regs.x = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e1b0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 cnt = regs.d[srcreg];
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	int carry = 0;
	cnt &= 63;
	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(regs.x) val |= 1;
	regs.x = carry != 0;
	}
	CFLG = regs.x;
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e1b8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 3584) >> 9);
	U32 dstreg = (opcode & 7) >> 0;
{{	S32 cnt = regs.d[srcreg];
{	S32 data = regs.d[dstreg];
{	U32 val = data;
	U32 cmask = 0x80000000;
	int carry = 0;
	cnt &= 63;
	if (!cnt) { CFLG = 0; } else {	for(;cnt;--cnt){
	carry=val&cmask; val <<= 1;
	if(carry)  val |= 1;
	}
	CFLG = carry!=0;
}
	NFLG = (val & cmask) != 0; ZFLG = val == 0; VFLG = 0;
	regs.d[dstreg] = (val);
}}}}}
void op_e1d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
	VFLG = 0;
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	CFLG=regs.x=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign) VFLG=1;
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void op_e1d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	regs.a[srcreg] += 2;
	VFLG = 0;
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	CFLG=regs.x=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign) VFLG=1;
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}}
void op_e1e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
	VFLG = 0;
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	CFLG=regs.x=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign) VFLG=1;
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}}
void op_e1e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 data = get_word(dataa);
	VFLG = 0;
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	CFLG=regs.x=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign) VFLG=1;
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void op_e1f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	dataa = get_disp_ea (dataa, nextiword());
{	S16 data = get_word(dataa);
	VFLG = 0;
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	CFLG=regs.x=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign) VFLG=1;
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}}
void op_e1f8(U32 opcode)
{
{{	A32 dataa = (S32)(S16)nextiword();
	S16 data = get_word(dataa);
	VFLG = 0;
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	CFLG=regs.x=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign) VFLG=1;
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void op_e1f9(U32 opcode)
{
{{	A32 dataa = nextilong();
	S16 data = get_word(dataa);
	VFLG = 0;
{	U16 val = data;
	U32 cmask = 0x8000;
	U32 sign = cmask & val;
	CFLG=regs.x=(val&cmask)!=0; val <<= 1;
	if ((val&cmask)!=sign) VFLG=1;
	NFLG = (val&cmask) != 0;
	ZFLG = val == 0;
	put_word(dataa,val);
}}}}
void op_e2d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	carry=val&1; val >>= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = regs.x = carry!=0;
	put_word(dataa,val);
}}}}
void op_e2d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	regs.a[srcreg] += 2;
{	U16 val = data;
	int carry = val&1;
	carry=val&1; val >>= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = regs.x = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e2e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	carry=val&1; val >>= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = regs.x = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e2e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	carry=val&1; val >>= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = regs.x = carry!=0;
	put_word(dataa,val);
}}}}
void op_e2f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	dataa = get_disp_ea (dataa, nextiword());
{	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	carry=val&1; val >>= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = regs.x = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e2f8(U32 opcode)
{
{{	A32 dataa = (S32)(S16)nextiword();
	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	carry=val&1; val >>= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = regs.x = carry!=0;
	put_word(dataa,val);
}}}}
void op_e2f9(U32 opcode)
{
{{	A32 dataa = nextilong();
	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	carry=val&1; val >>= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = regs.x = carry!=0;
	put_word(dataa,val);
}}}}
void op_e3d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = regs.x = carry!=0;
	put_word(dataa,val);
}}}}
void op_e3d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	regs.a[srcreg] += 2;
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = regs.x = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e3e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = regs.x = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e3e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = regs.x = carry!=0;
	put_word(dataa,val);
}}}}
void op_e3f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	dataa = get_disp_ea (dataa, nextiword());
{	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = regs.x = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e3f8(U32 opcode)
{
{{	A32 dataa = (S32)(S16)nextiword();
	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = regs.x = carry!=0;
	put_word(dataa,val);
}}}}
void op_e3f9(U32 opcode)
{
{{	A32 dataa = nextilong();
	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = regs.x = carry!=0;
	put_word(dataa,val);
}}}}
void op_e4d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	U32 cmask = 0x8000;
	val >>= 1;
	if(regs.x) val |= cmask;
	regs.x = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
regs.x = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void op_e4d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	regs.a[srcreg] += 2;
{	U16 val = data;
	int carry = val&1;
	U32 cmask = 0x8000;
	val >>= 1;
	if(regs.x) val |= cmask;
	regs.x = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
regs.x = CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e4e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	U32 cmask = 0x8000;
	val >>= 1;
	if(regs.x) val |= cmask;
	regs.x = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
regs.x = CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e4e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	U32 cmask = 0x8000;
	val >>= 1;
	if(regs.x) val |= cmask;
	regs.x = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
regs.x = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void op_e4f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	dataa = get_disp_ea (dataa, nextiword());
{	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	U32 cmask = 0x8000;
	val >>= 1;
	if(regs.x) val |= cmask;
	regs.x = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
regs.x = CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e4f8(U32 opcode)
{
{{	A32 dataa = (S32)(S16)nextiword();
	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	U32 cmask = 0x8000;
	val >>= 1;
	if(regs.x) val |= cmask;
	regs.x = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
regs.x = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void op_e4f9(U32 opcode)
{
{{	A32 dataa = nextilong();
	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	U32 cmask = 0x8000;
	val >>= 1;
	if(regs.x) val |= cmask;
	regs.x = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
regs.x = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void op_e5d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	if(regs.x) val |= 1;
	regs.x = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
regs.x = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void op_e5d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	regs.a[srcreg] += 2;
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	if(regs.x) val |= 1;
	regs.x = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
regs.x = CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e5e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	if(regs.x) val |= 1;
	regs.x = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
regs.x = CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e5e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	if(regs.x) val |= 1;
	regs.x = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
regs.x = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void op_e5f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	dataa = get_disp_ea (dataa, nextiword());
{	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	if(regs.x) val |= 1;
	regs.x = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
regs.x = CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e5f8(U32 opcode)
{
{{	A32 dataa = (S32)(S16)nextiword();
	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	if(regs.x) val |= 1;
	regs.x = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
regs.x = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void op_e5f9(U32 opcode)
{
{{	A32 dataa = nextilong();
	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	if(regs.x) val |= 1;
	regs.x = carry != 0;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
regs.x = CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void op_e6d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	U32 cmask = 0x8000;
	val >>= 1;
	if(carry) val |= cmask;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void op_e6d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	regs.a[srcreg] += 2;
{	U16 val = data;
	int carry = val&1;
	U32 cmask = 0x8000;
	val >>= 1;
	if(carry) val |= cmask;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e6e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	U32 cmask = 0x8000;
	val >>= 1;
	if(carry) val |= cmask;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e6e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	U32 cmask = 0x8000;
	val >>= 1;
	if(carry) val |= cmask;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void op_e6f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	dataa = get_disp_ea (dataa, nextiword());
{	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	U32 cmask = 0x8000;
	val >>= 1;
	if(carry) val |= cmask;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e6f8(U32 opcode)
{
{{	A32 dataa = (S32)(S16)nextiword();
	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	U32 cmask = 0x8000;
	val >>= 1;
	if(carry) val |= cmask;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void op_e6f9(U32 opcode)
{
{{	A32 dataa = nextilong();
	S16 data = get_word(dataa);
{	U16 val = data;
	int carry = val&1;
	U32 cmask = 0x8000;
	val >>= 1;
	if(carry) val |= cmask;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void op_e7d0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	if(carry)  val |= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void op_e7d8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	regs.a[srcreg] += 2;
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	if(carry)  val |= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e7e0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	regs.a[srcreg] -= 2;
{	A32 dataa = regs.a[srcreg];
	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	if(carry)  val |= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e7e8(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg] + (S32)(S16)nextiword();
	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	if(carry)  val |= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void op_e7f0(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 7) >> 0);
{{	A32 dataa = regs.a[srcreg];
	dataa = get_disp_ea (dataa, nextiword());
{	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	if(carry)  val |= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}}
void op_e7f8(U32 opcode)
{
{{	A32 dataa = (S32)(S16)nextiword();
	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	if(carry)  val |= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
void op_e7f9(U32 opcode)
{
{{	A32 dataa = nextilong();
	S16 data = get_word(dataa);
{	U16 val = data;
	U32 cmask = 0x8000;
	int carry = val&cmask;
	val <<= 1;
	if(carry)  val |= 1;
	VFLG = CFLG = 0;
	ZFLG = ((S16)(val)) == 0;
	NFLG = ((S16)(val)) < 0;
CFLG = carry!=0;
	put_word(dataa,val);
}}}}
