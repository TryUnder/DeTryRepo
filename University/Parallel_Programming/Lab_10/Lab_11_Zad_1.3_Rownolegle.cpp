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
    double* z = new double[size];

    for (int i = 0; i < size; ++i) {
        a[i] = (double)i/2;
        b[i] = (double)i/3;
        c[i] = (double)i/4;
        z[i] = (double)i/5;
    }

    double** A = new double* [size];
    double** E = new double* [size];

    for (int i = 0; i < size; ++i) {
        A[i] = new double[size];
        E[i] = new double[size];
        for (int j = 0; j < size; ++j) {
            A[i][j] = (double)(j+i)/7;
            E[i][j] = (double)(j+i)/8;
        }
    }

    #pragma omp parallel
    {
        for (int i = 0; i < 5; ++i) {
            #pragma omp for
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; ++k) {
                    E[j][k] = (beta * E[j][k]) - A[j][k];
                }
            }

            alfa = 0;
            #pragma omp barrier
            #pragma omp for reduction(+: alfa)
            for (int j = 0; j < size; ++j) {
                alfa += (a[j] * c[j]);
            }

            #pragma omp for
            for (int j = 0; j < size; ++j) {
                b[j] = c[j] + (alfa * a[j]);
            }

            #pragma omp for
            for (int j = 0; j < size; ++j) {
                z[j] = 0;
                for (int k = 0; k < size; ++k) {
                    z[j] = E[j][k] * b[j];
                }
            }

            #pragma omp for reduction(+: beta)
            for (int j = 0; j < size; ++j) {
                beta += (z[j] * b[j]);
            }
        }
    }
}