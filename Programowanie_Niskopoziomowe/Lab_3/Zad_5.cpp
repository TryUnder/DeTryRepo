#include <iostream>
using namespace std;

extern "C" __int64 case_1(int x, int op);

int main() {
	int x = 9;
	int op = 7;
	int result = case_1(x, op);
	cout << result << endl;
}
