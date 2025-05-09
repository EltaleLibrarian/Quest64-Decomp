#include "common.h"

extern OSMesgQueue D_8008F288;

//loads an overlay
void func_80024690(s32 devAddr, void* vAddr, s32 nbytes) {
    OSIoMesg sp28;

    osInvalDCache(vAddr, nbytes);
    osPiStartDma(&sp28, 0, 0, devAddr, vAddr, nbytes, &D_8008F288);
    osRecvMesg(&D_8008F288, NULL, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80024704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800248C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80024A48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80024B1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80024BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800250E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_8002513C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800252D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800253F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_8002543C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_8002568C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800256D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_8002571C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800258F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80025E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80026214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800262F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_800263A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80026434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80026488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_8002650C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/25290/func_80026554.s")
