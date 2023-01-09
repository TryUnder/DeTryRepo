#include <omp.h>
#include <iostream>

int main() {
    double a = 1.0;
    double b = 2.0;
    double c = 3.0;

    omp_set_num_threads(8);

    #pragma omp parallel private(b) firstprivate(c)
    {
        // a jest zmienną wspólną dla wszystkich wątków równą 1
        std::cout << a << std::endl;
    }
}