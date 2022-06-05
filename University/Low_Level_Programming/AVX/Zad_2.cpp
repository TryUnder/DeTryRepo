/*
Zad2: Proszę stworzyć program działający na wektorach liczb całkowitych odejmujący dwa
wektory z zapisem do trzeciego dla liczb 32-bitowych.
*/

#include <iostream>

void VSubPackedInt32(const int __size, __int32* packed_int_1, __int32* packed_int_2, __int32* packed_int_3) {
	__asm {
		push esi;
		push edi;

		mov ecx, __size;
		mov esi, packed_int_1;
		mov edi, packed_int_2;
		mov ebx, packed_int_3;
	_for:
		vmovdqu ymm0, ymmword ptr [esi + 4 * ecx - 32];
		vmovdqu ymm1, ymmword ptr [edi + 4 * ecx - 32];

		vsubpd ymm2, ymm1, ymm0;

		vmovdqu ymmword ptr [ebx + 4 * ecx - 32], ymm2;
		sub ecx, 8
		jnz _for;

		pop edi;
		pop esi;
	}
}

int main() {
	const int __size = 64;
	__int32* packed_int_1 = new __int32 [__size];
	__int32* packed_int_2 = new __int32 [__size];
	__int32* packed_int_3 = new __int32 [__size];

	for (auto i = 0; i < __size; ++i) {
		packed_int_1[i] = i;
		packed_int_2[i] = i + 2*i;
	}

	VSubPackedInt32(__size, packed_int_1, packed_int_2, packed_int_3);

	for (auto i = 0; i < __size; ++i) {
		std::cout << i << ":" << packed_int_3[i] << std::endl;
	}
}

