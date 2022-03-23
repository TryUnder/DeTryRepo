//DO POPRAWY

#include <iostream>
using namespace std;

extern "C" void Zad_3_x64(unsigned int _size, long long unsigned int* v);

int main() {
	const unsigned int _size = 7;
	long long unsigned int* v = new long long unsigned int [_size] {1, 2, 3, 4, 5, 100, 200};

	cout << "Tablica przed operacja zerowania co drugiego elementu: " << endl;
	for (unsigned int i = 0; i < _size; ++i) {
		cout << v[i] << " ";
		if (i == _size - 1)
			cout << endl;
	}

	Zad_3_x64(_size, v);

	cout << "Tablic po operacji zerowania co drugiego elementu: " << endl;
	for (unsigned int i = 0; i < _size; ++i) {
		cout << v[i] << " ";
		if (i == _size - 1)
			cout << endl;
	}
}
