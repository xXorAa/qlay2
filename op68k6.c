#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "qlmem.h"
#include "exe68k.h"
#include "op68ktbl.h"
void op_6000(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
	if (cctrue(0)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6001(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
	if (cctrue(0)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6100(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
{	regs.a[7] -= 4;
{	A32 spa = regs.a[7];
	put_long(spa,m68k_getpc());
	regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}}}
void op_6101(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
{	regs.a[7] -= 4;
{	A32 spa = regs.a[7];
	put_long(spa,m68k_getpc());
	regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}}}
void op_6200(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
	if (cctrue(2)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6201(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
	if (cctrue(2)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6300(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
	if (cctrue(3)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6301(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
	if (cctrue(3)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6400(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
	if (cctrue(4)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6401(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
	if (cctrue(4)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6500(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
	if (cctrue(5)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6501(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
	if (cctrue(5)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6600(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
	if (cctrue(6)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6601(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
	if (cctrue(6)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6700(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
	if (cctrue(7)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6701(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
	if (cctrue(7)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6800(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
	if (cctrue(8)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6801(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
	if (cctrue(8)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6900(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
	if (cctrue(9)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6901(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
	if (cctrue(9)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6a00(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
	if (cctrue(10)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6a01(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
	if (cctrue(10)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6b00(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
	if (cctrue(11)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6b01(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
	if (cctrue(11)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6c00(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
	if (cctrue(12)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6c01(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
	if (cctrue(12)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6d00(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
	if (cctrue(13)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6d01(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
	if (cctrue(13)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6e00(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
	if (cctrue(14)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6e01(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
	if (cctrue(14)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6f00(U32 opcode)
{
{	char *oldpcp = (char *)regs.pc_p;
{	S16 src = nextiword();
	if (cctrue(15)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
void op_6f01(U32 opcode)
{
	U32 srcreg = (S32)(S8)((opcode & 255) >> 0);
{	char *oldpcp = (char *)regs.pc_p;
{	U32 src = srcreg;
	if (cctrue(15)) regs.pc_p = (U16 *)(oldpcp + (S32)src);
}}}
