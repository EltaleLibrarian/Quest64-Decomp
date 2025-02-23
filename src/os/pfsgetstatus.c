#include "common.h"
#include "controller.h"
#include "siint.h"

void __osPfsRequestOneChannel(int channel);
void __osPfsGetOneChannelData(int channel, OSContStatus* data);

s32 __osPfsGetStatus(OSMesgQueue* queue, int channel) {
    s32 ret = 0;
    OSMesg dummy;
    OSContStatus data;

    __osPfsRequestOneChannel(channel);

    ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
    osRecvMesg(queue, &dummy, OS_MESG_BLOCK);

    ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
    osRecvMesg(queue, &dummy, OS_MESG_BLOCK);

    __osPfsGetOneChannelData(channel, &data);

    if (((data.status & CONT_CARD_ON) != 0) && ((data.status & CONT_CARD_PULL) != 0)) {
        return PFS_ERR_NEW_PACK;
    } else if ((data.errno != 0) || ((data.status & CONT_CARD_ON) == 0)) {
        return PFS_ERR_NOPACK;
    } else if ((data.status & CONT_ADDR_CRC_ER) != 0) {
        return PFS_ERR_CONTRFAIL;
    }

    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/os/pfsgetstatus/__osPfsRequestOneChannel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/os/pfsgetstatus/__osPfsGetOneChannelData.s")
