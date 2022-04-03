#include <iostream>
using namespace std;
extern "C" int suma(int a, int b);

int main(int argc, char* argv[]) {
	int a = 10;
	int b = 20;
	int c;
	c = suma(a, b);
	cout << "Suma=" << c << endl;
	return 0;
}
