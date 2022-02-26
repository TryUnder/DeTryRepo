/*
Proszę napisać program obliczający objętość sześcianu o boku a.
*/

#include <iostream>
using namespace std;

int main(){
	unsigned int a,result;
	cout << "Wprowadz a:"; cin >> a;
	__asm {
		mov eax, a;
		mov ebx, a;
		mul ebx;
		mul ebx;
		mov result, eax;
	}
	cout << "Objetosc szescianu o boku " << a << " wynosi: " << result << endl;
}
