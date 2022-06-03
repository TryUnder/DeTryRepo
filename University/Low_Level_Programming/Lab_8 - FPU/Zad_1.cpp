/*
Zad 1. Proszę napisać metodę w asemblerze wyznaczającą wartość
następującej funkcji:
y = ax3 + bx2 + cx + d
*/

#include <iostream>
using namespace std;

int main() {
	double a = 2.7;
	double b = 3.2;
	double c = 4.3;
	double d = 5.4;
	double x = 6.111f;
	double y = 0.0f;

	__asm {
		fld d;					d
		fld x;					x, d
		fld st(0);				x, x, d
		fmul st(0), st(1);		x2, x, d
		fld st(1);				x, x2, x, d
		fmul st(0), st(1);		x3, x2, x, d
		fmul a;					ax3, x2, x, d
		faddp st(3), st(0);		x2, x, ax3 + d
		fmul b;					bx2, x, ax3 + d
		faddp st(2), st(0);		x, ax3 + bx2 + d
		fmul c;					cx, ax3 + bx2 + d
		fadd;					ax3 + bx2 + cx + d
		fstp y;
	}
	std::cout << y << std::endl;
}