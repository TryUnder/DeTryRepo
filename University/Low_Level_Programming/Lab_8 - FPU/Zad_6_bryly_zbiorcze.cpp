/*
Zad 6. Proszę wyznaczyć Pc, Pb, V prostopadłościanu, szescianu, .. przy użyciu funkcji asemblerowych :
do uzupelnienia dla reszty bryl
*/
#include <iostream>

template <typename T>
auto PbProstopadloscian(T a, T b) {
	auto result = 0.0f;
	__asm {
		fld a;					a
		mov eax, 4;
		mov a, eax;
		fld b;					b, a
		fmulp st(1), st(0);		ab
		fild a;					4, ab
		fmulp st(1), st(0);		4ab
		fstp result;
	}
	return result;
}

template <typename T>
auto PcProstopadloscian(T a, T b, T c) {
	auto result = 0.0f;
	__asm {
		fld a;					a
		fld b;					b, a
		fld c;					c, b, a
		fmul st(1), st(0);		c, bc, a
		fmulp st(2), st(0);		bc, ac
		fld a;					a, bc, ac
		fld b;					b, a, bc, ac
		fmulp st(1), st(0);		ab, bc, ac
		faddp st(1), st(0);		bc + ab, ac
		faddp st(1), st(0);		ac + bc + ab
		fld1;					1, ac + bc + ab
		fld1;					1, 1, ac + bc + ab
		faddp st(1), st(0);		2, ac + bc + ab
		fmulp st(1), st(0);		2(ac + bc + ab)
		fstp result;
	}
	return result;
}

template <typename T>
auto VProstopadloscian(T a, T b, T c) {
	auto result = 0.0f;
	__asm {
		fld a;					a
		fld b;					b, a
		fld c;					c, b, a
		fmulp st(1), st(0);		bc, a
		fmulp st(1), st(0);		abc
		fstp result;
	}
	return result;
}

template <typename T>
auto DProstopadloscian(T a, T b, T c) {
	auto result = 0.0f;
	__asm {
		fld a;					a
		fmul st(0), st(0);		a2
		fld b;					b, a2
		fmul st(0), st(0);		b2, a2
		fld c;					c, b2, a2
		fmul st(0), st(0);		c2, b2, a2
		faddp st(1), st(0);		b2 + c2, a2
		faddp st(1), st(0);		a2 + b2 + c2
		fsqrt;					sqrt(a2 + b2 + c2)
		fstp result;
	}
	return result;
}

template <typename T>
auto PbSzescianu(T a) {
	double result = 0.0f;
	__asm {
		fld a;					a
		fmul st(0), st(0);		a2
		mov eax, 4;
		mov a, eax;
		fild a;					4, a2
		fmulp st(1), st(0);		4a2
		fstp result;
	}
	return result;
}

template <typename T>
auto PcSzescianu(T a) {
	double result = 0.0f;
	__asm {
		fld a;					a;
		fmul st(0), st(0);		a2
		mov eax, 6;
		mov a, eax;
		fild a;					6, a2
		fmulp st(1), st(0);		6a2
		fstp result;
	}
	return result;
}

template <typename T>
auto VSzescianu(T a) {
	double result = 0.0f;
	__asm {
		fld a;					a
		fmul st(0), st(0);		a2
		fld a;
		fmulp st(1), st(0);		a3
		fstp result;
	}
	return result;
}

template <typename T>
auto DSzescianu(T a) {
	double result = 0.0f;
	__asm {
		fld a;					a
		mov a, 3;
		fild a;					3, a
		fsqrt;					sqrt(3), a
		fmulp st(1), st(0);		a * sqrt(3)
		fstp result;
	}
	return result;
}

template <typename T>
auto HTrojkRow(T a) {
	double result = 0.0f;
	__asm {
		fld a;					a
		mov a, 2;
		fild a;					2, a
		mov a, 3;				
		fild a;					3, 2, a
		fsqrt;					sqrt(3), 2, a
		fmulp st(2), st(0);		2, a* sqrt(3)
		fdivp st(1), st(0);		a* sqrt(3) / 2
		fstp result;
	}
	return result;
}

template <typename T>
auto PTrojkRow(T a) {
	double result = 0.0f;
	__asm {
		fld a;					a
		fmul st(0), st(0);		a2
		mov a, 3;
		fild a;					3, a2
		mov a, 4;				
		fild a;					4, 3, a2
		fxch st(1);				3, 4, a2
		fsqrt;					sqrt(3), 4, a2
		fmulp st(2), st(0);		4, a2 * sqrt(3)
		fdivp st(1), st(0);
		fstp result;
	}
	return result;
}

template <typename T>
auto PcOstPrawCzwor(T a, T h) {
	double result = 0.0f;
	__asm {
		fld a;					a
		fld a;					a, a
		fmul st(1), st(0);		a, a2
		fld h;					h, a, a2
		mov a, 2;
		fild a;					2, h, a, a2
		fmulp st(1), st(0);		2h, a, a2
		fmulp st(1), st(0);		2ah, a2
		faddp st(1), st(0);		a2+2ah
		fstp result;
	}
	return result;
}

template <typename T>
auto VOstPrawCzwor(T a, T h) {
	double result = 0.0f;
	__asm {
		fld a;					a;
		fmul st(0), st(0);		a2
		fld h;					h, a2
		fmulp st(1), st(0);		a2*h
		mov a, 3
		fild a;					3, a2*h
		fdivp st(1), st(0);		a2*h/3
		fstp result;
	}
	return result;
}


int main() {
	std::cout << "Pb Prostopadloscian: " << PbProstopadloscian(2.3f, 3.5f) << std::endl;
	//https://www.wolframalpha.com/input?i=4ab%2C+a%3D2.3%2Cb%3D3.5

	std::cout << "Pc Prostopadloscian: " << PcProstopadloscian(2.3f, 3.5f, 7.6f) << std::endl;
	//https://www.wolframalpha.com/input?i=2%28ab%2Bbc%2Bac%29%2C+a%3D2.3%2Cb%3D3.5%2Cc%3D7.6

	std::cout << "V Prostopadloscian: " << VProstopadloscian(2.3f, 3.5f, 7.6f) << std::endl;
	//https://www.wolframalpha.com/input?i=abc%2C+a%3D2.3%2Cb%3D3.5%2Cc%3D7.6

	std::cout << "D Prostopadloscian: " << DProstopadloscian(2.3f, 3.5f, 7.6f) << std::endl;
	//https://www.wolframalpha.com/input?i=sqrt%28a%5E2%2Bb%5E2%2Bc%5E2%29%2C+a%3D2.3%2Cb%3D3.5%2Cc%3D7.6

	std::cout << "**************************************************************" << std::endl;

	std::cout << "Pb Szescianu: " << PbSzescianu(2.3f) << std::endl;
	//https://www.wolframalpha.com/input?i=4*a%5E2%2Ca%3D2.3

	std::cout << "Pc Szescianu: " << PcSzescianu(2.3f) << std::endl;
	//https://www.wolframalpha.com/input?i=6*a%5E2%2Ca%3D2.3

	std::cout << "V Szescianu: " << VSzescianu(2.3f) << std::endl;
	//https://www.wolframalpha.com/input?i=a%5E3%2Ca%3D2.3

	std::cout << "D Szescianu: " << DSzescianu(2.3f) << std::endl;
	//https://www.wolframalpha.com/input?i=a*sqrt%283%29%2Ca%3D2.3

	std::cout << "**************************************************************" << std::endl;

	std::cout << "H Trojk. Rown.: " << HTrojkRow(2.3f) << std::endl;
	//https://www.wolframalpha.com/input?i=a*sqrt%283%29%2F2%2Ca%3D2.3

	std::cout << "P Trojk. Rown.: " << PTrojkRow(2.3f) << std::endl;
	//https://www.wolframalpha.com/input?i=a%5E2*sqrt%283%29%2F4%2Ca%3D2.3

	std::cout << "**************************************************************" << std::endl;

	std::cout << "Pc Ost. Praw. Czwor.: " << PcOstPrawCzwor(2.5f, 10.3f) << std::endl;
	//https://www.wolframalpha.com/input?i=a%5E2%2B2*a*h%2Ca%3D2.5%2Ch%3D10.3

	std::cout << "V Ost. Praw. Czwor.: " << VOstPrawCzwor(2.5f, 10.3f) << std::endl;
	//https://www.wolframalpha.com/input?i=1%2F3*a%5E2*h%2Ca%3D2.5%2Ch%3D10.3

}