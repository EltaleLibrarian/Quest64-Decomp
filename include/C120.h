#ifndef _C120_H_
#define _C120_H_

typedef struct {
    char unk0[0x24];
    f32 bossX;
    f32 bossY;
    f32 bossZ;
}unkD_7D1A8s;

typedef struct {
    /* 0x00 */ u16 bossMap;
    /* 0x02 */ u16 bossSubmap;
    /* 0x04 */ u16 bossNumber;
    /* 0x06 */ u16 unk6; //possibly padding
    /* 0x08 */ void* modelVram;
    /* 0x0C */ f32 x;
    /* 0x10 */ f32 y;
    /* 0x14 */ f32 z;
}BossData;

typedef struct {
    s32 fileStart;
    s32 fileEnd;
}bossFile;

extern u8 D_8007D19C[];
extern BossData gBossData[];
extern s32 D_8007D1A0; //boss cutscene model loaded when !=0
extern unkD_7D1A8s D_8007D1A8; //boss position data
extern void* gBossVAddr; //Virtual address boss files are placed at
extern bossFile gBossFileOffsetTbl[]; //ptr to boss file ROM addresses
extern u8 D_8004D740[];

void func_8000B7DC(s32, f32, f32, f32, void*);
u32 func_8000B9D8(u32 arg0);
void func_8000B618(Mtx* arg0);


#endif
