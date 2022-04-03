#include <iostream>
#include <random>
using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> size(1, 10);
	uniform_int_distribution<> number(1, 100);
	unsigned int _size = size(gen);
	unsigned int* c = new unsigned int[_size];
	unsigned int* a = new unsigned int[_size];
	unsigned int* b = new unsigned int[_size];

	for (unsigned int i = 0; i < _size; ++i)
		a[i] = number(gen);
	for (unsigned int i = 0; i < _size; ++i) 
		b[i] = number(gen);
	for (unsigned int i = 0; i < _size; ++i)
		cout << "a[" << i << "]: " << a[i] << endl;
	cout << endl;
	for (unsigned int i = 0; i < _size; ++i)
		cout << "b[" << i << "]: " << b[i] << endl;
	cout << endl;

	__asm {
		mov ecx, _size;
		mov esp, c;
		mov esi, a;
		mov edi, b;
;
	_FOR:
		xor edx, edx;
		mov eax, [esi + 4 * ecx - 4];
		mov ebx, [edi + 4 * ecx - 4];
		div ebx;
		mov [esp + 4 * ecx - 4], eax;
		loop _FOR;
	}

	for (unsigned int i = 0; i < _size; ++i)
		cout << "c[" << i << "]: " << c[i] << endl;
}