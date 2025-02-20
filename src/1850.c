#include "common.h"
#include "1850.h"
#include "map_ids.h"
#include "33D0.h"
#include "31F00.h"


#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_80000C50.s")
/*void func_80000C50(s32 arg0) {
    osCreateViManager(0xFE);
    osCreateMesgQueue(&D_8007B320, &D_8007B338, 1);
    func_80024704();
    
    func_8002513C(
        &D_E7E800, 
        &Instrument_tbl_ROM_START, 
        &D_EBABD0, 
        &D_EEE020,
        &Instrument_tbl_ROM_START + 1);
    
    
    func_80025488(&D_EEE020+1, &D_EEFCE0, &D_EEFCE0+1);
    nnScCreateScheduler(&D_8007B358, 1U);
    func_80031300();
    if (D_80000300 == 1) {
        osViSetMode(&D_8006F4F0);
    } else {
        osViSetMode(&D_8006FDB0);
    }
    osViBlack(1U);
    func_80032704(&gSIMessageQ, &D_8007B3CC);
    osViBlack(1U);
    osViSetSpecialFeatures(0x5AU);
    nnScStartScheduler(&D_8007B358);
    func_800250E8(&D_8007B358);
    osCreateMesgQueue(&D_8007B9E8, &D_8007BA00, 8);
    nnScAddClient(&D_8007B358, &D_8007B9E0, &D_8007B9E8);
    D_8007B9D8 = nnScGetGfxMQ(&D_8007B358);
    func_80000FE8();

    while (1) {
    func_8000B520();
    func_80011B40();
    func_800121F0();
    func_800027D0();
    func_80021170();
    func_800100D0();
    func_80030E58();
    func_800265F0();
    func_80000EEC();
    func_80026A40();
loop_5:
    gGameState &= ~3;
    if (gGameMode == 0) {
        gGameMode = 1;
    }
    switch (gGameMode) {
    case 1:
        func_80001800();
        break;
    case 2:
        func_800020B4();
        break;
    case 3:
        func_8000227C();
        break;
    case 4:
        func_80002428();
        break;
    case 5:
        func_800025E8();
        break;
    }
    if (!(gGameState & 0x8000)) {
        goto loop_5;
    }
    }
}*/

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
//https://decomp.me/scratch/8sgMl

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_80001800.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_800020B4.s")
void func_800020B4(void) {
    OSMesg* sp4C;
    OSMesg* temp_s5;

    D_8007B348 = 0;
    sp4C = NULL;
    D_8008FD0E = 0;
    if (gGameMode == 2) {
        do {
            func_800314C0((s32) gCurrControllerNum);
            D_8007B2F8 = 0;
            func_800011DC(D_80301000[D_8007B2F4]);
            temp_s5 = D_80301000[D_8007B2F4];
            func_80026658();
            if (D_8007B348 == 0) {
                D_8007B348 += 1;
                do {
                    osRecvMesg(&D_8007B9E8, &sp4C, 1);
                } while (*(s16*)sp4C != 1);
            } else {
                do {
                    osRecvMesg(&D_8007B9E8, &sp4C, 1);
                } while (*(s16*)sp4C != 2);
            }
            osSendMesg(D_8007B9D8, temp_s5, 1);
            D_8007B2F4 ^= 1;
        } while (gGameMode == 2);
    }
    if (D_8008FD0E != 0) {
        func_80002EA0();
        D_8007B2E8 = 2;
    }
    func_80026A04();
    do {
        osRecvMesg(&D_8007B9E8, &sp4C, 1);
    } while (*(s16*)sp4C != 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_8000227C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_80002428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1850/func_800025E8.s")
