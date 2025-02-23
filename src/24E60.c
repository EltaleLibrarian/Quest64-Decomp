#include "common.h"

extern OSMesgQueue D_8007B320;
extern OSIoMesg D_8008D070;

void dma_write(u32 devAddr, void* vAddr, s32 size) {
    u32 mesgSize;

    osInvalICache(vAddr, size);
    osInvalDCache(vAddr, size);
    while (size != 0) {
        if (size > 0x4000) {
            mesgSize = 0x4000;
        } else {
            mesgSize = size;
        }
        osPiStartDma(&D_8008D070, 0, 0, devAddr, vAddr, mesgSize, &D_8007B320);
        osRecvMesg(&D_8007B320, NULL, 1);
        size -= mesgSize;
        devAddr = devAddr + mesgSize;
        vAddr = (u8*)vAddr + mesgSize;
    }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/24E60/func_80024330.s")
s32 count_digits(s32 value, u8 *str_ptr, u16 flags) //matched by a mysterious stranger. 
{
  u32 char_count;
  s32 continue_loop;
  s32 power;
  u8 *i_ptr;
  u32 i;
  if (flags & 2)
  {
    power = 10000;
    char_count = 4;
  }
  else
    if (flags & 4)
  {
    power = 10;
    char_count = 1;
  }
  else
  {
    char_count = 0;
    for (power = 10; power <= value; power *= 10)
    {
      char_count++;
    }

    power /= 10;
  }
  i_ptr = str_ptr;
 for (i = char_count; i > 0; i--) { *i_ptr = value / power;
    value %= power; //remainder
    power /= 10; //power
    i_ptr += 1;
  }

  i_ptr[0] = (u8) value;
  i_ptr[1] = 0xFF;
  if (flags & 1) //pad string width 
  {
    continue_loop = 0;
    continue_loop = 1;
    i_ptr = str_ptr;
    for (i = char_count; (i != 0) && continue_loop; i--)
    {
      if (!(*i_ptr))
      {
        *i_ptr = ' ';
      }
      else
      {
        continue_loop = 0;
      }
      i_ptr += 1;
    }

  }
  return char_count + 1; //return len + 1 for null terminator
}
