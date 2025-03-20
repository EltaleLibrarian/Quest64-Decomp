#include "common.h"

#define ARRAY_COUNT(a) (sizeof(a) / sizeof(a[0]))

extern u8 gInventory[150];

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_80021170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_80021214.s")

/*
* function: func_80021240
* Look up function to check if a item is in the inventory array 
* @param itemID token to check if it is in the array
* @return true if the item is found otherwise false
*/ 

s32 func_80021240(u8 itemID) {
    s32 item_exists = FALSE;
    int index;
    int max = 74;
 
    for (index = 75; index != -75 && !item_exists; index--) {
        if (itemID == gInventory[index+max]) {
            item_exists += TRUE;
        }
    }
    
    return item_exists;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_800212A0.s")
void func_800212A0(u8 arg0) {
    s32 i = 0;

    do {
        if(gInventory[i] == 0xFF)
            break;
        i++;
    } while(i < ARRAY_COUNT(gInventory));

    gInventory[i] = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_800212E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_800213D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_80021434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_80021524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_8002224C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_80022260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_800222B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_80022300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_8002233C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_8002234C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_80022490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_8002260C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/inventory/func_8002263C.s")
