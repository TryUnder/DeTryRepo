#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    cout << fixed;
    cout << setw(100) << setfill('-') <<"\n";
    cout << endl << "SPRAWOZDANIE NR 9"
    << endl << "PROGRAM KOMPILUJE SIE NA KOMPILATORZE MINGW" 
    << endl << "NA SYSTEMIE OPERACYJNYM WINDOWS 10" 
    << endl << "PROGRAM DOTYCZY OBLICZANIA WIELOMIANU INTERPOLACYJNEGO (TRYGONOMETRYCZNEGO)" 
    << endl << "WYZNACZANIA WARTOSCI FUNKCJI W PUNKCIE" 
    << endl << "WYZNACZANIA WARTOSCI FUNKCJI W PUNKCIE DLA WIELOMIANU INTERPOLACYJNEGO" 
    << endl << "OBLICZANIA WARTOSCI BEZWZGLEDNYCH I WZGLEDNYCH" << endl << endl;
    int wezly,nodes;
    cout << "PODAJ LICZBE WEZLOW DLA KTORYCH CHCESZ OBLICZYC WIELOMIAN INTERPOLACYJNY:   "; cin >> wezly; cout << endl;
    cout << "PODAJ LICZBE ARGUMENTOW DLA KTORYCH CHCESZ OBLICZYC" << endl << "1)WARTOSC FUNKCJI" << endl
         << "2)WARTOSC FUNKCJI W PUNKCIE DLA WIELOMIANU INTERPOLACYJNEGO" << endl <<"3)BLAD BEZWZGLEDNY" << endl <<"4)BLAD WZGLEDNY" << endl;
    cin >> nodes; cout << endl;
    double *nodesX = new double[nodes];
    cout << "WPROWADZ WARTOSC TYCH ARGUMENTOW: " << endl;
    for(size_t i=0; i<nodes; i++)
    {
        cout << "ARGUMENT NR" << "["<< i+1 <<"]:" <<"  "; 
        cin >> nodesX[i];
    }
    double n=(wezly-1)/2;
    cout << setw(100) << setfill('-') <<"\n";
    cout << setprecision(1) << "\t\t\tDLA N = " << n << endl << endl;
    double X[wezly],Y[wezly], B[wezly], BazaInterpolacji[wezly][wezly], BazaInterpolacjiTransponowana[wezly][wezly], BazaInterpolacjiOdwrotna[wezly][wezly];
    double mnoze[wezly];
    for(size_t i=0; i<wezly; i++)
    {
        X[i] = (2*i*M_PI)/(2*n+1);
        cout << "X[" << i+1 << "]: " << X[i] << endl;
    }
    cout << setw(100) << setfill('-') <<"\n";
    for(size_t i=0; i<wezly; i++)
    {
        Y[i] = pow(X[i],2)-(3*X[i]);
        cout << "Y[" << i+1 << "]: " << Y[i] << endl;
    }
    cout << setw(100) << setfill('-') <<"\n";
    cout << "\t\t\tBAZA INTERPOLACYJNA: " << endl << endl;
    int k;
    for(size_t i=0; i<wezly; i++)
    {
        k=1;
        for(size_t j=0; j<wezly; j++)
        {
            if(j==0){BazaInterpolacji[i][j] = 1/sqrt(2);continue;}
            else
            {
                if(j%2==0){BazaInterpolacji[i][j] = cos(k*X[i]);k++;}
                else BazaInterpolacji[i][j] = sin(k*X[i]);
            }
        }
    }   
    
    for(size_t i=0; i<wezly; i++)
    {
        for(size_t j=0; j<wezly; j++)
        {
            cout << setprecision(6) << BazaInterpolacji[i][j] << "    ";
        }
        cout << endl;
    }
    cout << setw(100) << setfill('-') <<"\n";
    cout << "\t\t\tTRANSPONOWANA BAZA INTERPOLACYJNA: " << endl << endl; 
    for(size_t i=0; i<wezly; i++)
    {
        for(size_t j=0; j<wezly; j++)
        {
            BazaInterpolacjiTransponowana[i][j] = BazaInterpolacji[j][i];
            cout << BazaInterpolacjiTransponowana[i][j] << "     ";
        }
        cout << endl;
    }
    cout << setw(100) << setfill('-') <<"\n";
    cout << "\t\t\tMACIERZ ODWROTNA: " <<  endl << endl;
    for(size_t i=0; i<wezly; i++)
    {
        for(size_t j=0; j<wezly; j++)
        {
            BazaInterpolacjiOdwrotna[i][j] = 2/((2*n)+1)*BazaInterpolacjiTransponowana[i][j];
            cout << BazaInterpolacjiOdwrotna[i][j] << "     ";
        }
        cout << endl;
    }
    int suma;
    for(size_t i=0; i<wezly; i++)
    {
        for(size_t j=0; j<wezly; j++)
        {         
            mnoze[i] += BazaInterpolacjiOdwrotna[i][j] * Y[j];
        }
    }
    int s=1;
    cout << setw(100) << setfill('-') <<"\n";
    cout  << "\t\t\tWEKTORY NIEWIADOMYCH TWORZACE WIELOMIAN INTERPOLACYJNY (TRYGONOMETRYCZNY): " << endl << endl;
    for(size_t i=0; i<wezly; i++)
    {
        if(i==0){cout << "a[" << i <<"]: " << mnoze[i] << endl;continue;}
        if(i%2==1){cout << "b[" << s <<"]: " << mnoze[i] << endl;}
        else {cout << "a[" << s <<"]: " << mnoze[i] << endl;s++;}
    }
    s=1;
    cout << setw(100) << setfill('-') <<"\n";
    cout << "\t\t\tFUNKCJA Y=X^2-3*x W POSTACI WIELOMIANU TRYGONOMETRYCZNEGO: "<< endl << endl;
    cout <<"W(X)=";
    for(size_t i=0; i<wezly; i++)
    {
        if(i==0){cout << mnoze[i]/sqrt(2);if(i<wezly-1)if(mnoze[i+1]>0)cout <<"+";continue;}
        if(i%2==1){cout << mnoze[i] <<"*sin("<< s <<"*x)";if(i<wezly-1)if(mnoze[i+1]>0)cout <<"+";}
        else {cout << mnoze[i] << "*cos("<< s <<"*x)";if(i<wezly-1)if(mnoze[i+1]>0)cout <<"+";s++;}
    }
    cout << endl;    
    for(size_t p=0; p<nodes; p++)
    {     
    cout << setw(100) << setfill('-') <<"\n";
    cout << "\t\t\tOBLICZENIA DLA OBIEGU NR: " << p+1 << endl;    
    cout << endl << "Y(" << setprecision(2) << nodesX[p] <<"): "; 
    double wartosc_funkcji_bazowej = ((pow(nodesX[p],2))-(3*nodesX[p]));
    cout << wartosc_funkcji_bazowej;
    cout << endl << "W(" << setprecision(2) << nodesX[p] << "): "; 
    double wartosc_funkcji_wielomian = 0;
    s=1;
    for(size_t i=0; i<wezly; i++)
    {
        if(i==0){wartosc_funkcji_wielomian+=(mnoze[i]/sqrt(2));continue;}
        if(i%2==1){wartosc_funkcji_wielomian+=(mnoze[i]*sin(s*nodesX[p]));}
        else{wartosc_funkcji_wielomian+=(mnoze[i]*cos(s*nodesX[p]));s++;}
    }
    cout << wartosc_funkcji_wielomian << endl;

    cout << "BLAD BEZWZGLEDNY: " << setprecision(5) << abs(wartosc_funkcji_bazowej-wartosc_funkcji_wielomian) << endl;
    cout << "BLAD WZGLEDNY: " << setprecision(5) << abs((wartosc_funkcji_bazowej-wartosc_funkcji_wielomian)/wartosc_funkcji_bazowej)*100 <<"%" << endl;
    if(p==nodes-1){cout << setw(100) << setfill('-') <<"\n";delete [] nodesX;cout << endl;}
    }
    return 0;
}

