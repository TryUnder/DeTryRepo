#include <iostream>
#include <random>
using namespace std;

extern "C" __int64 Zad_6_x64(long long int _size, long long int* _arr);

int main() {
	const long long int _size = 1000;
	long long int* _arr = new long long int[_size];
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distribution(1000, 100000);
	for (int i = 0; i < _size; ++i) {
		_arr[i] = distribution(gen);
	}

	int result = _arr[0];
	int result_asm;
	for (int i = 0; i < _size; ++i) {
		if (_arr[i] > result) {
			result = _arr[i];
		}
	}

	result_asm = Zad_6_x64(_size, _arr);
	cout << "Max z CPP: " << result << endl;
	cout << "Max z ASM: " << result_asm << endl;

}