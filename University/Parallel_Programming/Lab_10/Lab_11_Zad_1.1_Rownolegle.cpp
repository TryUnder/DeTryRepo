#include <iostream>
#include <omp.h>

int main() {
    double tBegin, tEnd;
    tBegin = omp_get_wtime();

    double alfa = 1.1;
    double beta = 2.2;

    const unsigned int size = 2000;

    double* a = new double[size];
    double* b = new double[size];
    double* c = new double[size];
    double* d = new double[size];
    double* e = new double[size];

    for (int i = 0; i < size; ++i) {
        a[i] = (double)i/2;
        b[i] = (double)i/3;
        c[i] = (double)i/4;
        d[i] = (double)i/5;
        e[i] = (double)i/6;
    }

    double** A = new double* [size];
    double** F = new double* [size];

    for (int i = 0; i < size; ++i) {
        A[i] = new double[size];
        F[i] = new double[size];
        for (int j = 0; j < size; ++j) {
            A[i][j] = (double)(j+i)/7;
            F[i][j] = (double)(j+i)/8;
        }
    }
    #pragma omp parallel
    {
        for (int i = 0; i < 5; ++i) {
            #pragma omp for
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; ++k) {
                    A[j][k] = (beta * A[j][k]) - F[j][k];
                }
            }

            /* Pewnie dlatego że w pierwszym zapisujesz 
            do alfy i w każdym rdzeniu musisz mieć wartość 0  
            A w drugim jest +=
            */

            alfa = 0;
            #pragma omp barrier
            #pragma omp for reduction(+: alfa)
            for (int j = 0; j < size; ++j) {
                alfa = a[j] * b[j];
            }

            #pragma omp for
            for (int j = 0; j < size; ++j) {
                d[j] = (alfa * a[j]) - c[j];
            }

            #pragma omp for
            for (int j = 0; j < size; ++j) {
                e[j] = 0;
                for (int k = 0; k < size; ++k) {
                    e[j] = A[j][k] * d[j];
                }
            }

            #pragma omp for reduction(+: beta)
            for (int j = 0; j < size; ++j) {
                beta += a[j] * e[j];
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            //std::cout << F[i][j] << " ";
        }
        //std::cout << std::endl;
    }

    tEnd = omp_get_wtime();
    std::cout << "Calosc zajela: " << tEnd - tBegin << " czasu" << std::endl;

}