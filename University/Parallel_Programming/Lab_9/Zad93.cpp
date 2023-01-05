#include <iostream>
#include <omp.h>
#include <cmath>

double function(double x) {
	return (sqrt(1 - pow(x,2)));
}

double metoda_trapezow(int n, int xp, int xk, double dx){
	double pole = 0;
	for (int i=0; i<n; ++i){
		pole = pole + function(xp+i*dx);
	}
	pole = (pole + function(xp) + function(xk)/2)*dx;
	return 2*pole;
}

double metoda_trapezow2(int n, int xp, int xk, double dx) {
	double pole = 0.0;
	#pragma omp parallel
	{
		#pragma omp for reduction(+: pole)
		for (int i=0; i<n; ++i){
			pole = pole + function(xp+i*dx);
		}
	}
	pole = (pole + function(xp) + function(xk)/2)*dx;
	return 2*pole;
}

int main(int argc, char** argv) {
	int n;
	double tBegin, tEnd, time;
	double pole = 0.0;
	
	tBegin = omp_get_wtime();
	std::cout << "Podaj liczbe przedzialow calkowania: ";
	std::cin >> n;
	double xp = -1;
	double xk = 1;
	double dx = (xk - xp)/n;

	pole = metoda_trapezow(n, xp, xk, dx);
	tEnd = omp_get_wtime();
	std::cout << pole << std::endl;
	std::cout << "czas sekwencyjnie: " << tEnd - tBegin << std::endl;
	pole = 0.0;
	
	tBegin = omp_get_wtime();
	pole = metoda_trapezow2(n, xp, xk, dx);
	tEnd = omp_get_wtime();
	std::cout << pole << std::endl;
	std::cout << "czas rownolegle: " << tEnd - tBegin << std::endl;
}
