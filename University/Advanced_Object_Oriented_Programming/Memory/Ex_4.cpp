#include <iostream>
#include <string>

using namespace std;

struct A {
    string m_name;

    A(const string& name) : m_name(name) {
        cout << "ctor: " << m_name << endl;
    }

    ~A() {
        cout << "dtor: " << m_name << endl;
    }
};

int main() {
    //7.
    A a("a, function scope");
    A b("b, function scope");

    {
        A a("a, block scope");
        A b("b, block scope");
    }

    /*
    Dane lokalne zaalokowane w funkcji są tworzone na stosie. Niszczone są automatycznie gdy sterowanie
    programu zostanie przeniesione poza zakres.
    Struktura FILO.
    */
}