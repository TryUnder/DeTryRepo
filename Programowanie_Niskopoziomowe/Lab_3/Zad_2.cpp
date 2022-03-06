#include <iostream>
using namespace std;

extern "C" __int64 if_2(int a, int b);

int main() {
	int a = 10;
	int b = 5;
	int result = if_2(a, b);
	cout << result << endl;
}
