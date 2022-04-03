#include <iostream>
using namespace std;

int main() {
	constexpr unsigned int _size = 7;
	unsigned int* _ptr = new unsigned int[_size] {500, 1, 2, 3, 4, 100, 200};
	int result;
	__asm {
		mov esi, _ptr;
		mov ecx, _size;
		mov edi, _size;
		xor edx, edx;
	_FOR:
		mov eax, [esi + 4 * ecx - 4];
		add edx, eax;
		dec ecx;
		jnz _FOR;
		mov eax, edx;
		xor edx, edx;
		idiv edi;
		mov result, eax;
	}
	cout << result << endl;
}
