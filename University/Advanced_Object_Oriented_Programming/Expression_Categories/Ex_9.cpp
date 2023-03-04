#include <iostream>

struct A {
    A() {
        std::cout << "ctor: " << std::endl;
    }
};

void foo(const A& a) {
    /*
    Pomimo tego, że "a" jest parametrem typu stałej referencji, która wiąże się z r-wartością, to 
    wyrażenie jest l-wartością.

    Wyrażenie "const A& a" jest l-wartością, ponieważ jest to referencja stała do obiektu typu
    "A". Referencja ta jest zawsze l-wartością, ponieważ referencja w C++ jest tylko aliasem do już
    istniejącego obiektu. W przypadku wywołania funkcji "foo(A())", wyrażenie "A()" jest tymczasowym
    obiektem, który istnieje tylko w momencie wywołania funkcji i jest tymczasowy. 
    Referencja "a" odnosi się do tego tymczasowego obiektu, który jest r-wartością.
    */
    std::cout << "foo: " << &a << std::endl;
}

int main() {
    // "A()" jest r-wartością
    foo(A());
}