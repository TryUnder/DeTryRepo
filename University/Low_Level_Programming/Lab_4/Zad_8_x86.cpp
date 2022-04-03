#include <iostream>
#include <random>
using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(1, 100);
	uniform_int_distribution<> size(1, 10);
	int _size = size(gen);
	int* _v = new int[_size];
	int* _w = new int[_size];
	for (int i = 0; i < _size; ++i) {
		_v[i] = distrib(gen);
		_w[i] = distrib(gen);
	}
	for (int i = 0; i < _size; ++i) {
		cout << "v[i]:" << _v[i] << "\t\t" << "w[i]: " << _w[i];
		cout << endl;
	}
	cout << endl;

	__asm {
		mov ecx, _size;
		mov esi, _v;
		mov edi, _w;
	_FOR:
		mov eax, [esi + 4 * ecx - 4];
		add eax, [edi + 4 * ecx - 4];
		mov [esi + 4 * ecx - 4], eax;
		loop _FOR;
	}

	for (int i = 0; i < _size; ++i) {
		cout << "v[i]+w[i]=" << _v[i];
		cout << endl;
	}
}