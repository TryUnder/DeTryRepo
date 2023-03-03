#include <iostream>

struct A {
    int m_t[3];

    int operator[] (unsigned i) {
        return m_t[i];
    }
};

int main() {
    A a1;
    //a1[0] = 1;
    /*
    Wbudowany operator przypisania dla intów oczekuje l-wartości po lewej stronie przypisania.
    Dlatego, że funkcja [] zwraca typ niereferencyjny, wyrażenie jest r-wartością. 
    Wyrażenie się nie skompiluje. 
    */
}