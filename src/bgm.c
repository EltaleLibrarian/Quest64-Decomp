#include "common.h"

typedef struct unk26658_s{
    u8 unk0;
    s8 unk1;
    u8 unk2;
}unk26658s;

typedef struct MapBGM_s{
    s16 map;
    s16 submap;
    s8 bgm;
    s8 pad;
}MapBGM;

extern unk26658s D_8008FCC8[];
extern s8 D_80053CA4[8];
extern s8 D_8005F010;
extern u8 D_80053CAC[70];
extern u8 D_8008FCC6;
extern s8 D_8008FCC0;
extern s8 gCurrentBGM; //ID of current BGM
extern u16 gPlayBGM; //non-zero value restarts/plays BGM
extern u16 gBGMDelay; //amount of delay before BGM start
extern MapBGM gMapBGMTable[];

void func_800252D8(s32, s32);
void func_80025364(s32);

//#pragma GLOBAL_ASM("asm/nonmatchings/bgm/func_800265F0.s")
void func_800265F0(void) {
    s32 i;
    unk26658s* tmp;

    gPlayBGM = 0;
    gBGMDelay = 0;
    gCurrentBGM = -1;
    D_8008FCC0 = gCurrentBGM;
    D_8008FCC6 = 0xFF;

    i = 0x10;
    tmp = D_8008FCC8;
    while(i > 0) {
        tmp->unk0 = 0;
        tmp++;
        i--;
    }
}

void func_80026658(void) {
    unk26658s* var_s0;
    s32 i;
    u8 temp;

    if ((gPlayBGM & 1) != 0) {
        if (gBGMDelay == 0) {
            if (D_8008FCC0 != -1) {
                gPlayBGM = gPlayBGM | 2;
            } else {
                gPlayBGM = gPlayBGM | 4;
            }
            gPlayBGM = gPlayBGM & ~0x1;
        } else {
            gBGMDelay--;
        }
    }
    if (gPlayBGM & 2) {
        gPlayBGM = gPlayBGM & 0xFFFD;
        gPlayBGM = gPlayBGM | 4;
        func_800253F0(0);
    } else if ((gPlayBGM & 4) && !(func_8002543C(0))) {
        gPlayBGM &= ~0x4;
        D_8008FCC0 = gCurrentBGM;
        if (D_8008FCC0 != -1) {
            func_800252D8(0, D_8008FCC0);
            func_80026A04();
            func_80025364(0);
        }
    }
    
    i = 16;
    var_s0 = &D_8008FCC8[0];
    
    for (i; i > 0; i--) {
        if (var_s0->unk0) {
            if (!--var_s0->unk0) {
                func_80025B8C(var_s0->unk1, var_s0->unk2, 64);
            }
        }
        var_s0++;
    }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/bgm/UpdateBGM.s")
void UpdateBGM(s8 newBGM) {
    if (newBGM != gCurrentBGM) {
        gCurrentBGM = newBGM;
        gPlayBGM |= 1;
    }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/bgm/func_800267F8.s")
void UpdateBGMDelay(s8 newBGM, u16 delay) {
    if (newBGM != gCurrentBGM) {
        gCurrentBGM = newBGM;
        gPlayBGM |= 1;
        gBGMDelay = delay & 0xFFFF;
    }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/bgm/GetMapBGM.s")
void GetMapBGM(s32 nextMap, s32 nextSubmap, u16 delay) {
    s32 mapNum;
    MapBGM* bgmData;
    
    bgmData = gMapBGMTable;
    
    for (mapNum = 0x46; mapNum != 0; mapNum--) {
        if ((nextMap == bgmData->map) && ((nextSubmap == bgmData->submap) || (bgmData->submap == -1))) {
            break;
        }
        bgmData++;
    }
    if (mapNum != 0) {
        if (gCurrentBGM != bgmData->bgm) {
            gCurrentBGM = bgmData->bgm;
            gPlayBGM |= 1;
            gBGMDelay = delay;
        }
    }
}

void func_800268D4(u8 arg0, s8 arg1, u8 arg2) {
    s32 var_v0;
    s32 temp_t2;
    unk26658s* var_v1;

    temp_t2 = (u32) ((D_80053CAC)[arg1] * (arg2) * D_8008FCC6) / 65536;
    if (arg0 == 0) {
        func_80025B8C(arg1, temp_t2, 0x40);
    } else {   
        var_v0 = 0xF;
        var_v1 = D_8008FCC8;
    
        while (var_v0 != 0 && var_v1->unk0 != 0) {
            var_v0--;
            var_v1++;
        }
        
        var_v1->unk0 = arg0;
        var_v1->unk1 = arg1;
        var_v1->unk2 = temp_t2;
    }
    
}

void func_8002699C(s8 arg0, u8 arg1) {
    u32 result = D_80053CAC[arg0] * arg1 * D_8008FCC6;
    result >>= 16;
    func_80025B8C(arg0, result, 0x40);
}   

void func_80026A04(void) {
    func_80026554(D_80053CA4[D_8005F010]);
}