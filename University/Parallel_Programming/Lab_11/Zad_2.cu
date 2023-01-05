#include <iostream>
#include <omp.h>

double function(double x){
    return (sqrt(1 - pow(x,2)));
}

int main() {
	unsigned int size = 100;
	double tBegin, tEnd;
	double pole = 0.0;
	unsigned int n = 1000000;
	
	double xp = -1.0 + 2.0 / size * rank;
    double xk = -1.0 + 2.0 / size * (rank + 1);
    double dx = (xk - xp) / n;
    
    tBegin = MPI_Wtime();
    for (int i = 0; i < size; ++i) {
			
	}  
}
