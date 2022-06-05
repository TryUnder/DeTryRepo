/*
Dodawanie zmiennoprzecinkowych wektorow na avx
*/

#include <iostream>

void VAddPackedFloat(const int __size, float* x, float* y, float* wynik) {
	__asm {
		push esi;
		push edi;
		
		mov ecx, __size;
		mov esi, x;
		mov edi, y;
		mov ebx, wynik;

	_for:
		vmovdqu ymm0, ymmword ptr [esi + 4 * ecx - 32];
		vmovdqu ymm1, ymmword ptr [edi + 4 * ecx - 32];

		vaddps ymm2, ymm1, ymm0;

		vmovdqu ymmword ptr [ebx + 4 * ecx - 32], ymm2;

		sub ecx, 4;
		jnz _for;

		pop edi;
		pop esi;
	}
}

int main() {
	const int __size = 16;
	float* x = new float [__size] {1.1f, 1.2f, 1.3f, 1.4f, 1.5f, 1.6f, 1.7f, 1.8f, 1.9f, 1.10f, 1.11f, 1.12f, 1.13f, 1.14f, 1.15f, 1.16f};
	float* y = new float [__size] {1.1f, 1.2f, 1.3f, 1.4f, 1.5f, 1.6f, 1.7f, 1.8f, 1.9f, 1.10f, 1.11f, 1.12f, 1.13f, 1.14f, 1.15f, 1.16f};
	float* wynik = new float [__size];

	VAddPackedFloat(__size, x, y, wynik);

	for (auto i = 0; i < __size; ++i) {
		std::cout << i << ": " << wynik[i] << std::endl;
	}
}