#ifndef _33D0_H_
#define _33D0_H_

//structs
typedef struct {
    u16 map;
    u16 submap;
    f32 x;
    f32 z;
    f32 yrot;
}SaveSpawnLocation;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u16 unkC;
    char unkE[2];
    s32 unk10;
    f32 unk14;
}unk80085368;

typedef struct {
    s32 start;
    s32 end;
}fileBounds;

typedef struct PlayerMainData{
    u16 unk0;
    s16 unk2;
    u16 currHP;
    u16 maxHP;
    u16 currMP;
    u16 maxMP;
    u16 agi;
    u16 def;
    s32 exp;
    s32 stone; //unused currency. Name derived from beta screenshots. 
    f32 collisionSize;
    f32 unk1C; //height? 160.0f by default. Lowering it makes numbers appear lower when brian takes damage, and rocks come out of his chest.
    f32 unk20; //also affects collision size. May be zCollisionSize and the above are X and Y.
    u8 elements[4];
    u16 HPXP;
    u16 MPXP;
    u16 agiXP;
    u16 defXP;
    u8 HPLevel;
    u8 MPLevel;
    u8 agiLevel;
    u8 defLevel;
    u8 spiritLevel;
    u8 unk35;
    u8 unk36;
    u8 unk37;
    u16 unk38;
    s16 unk3A;
    s16 unk3C;
    s16 unk3E;
    u16 unk40;
    s16 unk42;
    f32 unk44;
    struct PlayerMainData* next;
}PlayerMainData;
typedef struct {
             PosRot posrot;
             Vec3f speed;
             f32 scale;
             f32 shadowScale;
             Vec3f shadowRot;
             f32 unk38;
             f32 unk3C;
             f32 unk40;
             f32 unk44;
             f32 unk48;
             f32 unk4C;
             s16 unk50;
             s16 currentAnimID;
             u16 currentAnimFrame;
             u16 totalAnimFrames;
             u16 animFramerate;
             s16 unk5A;
             u16 unk5C;
             s16 unk5E;
             u16 unk60;
             u16 unk62;
             PlayerMainData* playerMainData;
             void* playerStatusPtr;
             u8 status[7];
    TransformAnim transformAnim;
    PlayerMainData* playerMainData;
    void* playerStatusPtr;
    u8 status[7];
}PlayerPosData;

//symbols
extern SaveSpawnLocation gSaveSpawnLocationTbl[17];
extern unk80085368 D_80085368;
extern PlayerMainData gPlayerMainData;
extern PlayerPosData gPlayerData1;
extern fileBounds D_80053F58[];




//functions
void func_80002EA0(void);
void func_80003870(Mtx* arg0);
#endif
