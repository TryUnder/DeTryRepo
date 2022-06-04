/*
Zadanie 1
Proszę napisać w assemblerze metodę tablicującą następującą funkcję:
	y = a * (sin(pi * p1 * x / 180))^2 + b * cos(pi * p2 * x / 180)
*/

#include <iostream>

void Func(size_t k, double* x, double* y, double* a, 
			double min_x, double max_x, double b, double p1,
			double p2, double buf) {
	__asm {
		push esi;
		push edi;

		mov esi, dword ptr x;
		mov edi, dword ptr y;
		mov ebx, a;
		mov ecx, k;

		fld min_x;					min_x
		fld max_x;					max_x, min_x
		fsubrp st(1), st(0);			max_x - min_x
		fild k;						k, max_x - min_x
		fdivp st(1), st(0);			(max_x - min_x) / size // krok

		fld b;						b, krok
		fld p1;						p1, b, krok
		fld p2;						p2, p1, b, krok
		fld buf;					buf, p2, p1, b, krok
		fld max_x;					x, buf, p2, p1, b, krok //max_x = x!!!
	_for:
		fldpi;						pi, x, buf, p2, p1, b, krok
		fmul st(0), st(3);			pi * p2, x, buf, p2, p1, b, krok
		fmul st(0), st(1);			pi * p2 * x, x, buf, p2, p1, b, krok
		fdiv st(0), st(2);			pi * p2 * x / 180, x, buf, p2, p1, b, krok
		fcos;						cos(pi * p2 * x / 180), x, buf, p2, p1, b, krok
		fmul st(0), st(5);			b * cos(pi * p2 * x / 180), x, buf, p2, p1, b, krok
									; dla 1 obiegu //https://www.wolframalpha.com/input?i=calculate+y%2C+y%3Db*cos%28pi*p*x%2F180%29%2Cb%3D2.5%2Cp%3D4.5%2Cx%3D10

		fldpi;						pi, b * cos(pi * p2 * x / 180), x, buf, p2, p1, b, krok
		fmul st(0), st(5);			pi * p1, b * cos(pi * p2 * x / 180), x, buf, p2, p1, b, krok
		fmul st(0), st(2);			pi * p1 * x, b * cos(pi * p2 * x / 180), x, buf, p2, p1, b, krok
		fdiv st(0), st(3);			pi * p1 * x / 180, b * cos(pi * p2 * x / 180), x, buf, p2, p1, b, krok
		fsin;						sin(pi * p1 * x / 180), b * cos(pi * p2 * x / 180), x, buf, p2, p1, b, krok
		fmul st(0), st(0);			sin^2(pi * p1 * x / 180), b * cos(pi * p2 * x / 180), x, buf, p2, p1, b, krok
		fmul qword ptr[ebx];		a* sin^2(pi * p1 * x / 180), b * cos(pi * p2 * x / 180), x, buf, p2, p1, b, krok
									; dla 1 obiegu //https::www.wolframalpha.com/input?i=calculate+y%2C+y%3Da*sin%28pi*p*x%2F180%29%5E2%2Ca%3D5.5%2Cp%3D3.5%2Cx%3D10

		faddp st(1), st(0);			a* sin^2(pi * p1 * x / 180) + b * cos(pi * p2 * x / 180), x, buf, p2, p1, b, krok
		fstp qword ptr[edi + 8 * ecx - 8]; x, buf, p2, p1, b, krok
		fst qword ptr[esi + 8 * ecx - 8]; x, buf, p2, p1, b, krok
		fsub st(0), st(5);			x - krok, buf, p2, p1, b, krok
		loop _for;
		pop edi;
		pop esi;
	}
}

int main() {
	size_t k = 5;
	double* x = new double[k];
	double* y = new double[k];

	double min_x = 1.0l;
	double max_x = 10.0l;

	double b = 2.5l;
	double p1 = 3.5l;
	double p2 = 4.5l;
	double buf = 180.0l;
	
	double* a = new double{ 5.5 };
	Func(k, x, y, a, min_x, max_x, b, p1, p2, buf);

	for (auto i = 0; i < k; ++i) {
		std::cout << x[i] << std::endl;
	}

	std::cout << std::endl;

	for (auto i = 0; i < k; ++i) {
		std::cout << y[i] << std::endl;
	}
}
