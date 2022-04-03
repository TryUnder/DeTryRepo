#include <iostream>
#include <random>
using namespace std;

extern "C" void Zad_8_x64(long long int _size, long long int* _v, long long int* _w);

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(1, 100);
	uniform_int_distribution<> size(1, 10);
	long long int _size = size(gen);
	long long int* _v = new long long int[_size];
	long long int* _w = new long long int[_size];
	for (int i = 0; i < _size; ++i) {
		_v[i] = distrib(gen);
		_w[i] = distrib(gen);
	}
	for (int i = 0; i < _size; ++i) {
		cout << "v[i]:" << _v[i] << "\t\t" << "w[i]: " << _w[i];
		cout << endl;
	}
	cout << endl;

	Zad_8_x64(_size, _v, _w);

	for (int i = 0; i < _size; ++i) {
		cout << "v[i]+w[i]=" << _v[i];
		cout << endl;
	}
}