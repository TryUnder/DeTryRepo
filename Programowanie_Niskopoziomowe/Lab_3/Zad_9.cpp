#include <iostream>
using namespace std;

extern "C" __int64 _WHILE_1(int a, int r, int max);

int main() {
	int wynik = 0;
	int a = 5;
	int r = 7;
	int max = 50;
	wynik = _WHILE_1(a, r, max);
	cout << wynik << endl;
}
