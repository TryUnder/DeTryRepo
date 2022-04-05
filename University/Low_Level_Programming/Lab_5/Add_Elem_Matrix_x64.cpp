#include <iostream>
#include <random>
using namespace std;

extern "C" __int64 Add_Elem_Matrix_x64(long long int x, long long int y, int** _arr);

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib_(2, 5);
	uniform_int_distribution<> distrib__(1, 100);
	long long int x = distrib_(gen);
	long long int y = distrib_(gen);
	int **_arr = new int *[x]; 
	/*
		Zewnętrzny wskaźnik jest zawsze takiego typu, na jakiej architekturze pracujemy. 
		Wewnętrzny z kolei jeest takiego typu, jaki zadeklarujemy.
		W tym przypadku używam 32 bit. w celu sprawdzenia DWORD PTR, oraz instrukcji MOVSXD
	*/
	for (int i = 0; i < x; ++i) {
		_arr[i] = new int[y]; 
	}

	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			_arr[i][j] = distrib__(gen);
			cout << _arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	long long int result = Add_Elem_Matrix_x64(x,y,_arr);

	cout << "Suma elementow macierzy wynosi: " << result << endl;
}