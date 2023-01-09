#include <iostream>
#include <omp.h>

int main(int argc, char** argv) {
	
	double tBegin, tEnd;
	
	tBegin = omp_get_wtime();
	
    unsigned int n = 2000;
    double** F = new double *[n];
    double** A = new double *[n];

    double Beta = 2.2;
    double alfa = 0.0;

    double* a = new double[n];
    double* b = new double[n];
    double* c = new double[n];
    double* e = new double[n];

    for (int i = 0; i < n; ++i) {
        a[i] = i;
        b[i] = i;
        c[i] = i;
        e[i] = i;
    }


    for (int i = 0; i < n; ++i) {
        F[i] = new double[n];
        A[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            F[i][j] = 1.4;
            A[i][j] = 1.5;
        }
    }
    for(int i = 0; i < 500; ++i) {
        //1
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                F[j][k] = (Beta * F[j][k]) - A[j][k];
            }
        }

        //2
        alfa = 0;
        for (int j = 0; j < n; ++j) {
            alfa += (a[j] * b[j]);
        }

        //3
        for (int j = 0; j < n; ++j) {
            a[j] = b[j] - (alfa * c[j]);
        }

        //4
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                e[j] = F[j][k] * a[k];
            }
        }

        //5
        for (int j = 0; j < n; ++j) {
            Beta += (e[j] * b[j]);
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         std::cout << F[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    
    tEnd = omp_get_wtime();
    
    std::cout << "Czas wyniosl: " << tEnd - tBegin << std::endl;
}
