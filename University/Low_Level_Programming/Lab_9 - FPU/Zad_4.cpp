/*
Zadanie 
Oblicz y = 4 * sin(^(3)a * pi/180) - 2 * cos(b*pi/180)^2
*/

#include <iostream>

int main() {
	double a = 2.5l;
	double b = -3.3l;
	double buf = 180.0l;
	double result = 0.0l;
	__asm {
		fld a;					a
		fld b;					b, a
		fld buf;				buf, b, a
		fldpi;					pi, buf, b, a
		fmul st(0), st(3);		pi* a, buf, b, a
		fdiv st(0), st(1);		pi* a / 180, buf, b, a
		fld st(0);				pi* a / 180, pi* a / 180, buf, b, a
		fmul st(0), st(0);		pi* a / 180, (pi * a / 180) ^ 2, buf, b, a
		fmulp st(1), st(0);		(pi * a / 180) ^ 3, buf, b, a
		fsin;					sin(pi * a / 180) ^ 3, buf, b, a
		fld1;					1, sin(pi * a / 180) ^ 3, buf, b, a
		fld1;					1, 1, sin(pi * a / 180) ^ 3, buf, b, a
		fld1;					1, 1, 1, sin(pi * a / 180) ^ 3, buf, b, a
		fld1;					1, 1, 1, 1, sin(pi * a / 180) ^ 3, buf, b, a
		faddp st(1), st(0);		2, 1, 1, sin(pi * a / 180) ^ 3, buf, b, a
		faddp st(1), st(0);		3, 1, sin(pi * a / 180) ^ 3, buf, b, a
		faddp st(1), st(0);		4, sin(pi * a / 180) ^ 3, buf, b, a
		fmulp st(1), st(0);		4 * sin(pi * a / 180) ^ 3, buf, b, a
		fldpi;					pi, 4 * sin(pi * a / 180) ^ 3, buf, b, a
		fmul st(0), st(3);		pi* b, 4 * sin(pi * a / 180) ^ 3, buf, b, a
		fdiv st(0), st(2);		pi* b / 180, 4 * sin(pi * a / 180) ^ 3, buf, b, a
		fmul st(0), st(0);		(pi * b / 180) ^ 2, 4 * sin(pi * a / 180) ^ 3, buf, b, a
		fcos;					cos(pi * b / 180) ^ 2, 4 * sin(pi * a / 180) ^ 3, buf, b, a
		fld1;					1, cos(pi * b / 180) ^ 2, 4 * sin(pi * a / 180) ^ 3, buf, b, a
		fld1;					1, 1, cos(pi * b / 180) ^ 2, 4 * sin(pi * a / 180) ^ 3, buf, b, a
		faddp st(1), st(0);		2, cos(pi * b / 180) ^ 2, 4 * sin(pi * a / 180) ^ 3, buf, b, a
		fmulp st(1), st(0);		2 * cos(pi * b / 180) ^ 2, 4 * sin(pi * a / 180) ^ 3, buf, b, a
		fsubp st(1), st(0);		(4 * sin(pi * a / 180) ^ 3) - (2 * cos(pi * b / 180) ^ 2), buf, b, a
		fstp result;
	}
	std::cout << result << std::endl;
    //https://www.wolframalpha.com/input?i=calculate+y%2C+y%3D4*sin%5E3%28a*pi%2F180%29-2*cos%5E2%28b*pi%2F180%29%2Ca%3D2.5%2Cb%3D-3.3
}
