/*
Zad
Dodaj dwa spakowane wektory intów 32 bitowe
*/

#include <iostream>

void AddInt32Vectors(int __size, __int32* packed_int_1, __int32* packed_int_2, __int32* packed_int_3) {
	__asm {
		push esi;
		push edi;
		mov esi, packed_int_1;
		mov edi, packed_int_2;
		mov ebx, packed_int_3;

		vmovdqu xmm0, xmmword ptr [esi];
		vmovdqu xmm1, xmmword ptr [edi];
		vpaddd xmm2, xmm1, xmm0;
		vmovdqu xmmword ptr [ebx], xmm2;

		pop edi;
		pop esi;
	}
}

int main() {
	const int __size = 4;
	__int32* packed_int_1 = new __int32[__size] { 1, 2, 3, 4};
	__int32* packed_int_2 = new __int32[__size] { 1, 2, 3, 4};
	__int32* packed_int_3 = new __int32[__size] {};
	
	AddInt32Vectors(__size, packed_int_1, packed_int_2, packed_int_3);

	for (auto i = 0; i < __size; ++i) {
		std::cout << packed_int_3[i] << std::endl;
	}
}
