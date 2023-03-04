#include <iostream>

int main() {
    struct A {
        void operator = (int i) & {
            std::cout << "l" << std::endl;
        }

        void operator = (int i) && = delete;
    };

    A a;
    a = 1; 
    //A().operator=(1);

    /*
    Operator przypisania wywołany na wyrażeniu która jest l-wartością skompiluje się, ponieważ 
    zdefiniowaliśmy jego przeciążoną wersje, która może być wywołana tylko dla l-wartości.

    W przypadku wywołania funkcji na rzecz obiektu tymczasowego (r-wartości), dojdzie do błędu kompilacji,
    bowiem w ramach deklaracji takowej funkcji, jawnie powiedzieliśmy, że chcemy aby operator przypisania
    nie został wywoływany na rzecz r-wartości "&& = delete".
    */
}