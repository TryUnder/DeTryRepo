#include <iostream>
#include <cmath>
#include <time.h>
#include <ctime>
using namespace std;

int* losuje_kule(const unsigned int N);
int** skreslam_liczby(int kupony);
void porownanie(int* wsk1, int** wsk2, const unsigned int N, int kupony);
int main()
{
    const unsigned int N = 7;
    int kupony;
    cout << "SYMULATOR TOTOLOTKA." << endl;
    int* wsk1 = losuje_kule(N);
    cout << "ILE KUPONOW CHCESZ SKRESLIC?: ";
    cin >> kupony;
    cout << endl;
    int** wsk2 = skreslam_liczby(kupony);
    porownanie(wsk1, wsk2, N, kupony);
    return 0;
}

int* losuje_kule(const unsigned int N)
{
    srand(time(NULL));
    int* T = new int[N];
    for (unsigned int i = 1; i < N; ++i)
    {
        T[i] = 1 + rand() % 49;
    }
    return T;
}

int** skreslam_liczby(int kupony)
{
    int** liczbakuponow = new int* [kupony];
    for (unsigned int i = 1; i <= kupony; ++i)
    {
        liczbakuponow[i] = new int[7];
        cout << "WPISZ LICZBY DO LOSOWANIA Z KUPONU: " << i << endl;
        for (unsigned int j = 1; j < 7; ++j)
        {
            cin >> liczbakuponow[i][j];
        }
    }
    return liczbakuponow;
}

void porownanie(int* wsk1, int** wsk2, const unsigned int N, int kupony)
{
    int* traf = new int[kupony];
    int liczba_trafien = 0;
    cout << "PROGRAM WYLOSOWAL: " << endl;
    for (unsigned int i = 1; i < N; ++i)
    {
        cout << wsk1[i] << "\t";
    }
    cout << endl;
    cout << "TWOJE LICZBY: " << endl;
    for (unsigned int i = 1; i <= kupony; ++i)
    {
        for (unsigned int j = 1; j < 7; ++j)
        {
            cout << wsk2[i][j] << "\t";
        }
        cout << endl;
    }
    for (unsigned int i = 1; i <= kupony; ++i)
    {
        for (unsigned int j = 1; j < 7; ++j)
        {
            if (wsk2[i][j] == wsk1[1])liczba_trafien = liczba_trafien + 1;
            if (wsk2[i][j] == wsk1[2])liczba_trafien = liczba_trafien + 1;
            if (wsk2[i][j] == wsk1[3])liczba_trafien = liczba_trafien + 1;
            if (wsk2[i][j] == wsk1[4])liczba_trafien = liczba_trafien + 1;
            if (wsk2[i][j] == wsk1[5])liczba_trafien = liczba_trafien + 1;
            if (wsk2[i][j] == wsk1[6])liczba_trafien = liczba_trafien + 1;
        }
        traf[i] = liczba_trafien;
        liczba_trafien = 0;
    }
    for (unsigned int i = 1; i <= kupony; ++i)
    {
        if ((traf[i] != 1) && (traf[i] != 0))cout << "W KUPONIE NR " << i << " TRAFILES " << traf[i] << " RAZY" << endl;
        if (traf[i] == 1)cout << "W KUPONIE NR " << i << " TRAFILES TYLKO RAZ" << endl;
        else { cout << "W KUPONIE NR " << i << " NIE TRAFILES ANI RAZU. SPROBUJ JESZCZE RAZ." << endl; }
    }
    delete[] traf;
}