#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main() {
	const int _size = 1000;
	int* _arr = new int[_size];
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(500, 50000);
	for (int i = 0; i < _size; ++i) {
		_arr[i] = distrib(gen);
	}
	
	int result = _arr[0];
	for (int i = 0; i < _size; ++i) {
		if (_arr[i] > result) {
			result = _arr[i];
		}
	}
	int result2;

	__asm {
		mov esi, _arr;
		mov ecx, _size;
		mov eax, [esi + 4 * ecx - 4];
	_FOR:
		cmp eax, [esi + 4 * ecx - 4];
		jge _OUT;
		mov eax, [esi + 4 * ecx - 4];
	_OUT:
		dec ecx;
		jnz _FOR;
		mov result2, eax;
	}

	cout << "Max z CPP: " << result << endl;
	cout << "Max z ASM: " << result2 << endl;
	
}