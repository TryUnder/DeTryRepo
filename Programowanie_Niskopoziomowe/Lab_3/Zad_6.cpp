#include <iostream>
using namespace std;

extern "C" __int64 case_2(int x, int op);

int main() {
	int x = 100;
	int op = 20;
	int result = case_2(x, op);
	cout << result << endl;
}
