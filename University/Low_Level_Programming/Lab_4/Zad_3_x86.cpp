#include <iostream>
using namespace std;

int main() {
	int _size = 7;
	int* v = new int [_size] {1, 2, 3, 4, 5, 100, 200};

	cout << "Tablica przed operacja zerowania co drugiego elementu: " << endl;
	for (unsigned int i = 0; i < _size; ++i) {
		cout << v[i] << " ";
		if (i == _size - 1)
			cout << endl;
	}

	__asm {
		mov esi, v;
		mov ebx, 2;
		mov edi, _size;
	_FOR:
		xor edx, edx;
		mov eax, edi;
		idiv ebx;
		cmp edx, 1;
		jz _REST;
		mov [esi + 4 * edi - 4], 0;
	_REST:
		dec edi;
		jnz _FOR;
	}

	cout << "Tablic po operacji zerowania co drugiego elementu: " << endl;
	for (unsigned int i = 0; i < _size; ++i) {
		cout << v[i] << " ";
		if (i == _size - 1)
			cout << endl;
	}
}
