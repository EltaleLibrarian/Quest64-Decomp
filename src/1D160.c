#include "common.h"
#include "el_math.h"
#include "1850.h"
#include "33D0.h"
#include "1D160.h"

//#pragma GLOBAL_ASM("asm/nonmatchings/1D160/func_8001C560.s") 
void func_8001C560(void) {
    gBattleState &= 0x8000;
    D_8008C574 = 0.0f;
    D_8008C578 = 0;
    if (gAllowBattles & 1) {
        if (gMapDataPtr->unk30 != NULL) {
            D_8008C560 = (s32) &gMapDataPtr->unk30[gNextSubmap];
            D_8008C564 = (s32) &gMapDataPtr->unk34[gNextSubmap];
            return;
        }
        D_8008C560 = 0;
        D_8008C564 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/1D160/func_8001C5F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1D160/func_8001C8C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1D160/func_8001CACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1D160/func_8001CFE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1D160/func_8001D358.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1D160/func_8001D474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1D160/func_8001D538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1D160/func_8001D640.s")

void func_8001D820(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/1D160/func_8001D828.s")
