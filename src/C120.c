#include "common.h"
#include "1850.h"
#include "C120.h"
#include "24E60.h"

//#pragma GLOBAL_ASM("asm/nonmatchings/C120/func_8000B520.s")
void func_8000B520(void) {
    *D_8007D19C = 0;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/C120/func_8000B530.s")
void func_8000B530(void)
{
  s32 fileStart;
  s32 fileEnd;
  int i;
  s32 fileSize;
  BossData *data;
  D_8007D1A0 = 0;
    
  for (i = 0; i < 8; i++)
  {
    data = &gBossData[i];
    if ((gNextMap == data->bossMap) && (gNextSubmap == data->bossSubmap))
    {
      if (func_8000B9D8(i) == 0)
      {
        fileStart = gBossFileOffsetTbl[data->bossNumber].fileStart;
        fileEnd = gBossFileOffsetTbl[data->bossNumber].fileEnd;
        fileSize = fileEnd - fileStart;
        dmaLoadFromROM((u8*)fileStart, &gBossVAddr, fileSize); //load boss file from RAM
        func_8000B7DC(i, data->x, data->y, data->z, &D_8007D1A8);
        D_8007D1A0 = i + 1;
      }
      return;
    }
  }

}

#pragma GLOBAL_ASM("asm/nonmatchings/C120/func_8000B618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C120/func_8000B740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C120/func_8000B7DC.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/C120/func_8000B9D8.s")
u32 func_8000B9D8(u32 arg0) {
    return D_8007D19C[arg0 >> 3] & 0xFF & D_8004D740[arg0 & 7];
}

//#pragma GLOBAL_ASM("asm/nonmatchings/C120/func_8000BA0C.s")
void func_8000BA0C(u16 arg0) {
    D_8007D19C[arg0 >> 3] |= D_8004D740[arg0 & 7];
}

#pragma GLOBAL_ASM("asm/nonmatchings/C120/func_8000BA4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/C120/func_8000BB68.s")
