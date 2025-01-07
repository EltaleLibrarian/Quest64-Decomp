#ifndef _328F0_H_
#define _328F0_H_

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 unk4;
    u8 unk5;
    s8 unk6;
    s8 unk7;
    s32 unk8;
    s32 unkC;    
}unk32218s;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
}unk31cf0s;


extern unk32218s D_8006CC88;
extern unk32218s D_8006E288;
extern unk32218s D_8006E298;
extern s32 D_8006E4B4;
extern void* D_8006E4B8[];
extern u8* D_8006E4C0[]; //alphabet texture
extern u8 gPakMenuScroll;
extern s32 D_80092CC0;
extern u16 D_80092D1A;
extern s32 D_80092D1C;
extern s32 D_80092D20;
extern OSMesgQueue* D_80092D28;
extern void* D_80092D2C;
extern s32 D_80092D30;
extern s16 D_80092D34;
extern s16 D_80092D36;

//may be a struct, not a u16*
extern u16* D_8006F3F8;



void func_80031CF0(u16 arg0, s8* arg1);
void func_80031DD4(s32 arg0);
void func_80031F1C(s16 arg0, s16 arg1);
void func_80031F74(u8* arg0);
//func_80031FBC
//func_80032020
//func_80032040
void func_80032218(unk32218s* arg0, s32 arg1);
void func_8003228C(void);
//func_8003232C
void func_80032560(u16 arg0);
//func_800325A8
//func_800325FC
void func_8003265C(void);
//func_80032704
#endif
