#include "common.h"
#include "31F00.h"

#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_800314C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_8003195C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_800319E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031A44.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031ACC.s")
/*initializes devices such as the rumble pak and the controller pak and returns an error ID if there is one.*/
s32 initPFSPaks(s32 arg0, s32 arg1)
{
    s32 con_error;
    u32 con_num;
  
  
  con_num = gCurrControllerNum;
  if (arg1 == 0xA)
  {
    if (osMotorInit(&gSIMessageQ, &gPFS[con_num], con_num) != 0)
    {
      con_error = osPfsInitPak(&gSIMessageQ, &gPFS[con_num], con_num);
      if (((con_error != PFS_ERR_DEVICE) && (con_error != PFS_ERR_NOPACK)) && (con_error != PFS_ERR_NEW_PACK))
      {
        con_error = __osGetID(&gPFS[con_num]);
      }
    }
    else
    {
      con_error = 4;
    }
  }
  else
  {
    con_error = osPfsInitPak(&gSIMessageQ, &gPFS[con_num], con_num);
  }
  return con_error;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031BB0.s")
s32 func_80031BB0(s32 arg0) {
    s32 var_v1;

    switch (arg0) {
    case PFS_ERR_NOPACK:
        var_v1 = -1;
        break;
    case PFS_ERR_CONTRFAIL:
    case PFS_ERR_DEVICE:
        var_v1 = -2;
        break;
    case PFS_ERR_INCONSISTENT:
    case PFS_ERR_ID_FATAL:
        var_v1 = -3;
        break;
    case PFS_ERR_NEW_PACK:
        var_v1 = -4;
        break;
    case PFS_ERR_EXIST:
        var_v1 = -5;
        break;
    default:
        var_v1 = -6;
        break;
    }
    return var_v1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031C0C.s")
