#include <iostream>

int main(int argc, char** argv) {
    unsigned int n = 2;
    double** F = new double *[n];
    double** A = new double *[n];

    double Beta = 2.2;
    double alfa = 0.0;

    double* a = new double[n] {1.5, 2.5};
    double* b = new double[n] {3.5, 4.5};
    double* c = new double[n] {5.5, 6.5};
    double* e = new double[n] {7.5, 8.5};
    for (int i = 0; i < n; ++i) {
        F[i] = new double;
        A[i] = new double;
        for (int j = 0; j < n; ++j) {
            F[i][j] = 1.4;
            A[i][j] = 1.5;
        }
    }
    for(int i = 0; i < 5; ++i) {
        //1
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                F[j][k] = (Beta * F[j][k]) - A[j][k];
            }
        }

        //2
        for (int j = 0; j < n; ++j) {
            alfa +=  (a[j] * b[j]);
        }

        //3
        for (int j = 0; j < n; ++j) {
            a[j] = b[j] - (alfa * c[j]);
        }

        //4
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                e[j] = F[j][k] * a[j];
            }
        }

        //5
        for (int j = 0; j < n; ++j) {
            Beta += (e[j] * b[j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << F[i][j] << " ";
        }
        std::cout << std::endl;
    }
}