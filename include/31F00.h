#ifndef _31F00_H_
#define _31F00_H_
#include "os.h"
s32 osPfsInitPak(OSMesgQueue *mq,  OSPfs *pfs,  int controller_no);
s32 __osGetID(OSPfs *pfs);


extern OSPfs gPFS[];
extern s8 gCurrControllerNum;
extern OSMesgQueue gSIMessageQ;

extern OSMesgQueue D_80092880;
extern OSContPad D_80092AA8;
extern s8 D_80092871;
extern s8 D_80092872;
extern u16 D_80092874;
extern u16 D_80092876;
extern u16 D_80092878;


#endif
