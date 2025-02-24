#include "PR/os_internal.h"
#include "assert.h"
#include "siint.h"

s32 __osSiRawStartDma(s32 direction, void* dramAddr) {
    assert(((u32)dramAddr & 0x3) == 0);

    if (__osSiDeviceBusy()) {
        return -1;
    }

    if (direction == OS_WRITE) {
        osWritebackDCache(dramAddr, 64);
    }

    IO_WRITE(SI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));

    if (direction == OS_READ) {
        IO_WRITE(SI_PIF_ADDR_RD64B_REG, PIF_RAM_START);
    } else {
        IO_WRITE(SI_PIF_ADDR_WR64B_REG, PIF_RAM_START);
    }

    if (direction == OS_READ) {
        osInvalDCache(dramAddr, 64);
    }

    return 0;
}
