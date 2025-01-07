#ifndef _1850_H
#define _1850_H

#include "nnsched.h"

#ifndef _UINTPTR_T
    #define _UINTPTR_T
    typedef unsigned            uintptr_t;
#endif

typedef struct {
    NNScTask task;
    char unk58[0xD0F0];
    OSMesg unkD148;
    void *unkD14C; 
}unk111Cs;

//unsorted symbols
extern s32 gGameState;
extern u16 gGameMode;
extern s32 gNextMap;
extern s32 gNextSubmap;
extern s32 D_80084EF8;
extern s32 D_80084F04;
extern u16 D_80084F14;
extern f32 D_80086E44;
extern s16 D_800859E2;
extern u32 gCurrentMap;
extern s32 gCurrentSubmap;
extern s32 D_80085370;
extern s16 D_8007BA60;
extern u16 D_8007BA62;
extern u16 D_8007B2E8;
extern s16 D_8007B2F0;
extern s8 D_8007B344;
extern s8 D_8007B345;
extern s32 D_8007B348;
extern f32 D_8007BA40;
extern f32 D_8007BA44;
extern f32 D_8007BA48;
extern s32 D_8007BA4C;
extern s16 D_8007BA64;

extern OSMesgQueue D_8007B320;
extern s32 D_8007B338;
extern u8 D_E7E800[0x2E10];
extern u8 D_EEE020[0x1CC0];
extern u8 D_EBABD0;
extern s32 Instrument_tbl_ROM_START[2];
extern u8 D_EEFCE0;
extern NNSched D_8007B358;
extern s32 D_80000300;
extern OSViMode D_8006F4F0;
extern OSViMode D_8006FDB0;
extern OSMesgQueue gSIMessageQ;
extern OSMesgQueue D_8007B3CC;
extern OSMesgQueue D_8007B9E8;
extern void* D_8007BA00;
extern NNScClient D_8007B9E0;
extern OSMesgQueue* D_8007B9D8;
extern s8 D_8008FD0E;
extern s32 D_8007B2F4;
extern s32 D_8007B2F8;
extern u8 D_80301000[][0xD150];




//functions
void func_80000EEC(void);
void func_80000FE8(void);

void func_80001800(void);
void func_800020B4(void);
void func_8000227C(void);
void func_80002428(void);
void func_800025E8(void);

//Most prototypes past here DO NOT belong in this header. Make sure to migrate and include as needed. 
void func_800027D0(void);
void func_8000B520(void);
void func_800100D0(void);
void func_80011B40(void);
void func_800121F0(void);
void func_80024704(void);
void func_800250E8(NNSched*);
void func_8002513C(s32 arg0, s32 arg1, u8* arg2, s32 arg3, u8* arg4);
void func_80025488(u32 arg0, s32 arg1, u8* arg2);
void func_80026A40(void);
s32 func_80031300(void);
u8 func_80032704(OSMesgQueue* arg0, OSMesgQueue* arg1); //return type may be wrong. 
#endif
