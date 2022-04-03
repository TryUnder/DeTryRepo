#include <iostream>
using namespace std;

extern "C" __int64 if_4(int a, int b);

int main() {
	int a = 170;
	int b = 150;
	int result = if_4(a, b);
	cout << result << endl;
}
