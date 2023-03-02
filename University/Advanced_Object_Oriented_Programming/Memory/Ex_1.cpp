#include <iostream>

using namespace std;

const int test1 = 1;

int main() {
    //1.
    //*const_cast<int*>(&test1) = 10;
    //const_cast<int&>(test1) = 10;
    /*
    Te operacje sie nie wykonaja, bo test1 jest zmienna w pamieci tylko do oczytu. (Globalna stała)
    Próba zapisu do pamieci tylko do odczytu spowoduje błąd pomimo const_cast
    */

    //2.
    const volatile int test2 = 2;
    *const_cast<int*>(&test2) = 20;
    cout << test2 << endl;
    const_cast<int&>(test2) = 200;
    cout << test2 << endl;
    /*
    Te operacje sie wykonaja bo sa w pamieci do odczytu i do zapisu (w funkcji,
    ktora alokuje pamiec na stosie). Dodatkowo, `const volatile` oznacza, że wartość może
    ulec zmianie przez procesy spoza programu (sprzęt, inne wątki)
    */
    
    //3.
    static const int test3 = 3;
    //*const_cast<int*>(&test3) = 30;
    //const_cast<int&>(test3) = 30;
    /*
    zmienne `static const` są stałe i ich wartość nie może być zmieniana po inicjalizacji,
    ponieważ wartość zmiennej jest znana podczas kompilacji i jest stałą, która jest wpisana do
    kodu maszynowego programu
    */

    //4.
    //*static_cast<char *>("Hello") = 'Y';
    /*
    Próba modyfikacji stałego ciągu znaków, który znajduje się w pamięci tylko do odczytu.
    Zgodnie z zasadami języka C++, ciągi znaków przypisywane bezpośrednio do wskaźnika, są
    uważane za stałe, co oznacza, że próba modyfikacji takiego ciągu znaków jest UB
    */
}