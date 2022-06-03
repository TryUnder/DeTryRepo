/*
Zad.3
Proszę napisać w assemblerze funkcję obliczającą objętość kuli
*/

#include <iostream>

double ObjetoscKuli(const double r) {
	double result{ 0.0f };
	__asm{
		fld1;				 1
		fld1;				 1, 1
		fld1;				 1, 1, 1
		fld1;				 1, 1, 1, 1
		faddp st(1), st(0);  2, 1, 1
		faddp st(1), st(0);  3, 1
		fld st(0);			 3, 3, 1
		faddp st(2), st(0);	 3, 4
		fdivp st(1), st(0);  4 / 3
		fldpi;				 pi, 4 / 3
		fmulp st(1), st(0);	 4 / 3 * pi
		fld r;				 r, 4 / 3 * pi
		fld r;				 r, r, 4 / 3 * pi
		fmul st(1), st(0);	 r, r2, 4 / 3 * pi
		fmulp st(1), st(0);  r3, 4 / 3 * pi
		fmulp st(1), st(0);	 4 / 3 * pi * r3
		fstp result;
	}
	return result;
}

int main() {
	std::cout << ObjetoscKuli(2.5f) << std::endl;
}