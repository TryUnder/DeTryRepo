/*
Konstruktor kopiujący używany jest do:
    1) kopiowania obiektu przy inicjalizacji innego obiektu:
        MyClass obj1;
        MyClass obj2 = obj1;
    
    2) przekazywania obiektu jako parametru do funkcji:
        void myFunction(const MyClass& obj) {
            // ...
        }

        MyClass obj;
        myFunction(obj); // przekazywanie obiektu przez referencję przy użyciu konstruktora kopiującego

    3) zwracanie obiektu przez funkcję:
        MyClass myFunction() {
            MyClass obj;
            return obj; // zwracanie obiektu przy użyciu konstruktora kopiującego
        }
*/

/*
Operator przypisania używany jest do:
    1) przypisania wartości jednego obiektu do drugiego:
        MyClass obj1, obj2;
        obj2 = obj1; // przypisanie wartości przy użyciu operatora przypisania
*/

/*
W każdej z powyższych sytuacji konstruktor kopiujący i operator przypisania są wywoływane w celu
skopiowania wartości jednego obiektu do drugiego.
*/

#include <iostream>
#include <string>

using namespace std;

struct A {
    string m_name;

    A(const string& name): m_name(name) {
        cout << "ctor: " << m_name << endl;
    }

    A(const A& a) {
        cout << "copy-ctor: " << a.m_name << endl;
        m_name = a.m_name + " copy";
    }

    void hello() const {
        cout << "Hello from: " << m_name << endl;
    }
};

void foo(A a) {
    a.hello();
}

void goo(const A& a) {
    a.hello();
}

int main() {
    //10.
    foo(A("foo"));
    goo(A("goo"));
    /*
    a) Przy kompilacji z flagą -fno-elide-constructors i -std=c++14 zostaną wywołane następujące
    konstruktory:
        1) W funkcji main() zostanie utworzony obiekt tymczasowy typu A przy użyciu konstruktora
        parametrycznego i wartości "foo". W tym przypadku nie zostanie zastosowana optymalizacja RVO,
        więc konstruktor parametryczny zostanie wywołany bezpośrednio dla tworzonego obiektu
        tymczasowego.

        2) Przy wywołaniu funkcji foo() następuje kopiowanie wartości przekazanej jako argument,
        czyli kopiowanie obiektu tymczasowego utworzonego w punkcie 1. Dlatego zostanie wywołany
        konstruktor kopiujący z parametrem obiektu tymczasowego, a na wyjściu pojawi się komunikat
        "copy-ctor: foo".

        3) W funkcji main zostanie utworzony obiekt tymczasowy typu A przy użyciu konstruktora
        parametrycznego i wartości "goo". W tym przypadku nie zostanie zastosowana optymalizacja RVO,
        więc konstruktor parametryczny zostanie wywołany bezpośrednio dla tworzonego obiektu
        tymczasowego.

        4) Przy wywołaniu funkcji goo() przekazany jest obiekt tymczasowy utworzony w punkcie 4 przez
        stałą referencję, więc konstruktor kopiujący nie zostanie wywołany. Zostanie wywołana jedynie
        metoda hello(), która wyświetli komunikat "Hello from: goo".
    
    b) Przy kompilacji z flagą -std=c++17 zostaną wywołane następujące konstruktory:
        1) Dzięki optymalizacji RVO (Return Value Optimization) nie zostanie utworzony obiekt
        tymczasowy dla typu A i wartości "foo". Obiekt przekazywany do funkcji będzie 
        bezpośrednio inicjalizowany za pomocą konstruktora przenoszącego.
        
        2) Obiekt `A("goo")` zostanie przekazany do funkcji `goo()` przez stałą referencję. Nie jest
        wymagane utworzenie obiektu tymczasowego, ponieważ nie jest wymagane kopiowanie obiektu 'A'.
    */
}