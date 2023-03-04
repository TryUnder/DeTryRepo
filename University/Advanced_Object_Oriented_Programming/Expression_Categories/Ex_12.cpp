#include <iostream>

struct A {
 A() {}
};

int& loo() {
    return *static_cast<int*>(0);
    
    /*
    Jeżeli funkcja którą definiujemy, ma zwracać typ referencyjny, to w rzeczywistości może zwracać
    l-wartość, albo r-wartość.

    Jeśli funkcja zwraca referencję do zmiennej lub pola obiektu, to zwraca l-wartość, czyli referencję
    do obiektu, którego adres możemy pobrać.
    
    W przypadku, gdy funkcja zwraca referencję do obiektu tymczasowego lub obiektu, który nie jest
    przechowywany w zmiennej, to zwraca r-wartość, czyli referencję do obiektu, który jest 
    traktowany jako tymczasowy i nie może być modyfikowany.

    Kod się kompiluje, ponieważ funkcja "loo()" zwraca referencję do wartości tymczasowej.

    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    Rzeczywiście, int* sugeruje, że pracujemy z adresem, jednak static_cast<int*>(0)
    nie tworzy adresu ani żadnej zmiennej typu int*.
    Wyrażenie to jest rzutowaniem wartości stałej 0 na typ wskaźnika do int, a 
    0 jest wartością stałą, która nie ma przypisanego miejsca w pamięci, 
    a co za tym idzie, nie jest adresem. Dlatego static_cast<int*>(0)
    zwraca r-wartość, a nie l-wartość.
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    
    Bez operatora dereferencji "*" zwracane wyrażenie "static_cast<int*>(0)" jest r-wartością,
    a próba przypisania r-wartości do l-wartości powoduje błąd, który mówi, że :
    "initial value of reference to non-const must be an lvalue".
    */
}

int main() {
    loo();
    int& l = loo();
}