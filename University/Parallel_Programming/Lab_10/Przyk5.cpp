#include <iostream>
#include <omp.h>

// BLEDNE ROZWIAZANIE

int main() {
    double a[100];
    double sum = 0.0;

    for (int i = 0; i < 100; ++i) {
        a[i] = i;
    }

    #pragma omp parallel
    {
        #pragma omp for
        for(int i = 0; i < 100; ++i)
            #pragma omp critical
            sum += a[i];
    }

    std::cout << "suma: " << sum << std::endl;
}