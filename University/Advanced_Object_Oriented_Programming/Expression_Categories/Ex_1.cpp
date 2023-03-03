#include <iostream>

int main() {
    const int i = 1;

    &i; // Wyrażenie "i" jest l-wartością
    //&2; // Wyrażenie "2" jest r-wartością

    // i = 2 // Błąd, pomimo tego, że "i" jest l-wartością
}