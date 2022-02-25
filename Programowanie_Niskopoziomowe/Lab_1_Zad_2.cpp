/*
Proszę obliczyć wartość y:
y=ax2 + bx + c
dla zadanych parametrów a, b, c i x.
*/

#include <iostream>
using namespace std;

int main(){
	signed int a, b, c, x;
	signed int result = 0;
	cout << "Wprowadz a:"; cin >> a;
	cout << "Wprowadz b:"; cin >> b;
	cout << "Wprowadz c:"; cin >> c;
	cout << "Wprowadz x:"; cin >> x;
	cout << "y=" << a << "*" << "pow(" << x << ",2)+" << b << "*" << x << "+" << c << endl;
	__asm {
		mov eax, x;
		mov ebx, x;
		mul eax;
		mov result, eax;
		mov ecx, a;
		mov eax, result;
		mul ecx;
		mov result, eax;
		xor eax, eax;
		xor ebx, ebx;
		mov eax, b;
		mov ebx, x;
		mul ebx;
		add result, eax;
		xor ebx, ebx;
		mov ebx, c;
		add result, ebx;
	}
	cout << "Dla zadanych parametrow y=" << result << endl;
}
