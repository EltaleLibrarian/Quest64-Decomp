#include "common.h"
#include <os_internal.h>
#include "osint.h"

/*!TODO! REMOVE THESE FROM THIS C FILE, AND PLACE THEM INTO THE CORRECT HEADER*/

extern void __osEnqueueAndYield(OSThread **);
extern u32 __osDisableInt(void);                               /* extern */
extern void __osRestoreInt(u32);                              /* extern */
extern OSThread *__osRunningThread;
extern OSThread *__osRunQueue;

//#pragma GLOBAL_ASM("asm/nonmatchings/yieldthread/func_80047C80.s")
void func_80047C80(void) {

    register u32 saveMask = __osDisableInt();
    __osRunningThread->state = 2;
    __osEnqueueAndYield(&__osRunQueue);
    __osRestoreInt(saveMask);
}