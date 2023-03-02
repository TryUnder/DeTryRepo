#include <iostream>

using namespace std;

struct A {
    A() {
        cout << "default-ctor" << endl;
    }

    A(const A &a) {
        cout << "copy-ctor" << endl;
    }

  ~A() {
    cout << "dtor" << endl;
  }
};

A foo() {
    return A();
}
//13.
A a = foo();

/*
Legacy C++14 -fno-elide-constructors
1."default-ctor" - Tworzony jest tymczasowy obiekt typu "A" w funkcji "foo()".

2."copy-ctor" - Wartość zwracana z funkcji "foo()" jest kopiowana na stos, ponieważ flaga
"-fno-elide-constructors" jest ustawiona, co powoduje wywołanie konstruktora kopiującego.

3."dtor" - Tymczasowy obiekt typu "A" zostaje usunięty z foo(), co powoduje wywołanie destruktora

4."copy-ctor" - Wartość zwrócona z funkcji "foo()" jest kopiowana do zmiennej a za pomocą
konstruktora kopiującego.

5."dtor" - Wywołanie destruktora "A" dla obiektu tymczasowego, który został stworzony podczas
inicjalizacji obiektu "a" przez wartość zwróconą przez funkcję "foo()".

6.Wywołanie destruktora A dla obiektu "a", który jest zniszczony przy zakończeniu programu.
*/

/*
W C++17, jeśli zwracamy wartość przez funkcje, to kompilator może zignorować kroki kopiowania i 
bezpośrednio utworzyć ten obiekt w miejscu docelowym. Jest to nazywane optymalizacją zwijania
wartości (copy elision), która polega na wyeliminowaniu kroków kopiowania lub przesuwania, gdy
jest to możliwe.

Wywołany zostanie jedynie kostruktor domyślny w momencie inicjalizacji zmiennej globalnej "a".
Wywołanie destruktora zostanie wykonane tylko raz, po zakończeniu działania programu.
*/
int main() {

}