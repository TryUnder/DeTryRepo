#include <iostream>
#include <omp.h>

int main() {
    int a, v = 0;
    #pragma omp parallel
    #pragma omp for lastprivate(a)
    for(int i = 0; i < 10; ++i) {
        a = i * 100;
        v += a;
    }

    std::cout << a << std::endl;
}