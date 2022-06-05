/*
ST(0) < ST(i) JB
ST(0) <= ST(i) JBE
ST(0) == ST(i) JE
ST(0) != ST(i) JNE
ST(0) >= ST(i) JAE
ST(0) > ST(i) JA
*/

#include <iostream>

int main() {
	double a = 5.0;
	double b = -6.0;
	__asm {
		xor eax, eax;
		fld a;					a
		fld b;
		fcomi st(0), st(1);
		jb _out;
		inc eax;
	_out:
	}
	
}
