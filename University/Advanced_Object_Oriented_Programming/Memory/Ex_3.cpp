#include <iostream>

using namespace std;

struct A {
    A() {
        cout << "A" << endl;
    }
};

void foo (bool flag) {
    cout << "foo" << endl;
    if (flag) {
        //6.
        static A a;
        /*
        Dane statyczne są inicjalizowane przed pierwszym użyciem i dostępne tylko w funkcji
        */
    }
}

int main() {
    cout << "Main" << endl;
    foo(false);
    foo(true);
    foo(true);
}