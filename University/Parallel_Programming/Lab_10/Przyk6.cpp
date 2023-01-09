#include <iostream>
#include <omp.h>

// ROZWIAZANIE POPRAWNE

int main() {
    double a[100];
    double sum = 0.0;

    for (int i = 0; i < 100; ++i) {
        a[i] = i;
    }

    #pragma omp parallel
    {
        double lsum = 0.0;
        
        #pragma omp for
        for (int i = 0; i < 100; ++i)
            lsum += a[i];

        #pragma omp critical
            sum += lsum;
    }
    std::cout << "suma: " << sum << std::endl;
}