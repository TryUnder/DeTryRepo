#include <iostream>
using namespace std;

extern "C" __int64 _FACTORIAL(int n);

int main() {
	constexpr int n = 5;
	int result = _FACTORIAL(n);
	cout << result << endl;
}
