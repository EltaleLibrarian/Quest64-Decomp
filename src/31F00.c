#include "common.h"
#include "31F00.h"

typedef struct Unk3 {
    s16 unk_00;
    s8 unk_02[0x10];
    s8 unk_12;
    u8 unk_13;
} Unk3;

extern s32		osContInit(OSMesgQueue *, u8 *, OSContStatus *);
extern s32		osContSetCh(u8);                                   /* extern */
extern void		osCreateMesgQueue(OSMesgQueue *, OSMesg *, s32);
extern void		osSetEventMesg(OSEvent, OSMesgQueue *, OSMesg);

s32 osMotorInit(OSMesgQueue* mq, OSPfs* pfs, int channel);
s32 osPfsFreeBlocks(OSPfs *pfs, s32 *bytes_not_used);
s32 osPfsReadWriteFile(OSPfs *pfs, s32 file_no, u8 flag, int offset, int nbytes, u8 * data_buffer);
extern s32 osPfsDeleteFile(OSPfs *, u16, u32, u8 *, u8 *);


extern u16 D_80092878;
extern Unk3 D_80092A38[4];
extern u8 D_8005FB40[];
extern s32 D_8005FB74;
extern OSPfs gPFS[];
extern u8 D_80092A88;
extern OSContStatus D_80092A90[4];
extern OSMesg D_80092AA0;

//#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031300.s")
s32 func_80031300(void) {
    s32 var_a2;
    OSContStatus* cont;
    s32 var_t4;
    s32 i;
    
    var_t4 = 0;
    D_80092878 = 0;
    for (i = 0; i < 4; i++) {
        D_80092A38[i].unk_12 = -128;
    }

    for (i = 0; i < 4; i++) {
        gPad[i].button = 0;
        gPad[i].stick_x = 0;
        gPad[i].stick_y = 0;
    }

    osCreateMesgQueue(&gSIMessageQ, &D_80092AA0, 1);
    osSetEventMesg(5, &gSIMessageQ, &D_80092AA0);
    osContInit(&gSIMessageQ, &D_80092A88, &D_80092A90[0]);
    osContSetCh(4);
    gCurrControllerNum = -1;
    var_a2 = 0;
    for (i = 0; i < 4; i++) {
        if (D_80092A88 & (1 << i)) {
            cont = &D_80092A90[i];
            if (cont->errno & 4) {
                D_80092A38[i].unk_12 = -1;
            } else if (cont->type & 2) {
                D_80092A38[i].unk_12 = -2;
            } else {
                D_80092A38[i].unk_12 = 0;
                var_a2 += 1;
                if (gCurrControllerNum == -1) {
                    gCurrControllerNum = i;
                }
                if (cont->status & 1) {
                    D_80092A38[i].unk_00 |= 0x8000;
                } else {
                    D_80092A38[i].unk_00 = 0;
                    if (i == gCurrControllerNum) {
                        var_t4 = 1;
                    }
                }
            }
        } else {
            D_80092A38[i].unk_12 = -3;
        }
    }
    if (var_a2 == 0) {
        return -1;
    }
    return var_t4;
}

void func_800314C0(s32 cont) {
    OSContPad* pad;
    u16 button;

    osContSetCh(4U);
    osContStartReadData(&gSIMessageQ);
    if (osRecvMesg(&gSIMessageQ, NULL, 1) != -1) {
        osContGetReadData(gPad);
    }
    pad = &gPad[cont];
    button = pad->button;
    gPadButtonPressed = button;
    gPadStickX = pad->stick_x;
    gPadStickY = pad->stick_y;
    D_80092876 = button & D_80092878;
    D_80092878 = ~button;
}

#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031574.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031800.s")
u8 func_80031800(s32 arg0) {
    s32 var_a0;
    s32 var_v0;
    s32 var_v1;

    var_v0 = -1; //fake, is assigned to 0 right after. var_v1 is what needs to be assigned the -1
    var_v1 = var_v0;
    do {
        var_v1 += 1;
        var_v0 = 0;
        var_a0 = 0;
        for (; var_v0 < 16; var_v0++) {
            if ((var_v1 + 0x1A) == D_80092A38[arg0].unk_02[var_v0]) {
                var_a0 = -1;
                break;
            }
        }

        if ((var_v1 >= 0x10) && (var_a0 != 0)) {
            var_a0 = -1;
            break;
        } 

    } while (var_a0 == 0);
    
    if (var_a0 == 0) {
        var_a0 = (var_v1 + 0x1A);
    }
    return var_a0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031890.s")
/* bss shenanigans

u8 func_80031890(s32 arg0, u8 arg1) {
    s32 temp_v0;
    s32 file_no;
    u8 ext_name[] = {0, 0, 0, 0}; //D_8005FB70
    
    s32 var_v1;

    file_no = -1;
    ext_name[0] = arg1;
    temp_v0 = osPfsAllocateFile(&gPFS[arg0], 0x3738U, 0x4E455445U, &D_8005FB40, ext_name, 0x200, &file_no);
    
    if (temp_v0 == 0) {
        var_v1 = file_no;
        D_80092A38[arg0].unk_02[var_v1] = arg1;
    } else {
        var_v1 = -temp_v0;
    }
    return var_v1;
}
*/
#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_8003195C.s")

/* Won't match until bss things happen
u8 func_8003195C(s32 arg0, u8 arg1) {
    s32 temp;
    u8 sp20[] = {0, 0, 0, 0}; //D_8005FB74
    sp20[0] = arg1;
    
    return osPfsDeleteFile(&gPFS[arg0], 0x3738, 0x4E455445, D_8005FB40, sp20);
}
*/

s32 func_800319E0(s32 pfsIndex, s32 file_no, s32 offset, s32 nbytes, u8* data_buffer) {
	osPfsReadWriteFile(&gPFS[pfsIndex], file_no, PFS_READ, offset, nbytes, data_buffer);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031A44.s")
s32 func_80031A44(s32 pfsFileNum, s32 arg1, s32 arg2, s32 arg3, u8* arg4) {
    s32 ret;
    s32 pfsBytesNotUsed;

    ret = osPfsFreeBlocks(&gPFS[pfsFileNum], &pfsBytesNotUsed);
    if (ret != 0) {
        return ret;
    }
    return osPfsReadWriteFile(&gPFS[pfsFileNum], arg1, 1, arg2, arg3, arg4);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031ACC.s")
/*initializes devices such as the rumble pak and the controller pak and returns an error ID if there is one.*/
s32 initPFSPaks(s32 arg0, s32 arg1)
{
    s32 con_error;
    u32 cont;
  
  
  cont = gCurrControllerNum;
  if (arg1 == 0xA)
  {
    if (osMotorInit(&gSIMessageQ, &gPFS[cont], cont) != 0)
    {
      con_error = osPfsInitPak(&gSIMessageQ, &gPFS[cont], cont);
      if (((con_error != PFS_ERR_DEVICE) && (con_error != PFS_ERR_NOPACK)) && (con_error != PFS_ERR_NEW_PACK))
      {
        con_error = __osGetID(&gPFS[cont]);
      }
    }
    else
    {
      con_error = 4;
    }
  }
  else
  {
    con_error = osPfsInitPak(&gSIMessageQ, &gPFS[cont], cont);
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


//#pragma GLOBAL_ASM("asm/nonmatchings/31F00/func_80031C0C.s")
s32 func_80031C0C(u8* str0, u8* str1, s32 size) {
  do {
      if (*str0++ != *str1++) {
          break;
      }
  } while(size--);

  return size;
}