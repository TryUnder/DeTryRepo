#include <iostream>

struct A {
    void operator = (int i) { std::cout << i << std::endl; }
};

int main() {
    A() = 1;
    A().operator=(1);

    /*
    r-wartość może być po lewej stronie, a kod nadal jest kompilowalny. 
    A() - jest r-wartością (tworzy obiekt tymczasowy), do którego możemy coś przypisać, ponieważ
    zdefiniowaliśmy operator przypisania.
    */
}