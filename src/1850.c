#include "common.h"
#include "1850.h"
#include "map_ids.h"
#include "33D0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_80000C50.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_80000EEC.s")
void func_80000EEC(void) {
    gGameState = 0x160;
    gGameMode = 4;
    gNextMap = -1;
    D_80084EF8 = -1;
    D_80084F04 = -1;
    D_80084F14 = 0xFFFF;
    D_80086E44 = 0.0f;
    D_800859E2 = 0;
    gCurrentMap = MAP_MONASTERY;
    gCurrentSubmap = SUBMAP_ABBOTS_CHAMBER;
    D_80085368.unk8 = -1;
    D_8007BA60 = 0xD;
    D_8007BA62 = 0x11;
    D_8007BA64 = 0;
    D_8007BA40 = -26.0f;
    D_8007BA44 = 0.0f;
    D_8007BA48 = M_PI/2;
    D_8007BA4C = 0x108;
    gPlayerMainData.unk3E = 0;
    D_8007B2E8 = 1;
    D_8007B2F0 = 0;
    D_8007B344 = 0;
    D_8007B345 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_80000FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_8000111C.s")
//unsure how to get this working in this build, because of D_80049FC0 and D_80049FC0_2 being at the same address. 
/*void func_8000111C(unk111Cs* arg0) {
    arg0->task.list.t.type = M_GFXTASK;
    arg0->task.list.t.flags = 0;    
    arg0->task.list.t.ucode_boot = D_80049EF0; // ucode boot at 0x80049EF0
    arg0->task.list.t.ucode_boot_size = (uintptr_t)D_80049FC0 - (uintptr_t)D_80049EF0;
    arg0->task.list.t.ucode = D_80049FC0_2; // ucode .text section at 0x80049FC0
    arg0->task.list.t.ucode_data = D_800723D0; // ucode .data section at 0x800723D0
    arg0->task.list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    arg0->task.list.t.dram_stack = D_80300000; // Stack at 0x80300000
    arg0->task.list.t.dram_stack_size = SP_DRAM_STACK_SIZE8;
    arg0->task.list.t.output_buff = D_8031B2A0;      // Output FIFO buffer starts at 0x8031B2A0
    arg0->task.list.t.output_buff_size = &D_8031B2A0[0x8000]; // Output FIFO buffer ends   at 0x803232A0
    arg0->task.list.t.yield_data_ptr = D_80300400;
    arg0->task.list.t.yield_data_size = OS_YIELD_DATA_SIZE;
    arg0->task.next = NULL;
    arg0->task.flags = OS_SC_SWAPBUFFER;
    arg0->task.msgQ = &D_8007B9E8;
    arg0->task.msg = &arg0->unkD148;
    arg0->task.framebuffer = arg0->unkD14C;
}*/

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_800011DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_80001800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_800020B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_8000227C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_80002428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_800025E8.s")
