#include <iostream>
#include <random>
using namespace std;

extern "C" void Zad_9_x64(long long unsigned int _size, long long unsigned int* c,
						  long long unsigned int* a, long long unsigned int* b);

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> size(1, 10);
	uniform_int_distribution<> number(1, 100);
	long long unsigned int _size = size(gen);
	long long unsigned int* c = new long long unsigned int[_size];
	long long unsigned int* a = new long long unsigned int[_size];
	long long unsigned int* b = new long long unsigned int[_size];

	for (long long unsigned int i = 0; i < _size; ++i)
		a[i] = number(gen);
	for (long long unsigned int i = 0; i < _size; ++i) 
		b[i] = number(gen);
	for (long long unsigned int i = 0; i < _size; ++i)
		cout << "a[" << i << "]: " << a[i] << endl;
	cout << endl;
	for (long long unsigned int i = 0; i < _size; ++i)
		cout << "b[" << i << "]: " << b[i] << endl;
	cout << endl;

	Zad_9_x64(_size, c, a, b);

	for (long long unsigned int i = 0; i < _size; ++i)
		cout << "c[" << i << "]: " << c[i] << endl;
}