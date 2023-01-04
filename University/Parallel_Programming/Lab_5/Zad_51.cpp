#include <mpi.h>
#include <iostream>
#include <cmath>

using namespace std;

double function(double x){
	return sqrt(1 - pow(x,2));
}

int main(int argc, char** argv){
	MPI_Init(&argc, &argv);
	double tBegin, tEnd;
	int n;
	double pole;
	cout << "Podaj liczbe przedzialow calkowania: ";
	cin >> n;
	tBegin = MPI_Wtime();
	double xp = -1;
	double xk = 1;
	double dx = (xk - xp)/n;

	
	for (int i=0; i<n; ++i){
		pole = pole + function(xp+i*dx);
	}
	pole = (pole + function(xp) + function(xk)/2)*dx;
	cout << 2*pole << endl;
	tEnd = MPI_Wtime();
	cout << "Czas wyniosl: " << tEnd - tBegin << endl;
	MPI_Finalize();	
}
