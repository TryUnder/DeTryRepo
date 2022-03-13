#include <iostream>
using namespace std;

extern "C" __int64 _1(int a, int b, int w);

int main() {
	int a = 15;
	int b = 20;
	int w = 0;
	int wynik = _1(a, b, w);
	cout << wynik << endl;
}
