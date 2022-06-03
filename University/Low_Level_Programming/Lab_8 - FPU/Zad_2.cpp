/*
Zad 2. Proszę napisać metodę w asemblerze wyznaczającą wartość
następującej funkcji:
y = 4 * x3 - 2x - 1
*/

#include <iostream>
using namespace std;

int main() {
	double x = 2.5f;
	double result = 0.0f;
	__asm {
		fld1;					1
		fld1;					1, 1
		fld1;					1, 1, 1
		fld1;					1, 1, 1, 1
		faddp st(1), st(0);		2, 1, 1
		faddp st(1), st(0);     3, 1
		faddp st(1), st(0);     4
		fld x;					x, 4
		fld x;					x, x, 4
		fmul st(0), st(1);		x2, x, 4
		fmulp st(1), st(0);		x3, 4
		fxch st(1);				4, x3
		fmulp st(1), st(0);		4x3
		fld1;					1, 4x3
		fld1;					1, 1, 4x3
		faddp st(1), st(0);		2, 4x3
		fld x;					x, 2, 4x3
		fmulp st(1), st(0);		2x, 4x3
		fsubp st(1), st(0);		4x3 - 2x
		fld1;					1, 4x3 - 2x
		fsubp st(1), st(0);		4x3 - 2x - 1
		fstp result;

	}
	std::cout << result << std::endl;
}