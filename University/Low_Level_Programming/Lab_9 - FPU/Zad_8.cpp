/*
ST(0) < ST(i) JB
ST(0) <= ST(i) JBE
ST(0) == ST(i) JE
ST(0) != ST(i) JNE
ST(0) >= ST(i) JAE
ST(0) > ST(i) JA

ax^2,						x <= -5
sin^2(pi*x/180)				-5 < x <= 0
ax^2log.2.(1+x)				0 < x <= 5
sqrt(16pix) - sqrt(32x^2)	x>5
*/

#include <iostream>

int main() {
	double x = 6.0;
	double a = 2.5;
	double buf = 180.0;
	double numb = 5.0;
	double result = 0.0;
	__asm {
		fld x;							x
		fld numb;						5, x
		fchs;							-5, x
		fxch st(1);						x, -5
		fcomi st(0), st(1);
		jbe _case_1;
		ja _case_2;
		jmp _exitx;

	_case_1:
		fmul st(0), st(0);				x ^ 2, -5
		fld a;							a, x ^ 2, -5
		fmulp st(1), st(0);				a* x ^ 2, -5
		jmp _exitx;

	_case_2:
		ftst;
		fstsw ax;
		sahf;
		ja _case_3;
		mov eax, 180;
		push eax;
		fild dword ptr[esp];			180, x, -5
		pop eax;
		fldpi;							pi, 180, x, -5
		fdivrp st(1), st(0);				p1 / 180, x, -5
		fmulp st(1), st(0);				pi / 180 * x, -5
		fmul st(0), st(0);				(pi / 180 * x)^2, -5
		fsin;							sin(pi / 180 * x)^2, -5
		
		jmp _exitx;

	_case_3:
		fxch st(1);
		fchs;
		fxch st(1);
		fcomi st(0), st(1);				x, 5
		ja _case_4;
		fld1;							1, x, 5
		faddp st(1), st(0);				1 + x, 5
		fld1;							1, 1 + x, 5
		fxch st(1);						1 + x, 1, 5
		fyl2x;							log.2.(4), 5
		fld x;							x, log.2.(4), 5
		fmul st(0), st(0);				x^2, log.2.(4), 5
		fmulp st(1), st(0);				x^2 * log.2.(4), 5
		fld a;							a, x^2 * log.2.(4), 5
		fmulp st(1), st(0);				a * x^2 * log.2.(4), 5
		jmp _exitx;
	_case_4:
		fldpi;							pi, x, 5
		mov eax, 16;
		push eax;
		fild dword ptr[esp];			16, pi, x, 5
		pop eax;
		fmulp st(1), st(0);				16 * pi, x, 5
		fmulp st(1), st(0);				16 * pi * x, 5
		fsqrt;							sqrt(16 * pi * x), 5
		fld x;							x, sqrt(16 * pi * x), 5
		fmul st(0), st(0);				x^2, sqrt(16 * pi * x), 5
		mov eax, 32;
		push eax;
		fild dword ptr[esp];			32, x^2, sqrt(16 * pi * x), 5
		pop eax;
		fmulp st(1), st(0);				32 * x^2, sqrt(16 * pi * x), 5
		fsqrt;							sqrt(32 * x^2), sqrt(16 * pi * x), 5
		faddp st(1), st(0);				sqrt(16 * pi * x) - sqrt(32 * x^2), sqrt(16 * pi * x), 5
		jmp _exitx;

	_exitx:
		fstp result;
	}
	std::cout << result << std::endl;
}
