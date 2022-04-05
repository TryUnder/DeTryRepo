#include <iostream>
#include <random>
using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib_(2, 5);
	uniform_int_distribution<> distrib__(1, 100);
	int x = distrib_(gen);
	int y = distrib_(gen);
	int **_arr = new int *[x];
	for (int i = 0; i < x; ++i) {
		_arr[i] = new int[y];
	}

	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			_arr[i][j] = distrib__(gen);
			cout << _arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int result = 0;
	__asm {
		xor eax, eax;
		mov ebx, x;
		mov esi, _arr;
	_OUTER:
		mov ecx, y;
		mov edx, [esi + 4 * ebx - 4];
	_FOR:
		add eax, [edx + 4 * ecx - 4];
		dec ecx;
		JNZ _FOR;
		dec ebx;
		JNZ _OUTER;
		mov result, eax;
	}

	cout << "Suma elementow macierzy wynosi: " << result << endl;
}