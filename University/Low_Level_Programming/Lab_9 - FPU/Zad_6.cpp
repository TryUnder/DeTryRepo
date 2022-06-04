/*
Zadanie 
Oblicz from i to n do x.i.^2
*/

#include <iostream>

int main() {
	const int _size = 5;
	double* x = new double[_size]{ 1.2,1.3,1.4,1.5,1.6 };
	double result = 0.0L;
	__asm {
		push esi;
		mov ecx, _size;
		mov esi, x;
		fldz;
	_for:
		fld qword ptr[esi + 8 * ecx - 8];
		fld qword ptr[esi + 8 * ecx - 8];
		fmulp st(1), st(0);
		fadd;
		loop _for;
		fstp result;
		pop esi;
	}
	std::cout << result << std::endl;
}
