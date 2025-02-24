#include "macros.h"
#include "PR/os_version.h"
#include "PR/os_internal.h"
#include "PR/R4300.h"
#include "PR/rcp.h"
#include "piint.h"

OSPiHandle __CartRomHandle ALIGNED(8);

OSPiHandle* osCartRomInit(void) {
    u32 domain = 0;
    u32 saveMask;

    if (__CartRomHandle.baseAddress == PHYS_TO_K1(PI_DOM1_ADDR2))
        return &__CartRomHandle;

    __CartRomHandle.type = DEVICE_TYPE_CART;
    __CartRomHandle.baseAddress = PHYS_TO_K1(PI_DOM1_ADDR2);
    osPiRawReadIo(NULL, &domain);
    __CartRomHandle.latency = domain & 0xff;
    __CartRomHandle.pulse = (domain >> 8) & 0xff;
    __CartRomHandle.pageSize = (domain >> 0x10) & 0xf;
    __CartRomHandle.relDuration = (domain >> 0x14) & 0xf;
    __CartRomHandle.domain = PI_DOMAIN1;
    __CartRomHandle.speed = 0;

    _bzero(&__CartRomHandle.transferInfo, sizeof(__OSTranxInfo));

    saveMask = __osDisableInt();
    __CartRomHandle.next = __osPiTable;
    __osPiTable = &__CartRomHandle;
    __osRestoreInt(saveMask);

    return &__CartRomHandle;
}
