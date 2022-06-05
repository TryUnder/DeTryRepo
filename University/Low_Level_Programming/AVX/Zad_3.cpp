/*
Zad3: Proszę stworzyć program działający na wektorach liczb całkowitych mnożący dwa
wektory z zapisem do trzeciego dla liczb 32-bitowych.
*/

#include <iostream>

auto VMulPackedInt32(const int __size, __int32* packed_int_32_1,
					__int32* packed_int_32_2, __int32* packed_int_32_3) {
	__asm {
		push esi;
		push edi;
		mov ecx, __size;
		mov esi, packed_int_32_1;
		mov edi, packed_int_32_2;
		mov ebx, packed_int_32_3;

	_for:
		vmovdqu ymm0, ymmword ptr [esi + 4 * ecx - 32];
		vmovdqu ymm1, ymmword ptr [edi + 4 * ecx - 32];

		vpmulld ymm2, ymm1, ymm0; // multiply the packed dword signed integers 

		vmovdqu ymmword ptr [ebx + 4 * ecx - 32], ymm2;

		sub ecx, 8;
		jnz _for;

		pop edi;
		pop esi;
	}
}

int main() {
	const int __size = 128;
	auto packed_int_32_1 = (__int32*)malloc(__size * sizeof(__int32));
	auto packed_int_32_2 = (__int32*)malloc(__size * sizeof(__int32));
	auto packed_int_32_3 = (__int32*)malloc(__size * sizeof(__int32));

	for (auto i = 0; i < __size; ++i) {
		packed_int_32_1[i] = i;
		packed_int_32_2[i] = i + 1;
	}

	VMulPackedInt32(__size, packed_int_32_1, packed_int_32_2, packed_int_32_3);

	for (auto i = 0; i < __size; ++i) {
		std::cout << i << ": " << packed_int_32_3[i] << std::endl;
	}
}