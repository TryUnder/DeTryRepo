#include <iostream>
#include <random>
using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> _size(1, 10);
	uniform_int_distribution<> _numbers(1, 100);
	unsigned int sizex = _size(gen);
	unsigned int* _arr = new unsigned int[sizex];
	for (unsigned int i = 0; i < sizex; ++i)
		_arr[i] = _numbers(gen);
	for (unsigned int i = 0; i < sizex; ++i)
		cout << _arr[i] << endl;
	cout << endl;
	__asm {
		mov esi, _arr;
		mov ecx, sizex;
	_FOR:
		mov edi, 1;
		mov eax, [esi + 4 * ecx - 4];
		mov ebx, eax;
	_NE:
		cmp edi, ebx;
		jne _INC;
		mov [esi + 4 * ecx - 4], eax;
		loop _FOR;
		jmp _EXIT;
	_INC:
		add eax, ebx;
		inc edi;
		jmp _NE;
	_EXIT:
	}

	for (unsigned int i = 0; i < sizex; ++i)
		cout << _arr[i] << endl;

}