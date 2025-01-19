#ifndef _31F00_H_
#define _31F00_H_
#include "os.h"
s32 osPfsInitPak(OSMesgQueue *mq,  OSPfs *pfs,  int controller_no);
s32 __osGetID(OSPfs *pfs);


extern OSPfs gPFS[];
extern s8 gCurrControllerNum;
extern OSMesgQueue gSIMessageQ;

extern OSMesgQueue D_80092880;
extern OSContPad gPad;
extern s8 gPadStickX;
extern s8 gPadStickY;
extern u16 gPadButtonPressed;
extern u16 D_80092876;
extern u16 D_80092878;


#endif
