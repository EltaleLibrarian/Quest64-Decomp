#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/24E60/dma_write.s")

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
