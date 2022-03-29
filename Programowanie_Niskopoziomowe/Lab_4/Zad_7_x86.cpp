#include <iostream>
using namespace std;
// do poprawy !!!

int main() {
	const int _size = 5;
	int* _arr = new int[_size];
	cout << _arr << endl;
	
	__asm {
		mov edx, 0;
		push edx;
		xor edi, edi;
		xor eax, eax;
		mov eax, 0;
		push eax;
		mov edi, _size;
		mov ecx, 1;
		mov esi, 1;
		mov ebp, _arr;
		xor ebx, ebx;
	_FOR:
		xor edx, edx;
		mov eax, esi;
		idiv ecx;
		cmp edx, 0;
		jnz _OUT;
		add ebx, 1;
	_OUT:
		dec ecx;
		jnz _FOR;
		cmp ebx, 2;
		jne _OUT2;
		pop eax;
		pop edx;
		push eax;
		inc edx;
		mov [ebp + edx - 4], esi;
		push edx;
		xor eax, eax;
		pop eax;
		inc eax;
		push eax;
	_OUT2:
		pop eax;
		cmp eax, edi;
		push eax;
		je _EQUAL;
		inc esi;
		mov ecx, esi;
		xor ebx, ebx;
		jmp _FOR;
		
	_EQUAL:
		mov _arr, ebp;
	}
	cout << _arr << endl;
	for (int i = 0; i < _size; ++i) {
		cout << _arr[i] << endl;
	}
	
}