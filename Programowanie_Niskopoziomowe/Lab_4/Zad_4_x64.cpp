#include <iostream>
using namespace std;

extern "C" __int64 Zad_4_x64(unsigned int _size, unsigned long long int* _ptr);

int main() {
	unsigned int _size = 5;
	unsigned long long int* _ptr = new unsigned long long int [_size] {50, 100, 30, 20, 300};
	unsigned int result = Zad_4_x64(_size, _ptr);
	cout << result << endl;
}
