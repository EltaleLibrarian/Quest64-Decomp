#include "common.h"

extern u16 D_8008FD0C;
extern u8 D_8005FAA0[]; //Display List
extern u16 D_8008FD20;
extern s8 D_8008FD22;
extern s32 D_8008FD24;
extern u8 D_8008FD28;
extern s8 D_8008FD29;
extern s8 D_8008FD2A;
extern s8 D_8008FD2B;
extern s8 D_8008FD2C;
extern s16 gGameMode;
extern s8 D_8008FD31[];
extern s8 gCurrControllerNum;


void func_8002DF6C(void);
void func_8002DFD0(void);
s32 func_8003195C(s8, u8);
void func_80029B58(s32, s32, s32, s32, s32);

//#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002B510.s")
void func_8002B510(s32 arg0) {
    gGameMode = 2;
    D_8008FD0C = D_8008FD0C | arg0 | 0x4000;
    D_8008FD20 = 0x1000;
    D_8008FD28 = 0xFF;
    D_8008FD2A = 0;
    D_8008FD29 = 0;
    D_8008FD22 = 0;
    D_8008FD2B = 0;
    D_8008FD2C = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002B57C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002B6F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002B8C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002BCA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002C818.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002D5D4.s")
void func_8002D5D4(void) {

    D_8008FD29 -= 1;
    if (D_8008FD29 < 0) {
        D_8008FD20 &= ~7;
        D_8008FD20 = D_8008FD20;
    }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002D614.s")
void func_8002D614(void) {
    s32 temp_v0;
    s32 temp_v1;
    

    temp_v0 = func_8003195C(gCurrControllerNum, *&D_8008FD31[D_8008FD2A * 2]);
    if (temp_v0 != 0) {
        D_8008FD24 = temp_v0;
        switch (-func_80031BB0(temp_v0)) {
            case 1:
            D_8008FD22 = 8;
            D_8008FD29 = 0xA;
            break;
                
            case 4:
            D_8008FD22 = 0xC;
            D_8008FD29 = 0xA;
            break;
                
            default:
            D_8008FD22 = 0x11;
            D_8008FD29 = 0xA;
            break;
        }

        D_8008FD20 &= ~7 ;
        D_8008FD20 |= 5;
        D_8008FD20 &= ~0x2000;
    } else {
        D_8008FD20 &= ~7 ;
        D_8008FD20 |= 5;
        D_8008FD20 &= ~0x2000;
        D_8008FD22 = 0x16;
        D_8008FD29 = 0xA;
        D_8008FD31[D_8008FD2A * 2] = -1;
    }
   
}

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002D748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002D8BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002DBE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002DD18.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002DF6C.s")
void func_8002DF6C(void) {

    gSPDisplayList(gMasterGfxPos++, D_8005FAA0);
    gDPSetTextureLUT(gMasterGfxPos++, G_TT_RGBA16);
    D_8008FD0C &= 0xFFEF;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002DFD0.s") //draws the save/load screen backgrounds. 
void func_8002DFD0(void) {
    func_80029B58(0, 0x3C, 0x22, 0xC8, 0xAB);
    func_80029B58(0x37, 0x3F, 0xCE, 0xC8, 3);
    func_80029B58(0x37, 0x105, 0x28, 2, 0xA9);
    func_80029B58(0x37, 0x3B, 0x21, 0xCA, 1);
    func_80029B58(0x37, 0x3B, 0xCD, 0xCA, 1);
    func_80029B58(0x37, 0x3B, 0x21, 1, 0xAD);
    func_80029B58(0x37, 0x104, 0x21, 1, 0xAD);
    func_80029B58(0x38, 0x3D, 0x23, 0xC5, 1);
    func_80029B58(0x38, 0x3D, 0x23, 1, 0xA8);
    func_80029B58(0x39, 0x3D, 0xCB, 0xC6, 1);
    func_80029B58(0x39, 0x102, 0x23, 1, 0xA9);
    func_80029B58(0x3F, 0x5A, 0x2E, 0x96, 2);
    func_80029B58(0x3F, 0x5A, 0x44, 0x96, 2);
    func_80029B58(0x3F, 0x5A, 0x7B, 0x96, 2);
    func_80029B58(0x3F, 0x5A, 0x91, 0x96, 2);
    func_80029B58(0x42, 0x5E, 0x67, 0x7C, 0xC);
    func_80029B58(0x42, 0x5E, 0xB5, 0x7C, 0xC);
    func_80029B58(0x46, 0x55, 0x58, 0x14, 0xE);
    func_80029B58(0x47, 0xA2, 0x58, 0x18, 0xE);
    func_80029B58(0x46, 0x55, 0xA6, 0x14, 0xE);
    func_80029B58(0x47, 0xA2, 0xA6, 0x18, 0xE);
}

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002E234.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002E404.s")
