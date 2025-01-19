#include "common.h"
s32 func_801000A8_ovl_title();                      /* extern */
extern s32 D_8011AD44;

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_80100000_ovl_title.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_8010004C_DA693C.s")
s32 func_8010004C_DA693C(void) {
    if (func_801000A8_ovl_title() == 0) {
        if (D_8011AD44 == 0) {
            return 1;
        }
        if (D_8011AD44 == 0xF) {
            D_8011AD44 = 0;
            return 0;
        }
        goto block_5;
    }
block_5:
    return 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_801000A8_ovl_title.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_801006D8_ovl_title.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_80100B14_ovl_title.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_80100BA0_ovl_title.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_80102E30_ovl_title.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_80102F14_ovl_title.s")
