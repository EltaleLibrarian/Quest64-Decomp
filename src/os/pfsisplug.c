#include "common.h"
#include "controller.h"
#include "PR/os_internal.h"

s32 osPfsIsPlug(OSMesgQueue *queue, u8 *pattern)
{
    s32 ret;
    OSMesg dummy;
    u8 bitpattern;
    OSContStatus data[MAXCONTROLLERS];
    int channel;
    u8 bits;
    int crc_error_cnt;
    ret = 0;
    bits = 0;
    crc_error_cnt = 3;
    __osSiGetAccess();
    while (TRUE)
    {
        __osPfsRequestData(CONT_CMD_REQUEST_STATUS);
        ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
        osRecvMesg(queue, &dummy, OS_MESG_BLOCK);
        ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
        osRecvMesg(queue, &dummy, OS_MESG_BLOCK);
        __osPfsGetInitData(&bitpattern, data);
        for (channel = 0; channel < __osMaxControllers; channel++)
        {
            if ((data[channel].status & CONT_ADDR_CRC_ER) == 0)
            {
                crc_error_cnt--;
                break;
            }
        }
        if (__osMaxControllers == channel)
            crc_error_cnt = 0;
        if (crc_error_cnt < 1)
        {
            for (channel = 0; channel < __osMaxControllers; channel++)
            {
                if (data[channel].errno == 0 && (data[channel].status & CONT_CARD_ON) != 0)
                    bits |= 1 << channel;
            }
            __osSiRelAccess();
            *pattern = bits;
            return ret;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/os/pfsisplug/__osPfsRequestData.s")

#pragma GLOBAL_ASM("asm/nonmatchings/os/pfsisplug/__osPfsGetInitData.s")
