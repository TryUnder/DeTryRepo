/*
Zadanie 1
y = ax^(b) - bx^(c) + cx + d
*/

#include <iostream>

double Func(double a, double b, double c, double d, double x) {
	double result = 0.0f;
	__asm {
		fld b;					b
		fld x;					x, b
		fyl2x;					b* log.2.x
		f2xm1;					2 ^ (b * log.2.x) - 1
		fld1;					1, 2 ^ (b * log.2.x) - 1
		fadd;					x^ b

		fld c;					c, x^ b
		fld x;					x, c, x^ b
		fyl2x;					c* log.2.x, x^ b
		f2xm1;					2 ^ (c * log.2.x) - 1, x^ b
		fld1;					1, 2 ^ (c * log.2.x) - 1, x^ b
		fadd;					x^ c, x^ b

		fld b;					b, x^ c, x^ b
		fmulp st(1), st(0);		b* x ^ (c), x^ b
		fxch st(1);				x ^ (b), b* x ^ (c)
		fld a;					a, x ^ (b), b* x ^ (c)
		fmulp st(1), st(0);		a* x(b), b* x ^ (c)
		fld c;					c, a* x ^ (b), b* x ^ (c)
		fld x;					x, c, a* x ^ (b), b* x ^ (c)
		fmulp st(1), st(0);		cx, a* x ^ (b), b* x ^ (c)
		fld d;					d, cx, a* x ^ (b), b* x ^ (c)
		faddp st(1), st(0);     cx + d, a* x ^ (b), b* x ^ (c)
		faddp st(1), st(0);		cx + d + a * x ^ (b), b* x ^ (c)
		fxch st(1);				b* x ^ (c), cx + d + a * x ^ (b) // albo mozna bylo zmienic znak na stosie
		fsubp st(1), st(0);		cx + d + a * x ^ (b) - (b * x ^ (c))

		fstp result;
	}
	return result;
}

int main() {
	std::cout << " x^y " << Func(15.20f, 0.6f, 0.25f, -2.3f, 2.3f) << std::endl;
	//https://www.wolframalpha.com/input?i=calculate+y%2Cy%3Da*x%5E%28b%29-b*x%5E%28c%29%2Bc*x%2Bd+%2Ca%3D15.20%2Cb%3D0.6%2Cc%3D0.25%2Cd%3D-2.3%2Cx%3D2.3
}
