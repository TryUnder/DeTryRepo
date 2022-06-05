/*
Dodawanie dwoch macierzy na avx
*/

#include <iostream>

void mtx2_avx_int(int** t1, int** t2, int** t3, int rows, int cols) {
	__asm {
		push esi;
		push edi;
		mov eax, rows;

	_OUTER_LOOP:
		mov esi, t1;
		mov edi, t2;
		mov ebx, t3;

		mov esi, dword ptr [esi + 4 * eax - 4];
		mov edi, dword ptr [edi + 4 * eax - 4];
		mov ebx, dword ptr [ebx + 4 * eax - 4];
		mov ecx, cols;

	_INNER_LOOP:
		vmovdqu ymm0, ymmword ptr [esi + 4 * ecx - 32];
		vmovdqu ymm1, ymmword ptr [edi + 4 * ecx - 32];
		
		vpaddd ymm2, ymm1, ymm0;
		vmovdqu ymmword ptr [ebx + 4 * ecx - 32], ymm2;

		sub ecx, 4;
		jnz _INNER_LOOP;

		dec eax;
		jnz _OUTER_LOOP;

		pop edi;
		pop esi;
	}
}

int main() {
	const int __size_x = 16;
	const int __size_y = 16;

	__int32** t1 = new __int32* [__size_x];
	for (auto i = 0; i < __size_x; ++i) {
		t1[i] = new __int32[__size_y];
		for (auto j = 0; j < __size_y; ++j) {
			t1[i][j] = (i + j) * 2;
		}
	}

	__int32** t2 = new __int32* [__size_x];
	for (auto i = 0; i < __size_x; ++i) {
		t2[i] = new __int32[__size_y];
		for (auto j = 0; j < __size_y; ++j) {
			t2[i][j] = (i + j) * 4;
		}
	}

	__int32** t3 = new __int32* [__size_x];
	for (auto i = 0; i < __size_x; ++i) 
		t3[i] = new __int32[__size_y];

	mtx2_avx_int(t1, t2, t3, __size_x, __size_y);

	for (auto i = 0; i < __size_x; ++i) {
		for (auto j = 0; j < __size_y; ++j) {
			std::cout << t3[i][j] << " ";
		}
		std::cout << std::endl;
	}
}