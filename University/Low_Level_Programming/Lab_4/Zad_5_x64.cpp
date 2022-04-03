#include <iostream>
using namespace std;

extern "C" __int64 Zad_5_x64(unsigned int _size, long long int* _arr);

int main() {
	const long long int _size = 5;
	long long int* _arr = new long long int[_size]{ 200, 100, 310, 800, 231 };
	long long int result = Zad_5_x64(_size, _arr);
	cout << result << endl;
}
