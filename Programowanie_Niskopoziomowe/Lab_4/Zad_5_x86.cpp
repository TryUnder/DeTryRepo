#include <iostream>
using namespace std;

int main() {
	const int _size = 7;
	int* v = new int[_size] {4, 87, 1, 85, 5, 10, 20};
	int result;
	__asm {	
		mov ecx, _size;
		mov esi, v;
		mov eax, [esi + 4 * ecx - 4];
	_FOR:
		cmp eax, [esi + 4 * ecx - 4];
		jnge _OUT;
		mov eax, [esi + 4 * ecx - 4];
	_OUT:
		dec ecx; 
		jnz _FOR;
		mov result, eax;
	}
	cout << result << endl;
}
