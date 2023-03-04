#include <iostream>

int main() {
    int x = 1;

    ++x;

    /*
    Prefiksowa wersja operatora inkrementacji jest l-wartością, ++<expr>, ponieważ prefiksowy operator
    inkrementacji zwraca referencje do od razu inkrementowanego obiektu, jako operand.
    */

    x++;

    /*
    Sufiksowa wersja operatora inkrementacji jest r-wartością, <expr>++, ponieważ sufiksowy operator
    inkrementacji zwraca tymczasową kopie (która jest r-wartością) obiektu, którą otrzymał, jako operand.
    */

    //++1;
    //1++;

    /*
    Wymagana l-wartość. Nie da się przekonwertować r-wartości do l-wartości.
    */

    ++++x; // l-wartość
    //x++++; // r-wartość. ++ oczekuje l-wartości

    // Dlatego ++++x się kompiluje, a x++++ nie.

    /*
    Wersja prefiksowa ma pierwszeństwo przed sufiksową.
    Asocjacja prefiksowej wersji zachodzi od prawej do lewej.
    */
}