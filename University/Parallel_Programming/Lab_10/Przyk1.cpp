#include <iostream>
#include <omp.h>

int main() {
    double a[8];
    omp_set_num_threads(8);
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        a[id] = id;
        std::cout << id << std::endl;
    }
    std::cout << "ok " << std::endl;
}