#include <iostream>
using namespace std;

extern "C" __int64 if_3(int a, int b);

int main() {
	int a = 50;
	int b = 100;
	int result = if_3(a,b);
	cout << result << endl;
}
