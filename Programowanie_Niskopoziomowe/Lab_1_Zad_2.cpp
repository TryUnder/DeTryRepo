/*
Proszę obliczyć wartość y:
y=ax2 + bx + c
dla zadanych parametrów a, b, c i x.
*/

#include <iostream>
using namespace std;

int main() {
	signed int a, b, c, x;
	signed int result = 0;
	cout << "Wprowadz a:"; cin >> a;
	cout << "Wprowadz b:"; cin >> b;
	cout << "Wprowadz c:"; cin >> c;
	cout << "Wprowadz x:"; cin >> x;
	cout << "y=" << a << "*" << "pow(" << x << ",2)+" << b << "*" << x << "+" << c << endl;
	__asm {
		mov eax, x;
		mov edx, x;
		imul eax;
		mov ebx, eax;
		mov ecx, a;
		mov eax, ebx;
		imul ecx;
		mov ebx, eax;
		xor eax, eax;
		xor edx, ebx;
		mov eax, b;
		mov edx, x;
		imul edx;
		add ebx, eax;
		xor edx, ebx;
		mov edx, c;
		add ebx, edx;
		mov result, ebx;
	}
	cout << "Dla zadanych parametrow y=" << result << endl;
}
