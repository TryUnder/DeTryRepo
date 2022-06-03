/*
Zad 4
Proszę napisać w assemblerze funkcję obliczającą pole kuli
*/

#include <iostream>

template <typename T>
auto PoleKuli(const T r) {
	auto result = 0.0f;
	__asm {
		fld1;					1
		fld1;					1, 1
		fld1;					1, 1, 1
		fld1;					1, 1, 1, 1
		faddp st(1), st(0);		2, 1, 1
		faddp st(1), st(0);		3, 1
		faddp st(1), st(0);		4
		fldpi;					pi, 4
		fmulp st(1), st(0);		4 * pi
		fld r;					r, 4 * pi
		fld r;					r, r, 4 * pi
		fmulp st(1), st(0);		r2, 4 * pi
		fmulp st(1), st(0);		4 * pi * r2
		fstp result;
	}
	return result;
}

int main() {
	std::cout << PoleKuli(2.5f) << std::endl;
}