#include <iostream>
#include <random>
using namespace std;

extern "C" void Zad_10_x64(long long unsigned int sizex, long long unsigned int* _arr);

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> _size(1, 10);
	uniform_int_distribution<> _numbers(1, 100);
	long long unsigned int sizex = _size(gen);
	long long unsigned int* _arr = new long long unsigned int[sizex];
	for (long long unsigned int i = 0; i < sizex; ++i)
		_arr[i] = _numbers(gen);
	for (long long unsigned int i = 0; i < sizex; ++i)
		cout << _arr[i] << endl;
	cout << endl;
	
	Zad_10_x64(sizex, _arr);

	for (long long unsigned int i = 0; i < sizex; ++i)
		cout << _arr[i] << endl;

}