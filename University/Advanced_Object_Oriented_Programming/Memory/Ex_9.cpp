#include <iostream>
#include <string>

using namespace std;

struct A {
    string m_name;

    A(const string& name): m_name(name) {
        cout << "ctor: " << m_name << endl;
    }

    A(const A &a) {
        cout << "copy-ctor: " << a.m_name << endl;
        m_name = a.m_name + " copy";
    }

    void hello() const {
        cout << "Hello from " << m_name << endl;
    }
};

A foo() {
    //12.
    A a("foo");
    /*
    W C++ legacy, przy zwracaniu wartości przez funkcje, kopiowała ona przy pomocy konstruktora
    kopiującego obiekt najpierw na stos, a później ze stosu do miejsca docelowego. Od C++17 
    został wprowadzony konstruktor przenoszący, który może być utworzony niejawnie przez kompilator,
    podczas optymalizacji gdy zwracamy obiekt z funkcji.
    */
    return a;
}

A& goo() {
    static A a("goo");
    return a;
}

int main() {
    //11.
    foo().hello();
    goo().hello();
    /*
    Nie skompiluje się, bo kod próbuje wywołać metodę 'hello()' na obiekcie 'A', który jest zwracany
    przez wartość z funkcji 'foo()'. Zwracany obiekt jest kopiowany, za pomocą domyślnego konsturktora
    kopiującego, jednak próba wywołania tej metody jest niepoprawna. Obiekt ten jest tymczasowy i ma
    czas życia tylko do końca instrukcji wywołania.

    #edit skompilowalo sie, ale nadal jest pewnie UB..
    */
}