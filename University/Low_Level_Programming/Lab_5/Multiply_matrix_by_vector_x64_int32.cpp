#include <iostream>
#include <random>
using namespace std;

extern "C" void Multiply_matrix_by_vector_x64_int32(int x, int** _mat, int *_vec, int* _vec_ret);

int main() {
	//random_device rd;
	//mt19937 gen(rd());
	//uniform_int_distribution<> distrib_(3, 5);
	//uniform_int_distribution<> distrib__(1, 100);
	//int x = distrib_(gen);
	//int y = distrib_(gen);
	int x = 3;
	int y = 3;
	int** _mat = new int* [x];
	int* _vec = new int [y]{1,2,3};
	int* _vec_ret = new int [x]{0,0,0};
	
	for (int i = 0; i < x; ++i) {
		_mat[i] = new int[x];
	}
	cout << "Macierz A: " << endl;
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			_mat[i][j] = i+j;
			cout << _mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Wektor B: " << endl;
	for (int i = 0; i < y; ++i) {
		cout << _vec[i] << endl;
	}
	cout << endl;
	cout << "Macierz A * Wektor B = " << endl;

	Multiply_matrix_by_vector_x64_int32(x,_mat, _vec, _vec_ret);

	for (int i = 0; i < y; ++i) {
		cout << _vec_ret[i] << endl;
	}

}