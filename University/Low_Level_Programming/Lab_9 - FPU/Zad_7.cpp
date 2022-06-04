/*
Zadanie 
Dla wektora x należ do R+N oblicz wartość wyrażenia
	y.i. = 5 * (x.i.)^2 - x.i.
*/

#include <iostream>

int main() {
	auto __size = 5;
	double* x = new double[__size]{ 1.1,1.2,1.3,1.4,1.5 };
	double* y = new double[__size];
	__asm {
		push esi;
		mov ecx, __size;
		mov esi, x;
		mov edi, y
		fldz;												0
	_for:
		fld qword ptr [esi + 8 * ecx - 8];					liczba, 0
		fld qword ptr [esi + 8 * ecx - 8];					liczba, liczba, 0
		fmul st(1), st(0);									liczba, liczba^2, 0
		fmulp st(1), st(0);									liczba^3, 0
		fild __size;										5, liczba^3, 0
		fmulp st(1), st(0);									5 * liczba^3, 0
		fld qword ptr [esi + 8 * ecx - 8];					liczba, 5 * liczba^3, 0
		fsubp st(1), st(0);									5 * liczba^3 - liczba, 0
		fstp qword ptr [edi + 8 * ecx - 8];					0
		loop _for;
		pop esi;
	}
	
	for (auto i = 0; i < __size; ++i) {
		std::cout << y[i] << std::endl;
	}
}
