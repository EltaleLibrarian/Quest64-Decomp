#include "common.h"
#include "328F0.h"
#include "1850.h"

void func_8003232C(s32);
void func_80032020(s32);

void func_80031CF0(u16 arg0, u8* arg1) {

    if (arg0 >= 1000) {
        arg0 = 999;
    }
    arg1[0] = (arg0 / 100) + (arg0 >= 100) + 15;
    arg1[1] = ((arg0 % 100) / 10) + (arg0 >= 10) + 15;
    arg1[2] = (arg0 % 10) + 16;
}

#define TILE_ROW(arg) (((arg) & 0xF8) * 0xC)
#define TILE_COL(arg) (((arg) & 7) * 8)

#define ROW_OFFSET(arg) ((TILE_ROW(arg) / 2) * 8)
#define COL_OFFSET(arg) ((TILE_COL(arg) / 2))

#define TEXTURE_ADDR(base, arg) ((u8*)((ROW_OFFSET(arg) + COL_OFFSET(arg)) + (s32)(base)))

void func_80031DD4(s32 arg0) {
    u8 temp_t7;
    u16 *var_a0;
    s32 i, j;
    s32 var_v0;
    u32* var_a1;
    if (arg0 == 1) {
        D_80092D30 += 3;
        return;
    }
    
    if (arg0 == 0xA) {
        D_80092D36 += 0xD;
        func_80031F1C(D_80092D34, D_80092D36);
        return;
    }
    
    if ((arg0 < 0xF) || (D_80092CC0 < arg0)) {
        arg0 = 0x3B;
    }
    
    arg0 -= 0xF;  
    var_a0 = D_80092D30;

    var_a1 = (u32*)TEXTURE_ADDR(D_8006E4C0, arg0);

    for (i = 0; i < 0xC; i++) {
        for (j = 0x1C; j >= 0; j -= 4) {
            temp_t7 = ((*var_a1) >> j) & 0xF;
            if (temp_t7 != 0) {
                *var_a0 = (D_8006F3F8[temp_t7]);
            }
            var_a0++;
        }
        var_a0 += 0x138;
        var_a1 += 0x8;
    }
    D_80092D30 += 9;
}

void func_80031F1C(s16 arg0, s16 arg1) {
    D_80092D34 = arg0;
    D_80092D36 = arg1;
    D_80092D30 = (u16*)((arg0 + arg1 * 0x140) * 2 + (s32)D_80092D20); //TODO: fix D_80092D20 type
}

void func_80031F74(u8* arg0) {
    while (*arg0 != 0) {
        func_80031DD4(*arg0++);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/328F0/func_80031FBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/328F0/func_80032020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/328F0/func_80032040.s")

void func_80032040(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8* arg4, s32 arg5, u8 arg6);

//writing this as a normal for loop causes an instruction to occur too early
void func_80032218(unk32218s* arg0, s32 arg1) {
    s32 var_s1;
    unk32218s* var_s0;

    var_s1 = 0;
    if (arg1 > 0) {
        var_s0 = arg0;
        do {
            func_80032040(var_s0->unk0, var_s0->unk2, var_s0->unk4, var_s0->unk5, var_s0->unk8, var_s0->unkC, 2);
            var_s1++;
            var_s0++;
        } while (var_s1 != arg1);
    }
}

void func_8003228C(void) {
    osWritebackDCacheAll();
    osRecvMesg(D_80092D28, &D_80092D2C, 1);
    if (D_80092D1C != 0) {
        osViSwapBuffer(D_8006E4B8[D_8006E4B4 & 1]);
        D_80092D20 = D_8006E4B8[++D_8006E4B4 & 1]; 
        D_80092D1C = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/328F0/func_8003232C.s")

void func_80032560(u16 arg0) {
    u8 sp1C[3];

    func_80032020(1);
    func_80031CF0(arg0, sp1C);
    func_80031F1C(0xC8, 0xAD);
    func_80031FBC(sp1C, 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/328F0/func_800325A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/328F0/func_800325FC.s")

void func_8003265C(void) {
    s32 i;

    func_80032218(&D_8006CC88, 0xF0);
    func_80032560(D_80092D1A);

    if (gPakMenuScroll != 0) {
        func_80032218(&D_8006E288, 1);
    }

    if (gPakMenuScroll < 0xA) {
        func_80032218(&D_8006E298, 1);
    }

    for (i = 0; i < 6; i++) {
        func_8003232C(i);
    }
    D_80092D1C = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/328F0/func_80032704.s")
