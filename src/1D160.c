#include "common.h"
#include "el_math.h"
#include "1850.h"
#include "33D0.h"
#include "1D160.h"
typedef struct {
    s16 min_x;
    s16 min_z;
    s16 width;
    s16 depth;
    char pack_ids[0x10];
}EncounterRegion;
typedef struct {
    EncounterRegion* regions;
    s32 total_regions;
}AreaRegionDefinitions;


void func_8001C560(void) { //!TODO This fuction has 2 likely errors. The global variables are likely structs of some sort. 
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

//#pragma GLOBAL_ASM("asm/nonmatchings/1D160/func_8001D474.s")
void* func_8001D474(f32 brian_x, f32 brian_z, AreaRegionDefinitions* arg2) {
    s32 region_count;
    EncounterRegion* region;

    region = NULL;
    if (arg2 != NULL) {
        region_count = arg2->total_regions;
        region = arg2->regions;
        
        while (region_count != 0) {
            if (!(region->min_x <= brian_x) || !(region->min_z <= brian_z) || !((brian_x - region->min_x) <= region->width) || !((brian_z - region->min_z) <= region->depth)) {
                region_count--;
                region++;
            } else {
                break;
            }
        }
        if (region_count == 0) {
            region = NULL;
        }
    }
    return region;
}

#pragma GLOBAL_ASM("asm/nonmatchings/1D160/func_8001D538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1D160/func_8001D640.s")

void func_8001D820(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/1D160/func_8001D828.s")
