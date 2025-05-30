#include "common.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
}struct_unkF238_3;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u16 unk6;
    f32 unk8;
    f32 unkC;
    f32 unk10;
}struct_unkF238_2;

typedef struct {
    s16 unk0;
    s16 unk2;
    char unk4[4];
    s16 unk8;
    s16 unkA;
    char unkC[8];
    struct_unkF238_2* unk14;
    u16 unk18;
    char unk1A[2];
    struct_unkF238_3* unk1C;
}struct_unkF238;

typedef struct {
    char unk0[4];
    f32 unk4;
    char unk8[4];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s16 unk18;
}unkF238arg5;

typedef struct Coordinates2D_s{
    f32 x;
    f32 y;
}Coordinates2D;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u16 unk14;
    u16 unk16;
    char unk18[0xC];
}struct_8000FFE8;

typedef struct {
    s32 unk0;
    struct_8000FFE8* unk4;
    s32 unk8;
    char unkC[0x6];
    u16 unk12;
    u16 unk14;
}struct_80084F1C;

extern Coordinates2D D_80085358;
extern u16 gBattleState;

extern struct_80084F1C* D_80084F1C;
s32 func_8000FFE8(struct_8000FFE8* arg0);
void rotateCoordinatesByAngle(f32 angle, Coordinates2D* coordinates);
void func_80010080(struct_8000FFE8*);                  /* extern */
s32 func_8000FF54(f32 arg0);

s32 func_8000F5A4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000EE60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000F0BC.s")
//https://decomp.me/scratch/r5BGe

#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000F238.s")
#ifdef NON_MATCHING //https://decomp.me/scratch/aBcO4
s32 func_8000F238(f32 arg0, f32 arg1, f32 arg2, u16 arg3, struct_unkF238 *arg4, unkF238arg5 *arg5)
{
  struct_unkF238_3 *temp_s4;
  s32 ret;
  f32 temp_f20;
  f32 temp_f22;
  f32 temp_f24;
  f32 temp_f26;
  f32 sp74;
  f32 sp70;
  s32 var_s0;
  s32 count;
  f32 x;
  f32 y;
  f32 z;
  f32 new_var6;
  f32 tmp1;
  f32 tmp2;
  f32 tmp3;
  f32 tmp4;
  struct_unkF238_2 *var_s1;
  struct_unkF238_3 *ptr1;
  struct_unkF238_3 *ptr2;
  struct_unkF238_3 *ptr3;
  ret = 0;
  temp_s4 = arg4->unk1C;
  var_s1 = arg4->unk14;
  if (var_s1 != 0)
  {
    tmp1 = arg4->unk0 * arg2;
    tmp2 = arg4->unk2 * arg2;
    tmp3 = arg4->unk8 * arg2;
    tmp4 = arg4->unkA * arg2;
    if ((((arg0 < tmp1) || (arg0 > tmp2)) || (arg1 < tmp3)) || (arg1 > tmp4))
    {
      return 0;
    }
    for (count = arg4->unk18; count != 0; count--, var_s1++)
    {
      if (var_s1->unk6 & arg3)
      {
        ptr1 = &temp_s4[var_s1->unk0];
        ptr2 = &temp_s4[var_s1->unk2];
        ptr3 = &temp_s4[var_s1->unk4];
        sp74 = ptr1->unk0 * arg2;
        sp70 = ptr1->unk4 * arg2;
        temp_f20 = ptr2->unk0 * arg2;
        temp_f22 = ptr2->unk4 * arg2;
        temp_f24 = ptr3->unk0 * arg2;
        temp_f26 = ptr3->unk4 * arg2;
        if ((arg0 == sp74) && (arg1 == sp70))
        {
          var_s0 = 1;
        }
        else
          if ((arg0 == temp_f20) && (arg1 == temp_f22))
        {
          var_s0 = 1;
        }
        else
          if ((arg0 == temp_f24) && (arg1 == temp_f26))
        {
          var_s0 = 1;
        }
        else
        {
          var_s0 = func_8000F5A4(arg0, arg1, sp74, sp70, temp_f20, temp_f22);
          var_s0 += func_8000F5A4(arg0, arg1, temp_f20, temp_f22, temp_f24, temp_f26);
          var_s0 += func_8000F5A4(arg0, arg1, sp74, sp70, temp_f24, temp_f26);
        }

          
        if (var_s0 == 1)
        {
          x = var_s1->unk8;
          y = var_s1->unkC;
          z = var_s1->unk10;
          new_var6 = ptr1->unk2 * arg2;
            
          if (y != 0.0f)
          {
            arg5->unk4 = (-(((x * arg0) + (z * arg1)) - (((x * sp74) + (y * new_var6)) + z * sp70))) / y;
            arg5->unk18 = var_s1->unk6;
          }
          else
          {
            arg5->unk18 = var_s1->unk6;
          }
          arg5->unkC = x;
          arg5->unk10 = y;
          arg5->unk14 = z;
          ret = 1;
          break;
        }
      }
    }

  }
  return ret;
}
#endif

//#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000F5A4.s")
s32 func_8000F5A4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    if (((arg3 <= arg1) && (arg1 < arg5)) || ((arg5 <= arg1) && (arg1 < arg3))) {
        if ((arg2 <= arg0) && (arg4 < arg0)) {
            return 1;
        }
        if ((arg0 <= arg2) && (arg0 < arg4)) {
            return 0;
        }
        if ((arg3 != arg5) && ((((arg1 - arg3) * ((arg2 - arg4) / (arg3 - arg5))) + arg2) < arg0)) {
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000F6A4.s")
//https://decomp.me/scratch/5Uq92

#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000FCBC.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000FDE0.s") TODO This function has ugly, ugly gotos in it. https://decomp.me/scratch/MkToR
s32 func_8000FDE0(f32 arg0, f32 arg1, f32 arg2)
{
  f32 x;
  s32 ret;
  struct_80084F1C *new_var;
  f32 y;
  s32 var_s2;
  struct_8000FFE8 *var_s0;
  new_var = D_80084F1C;
  ret = 0;
  if ((D_80084F1C->unk8 == 0) || ((var_s2 = new_var->unk8, (gBattleState & 1) != 0)))
  {
    return 0;
  }
  var_s0 = D_80084F1C->unk4;
  if (D_80084F1C->unk8 != 0)
  {
    loop_5:
    if (func_8000FFE8(var_s0) != 0)
    {
      D_80085358.x = arg0 - var_s0->unk0;
      D_80085358.y = arg1 - var_s0->unk4;
      rotateCoordinatesByAngle(var_s0->unk8, &D_80085358);
      x = D_80085358.x;
      if (x < 0.0f)
      {
        x = -x;
      }
      y = D_80085358.y;
      if (y < 0.0f)
      {
        y = -y;
      }
      if ((x < var_s0->unkC) && (y < var_s0->unk10))
      {
        if ((var_s0->unk14 & 2) || (func_8000FF54(arg2 - var_s0->unk8) != 0))
        {
          func_80010080(var_s0);
          ret = 1;
        }
      }
      else
      {
        goto block_15;
      }
    }
    else
    {
      block_15:
      var_s2 -= 1;

      var_s0++;
      if (var_s2 != 0)
      {
        goto loop_5;
      }
    }

  }
  return ret;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000FF54.s")
s32 func_8000FF54(f32 arg0)
{
  if (M_PI < arg0)
  {
    arg0 -= M_PI * 2;
  }
  else
    if (arg0 < -M_PI)
  {
    arg0 += M_PI * 2;
  }
  if (arg0 < 0.0f)
  {
    arg0 = -arg0;
  } 
  return arg0 < M_PI / 8; //arg0 < 22.5° in radians. 
}

//#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000FFE8.s")
s32 func_8000FFE8(struct_8000FFE8* arg0) {
    s32 ret;
    s32 i;
    
    
    if (arg0->unk14 & 0x30) {
        for (i = 0; i < 150; i++) {
            if (gInventory[i] == arg0->unk16) {
                break;
            }
        }
        if (arg0->unk14 & 0x10) {
            if (i < 150) {
                ret = 1;
            } else {
                ret = 0;
            }
        } else {
            if (i < 150) {
                ret = 0;
            } else {
                ret = 1;
            }
        }
    } else {
        ret = 1;
    }
    
    return ret;
}