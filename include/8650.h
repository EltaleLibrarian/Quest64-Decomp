#ifndef _8650_H_
#define _8650_H_

#include <animation.h>

typedef struct {
    char unk0[0x2];
    s16 unk2;
    char unk4[0xA];
    s16 unkE;
}NPCData3;

typedef struct {
    char unk0[0x4];
    u8 unk4;
    char unk5[0xB];
    NPCData3* unk10;
    u8* NPCName;
    u16 unk18;
}NPCData2;

typedef struct {
/*0x00*/u16 action;
/*0x02*/u16 actionTimer;
/*0x04*/f32 xWanderOrigin; //xpos of a point a wandering NPC can't stray too far from.  
/*0x08*/f32 zWanderOrigin; //zpos of a point a wandering NPC can't stray too far from. 
/*0x0C*/f32 yRotReturn; //yRotation to return to when done speaking. 
/*0x10*/f32 unk10; //changes based on where Brian speaks to the NPC from. Current purpose unknown. 
/*0x14*/TransformAnim transformationAnimation;
/*0x78*/char unk78[4];
/*0x80*/NPCData2* NPCData2;    
}NPCData;




extern u8 gMessageBuffer[0x400];
extern u8 gNPCName[0x20];
extern NPCData gNPCData[0x10];

void func_80007F18(Mtx* arg0);
void LoadNPCName(NPCData* arg0, s32 arg1);
void func_80008AD8(s32 arg0, u8 *arg1);
#endif 

