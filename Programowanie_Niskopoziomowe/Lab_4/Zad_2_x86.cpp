#include <iostream>
using namespace std;

int main() {
	constexpr unsigned int _size = 5;
	int* v = new int[_size] {2, 7, 1, 3, 22};

	__asm {
		mov ebx, 2;
		xor edx, edx;
		mov ecx, _size;
		mov esi, v;

	_FOR:
		mov eax, [esi + 4 * ecx - 4];
		div ebx;
		mov eax, [esi + 4 * ecx - 4];
		cmp edx, 1;
		jz _REST;
		imul eax, eax;
		mov[esi + 4 * ecx - 4], eax;
		
	_REST:
		dec ecx;
		jnz _FOR;
	}
	for (int i = 0; i < _size; ++i) {
		cout << v[i] << endl;
	}

}
