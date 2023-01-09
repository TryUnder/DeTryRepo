#include <iostream>

int main() {
    double a[100];
    double sum = 0.0;

    for (int i = 0; i < 100; ++i) {
        a[i] = i;
    }

    for (int i = 0; i < 100; ++i) {
        sum += a[i];
    }

    std::cout << "suma: " << sum << std::endl;
}