#include <iostream>

int main() {
    static_cast<int*>(0);
   
    /*
    0 i nullptr są literałami reprezentującymi wartość null typu wskaźnikowego.
    Obie te wartości są r-wartościami.
    */

    //&static_cast<int*>(0);

    /*
    Error - wymagana l-wartość.
    */

    //&nullptr

    /*
    Error - wymagana l-wartość
    */
}