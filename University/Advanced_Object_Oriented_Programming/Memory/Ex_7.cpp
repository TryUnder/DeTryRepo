#include <cassert>
#include <iostream>

int main()
{
    for(unsigned x = 1; true; ++x)
    {
        // Allocate 1 GiB.
        //9.
        std::byte *p = new std::byte [1024 * 1024 * 1024];
        /*
        Alokacja pamięci na stercie jest wolna, bo sterta jest złożoną strukturą danych.
        Dodatkowo zajmuje się fragmentacją i defragmentacją pamięci, co wymaga większej ilości operacji.
        Sterta może rozrastać się do nieograniczonych rozmiarów (kontrolowanych przez system operacyjny).
        Odmowa przydzielenia większej ilości pamięci na stercie wiąże się z wyrzuceniem wyjątku std::bad_alloc
        */
        assert(p);
        std::cout << "Allocated " << x << "GiBs." << std::endl;
    }
}