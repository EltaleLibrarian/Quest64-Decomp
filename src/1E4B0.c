#include "common.h"
#include "33D0.h" //includes arg0 struct
#include "1E4B0.h"
#include "animation.h"


void func_8001D8B0(TransformAnim* arg0, s32 next_anim, s32 next_anim_framerate, s32 arg3, s32 arg4, u16 arg5) {
	if (next_anim != -1) {
		if (next_anim != arg0->currentAnimID) {
			arg0->currentAnimID = next_anim;
			arg0->unk60 = arg0->unk60 | 0x400;
			arg0->unk60 = arg0->unk60 & 0xFDFF;
		}

		arg0->animFramerate = next_anim_framerate;
		if (arg5 & 1) {
			arg0->currentAnimFrameNum = arg0->totalAnimFrames = 0;
		}
	}

	if (arg3 != -1) {
		if (arg3 != arg0->unk5A) {
			arg0->unk5A = arg3;
		}
		arg0->unk5C = arg4;
	}
}

#pragma GLOBAL_ASM("asm/nonmatchings/1E4B0/func_8001D924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1E4B0/func_8001DB38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1E4B0/func_8001DC78.s")

void func_8001E0AC(s32 arg0, TransformAnim* arg1, unk1E0ACarg2s* arg2) {
	s32 temp_v0 = arg1->currentAnimFrameNum += arg0;

	if (temp_v0 >= arg2->unk2) {
		if (arg1->currentAnimID != arg1->unk5A) {
			arg1->currentAnimID = arg1->unk5A;
			arg1->currentAnimFrameNum = 0U;
			arg1->totalAnimFrames = 0U;
			arg1->animFramerate = arg1->unk5C; //unk5C should probably be called newFramerate
			arg1->unk60 |= 0x400;
		} else {
			arg1->currentAnimFrameNum = temp_v0 - arg2->unk2;
			arg1->unk60 |= 0x200;
		}
	} else {
		arg1->unk60 &= ~0x600;
	}
	arg1->totalAnimFrames++;
}

void func_8001E138(MtxF* arg0, unk22b40s* arg1) {
    f32 x, y, z;
    x = arg0->mf[0][0];
    y = arg0->mf[1][0];
    z = arg0->mf[2][0];
    arg0->mf[3][0] -= x * arg1->unk8.x + y * arg1->unk8.y + z * arg1->unk8.z;
    x = arg0->mf[0][1];
    y = arg0->mf[1][1];
    z = arg0->mf[2][1];
    arg0->mf[3][1] -= x * arg1->unk8.x + y * arg1->unk8.y + z * arg1->unk8.z;
    x = arg0->mf[0][2];
    y = arg0->mf[1][2];
    z = arg0->mf[2][2];
    arg0->mf[3][2] -= x * arg1->unk8.x + y * arg1->unk8.y + z * arg1->unk8.z;
}
