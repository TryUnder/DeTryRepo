#include <iostream>

using namespace std;

void foo(long int x) {
    //8.
    int y = x;
    /*
    Alokacja pamięci na stosie jest szybsza. Wystarczy tylko zwiększyć wartość rejestru stosu.
    Dodatkowo, szybkość dostępu do kolokowanych danych na stosie jest jeszcze szybsza dzięki
    temu, że znajdują się pamięci podręcznej procesora. 
    Stos ma określony rozmiar, jednakże niektóre systemy operacyjne potrafią zwiększać wartość stosu.
    */
    cout << y << endl;
    foo(++y);
}

int main() {
    foo(0);
}