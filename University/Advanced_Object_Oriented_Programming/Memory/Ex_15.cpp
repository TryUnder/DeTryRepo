#include <iostream>
#include <string>

using namespace std;

struct A {
    A() {
        cout << "default-ctor" << endl;
    }

    A(const A& a) {
        cout << "copy-ctor" << endl;
    }

    ~A() {
        cout << "dtor" << endl;
    }
};

// Global data
A a;

A foo() {
    // zwracamy a z funkcji, a nie globalne
    static A a;
    return a;
}

A goo() {
    return a;
}

int main() {
    foo();
    goo();
}