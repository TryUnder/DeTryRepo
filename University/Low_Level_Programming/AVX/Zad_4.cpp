/*
Zad4: Proszę stworzyć programy działające na wektorach liczb całkowitych
dodające/odejmujące/mnożące dwa wektory z zapisem do trzeciego dla liczb typu INT64.
4 ostatnie wartosci sa z dupy. ciekawe czemu. pewnie sub ecx, 4; nie wyhacza ostatnich
*/

#include <iostream>
void VAddPackedInt64(const int __size, __int64* x, __int64* y, __int64* suma) {
	__asm {
		push esi;
		push edi;

		mov ecx, __size;
		mov esi, x;
		mov edi, y;
		mov ebx, suma;

	_for:
		vmovdqu ymm0, ymmword ptr [esi + 8 * ecx - 64];
		vmovdqu ymm1, ymmword ptr [edi + 8 * ecx - 64];

		vpaddq ymm2, ymm1, ymm0;

		vmovdqu ymmword ptr [ebx + 8 * ecx - 64], ymm2;
		sub ecx, 4;
		jnz _for;

		pop edi;
		pop esi;
	}
}

void VSubPackedInt64(const int __size, __int64* x, __int64* y, __int64* roznica) {
	__asm {
		push esi;
		push edi;

		mov ecx, __size;
		mov esi, x;
		mov edi, y;
		mov ebx, roznica;

	_for:
		vmovdqu ymm0, ymmword ptr [esi + 8 * ecx - 64];
		vmovdqu ymm1, ymmword ptr [edi + 8 * ecx - 64];

		vpsubq ymm2, ymm1, ymm0;

		vmovdqu ymmword ptr[ebx + 8 * ecx - 64], ymm2;

		sub ecx, 4;
		jnz _for;

		pop edi;
		pop esi;
	}
}

void VMulPackedInt64(const int __size, __int64* x, __int64* y, __int64* iloczyn) {
	__asm {
		push esi;
		push edi;

		mov esi, x;
		mov edi, y;
		mov ebx, iloczyn;
		mov ecx, __size;

	_for:
		vmovdqu ymm0, ymmword ptr [esi + 8 * ecx - 64];
		vmovdqu ymm1, ymmword ptr [edi + 8 * ecx - 64];

		vpmuldq ymm2, ymm1, ymm0;

		vmovdqu ymmword ptr [ebx + 8 * ecx - 64], ymm2;
		sub ecx, 4;
		jnz _for;
	
		pop edi;
		pop esi;
	}
}

int main() {
	const int __size = 32;
	auto* x = (__int64*)malloc(__size * sizeof(__int64));
	auto* y = (__int64*)malloc(__size * sizeof(__int64));
	
	auto* suma = new __int64[__size];
	auto* roznica = new __int64[__size];
	auto* iloczyn = new __int64[__size];

	for (auto i = 0; i < __size; ++i) {
		x[i] = i + 1;
		y[i] = i + 5;
	}

	VAddPackedInt64(__size, x, y, suma);
	VSubPackedInt64(__size, x, y, roznica);
	VMulPackedInt64(__size, x, y, iloczyn);

	for (auto i = 0; i < __size; ++i) {
		if (i == 0) std::cout << "Suma: \n" << std::endl;
		std::cout << i << ": " << suma[i] << std::endl;
	}

	for (auto i = 0; i < __size; ++i) {
		if (i == 0) std::cout << "Roznica: \n" << std::endl;
		std::cout << i << ": " << roznica[i] << std::endl;
	}

	for (auto i = 0; i < __size; ++i) {
		if (i == 0) std::cout << "Iloczyn: \n" << std::endl;
		std::cout << i << ": " << iloczyn[i] << std::endl;
	}
}