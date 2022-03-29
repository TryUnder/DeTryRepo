#include <iostream>
using namespace std;
// do poprawy !!! - raz dziala raz nie

int main() {
	const int _size = 25;
	int* _arr = new int[_size];

	__asm {
		xor ebx, ebx;
		push ebx;
		xor edi, edi;
		mov ebp, _arr;
		mov edi, 25;
		mov ecx, 1;
		mov esi, 1;
	_BEFORE:
		xor ebx, ebx;
		mov ecx, esi;
	_FOR:
		xor edx, edx;
		mov eax, esi;
		idiv ecx;
		cmp edx, 0;
		jnz _OUT;
		inc ebx;
	_OUT:
		dec ecx;
		jnz _FOR;

		cmp ebx, 2;
		jne _NOT_A_PRIME;
		xor ebx, ebx;
		pop ebx;

		mov[ebp + 4 * ebx], esi;
		inc ebx;
		push ebx; 			ilo�� liczb pierwszych na stosie

	_NOT_A_PRIME:
		add esi, 1;
		cmp ebx, edi;
		jne _BEFORE;
		mov _arr, ebp;
	}

	for (int i = 0; i < _size; ++i) {
		cout << _arr[i] << endl;
	}

}
