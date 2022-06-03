/*
Zad 6. Proszę napisać metodę w asemblerze mnożącą dwa wektory x oraz z
zgodnie z następującym wzorem przy wykorzystaniu koprocesora. Obliczenia
wykonujemy dla zmiennych rzeczywistych typu double, rozmiar dla typu double
to 64 bity
*/
#include <iostream>

double VectorMultiplying(int n, double* x, double* z) {
	double SumOfElements = 0.0f;
	__asm {
		xor eax, eax;
		push esi;
		push edi;
		mov ecx, n;
		mov esi, x;
		mov edi, z;
		fldz
	_for:
		fld qword ptr[esi + 8 * ecx - 8]; np	6
		fld qword ptr[edi + 8 * ecx - 8]; np	2, 6	
		fmul;
		fadd;
		dec ecx;
		jnz _for
		pop edi;
		pop esi;
		fstp SumOfElements;
	}
	return SumOfElements;
}

void FreeMemory(double* x, double* z) {
	delete[] x;
	delete[] z;
}

int main() {
	const int n = 7;
	double* x = (double*)malloc(n * sizeof(double));
	double* z = (double*)malloc(n * sizeof(double));
	for (auto i = 0; i < n; ++i) {
		*(x + i) = i + 1;
		*(z + i) = i + 10;
	}
	std::cout << sizeof(double) << std::endl;
	std::cout << VectorMultiplying(n, x, z) << std::endl;
	FreeMemory(x, z);
}