#include <iostream>
using namespace std;
double A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
double B[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
double C[1][1] = {1};
double Pr1[2][3] = {{1,2,3},{4,5,6}};
double Pr2[2][3] = {{1,2,3},{4,5,6}};
double Dodatkowa[2][2] = {{1,2},{3,4}};
double Pr4[1][3] = {1,2,3};
double Pr5[3][20] = {{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},
                     {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},
                     {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}};
int start;

double Wypisz_Macierz_A()
{
    int i=0;
    int j=0;
    int n=9;
        cout << "MACIERZ A: ";
        for (i;i<n;i++)
        {
           for (j;j<n;j++)
           {
               if(j%3 != 0)cout << "\t";
               if(j%3 == 0)cout << endl << endl;
               if((j==3) || (j==6)) cout <<"[ ";
               if(j==0)    cout << "[ ";
                cout << A[i][j];
                if(j==2 || j==5 || j==8) cout << " ]" << endl;
           }
        }
        return 0;
}
double Wypisz_Macierz_B()
{
    int i=0;
    int j=0;
    int n=9;
        cout << endl << "MACIERZ B: ";
        for (i;i<n;i++)
        {
           for (j;j<n;j++)
           {
               if(j%3 != 0)cout << "\t";
               if(j%3 == 0)cout << endl << endl;
               if(j==3 || j==6) cout <<"[ ";
               if(j==0)    cout << "[ ";
               cout << A[i][j];
                if(j==2 || j==5 || j==8) cout << " ]"<< endl;
           }
        }
    return 0;
}
double Wypisz_Macierz_C()
{
    cout << "MACIERZ C: " << endl << endl;
    cout << "[" << C[0][0] << "]" << endl << endl;
    return 0;
}
double Wypisz_Macierz_Prostokatna_1()
{
 int i=0;
 int j=0;
 int n=6;
 cout << "Macierz Pr1: " << endl << endl;
 cout << "[ ";
 for(i;i<n;i++)
 {
     for(j;j<n;j++)
     {
         if(j==3) cout << "[ ";
         cout << Pr1[i][j];
         if(j==2 || j == 5) cout << " ]";
         cout << "\t";
         if(j==2) cout << endl << endl << endl;

     }
         cout << endl << endl;
     return 0;
 }
}
double Wypisz_Macierz_Prostokatna_2()
{
 int i=0;
 int j=0;
 int n=6;
 cout << "Macierz Pr2: " << endl << endl;
 cout << "[ ";
 for(i;i<n;i++)
 {
     for(j;j<n;j++)
     {
         if(j==3) cout << "[ ";
         cout << Pr2[i][j];
         if(j==2 || j == 5) cout << " ]";
         cout << "\t";
         if(j==2) cout << endl << endl << endl;

     }
         cout << endl << endl;
     return 0;
 }
}
double Wypisz_Macierz_Dodatkowa_3()
{
 int i=0;
 int j=0;
 int n=4;
 cout << "Macierz Dodatkowa3: " << endl << endl;
 cout << "[ ";
 for(i;i<n;i++)
 {
     for(j;j<n;j++)
     {
         if(j==2) cout << "[ ";
         cout << Dodatkowa[i][j];
         if(j==1 || j==3) cout << " ]";
         cout << "\t";
         if(j==1) cout << endl << endl << endl;
     }
 }
 cout << endl << endl;
 return 0;
}
double Wypisz_Macierz_Prostokatna_4()
{
	cout << "Macierz Pr4: " << endl << endl;
	cout << "[" << Pr4[0][0] << "\t" << Pr4[0][1] << "\t" << Pr4[0][2];
	cout << "]" << endl << endl;
	return 0;
}
double Dodaj_Macierze_Kwadratowe()
{
    int i=0;
    int j=0;
    int n=9;
    cout << "UWAGA, ROZPOCZYNAM PROCES DODAWANIA MACIERZY KWADRATOWYCH ..." << endl << endl;
    cout << "MACIERZ D: = MACIERZ A + MACIERZ B" << endl;
        for(i;i<n;i++)
        {
            for(j;j<n;j++)
            {
                if(j%3 != 0)cout << "\t";
               if(j%3 == 0)cout << endl << endl;
               if(j==3 || j==6) cout <<"[ ";
               if(j==0)    cout << "[ ";
                cout << A[i][j]+B[i][j];
                if(j==2 || j==5 || j==8) cout << " ]" << endl;
            }
        }
        cout << endl;
        return 0;
}

double Nie_Moge_Dodac_Macierzy_Kwadratowych()
{
cout << "UWAGA, ROZPOCZYNAM PROCES DODAWANIA MACIERZY KWADRATOWYCH..." << endl << endl;
cout << "MACIERZ E: = MACIERZ A + MACIERZ C" << endl;
cout << "WYKRYTO BLAD. NIESTETY, NIE MOGE DODAC MACIERZY. WYMIAR MACIERZY A =/= WYMIARU MACIERZY C" << endl;
return 0;
}

double Odejmij_Macierze_Kwadratowe()
{
int i=0;
int j=0;
int n=9;
    cout << endl << "UWAGA, ROZPOCZYNAM PROCES ODEJMOWANIA MACIERZY KWADRATOWYCH..." << endl << endl;
    cout << "MACIERZ F: = MACIERZ A - MACIERZ B" << endl;
        for(i;i<n;i++)
        {
            for(j;j<n;j++)
            {
                if(j%3 != 0)cout << "\t";
               if(j%3 == 0)cout << endl << endl;
               if(j==3 || j==6) cout <<"[ ";
               if(j==0)    cout << "[ ";
                cout << A[i][j]-B[i][j];
                if(j==2 || j==5 || j==8) cout << " ]" << endl;
            }
        }
        return 0;
}

double Nie_Moge_Odjac_Macierzy_Kwadratowych()
{
cout << endl << "UWAGA, ROZPOCZYNAM PROCES ODEJMOWANIA MACIERZY KWADRATOWYCH..." << endl << endl;
cout << "MACIERZ G: = MACIERZ A - MACIERZ C" << endl;
cout << "WYKRYTO BLAD. NIESTETY, NIE MOGE ODJAC MACIERZY. WYMIAR MACIERZY A =/= WYMIARU MACIERZY C";
return 0;
}

double Dodaj_Macierze_Prostokatne()
{
    cout << endl << "UWAGA, ROZPOCZYNAM PROCES DODAWANIA MACIERZY PROSTOKATNYCH ..." << endl << endl;
    int i=0;
 int j=0;
 int n=6;
 cout << "MACIERZ H: = MACIERZ PR1 + MACIERZ PR2" << endl << endl;
 cout << "[ ";
 for(i;i<n;i++)
 {
     for(j;j<n;j++)
     {
         if(j==3) cout << "[ ";
         cout << Pr1[i][j]+Pr2[i][j];
         if(j==2 || j == 5) cout << " ]";
         cout << "\t";
         if(j==2) cout << endl << endl << endl;
     }
  }
  cout << endl << endl;
  return 0;
}

double Nie_Moge_Dodac_Macierzy_Prostokatnych()
{
cout << "UWAGA, ROZPOCZYNAM PROCES DODAWANIA MACIERZY PROSTOKATNYCH..." << endl << endl;
cout << "MACIERZ I: = MACIERZ Pr1 + MACIERZ Pr4" << endl;
cout << "WYKRYTO BLAD. NIESTETY, NIE MOGE DODAC MACIERZY. WYMIAR MACIERZY Pr1 =/= WYMIARU MACIERZY Pr4" << endl;
return 0;
}

double Odejmij_Macierze_Prostokatne()
{
    cout << endl << "UWAGA, ROZPOCZYNAM PROCES ODEJMOWANIA MACIERZY PROSTOKATNYCH ..." << endl << endl;
 int i=0;
 int j=0;
 int n=6;
 cout << "MACIERZ J: = MACIERZ PR1 - MACIERZ PR2" << endl << endl;
 cout << "[ ";
 for(i;i<n;i++)
 {
     for(j;j<n;j++)
     {
         if(j==3) cout << "[ ";
         cout << Pr1[i][j]-Pr2[i][j];
         if(j==2 || j == 5) cout << " ]";
         cout << "\t";
         if(j==2) cout << endl << endl << endl;
     }

  }
  cout << endl << endl;
  return 0;
}

double Nie_Moge_Odjac_Macierzy_Prostokatnych()
{
cout << endl << endl << "UWAGA, ROZPOCZYNAM PROCES ODEJMOWANIA MACIERZY PROSTOKATNYCH..." << endl << endl;
cout << "MACIERZ K: = MACIERZ PR1 - MACIERZ PR4" << endl;
cout << "WYKRYTO BLAD. NIESTETY, NIE MOGE ODJAC MACIERZY. WYMIAR MACIERZY Pr1 =/= WYMIARU MACIERZY Pr4" << endl << endl;
return 0;
}

double Moge_Pomnozyc_Macierze_Kwadratowe()
{
    cout << endl << "UWAGA, WLASNIE MNOZE MACIERZE KWADRATOWE: MACIERZ L = MACIERZ A * MACIERZ B " << endl;
    int suma;
    for(int i=0;i<3;i++) // up to number of rows in Matrix A HL
    {
        cout << "[ ";
        for(int j=0;j<3;j++) // up to number of columns in Matrix B HL
        {
            suma=0;
            for(int k=0;k<3;k++) // up to number of columns in Matrix A HL
            {
                suma=suma+ A[i][k] * B[k][j];
            }
        cout << suma;
        if (j==2)cout << " ]";
        cout << "\t";
        }
    cout << endl << endl << endl;
    }
    return 0;
}
double Nie_Moge_Pomnozyc_Macierzy_Kwadratowych()
{
    cout << "MNOZENIE MACIERZY: MACIERZ A * MACIERZ DODATKOWA. " << endl;
    cout << "WYKRYTO BLAD. NIE MOGE POMNOZYC MACIERZY. LICZBA KOLUMN MACIERZY A (3) =/= LICZBY WIERSZY MACIERZY DODATKOWEJ (2)" << endl;
    return 0;
}

double Moge_Pomnozyc_Macierze_Prostokatne()
{
    int suma;
    cout << endl << endl << "UWAGA. WLASNIE MNOZE MACIERZE PROSTOKATNE: MACIERZ Pr4 * MACIERZ Pr5" << endl;
    cout << "[ ";
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<20;j++)
        {
            suma=0;
            for(int k=0;k<3;k++)
            {
                suma=suma+Pr4[i][k] * Pr5[k][j];
            }
            cout << suma;
            if(j==19) cout << " ]";
            cout << "\t";
        }
        cout << endl;
    }
    return 0;
}
double Nie_Moge_Pomnozyc_Macierzy_Prostokatnych()
{
    cout << endl << endl << "MNOZENIE MACIERZY: MACIERZ C * MACIERZ Pr4 " << endl;
    cout << "WYKRYTO BLAD. NIE MOGE POMNOZYC MACIERZY. LICZBA KOLUMN MACIERZY C (1) =/= LICZBY WIERSZY MACIERZY Pr5 (3)" << endl;
    return 0;
}

int main()
{
    cout << "KOMPILUJE SIE NA PEWNO NA CODEBLOCKS 20.03 (WIN10), oraz na kompilatorze: "
                                    << endl
         << "MinGW-W64-builds-4.3.5"
                                    << endl
    << "DOTYCZY: "                  << endl
    << "\t - DODAWANIA MACIERZY"    << endl
    << "\t - ODEJMOWANIA MACIERZY"  << endl
    << "\t - MNOZENIA MACIERZY"     << endl << endl;
    start = Wypisz_Macierz_A();
    start = Wypisz_Macierz_B();
    start = Wypisz_Macierz_C();
    start = Wypisz_Macierz_Prostokatna_1();
    start = Wypisz_Macierz_Prostokatna_2();
    start = Wypisz_Macierz_Dodatkowa_3();
	start = Wypisz_Macierz_Prostokatna_4();
	start = Dodaj_Macierze_Kwadratowe();
    start = Nie_Moge_Dodac_Macierzy_Kwadratowych();
	start = Odejmij_Macierze_Kwadratowe();
    start = Nie_Moge_Odjac_Macierzy_Kwadratowych();
	start = Dodaj_Macierze_Prostokatne();
	start = Nie_Moge_Dodac_Macierzy_Prostokatnych();
	start = Odejmij_Macierze_Prostokatne();
	start = Nie_Moge_Odjac_Macierzy_Prostokatnych();
	start = Moge_Pomnozyc_Macierze_Kwadratowe();
	start = Nie_Moge_Pomnozyc_Macierzy_Kwadratowych();
	start = Moge_Pomnozyc_Macierze_Prostokatne();
	start = Nie_Moge_Pomnozyc_Macierzy_Prostokatnych();
    return 0;
}
