#include <iostream>
using namespace std;

extern "C" __int64 if_1(int a, int b);

int main()
{
	int a = 1;
	int b = 10;
	int result;
	result = if_1(a, b);
	cout << result << endl;
}
