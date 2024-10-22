#ifndef _31F00_H_
#define _31F00_H_
#include "os.h"
s32 osPfsInitPak(OSMesgQueue *mq,  OSPfs *pfs,  int controller_no);
s32 __osGetID(OSPfs *pfs);


extern OSPfs gPFS[];
extern s8 gCurrControllerNum;
extern OSMesgQueue gSIMessageQ;


#endif
