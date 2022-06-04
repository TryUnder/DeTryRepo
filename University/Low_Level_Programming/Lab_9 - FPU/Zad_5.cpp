/*
Zadanie 
Oblicz y = log.2.((1 + a / (b+1))^2) + log.2.((1 + b / (a+1)))
*/

#include <iostream>

int main() {
	double result = 0.0l;
	double a = 3.0;
	double b = 4.5;
	double value = 0.0l;
	__asm {
		fld a;					a
		fld1;					1, a
		faddp st(1), st(0);		1 + a
		ftst;
		fstsw ax;
		sahf;
		jz _mianownik_zero;
		fld b;					b, 1 + a
		fdivrp st(1), st(0);	b / (1 + a)
		fld1;					1, b / (1 + a)
		faddp st(1), st(0);		1 + (b / (1 + a))
		fmul st(0), st(0);		(1 + (b / (1 + a)))^2
		fld1;					1, (1 + (b / (1 + a))) ^ 2
		fxch st(1);				(1 + (b / (1 + a))) ^ 2, 1
		fyl2x;					1*log2(1, (1 + (b / (1 + a))) ^ 2)
		
		fld b;					b, 1 * log2(1, (1 + (b / (1 + a))) ^ 2)
		fld1;					1, b, 1 * log2(1, (1 + (b / (1 + a))) ^ 2)
		faddp st(1), st(0);		b + 1, 1 * log2(1, (1 + (b / (1 + a))) ^ 2)
		ftst;					
		fstsw ax;
		sahf;
		jz _mianownik_zero;
		fld a;					a, b + 1, 1 * log2(1, (1 + (b / (1 + a))) ^ 2)
		fdivrp st(1), st(0);	a / (b + 1), 1 * log2(1, (1 + (b / (1 + a))) ^ 2)
		fld1;					1, a / (b + 1), 1 * log2(1, (1 + (b / (1 + a))) ^ 2)
		faddp st(1), st(0);		1 + a / (b + 1), 1 * log2(1, (1 + (b / (1 + a))) ^ 2)
		fmul st(0), st(0);		(1 + a / (b + 1))^2, 1 * log2(1, (1 + (b / (1 + a))) ^ 2)
		fld1;					1, (1 + a / (b + 1)) ^ 2, 1 * log2(1, (1 + (b / (1 + a))) ^ 2)
		fxch st(1);				(1 + a / (b + 1)) ^ 2, 1, 1 * log2(1, (1 + (b / (1 + a))) ^ 2)
		fyl2x;					1 * log2((1 + a / (b + 1)) ^ 2), 1 * log2(1, (1 + (b / (1 + a))) ^ 2)
		faddp st(1), st(0);		(1 * log2((1 + a / (b + 1)) ^ 2)) + (1 * log2(1, (1 + (b / (1 + a))) ^ 2))
		jmp __exit;
	_mianownik_zero:

	__exit:
		fstp result;
	}
	std::cout << result << std::endl;
	//z photomath się zgadza
    
}
