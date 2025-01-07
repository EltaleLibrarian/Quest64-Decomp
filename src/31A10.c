#include "common.h"
#include "24E60.h"
#include "31A10.h"

#pragma GLOBAL_ASM("asm/nonmatchings/31A10/func_80030E10.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/31A10/func_80030E58.s") //load_text_graphics
void func_80030E58(void) {
    dma_write(&D_D3E240, &D_80331A30, 0x80U);
    dma_write(&D_D3E2C0, &D_803232A0, 0xE790U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/31A10/func_80030EA0.s")
