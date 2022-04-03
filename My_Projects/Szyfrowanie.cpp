#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main(int argc, char* argv[])
{
    if ((argc == 1) || (argc == 2))
    {
        cerr << "ZA MALO PARAMETROW" << endl << endl;
        cerr << "PROGRAM DOTYCZY SZYFROWANIA DANYCH" << endl;
        cerr << "ABY MOGL ZADZIALAC POPRAWNIE, WPISZ: " << endl;
        cerr << "PARAMETRY URUCHOMIENIA PROGRAMU PO SPACJI: " << endl;
        cerr << "PIERWSZY PARAMETR - SLOWO DO ZASZYFROWANIA SKLADAJACE SIE Z LITER BEZ POLSKICH ZNAKOW" << endl;
        cerr << "DRUGI PARAMETR - 4 CYFROWY PIN - ZAPAMIETAJ GO" << endl;
        return 0;
    }
    cout << "NAPISZ PROGRAM KTORY M.IN PRZY POMOCY FUNKCJI BIBLIOTECZNYCH (STRING) ZASZYFRUJE" << endl
        << "PODANE PRZEZ UZYTKOWNIKA SLOWO POBRANE Z POZIOMU LINII URUCHOMIENIA PROGRAMU, WYPISZE JE NA EKRANIE" << endl
        << "ORAZ ODSZYFRUJE." << endl << endl;
    cout << "WPISANE SLOWO PRZEZ UZYTKOWNIKA: " << argv[1] << endl;
    string dane = argv[1];
    string* Tablica = new string[dane.length()];
    string* Tablica2 = new string[dane.length()];
    cout << "ROZPOCZYNAM PROCES SZYFROWANIA DANYCH" << endl << "TO CHWILE POTRWA." << endl;
    Sleep(1000);
    cout << "3" << endl;
    Sleep(1000);
    cout << "2" << endl;
    Sleep(1000);
    cout << "1" << endl << endl << endl;

    for (unsigned int i = 0; i < dane.length(); i++)
    {
        if (dane.at(i) == 'A') Tablica[i] = "00E";
        if (dane.at(i) == 'B') Tablica[i] = "01E";
        if (dane.at(i) == 'C') Tablica[i] = "02E";
        if (dane.at(i) == 'D') Tablica[i] = "03E";
        if (dane.at(i) == 'E') Tablica[i] = "04E";
        if (dane.at(i) == 'F') Tablica[i] = "05E";
        if (dane.at(i) == 'G') Tablica[i] = "06E";
        if (dane.at(i) == 'H') Tablica[i] = "07E";
        if (dane.at(i) == 'I') Tablica[i] = "08E";
        if (dane.at(i) == 'J') Tablica[i] = "09E";
        if (dane.at(i) == 'K') Tablica[i] = "10E";
        if (dane.at(i) == 'L') Tablica[i] = "11E";
        if (dane.at(i) == 'M') Tablica[i] = "12E";
        if (dane.at(i) == 'N') Tablica[i] = "13E";
        if (dane.at(i) == 'O') Tablica[i] = "14E";
        if (dane.at(i) == 'P') Tablica[i] = "15E";
        if (dane.at(i) == 'Q') Tablica[i] = "16E";
        if (dane.at(i) == 'R') Tablica[i] = "17E";
        if (dane.at(i) == 'S') Tablica[i] = "18E";
        if (dane.at(i) == 'T') Tablica[i] = "19E";
        if (dane.at(i) == 'U') Tablica[i] = "20E";
        if (dane.at(i) == 'V') Tablica[i] = "21E";
        if (dane.at(i) == 'W') Tablica[i] = "22E";
        if (dane.at(i) == 'X') Tablica[i] = "23E";
        if (dane.at(i) == 'Y') Tablica[i] = "24E";
        if (dane.at(i) == 'Z') Tablica[i] = "25E";
        if (dane.at(i) == 'a') Tablica[i] = "26E";
        if (dane.at(i) == 'b') Tablica[i] = "27E";
        if (dane.at(i) == 'c') Tablica[i] = "28E";
        if (dane.at(i) == 'd') Tablica[i] = "29E";
        if (dane.at(i) == 'e') Tablica[i] = "30E";
        if (dane.at(i) == 'f') Tablica[i] = "31E";
        if (dane.at(i) == 'g') Tablica[i] = "32E";
        if (dane.at(i) == 'h') Tablica[i] = "33E";
        if (dane.at(i) == 'i') Tablica[i] = "34E";
        if (dane.at(i) == 'j') Tablica[i] = "35E";
        if (dane.at(i) == 'k') Tablica[i] = "36E";
        if (dane.at(i) == 'l') Tablica[i] = "37E";
        if (dane.at(i) == 'm') Tablica[i] = "38E";
        if (dane.at(i) == 'n') Tablica[i] = "39E";
        if (dane.at(i) == 'o') Tablica[i] = "40E";
        if (dane.at(i) == 'p') Tablica[i] = "41E";
        if (dane.at(i) == 'q') Tablica[i] = "42E";
        if (dane.at(i) == 'r') Tablica[i] = "43E";
        if (dane.at(i) == 's') Tablica[i] = "44E";
        if (dane.at(i) == 't') Tablica[i] = "45E";
        if (dane.at(i) == 'u') Tablica[i] = "46E";
        if (dane.at(i) == 'v') Tablica[i] = "47E";
        if (dane.at(i) == 'w') Tablica[i] = "48E";
        if (dane.at(i) == 'x') Tablica[i] = "49E";
        if (dane.at(i) == 'y') Tablica[i] = "50E";
        if (dane.at(i) == 'z') Tablica[i] = "51E";
    }
    string dane2;
    for (unsigned int i = 0; i < dane.length(); i++)
    {
        dane2.append(Tablica[i]);
    }
    cout << "POMYSLNIE ZASZYFROWANE DANE" << endl;
    cout << "SLOWO W POSTACI ZASZYFROWANEJ: " << dane2 << endl;
    cout << "CZY CHCESZ ODSZYFROWAC SLOWO? " << endl << "WPISZ: "
        << endl << "\"0\" - NIE"
        << endl << "\"1\" - TAK"
        << endl;
    int i, pin;
    cin >> i;
    if (i)
    {
        cout << "ABY MOC ODSZYFROWAC DANE WPROWADZ PIN: " << endl;
        cin >> pin;
        int pin_bazowy = atoi(argv[2]);
        if (pin_bazowy == pin)
        {
            cout << "PODALES PRAWIDLOWY PIN" << endl
                << "ROZPOCZYNAM PROCES DESZYFROWANIA DANYCH" << endl
                << "TO CHWILE POTRWA" << endl;
            Sleep(1000);
            cout << "3" << endl;
            Sleep(1000);
            cout << "2" << endl;
            Sleep(1000);
            cout << "1" << endl << endl << endl;
            int i = 0;
            for (unsigned int j = 0; j <= dane2.length(); j += 3)
            {
                if (dane2.substr(j, 3) == "00E") Tablica2[i] = "A";
                if (dane2.substr(j, 3) == "01E") Tablica2[i] = "B";
                if (dane2.substr(j, 3) == "02E") Tablica2[i] = "C";
                if (dane2.substr(j, 3) == "03E") Tablica2[i] = "D";
                if (dane2.substr(j, 3) == "04E") Tablica2[i] = "E";
                if (dane2.substr(j, 3) == "05E") Tablica2[i] = "F";
                if (dane2.substr(j, 3) == "06E") Tablica2[i] = "G";
                if (dane2.substr(j, 3) == "07E") Tablica2[i] = "H";
                if (dane2.substr(j, 3) == "08E") Tablica2[i] = "I";
                if (dane2.substr(j, 3) == "09E") Tablica2[i] = "J";
                if (dane2.substr(j, 3) == "10E") Tablica2[i] = "K";
                if (dane2.substr(j, 3) == "11E") Tablica2[i] = "L";
                if (dane2.substr(j, 3) == "12E") Tablica2[i] = "M";
                if (dane2.substr(j, 3) == "13E") Tablica2[i] = "N";
                if (dane2.substr(j, 3) == "14E") Tablica2[i] = "O";
                if (dane2.substr(j, 3) == "15E") Tablica2[i] = "P";
                if (dane2.substr(j, 3) == "16E") Tablica2[i] = "Q";
                if (dane2.substr(j, 3) == "17E") Tablica2[i] = "R";
                if (dane2.substr(j, 3) == "18E") Tablica2[i] = "S";
                if (dane2.substr(j, 3) == "19E") Tablica2[i] = "T";
                if (dane2.substr(j, 3) == "20E") Tablica2[i] = "U";
                if (dane2.substr(j, 3) == "21E") Tablica2[i] = "V";
                if (dane2.substr(j, 3) == "22E") Tablica2[i] = "W";
                if (dane2.substr(j, 3) == "23E") Tablica2[i] = "X";
                if (dane2.substr(j, 3) == "24E") Tablica2[i] = "Y";
                if (dane2.substr(j, 3) == "25E") Tablica2[i] = "Z";
                if (dane2.substr(j, 3) == "26E") Tablica2[i] = "a";
                if (dane2.substr(j, 3) == "27E") Tablica2[i] = "b";
                if (dane2.substr(j, 3) == "28E") Tablica2[i] = "c";
                if (dane2.substr(j, 3) == "29E") Tablica2[i] = "d";
                if (dane2.substr(j, 3) == "30E") Tablica2[i] = "e";
                if (dane2.substr(j, 3) == "31E") Tablica2[i] = "f";
                if (dane2.substr(j, 3) == "32E") Tablica2[i] = "g";
                if (dane2.substr(j, 3) == "33E") Tablica2[i] = "h";
                if (dane2.substr(j, 3) == "34E") Tablica2[i] = "i";
                if (dane2.substr(j, 3) == "35E") Tablica2[i] = "j";
                if (dane2.substr(j, 3) == "36E") Tablica2[i] = "k";
                if (dane2.substr(j, 3) == "37E") Tablica2[i] = "l";
                if (dane2.substr(j, 3) == "38E") Tablica2[i] = "m";
                if (dane2.substr(j, 3) == "39E") Tablica2[i] = "n";
                if (dane2.substr(j, 3) == "40E") Tablica2[i] = "o";
                if (dane2.substr(j, 3) == "41E") Tablica2[i] = "p";
                if (dane2.substr(j, 3) == "42E") Tablica2[i] = "q";
                if (dane2.substr(j, 3) == "43E") Tablica2[i] = "r";
                if (dane2.substr(j, 3) == "44E") Tablica2[i] = "s";
                if (dane2.substr(j, 3) == "45E") Tablica2[i] = "t";
                if (dane2.substr(j, 3) == "46E") Tablica2[i] = "u";
                if (dane2.substr(j, 3) == "47E") Tablica2[i] = "v";
                if (dane2.substr(j, 3) == "48E") Tablica2[i] = "w";
                if (dane2.substr(j, 3) == "49E") Tablica2[i] = "x";
                if (dane2.substr(j, 3) == "50E") Tablica2[i] = "y";
                if (dane2.substr(j, 3) == "51E") Tablica2[i] = "z";
                i++;
            }

            string deszyfrowane_dane;
            for (unsigned int i = 0; i < dane.length(); i++)
            {
                deszyfrowane_dane.append(Tablica2[i]);
            }
            cout << "DANE PO OPERACJI DESZYFROWANIA: " << deszyfrowane_dane << endl;
        }
    }
    cout << "KONCZE DZIALANIE";
    delete[] Tablica;
    Tablica = nullptr;
    delete[] Tablica2;
    Tablica2 = nullptr;
    return 0;
}