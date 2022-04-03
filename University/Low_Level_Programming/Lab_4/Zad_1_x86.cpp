#include <iostream>
using namespace std;

int main() {
	constexpr unsigned int _size = 5;
	int* v = new int[_size] {1, 2, 3, 4, 5};
	__asm {
		mov edx, _size;
		mov esi, v;

	_FOR:
		mov eax, [esi + 4 * edx - 4];
		imul eax, eax;
		mov[esi + 4 * edx - 4], eax;
		dec edx;
		jnz _FOR;
	}
	for (int i = 0; i < _size; ++i) {
		cout << v[i] << endl;
	}

}
