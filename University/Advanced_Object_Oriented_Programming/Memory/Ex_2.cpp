#include <iostream>
using namespace std;

char t[] = "Hello!";

/*
Pamiec do odczytu i do zapisu przechowuje
    * dane globalne i statyczne o okreslonym rozmiarze
    * dane lokalne na stosie
    * dane dynamiczne na stercie
*/

/*
Dane globalne są inicjalizowane przed wejściem do maina i są dostępne wszędzie w programie
*/

int main() {
    //5.
    t[0] = 'Y';
    cout << t << endl;
    /*
    Tablica znaków (character array) (char *) może być modyfikowana,
    w przeciwieństwie do literału łancuchowego (string literal) (const char*)
    */

    /* 
    W przypadku literału łańcuchowego, np. "Hello", wartość jest już znana
    podczas kompilacji, więc kompilator może zarezerwować odpowiednią ilość miejsca
    w pamięci dla ciągu znaków.
    */

    /*
    W przypadku tablicy znaków, pamięć musi być zaalokowana przez programistę. 
    * char str[6] - znana w czasie kompilacji.
    * char* str = new char[6] - nie jest znana podczas kompilacji.
    Podczas tej lini kodu, system operacyjny alokuje w pamięci blok 6 bajtów, a
    adres początku bloku jest przypisywany do wskaźnika 'str'
    */
}