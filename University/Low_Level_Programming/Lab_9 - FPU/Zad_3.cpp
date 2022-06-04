/*
Zadanie 
y = pow(1 + pow(a,-2) + sqrt(pow(fabs(b),-3)2),2)
*/

#include <iostream>

int main() {
	double a = 2.5;
	double b = -3.3;
	double result = 0.0l;
	__asm {
		fld b;					b
		fabs; | b |				| b |
		fld1;					1, | b |
		fdivrp st(1), st(0);	1 / | b |
		fld st(0);				1 / | b | , 1 / | b |
		fmul st(1), st(0);		1 / | b | , (1 / | b | ) ^ 2
		fmulp st(1), st(0);		(1 / | b | ) ^ 3
		fsqrt;					sqrt((1 / | b | ) ^ (3), 2)
		fld1;					1, sqrt((1 / | b | ) ^ (3), 2)
		faddp st(1), st(0);		sqrt((1 / | b | ) ^ (3), 2) + 1
		fld a;					a, sqrt((1 / | b | ) ^ (3), 2) + 1
		fld1;					1, a, sqrt((1 / | b | ) ^ (3), 2) + 1
		fdivrp st(1), st(0);	1 / a, sqrt((1 / | b | ) ^ (3), 2) + 1
		fmul st(0), st(0);		(1 / a) ^ 2, sqrt((1 / | b | ) ^ (3), 2) + 1
		faddp st(1), st(0);		(1 / a) ^ 2 + sqrt((1 / | b | ) ^ (3), 2) + 1
		fstp result;
	}
}
