#ifndef _191F0_H_
#define _191F0_H_

typedef struct {
/*0x00*/ Vec3f* targetPos;
/*0x04*/ u8 damageDigits[8];
/*0x0C*/ u16 damageDisplayTimer;
/*0x0E*/ char unkE[2];
/*0x10*/ s32 unk10;
/*0x14*/ s32 numDigits;
/*0x18*/ s32 unk18;    
}DamageDigs; // size = 0x1C

extern DamageDigs D_800873D0[10];

void func_80018DF4(Vec3f* arg0, s32 arg1, s32 arg2); 

#endif
