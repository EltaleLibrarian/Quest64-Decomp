#ifndef _ANIMATION_H_
#define _ANIMATION_H_

typedef struct s_Animation {
/*0x00*/    PosRot posrot;
/*0x18*/    Vec3f speed_or_direction;
/*0x24*/    f32 scale;
/*0x28*/    f32 collision_scale;
/*0x2C*/    Vec3f shadowRot;
/*0x38*/    f32 unk38;
/*0x3C*/    f32 unk3C;
/*0x40*/    f32 unk40;
/*0x44*/    f32 unk44;
/*0x48*/    f32 unk48;
/*0x4C*/    f32 unk4C;
/*0x50*/    s16 unk50;
/*0x52*/    s16 currentAnimID;
/*0x54*/    u16 currentAnimFrameNum;
/*0x56*/    u16 totalAnimFrames;
/*0x58*/    u16 animFramerate;
/*0x5A*/    s16 unk5A;
/*0x5C*/    u16 unk5C;
/*0x5E*/    u16 unk5E;
/*0x60*/    u16 unk60;
/*0x62*/    u16 unk62;
/*0x64*/    void* unk64; //points to beginning of actor using this struct. 
}TransformAnim;

#endif
