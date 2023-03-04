#include <iostream>

int main() {
    struct A {
        A() {
            std::cout << "ctor: " << this << std::endl;
        }
    };

    try {
        //"A()" jest r-wartością
        throw A();
    }

    catch (A a) {
        // a jest l-wartością

        /*
        Gdybyśmy użyli "const A& a" w definicji catch, wyjątek nadal zostałby przechwycony, ale
        referencja byłaby teraz stałą referencją do obiektu typu "A".

        Stała referencja nie pozwala na modyfikację wartości, do której odnosi się referencja.
        W przypadku "A& a", obiekt "a" w bloku catch byłby tylko do odczytu, a próba modyfikacji
        jego wartości zakończyłaby się błędem kompilacji.

        Gdybyśmy przechwycili obiekt przez wartość, na wyjściu uzyskalibyśmy inne adresy, dlatego że
        doszłoby do kopiowania.
        */
        std::cout << "catch: " << &a << std::endl;
    }
}