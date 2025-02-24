#include "common.h"

extern s32 D_8011AD34;
extern u8 D_80103138_ovl_title[];
extern s32 D_80103420_ovl_title;
extern s32 D_80103424_ovl_title;
extern s32 D_8011AD30;
extern s32 D_8011AD38;
extern s32 D_8011AD3C;
extern s32 D_8011AD40;
extern s32 gTitleTimeoutTimer;

void func_80100000_ovl_title(void);
s32 func_801000A8_ovl_title(void);
void func_80100BA0_ovl_title(s32);

void func_80100000_ovl_title(void) {
    D_8011AD30 = 0;
    gTitleTimeoutTimer = 0;
    D_80103424_ovl_title = 1;
    D_80103420_ovl_title = 0;
    D_8011AD34 = 1;
    D_8011AD3C = 0;
    D_8011AD40 = 8;
    D_8011AD38 = 0;
}

s32 func_8010004C_DA693C_ovl_title(void) {
    if (func_801000A8_ovl_title() == 0) {
        if (gTitleTimeoutTimer == 0) {
            return 1;
        }
        if (gTitleTimeoutTimer == 0xF) {
            gTitleTimeoutTimer = 0;
            return 0;
        }
    }
    return 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_801000A8_ovl_title.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_801006D8_ovl_title.s")

void func_80100B14_ovl_title(void) {
    gSPDisplayList(gMasterGfxPos++, D_80103138_ovl_title);
    gDPSetEnvColor(gMasterGfxPos++, 0x00, 0x00, 0x00, 0xFF);
    
    func_80100BA0_ovl_title(gTitleTimeoutTimer);
    if (--D_8011AD34 == 0) {
        gTitleTimeoutTimer = 0xF;
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_80100BA0_ovl_title.s")
//https://decomp.me/scratch/0t25M

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_80102E30_ovl_title.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/title/DA68F0/func_80102F14_ovl_title.s")
