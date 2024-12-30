#include <rcp.h>

#pragma GLOBAL_ASM("asm/nonmatchings/os/O1/aigetlen/osAiGetLength.s")
/*
Anything using IO_READ has problems right now. 

u32 osAiGetLength(void)
{
    return IO_READ(AI_LEN_REG);
}*/