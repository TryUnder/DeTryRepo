#include <iostream>

int main() {
    *static_cast<int*>(0);
    
    int x = 1;
    int* p = &x;
    
    *p;
    
    /*
    Operator wyłuskania oczekuje r-wartości do tego, aby móc pobrać wartość z pamięci, na którą
    wskazuje "p". W związku z tym, że "p" jest l-wartością, (bo można pobrać jej adres (adres tego
    wskaźnika, który pokazuje na x)), zachodzi niejawna konwersja z l-wartości na r-wartość.

    Operator wyłuskania oczekuje r-wartości jako swojego operandu, aby zapobiec przypadkowej
    modyfikacji wartości, na którą wskazuje wskaźnik, przez programistę.
    */
}