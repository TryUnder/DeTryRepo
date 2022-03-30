#include <iostream>
#include <random>
using namespace std;

extern "C" void Zad_7_x64(long long int _size, long long int* _ptr);

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(1, 100);
	long long int _size = 5;
	long long int* _arr = new long long int[_size];
	Zad_7_x64(_size,_arr);
	for (int i = 0; i < _size; ++i) {
		cout << _arr[i] << endl;
	}
}