#include "common.h"
#include "33D0.h"
#include "10C80.h"
#include "1850.h"

#define NO_PAK 1
#define CONTROLLER_FAILURE 2
#define PAK_FAILURE 3
#define PAK_NEW 4
#define PAK_FILE_EXIST 5

typedef struct {
    s8 unk0;
    s8 unk1;
}struct_8008FD30;

typedef struct SaveData {
    /* 0x00 */ PlayerMainStats playerStats;
    /* 0x38 */ u16 unk38;                           /* inferred */
    /* 0x3A */ u16 curDay;                           /* inferred */
    /* 0x3C */ s32 nextMap;                           /* inferred */
    /* 0x40 */ s32 nextSubMap;                           /* inferred */
    /* 0x44 */ s32 unk44;                           /* inferred */
    /* 0x48 */ s32 unk48;                           /* inferred */
    /* 0x4C */ s32 unk4C;                           /* inferred */
    /* 0x50 */ s32 unk50;                           /* inferred */
    /* 0x54 */ s32 unk54;                           /* inferred */
    /* 0x58 */ s32 unk58;                           /* inferred */
    /* 0x5C */ s16 unk5C;                           /* inferred */
    /* 0x5E */ u16 unk5E;                           /* inferred */
    /* 0x60 */ s16 unk_60;
    /* 0x60 */ s8 unk_62;
    /* 0x60 */ s8 unk_63;
} SaveData;

typedef struct Unk4 {
    char unk_00[0x20];
    char unk_20[0x10];
    char unk_30[0x97];
    char unk_C7[1];
} Unk4; //sizeof 0xC8

extern struct_8008FD30 D_8008FD30;

extern u16 D_8008FD0C;
extern u8 D_8005FAA0[]; //Display List
extern u16 D_8008FD20;
extern s8 D_8008FD22;
extern s32 gControllerPakError;
extern u8 D_8008FD28;
extern s8 D_8008FD29;
extern s8 gSelectedSaveSlot;
extern s8 D_8008FD2B;
extern u8 D_8008FD2C;
extern s8 D_8008FD31[];
extern s8 gCurrControllerNum;
extern s32 D_80084EF8;
extern SaveData D_8008FD58[16];
extern s32 D_80084EFC;
extern s32 D_80084F00;
extern s32 D_80084F08;
extern s8 gMessageSpeed;
extern s32 D_80084F0C;
extern s8 D_8005F010;
extern Unk4 D_80090398;
extern u8 D_800869D8[0x20];
extern u8 D_80086AE8[0x10];
extern u8 D_8007D19C[1];



void func_8002DF6C(void);
void func_8002DFD0(void);
s32 func_8003195C(s8, u8);
void func_80029B58(s32, s32, s32, s32, s32);

//external
s32 func_80031BB0(s32 arg0);
s32 initPFSPaks(s32 arg0, s32 arg1);

//#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002B510.s")
void func_8002B510(s32 arg0) {
    gGameMode = 2;
    D_8008FD0C = D_8008FD0C | arg0 | 0x4000;
    D_8008FD20 = 0x1000;
    D_8008FD28 = 0xFF;
    gSelectedSaveSlot = 0;
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
    

    temp_v0 = func_8003195C(gCurrControllerNum, (&D_8008FD30)[gSelectedSaveSlot].unk1);
    if (temp_v0 != 0) {
        gControllerPakError = temp_v0;
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
        (&D_8008FD30)[gSelectedSaveSlot].unk1 = -1;
    }
   
}

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002D748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002D8BC.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002DBE0.s")
void func_8002DBE0(void) {
    s32 error;
    s32 error_type;

    rmonPrintf("Repair Info %d %d\n", gSelectedSaveSlot, gControllerPakError);
    error = initPFSPaks((s32) (&D_8008FD30)[gSelectedSaveSlot].unk0, gControllerPakError);
    if (error) {
        gControllerPakError = error;
        error_type = -func_80031BB0(error);
        switch (error_type) {
            case NO_PAK:
                D_8008FD22 = 0x8;
                D_8008FD29 = 0xA;
                break;
            case PAK_FAILURE:
                D_8008FD22 = 0x10;
                D_8008FD29 = 0xA;
                break;
            default:
                D_8008FD22 = 0x11;
                D_8008FD29 = 0xA;
                break;
        }
        
        D_8008FD20 &= 0xFFF8;
        D_8008FD20 &= 0xBFFF;
        D_8008FD20 |= 0x1000;
    } else {
        D_8008FD20 &= 0xDFFF;
        D_8008FD20 &= 0xFFF8;
        D_8008FD20 &= 0xBFFF;
        D_8008FD20 |= 0x1000;
        D_8008FD2C++;
    }
}

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

//#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002E234.s")

void func_8002E234(s32 arg0) {
    SaveData* temp_a2;
    s32 i;
    u8* ptr1;
    u8* ptr2;

    temp_a2 = &D_8008FD58[arg0];
    temp_a2->playerStats = gPlayerMainData.playerStats;
    temp_a2->unk38 = D_800859E2;
    temp_a2->curDay = gCurrentDay;
    temp_a2->nextMap = gNextMap;
    temp_a2->nextSubMap = gNextSubmap;
    temp_a2->unk44 = D_80084EF8;
    temp_a2->unk48 = D_80084EFC;
    temp_a2->unk4C = D_80084F00;
    temp_a2->unk50 = D_80084F04;
    temp_a2->unk54 = D_80084F08;
    temp_a2->unk58 = D_80084F0C;
    temp_a2->unk5C = D_8007BA60;
    temp_a2->unk5E = D_8007BA62;
    temp_a2->unk_60 = D_8007BA64;
    temp_a2->unk_62 = gMessageSpeed;
    temp_a2->unk_63 = D_8005F010;
    
    ptr1 = D_80090398.unk_00;
    ptr2 = D_800869D8;
    for (i = 0x20; i != 0; i--) {
        *ptr1++ = *ptr2++;
    }
    
    ptr1 = D_80090398.unk_20;
    ptr2 = D_80086AE8;
    for (i = 0x10; i != 0; i--) {
        *ptr1++ = *ptr2++;
    }
    
    ptr1 = D_80090398.unk_30;
    ptr2 = gInventory;
    for (i = sizeof(gInventory) + 1; i != 0; i--) {
        *ptr1++ = *ptr2++;
    }
    
    ptr1 = D_80090398.unk_C7;
    ptr2 = D_8007D19C;
    for (i = 1; i != 0; i--) {
        *ptr1++ = *ptr2++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/2C110/func_8002E404.s")
