#include <mpi.h>
#include <iostream>
#include <cmath>

using namespace std;

double function(double x){
	return sqrt(1 - pow(x,2));
}

double metoda_trapezow(double n, int xp, int xk, double dx){
	double pole = 0;
	for (int i=0; i<n; ++i){
		pole = pole + function(xp+i*dx);
	}
	pole = (pole + function(xp) + function(xk)/2)*dx;
	return 2*pole;
}

int main(int argc, char** argv){
	MPI_Init(&argc, &argv);
	int n;
	double pole;
	cout << "Podaj liczbe przedzialow calkowania: ";
	cin >> n;
	double xp = -1;
	double xk = 1;
	double dx = (xk - xp)/n;

	pole = metoda_trapezow(n, xp, xk, dx);
	cout << pole << endl;
	MPI_Finalize();	
}
