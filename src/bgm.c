#include "common.h"

typedef struct unk26658_s{
    u8 unk0;
    s8 unk1;
    u8 unk2;
}unk26658s;

extern unk26658s D_8008FCC8;
extern s8 D_80053CA4;
extern s8 D_8005F010;
extern u8 D_80053CAC[70];
extern u8 D_8008FCC6;

extern u8 func_80026554(u8);

#pragma GLOBAL_ASM("asm/nonmatchings/bgm/func_800265F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bgm/func_80026658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bgm/UpdateBGM.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bgm/func_800267F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/bgm/func_8002684C.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/bgm/func_800268D4.s")
void func_800268D4(u8 arg0, s8 arg1, u8 arg2) {
    s32 var_v0;
    s32 temp_t2;
    unk26658s* var_v1;

    temp_t2 = (u32) ((D_80053CAC)[arg1] * (arg2) * D_8008FCC6) / 65536;
    if (arg0 == 0) {
        func_80025B8C(arg1, temp_t2, 0x40);
    } else {   
        var_v0 = 0xF;
        var_v1 = &D_8008FCC8;
    
        while (var_v0 != 0 && var_v1->unk0 != 0) {
            var_v0--;
            var_v1++;
        }
        
        var_v1->unk0 = arg0;
        var_v1->unk1 = arg1;
        var_v1->unk2 = temp_t2;
    }
    
}

//#pragma GLOBAL_ASM("asm/nonmatchings/bgm/func_8002699C.s")
void func_8002699C(s8 arg0, u8 arg1) {
    u32 result = D_80053CAC[arg0] * arg1 * D_8008FCC6;
    result >>= 16;
    func_80025B8C(arg0, result, 0x40);
}   

//#pragma GLOBAL_ASM("asm/nonmatchings/bgm/func_80026A04.s")
void func_80026A04(void) {
    func_80026554(*(&D_80053CA4 + D_8005F010));
}