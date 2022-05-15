#include <iostream>
using namespace std;


int main()
{
	float a = 2.7;
	float b = 3.2;
	float c = 4.3;
	float d = 5.4;
	float x = 6.111;
	float y;
	__asm {
		fld d;			 d
		fld x;			 x, d
		fld st;			 x, x, d
		fmul st, st;	 x ^ 2, x, d
		fld st;			 x ^ 2, x ^ 2, x, d
		fmul st, st(2);  x ^ 3, x ^ 2, x, d
		fmul a;			 ax ^ 3, x ^ 2, x, d
		faddp st(3), st; x ^ 2, x->ax ^ 3 + d
		fmul b;			 bx ^ 2, x
		faddp st(2), st; x  ->	ax ^ 3 + bx ^ 2 + d
		fmul c;			 cx ->	ax ^ 3 + bx ^ 2 + d
		faddp st(1), st;    ->  ax ^ 3 + bx ^ 2 + cx + d
		fstp y
	}

	std::cout << y << std::endl;
}