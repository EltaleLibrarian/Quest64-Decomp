#include "common.h"
#include "10C80.h"

//s32 D_80085B68[4][3];


/*This C file contains functions relating to mostly lighting, and time of day.*/

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_80010080.s")

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_800100D0.s")
/*void func_800100D0(void) {
    s32 i;
    gCurrentTime = 0x1EC3;
    gDayLength = 0x6978;
    gCurrentDay = 1;
    D_8008C634 = 7;
    for (i = 0; i < 4; i++) {
        D_80085B68[i][0] = 0;
        D_80085B68[i][1] = 0;
        D_80085B68[i][2] = 0;
    }
}*/

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_80010150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_800102D0.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_80010510.s")
void func_80010510(s32 arg0) {

    gCurrentTime = arg0;
    if (gDayLength <= gCurrentTime) {
        gCurrentTime = gCurrentTime - gDayLength;
        if (gCurrentDay < 9999) {
            gCurrentDay++;
            }
    }
    D_800859D8 = gCurrentTime;
}

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_80010564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_80010B58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_80010CAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_80010E70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_80010EC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_800110D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_80011100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_80011150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_80011170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_800111A4.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_800111D8.s")
void func_800111D8(s32 arg0, s32 arg1) {
    D_80085A14[arg0].unk0[0] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_800111F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/10C80/func_80011768.s")
