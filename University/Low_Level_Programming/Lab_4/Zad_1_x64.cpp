#include <iostream>
using namespace std;

extern "C" void zad_1(unsigned int _size, long long int* v);

int main() {
	unsigned int _size = 5;
	long long int* v = new long long int[_size] {1, 2, 3, 4, 5};
	zad_1(_size, v);

	for (int i = 0; i < _size; ++i) {
		cout << v[i] << endl;
	}

}
