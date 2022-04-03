#include <iostream>
using namespace std;

extern "C" void Zad_2_x64(unsigned int _size, long long int* arr);

int main() {
	const unsigned int _size = 5;
	long long int* arr = new long long int [_size] {37, 42, 88, 31, 55};
	Zad_2_x64(_size, arr);
	for (unsigned int i = 0; i < _size; ++i) {
		cout << arr[i] << endl;
	}
}
