/*
Zad 5
Proszę napisać w assemblerze funkcję wyznaczającą wartość następującej funkcji:
	y = (a - 1)(3 * x) + c(b - a) + a (c - b)
*/

#include <iostream>

template <typename T>
auto CalculateExpression(const T a, const T b, const T c, const T x) {
	auto result = 0.0f;
	__asm {
		fld1;				1
		fld1;				1, 1
		fld1;				1, 1, 1
		faddp st(1), st(0); 2, 1
		faddp st(1), st(0); 3
		fld x;				x, 3
		fld a;				a, x, 3
		fld b;				b, a, x, 3
		fld c;				c, b, a, x, 3
		fsub st(0), st(1);  (c - b), b, a, x, 3
		fmul st(0), st(2);  a(c - b), b, a, x, 3
		fxch st(1);			b, a(c - b), a, x, 3
		fsub st(0), st(2);  (b - a), a(c - b), a, x, 3
		fxch st(4);			3, a(c - b), a, x, (b - a)
		fmulp st(3), st(0); a(c - b), a, 3x, (b - a)
		fld1;				1, a(c - b), a, 3x, (b - a)
		fsubp st(2), st(0); a(c - b), (a - 1), 3x, (b - a)
		fxch st(1);			(a - 1), a(c - b), 3x, (b - a)
		fmulp st(2), st(0); a(c - b), 3x(a - 1), (b - a)
		fld c;				c, a(c - b), 3x(a - 1), (b - a)
		fmulp st(3), st(0); a(c - b), 3x(a - 1), c(b - a)
		faddp st(1), st(0); 3x(a - 1) + a(c - b), c(b - a)
		faddp st(1), st(0); c(b - a) + 3x(a - 1) + a(c - b)
		fstp result;
	}
	return result;
}

int main() {
	std::cout << CalculateExpression(2.5f, 5.5f, 1.2f, 2.0f) << std::endl;
	/*
	dla tych danych
	https://www.wolframalpha.com/input?i=%28a-1%29%283*x%29+%2B+c%28b-a%29+%2B+a%28c-b%29%2C+a%3D2.5%2C+b%3D5.5%2C+c%3D1.2%2C+x%3D2.0
	*/
}