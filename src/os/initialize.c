#include "common.h"

//TODO: is the MHz on the right correct?
#define OS_VI_NTSC_CLOCK  0x02E6D354  // 48.625 MHz
#define OS_VI_PAL_CLOCK   0x02F5B2D2  // 49.656 MHz
#define OS_VI_MPAL_CLOCK  0x02E6025C  // 48.681 MHz

#define	OS_CLOCK_RATE		62500000LL
#define	OS_CPU_COUNTER		(OS_CLOCK_RATE*3/4)

#define PI_DOM2_ADDR1 0x05000000  /* to 0x05FFFFFF */
#define PI_DOM2_DD   (PI_DOM2_ADDR1+0x508)

#define	OS_TV_PAL		0
#define	OS_TV_NTSC		1
#define	OS_TV_MPAL		2

typedef struct
{
   /* 0x0 */ unsigned int inst1;
   /* 0x4 */ unsigned int inst2;
   /* 0x8 */ unsigned int inst3;
   /* 0xC */ unsigned int inst4;
} __osExceptionVector;
extern __osExceptionVector __osExceptionPreamble;

OSTime osClockRate = 0x0000000003B9ACA0;
u32 osViClock = OS_VI_NTSC_CLOCK; //?
u32 D_8006F40C = 0;
OSIntMask __OSGlobalIntMask = 0x003FFF01;
s32 __osShutdown = 0;
u32 __osFinalrom;    //= 0; | bss

void __createSpeedParam(void);
s32 __osGetHWIntrRoutine();

void __osInitialize_common(void) {
    u32 pifdata;
    u32 sp38 = 0;

    __osFinalrom = TRUE;

    __osSetSR(__osGetSR() | SR_CU1);    //enable fpu
    __osSetFpcCsr(FPCSR_FS | FPCSR_EV); //flush denorm to zero, enable invalid operation

    while (__osSpRawReadIo(PIF_RAM_END - 3, &pifdata)) { //last byte of joychannel ram
        ;
    }
    while (__osSpRawWriteIo(PIF_RAM_END - 3, pifdata | 8)) {
        ; //todo: magic contant
    }
    *(__osExceptionVector *)UT_VEC = __osExceptionPreamble;
    *(__osExceptionVector *)XUT_VEC = __osExceptionPreamble;
    *(__osExceptionVector *)ECC_VEC = __osExceptionPreamble;
    *(__osExceptionVector *)E_VEC = __osExceptionPreamble;
    osWritebackDCache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
    osInvalICache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
    __createSpeedParam();
    osPiRawReadIo(4, &sp38);
    sp38 &= ~0x0F;
    
    if (sp38) {
        osClockRate = sp38;
    }
    osClockRate = osClockRate * 3 / 4;

    if (osResetType == 0) { // cold reset
        _bzero(osAppNMIBuffer, OS_APP_NMI_BUFSIZE);
    }
    
    if (osTvType == OS_TV_PAL) {
        osViClock = OS_VI_PAL_CLOCK;     
    } else if (osTvType == OS_TV_MPAL) {
        osViClock = OS_VI_MPAL_CLOCK;   
    } else { //OS_TV_NTSC
        osViClock = OS_VI_NTSC_CLOCK;
    }
}
