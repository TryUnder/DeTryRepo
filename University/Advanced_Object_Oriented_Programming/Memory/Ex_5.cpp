#include <iostream>
#include <string>

using namespace std;

struct A {
    A() {
        cout << "ctor\n";
    }

    ~A() {
        cout << "dtor\n";
    }
};

A* factory() {
    //7.
    return new A();
    /*
    Dane alokowane dynamicznie znajdują się w przestrzeni pamięci, która nazywa się stertą (heap).
    */
}

int main() {
    A* p = factory();
    delete p;
}