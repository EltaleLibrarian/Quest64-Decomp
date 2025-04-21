#include "common.h"

typedef struct {
    PosRot posrot;
    f32 scale;
}ActorShadows;

extern ActorShadows gActorShadows[64];
extern u32 gNumShadowsToDrawThisFrame;

void ResetShadowCount(void);
void PositionActorShadow(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);

void ResetShadowCount(void) {
    gNumShadowsToDrawThisFrame = 0;
}

void PositionActorShadow(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    ActorShadows* this_shadow;

    if (gNumShadowsToDrawThisFrame < 0x40U) {        
        this_shadow = &gActorShadows[gNumShadowsToDrawThisFrame++];
        this_shadow->posrot.pos.x = arg0;
        this_shadow->posrot.pos.y = arg1;
        this_shadow->posrot.pos.z = arg2;
        this_shadow->posrot.rot.x = arg3;
        this_shadow->posrot.rot.y = arg4;
        this_shadow->posrot.rot.z = arg5;
        this_shadow->scale = arg6;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/shadow/func_800118D4.s")
