#include "common.h" 

typedef struct unk26658_s{
    u8 unk0;
    s8 unk1;
    u8 unk2;
}unk26658s;

extern unk26658s D_8008FCC8[];
extern s8 D_80053CA4;
extern s8 D_8005F010;
extern u8 D_80053CAC[70];
extern u8 D_8008FCC6;
extern s8 D_8008FCC0;
extern s8 D_8008FCC1; //ID of current BGM
extern u16 D_8008FCC2; //non-zero value restarts/plays BGM
extern u16 D_8008FCC4; //amount of delay before BGM start

void func_800252D8(s32, s32);
void func_80025364(s32);

#pragma GLOBAL_ASM("asm/nonmatchings/bgm/func_800265F0.s")

void func_80026658(void) {
    unk26658s* var_s0;
    s32 i;
    u8 temp;

    if ((D_8008FCC2 & 1) != 0) {
        if (D_8008FCC4 == 0) {
            if (D_8008FCC0 != -1) {
                D_8008FCC2 = D_8008FCC2 | 2;
            } else {
                D_8008FCC2 = D_8008FCC2 | 4;
            }
            D_8008FCC2 = D_8008FCC2 & ~0x1;
        } else {
            D_8008FCC4--;
        }
    }
    if (D_8008FCC2 & 2) {
        D_8008FCC2 = D_8008FCC2 & 0xFFFD;
        D_8008FCC2 = D_8008FCC2 | 4;
        func_800253F0(0);
    } else if ((D_8008FCC2 & 4) && !(func_8002543C(0))) {
        D_8008FCC2 &= ~0x4;
        D_8008FCC0 = D_8008FCC1;
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

#pragma GLOBAL_ASM("asm/nonmatchings/bgm/UpdateBGM.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bgm/func_800267F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bgm/func_8002684C.s")

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
    func_80026554(*(&D_80053CA4 + D_8005F010));
}