#include <iostream>
#include <omp.h>

int main() {
    double sum = 0.0;
    double tab[100];

    for (int i = 0; i < 100; ++i) {
        tab[i] = i;
    }

    #pragma omp parallel
    #pragma omp for reduction(+: sum)
    for (int i = 0; i < 100; i++) 
        sum += tab[i];

    std::cout << "sum: " << sum << std::endl;
}