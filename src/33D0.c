#include "common.h"
#include "1850.h"
#include "33D0.h"
#include "24E60.h"
#include "bgm.h"
#include "el_math.h"

#define TAU 2 * M_PI

typedef struct {
    char unk0[0x10];
    f32 currentAngle;
    char unk14[4];
    f32 pitch;
    char unk1C[4];
    f32 roll;
    char unk24[0x3C];
    u16 flags;
}TurnState;

typedef struct {
    s16 unk0;
    char unk2[2];
    u16 countdown;
    char unk6[0x11A];
    u16 unk120;
    char unk122[6];
    f32 unk128;
    f32 unk12C;
    f32 targetAngle;
    f32 unk134;
}TurnTimer;

typedef struct {
    /*0x00*/ Vec3f pos;
    /*0x0C*/ f32 yrot;
    /*0x10*/ f32 zrot;
    /*0x14*/ f32 xrot;
    /*0x18*/ Vec3f scale;
    /*0x24*/ f32 unk24;
    /*0x28*/ f32 unk28;
    /*0x2C*/ f32 unk2C;
    /*0x30*/ s16 unk30; //maybe padding. 
    /*0x32*/ u16 startingFrame;
    }LimbKeyframe;
    
    typedef struct {
        LimbKeyframe* unk0; //pointer to an array
        u16 unk4;
        u16 numFramesInAnim;
        f32 unk8;
        f32 unkC;
        f32 unk10;
        s8 unk14;
        s8 unk15;
        u8 unk16;
        char unk17; //unread?
        s32 unk18;
        char unk1C[4];
    }unk22b40s;
    
    typedef struct AnimationData {
        s16 numOfPartsToLoad;
        s16 animationTotalFrameCount;
        unk22b40s* unk_04;
        void* unk_08;
    } AnimationData;


    typedef struct {
        s16 unk0;
        char unk2[2];
        s16 unk4;
    }struct_69FC;

    typedef struct {
        s32 unk0;
        s32 unk4;
        u16 unk8;
        char unkA[2];
        f32 unkC;
        f32 unk10;
        f32 unk14;
        char unk18[0x10];
        f32 unk28;
        f32 unk2C;
        char unk30[4];
        f32 unk34;
        char unk38[4];
        f32 unk3C;
        f32 unk40;
        f32 unk44;
        f32 unk48;
        f32 unk4C;
        char unk50[4];
        f32 unk54;
        f32 unk58;
        f32 unk5C;
        f32 unk60;
        f32 unk64;
        f32 unk68;
        f32 unk6C;
        f32 unk70;
        char unk74[4];
        f32 unk78;
        f32 unk7C;
        s32 unk80;
        f32 unk84;
    }struct_80086DC0;

    

    void func_80005748(u16, TurnState*, TurnTimer*);         /* extern */
    void func_80004E58(f32, f32, TurnState*, TurnTimer*);  /* extern */
    void rotateCoordinatesByAngle(f32 angle, Coordinates2D* coordinates);
    void func_800056D0(TransformAnim* arg0, AnimationData* arg1, Coordinates2D* arg2);
    void func_8001D924(TransformAnim*, AnimationData*, f32); /* extern */
    void func_80006720(TransformAnim*);   

    extern s32 D_8007BC2C;
    extern u16 D_8008C594;
    extern u16 gBattleState;
    extern Coordinates2D D_8007BC30;
    extern struct_80086DC0 D_80086DC0;



#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_800027D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80002918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80002EA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80002F60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80003870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80003A1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80003B60.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80003F5C.s")
void func_80003F5C(TurnState* state, TurnTimer* timer, AnimationData* unusedArg) {
    u16 temp_t7;

    state->roll = 0.0f;
    state->pitch = 0.0f;
    timer->countdown--;
    if (!timer->countdown) {
        timer->unk0 = 0;
        state->flags = (u16) (state->flags & 0xFFFC);
    }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80003F98.s")
void func_80003F98(TurnState* arg0, TurnTimer* arg1, AnimationData* arg2) {

    func_80005748(0xA01U, arg0, arg1);
    arg0->pitch = (f32) (arg0->pitch * 0.68);
    arg0->roll = (f32) (arg0->roll * 0.68);
    arg1->countdown--;
    if (!arg1->countdown) {
        arg1->unk0 = 0;
        arg0->roll = 0.0f;
        arg0->pitch = 0.0f;
        arg0->flags &= 0xFFFE;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80004040.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_800041B4.s")
void func_800041B4(TransformAnim* arg0, TurnTimer* arg1, AnimationData* arg2) {

    func_800056D0(arg0, arg2, &D_8007BC30);
    arg0->speed_or_direction.x = D_8007BC30.x;
    //something wrong here with D_8007BC30. 
    arg0->speed_or_direction.z = D_8007BC30.y;
    func_80005748(0xA01U, (TurnState* ) arg0, arg1);
    arg1->countdown--;
    if  (arg1->countdown == arg1->unk120) {
        D_80086DC0.unk4C = 250.0f;
        D_80086DC0.unk58 = 150.0f;
        D_80086DC0.unk70 = 0.01f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80004260.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_800043C4.s")
void func_800043C4(TurnState* arg0, TurnTimer* arg1, AnimationData* arg2) {

    func_80004E58(arg1->unk128, arg1->unk12C, arg0, arg1);
    func_80005748(0xA01U, arg0, arg1);
    arg1->countdown--;
    if (!arg1->countdown) {
        arg1->unk0 = 0;
        arg0->roll = 0.0f;
        arg0->pitch = 0.0f;
        arg0->flags &= 0xFFFE;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80004448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_800045F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80004708.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_800048D0.s")
void func_800048D0(TurnState* arg0, TurnTimer* arg1, AnimationData* arg2) {

    func_800056D0((TransformAnim* ) arg0, arg2, &D_8007BC30);
    arg0->pitch = D_8007BC30.x;
    arg0->roll = D_8007BC30.y;
    func_80005748(0xA00U, arg0, arg1);
    arg1->countdown--;
    if (!arg1->countdown) {
        arg1->unk0 = 0;
        arg0->flags &= 0xFFFE;
        arg0->currentAngle = arg1->unk134;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_8000496C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80004AB8.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80004BD0.s")
void func_80004BD0(TurnState* state, TurnTimer* timer, AnimationData* unusedArg) {
    f32 deltaAngle;
    
    state->roll = 0.0f;
    state->pitch = 0.0f;
    
    if (timer->countdown < 0x26) {
        deltaAngle = (timer->targetAngle - state->currentAngle);
        if (deltaAngle < -M_PI) {
            deltaAngle += TAU;
        } else if (deltaAngle > M_PI) {
            deltaAngle -= TAU;
        }
        
        state->currentAngle += deltaAngle * 0.2;

        if (state->currentAngle < -M_PI) {
            state->currentAngle += TAU;
        } else if (state->currentAngle > M_PI) {
            state->currentAngle -= TAU;
        }
    }
    
    timer->countdown--;
    if (!timer->countdown) {
        timer->unk0 = 0;
        state->flags &= -4;
        GetMapBGM(gNextMap, gNextSubmap, 0x1EU);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80004D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80004E58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_8000534C.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_800056D0.s")
void func_800056D0(TransformAnim* arg0, AnimationData* arg1, Coordinates2D* arg2) {
    func_80006720(arg0);
    func_8001D924(arg0, &arg1[arg0->currentAnimID], arg0->scale);
    arg2->x = -arg0->unk44;
    arg2->y = arg0->unk4C;
    rotateCoordinatesByAngle(arg0->posrot.rot.y, arg2);
}

void func_80005740(void) {
    return;
}

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80005748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80005A10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80005C6C.s")
//https://decomp.me/scratch/VFBkm

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_8000600C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_800060D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80006340.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80006604.s")
void func_80006604(struct_69FC* arg0, TransformAnim* arg1, AnimationData* arg2) {
    func_8001D8B0(arg1, 0x1C, 1, 0x1D, 1, 1U);
    func_80006720(arg1);
    func_8001D924(arg1, &arg2[arg1->currentAnimID], arg1->scale);
    arg0->unk0 = 0xB;
    arg0->unk4 = 0x5A;
    arg1->unk60 |= 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_8000669C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80006720.s")

/*
void func_80006720(TransformAnim* arg0) {
    s32 start;
    s32 size;
    fileBounds* fb;
    static s32 D_8004C270 = 0; // or could be .bss

    if (D_8004C270 != arg0->currentAnimID) {

        D_8004C270 = arg0->currentAnimID;
        
        fb = &D_80053F58[D_8004C270];      
        
        start = fb->start;
        size = fb->end - start;      
        
        dmaLoadFromROM(start, 0x80200000, size);
    }
}
*/
#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80006774.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_800069FC.s")
void func_800069FC(struct_69FC* arg0, TransformAnim* playerAnim, s32 arg2) {
    arg0->unk0 = 0xD;
    arg0->unk4 = 0x14;
    playerAnim->unk60 |= 1;
    func_8001D8B0(playerAnim, 0xA, 1, D_8007BC2C, 1, 1U);
    func_800140EC(0x23, playerAnim);
}

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80006A74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80006B1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80006BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80006F6C.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_80007030.s")
s32 func_80007030(s32 arg0, TransformAnim* arg1) {
    s32 ret;

    ret = 0;
    if (!(arg1->unk60 & 1) && !(gGameState & 0x80)) {
        if (gBattleState & 1) {
            if (!(gBattleState & 0x202)) {
                ret = 0;
                if ((func_80015B50() == 0) && (D_8008C594 == 0)) {
                    ret = 1;
                }
            }
        } else {
            ret = 1;
        }
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_800070C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_800072A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_800073CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/33D0/func_800074A0.s")
//https://decomp.me/scratch/bSlb6