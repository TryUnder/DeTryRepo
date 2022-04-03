// Ten plik jest kontynuacja sprawozdania 10 z dodanymi dwoma algorytmami.
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>

using namespace std;
void IntroduceMe();
double funkcja(double x);
double metoda_prostokatow(double n, int xp, double dx);
double fblad_bezwzgledny(double& blad_bezwzgledny, double& prawdziwa_calka, double& pole);
double fblad_wzgledny(double& blad_bezwzgledny, double& blad_wzgledny, double& prawdziwa_calka);
double metoda_trapezow(double n, int xp, int xk, double dx);
double metoda_simsona(double n, int xp, int xk, double dx);
double metoda_monte_carlo(double n, int xp, int xk);

int main()
{
    srand((unsigned)time(NULL));
    cout << setw(100) << setfill('-') << "\n";
    IntroduceMe();
    cout << setw(100) << setfill('-') << "\n";
    int xp,xk,metoda;
    double n;
    double prawdziwa_calka,pole,blad_bezwzgledny,blad_wzgledny;
    cout << "WPROWADZ DOLNA GRANICE CALKOWANIA: "; cin >> xp;
    cout << "WPROWADZ GORNA GRANICE CALKOWANIA: "; cin >> xk;
    cout << "WPROWADZ LICZBE PODZIALOW: "; cin >> n;
    cout << "WPROWADZ PRAWDZIWA WARTOSC CALKI: "; cin >> prawdziwa_calka;
    double dx = (xk-xp)/n;
    cout << "WYBIERZ METODE OBLICZANIA CALKI OZNACZONEJ: " << endl;
    cout << "WPISZ \"1\" - METODA PROSTOKATOW" << endl;
    cout << "WPISZ \"2\" - METODA TRAPEZOW" << endl;
    cout << "WPISZ \"3\" - METODA SIMSONA" << endl;
    cout << "WPISZ \"4\" - METODA MONTE CARLO" << endl;
    cin >> metoda;
    if(metoda==1)
    {
        cout << "OGRANICZENIE DOLNE WYNOSI: " << xp << endl;
        cout << "OGRANICZENIE GORNE WYNOSI: " << xk << endl;
        cout << "LICZBA PODZIALOW WYNOSI: " << n << endl;
        cout << "PRAWDZIWA WARTOSCI CALKI WYNOSI: " << prawdziwa_calka << endl;
        pole = metoda_prostokatow(n,xp,dx);
        cout << "CALKA OZNACZONA OBLICZONA METODA PROSTOKATOW WYNOSI: " << pole << endl; 
        cout << "BLAD BEZWZGLEDNY WYNOSI: " << fblad_bezwzgledny(blad_bezwzgledny,prawdziwa_calka,pole) << endl;
        cout << "BLAD WZGLEDNY WYNOSI: " << fblad_wzgledny(blad_bezwzgledny,blad_wzgledny,prawdziwa_calka) << "%" << endl;
        cout << setw(100) << setfill('-') << "\n";
    }
    if(metoda==2)
    {
        cout << "OGRANICZENIE DOLNE WYNOSI: " << xp << endl;
        cout << "OGRANICZENIE GORNE WYNOSI: " << xk << endl;
        cout << "LICZBA PODZIALOW WYNOSI: " << n << endl;
        cout << "PRAWDZIWA WARTOSCI CALKI WYNOSI: " << prawdziwa_calka << endl;
        pole = metoda_trapezow(n,xp,xk,dx);
        cout << "CALKA OZNACZONA OBLICZONA METODA TRAPEZOW WYNOSI: " << pole << endl;
        cout << "BLAD BEZWZGLEDNY WYNOSI: " << fblad_bezwzgledny(blad_bezwzgledny,prawdziwa_calka,pole) << endl;
        cout << "BLAD WZGLEDNY WYNOSI: " << fblad_wzgledny(blad_bezwzgledny,blad_wzgledny,prawdziwa_calka) << "%" << endl;
        cout << setw(100) << setfill('-') << "\n";
    }
    if(metoda==3)
    {
        cout << "OGRANICZENIE DOLNE WYNOSI: " << xp << endl;
        cout << "OGRANICZENIE GORNE WYNOSI: " << xk << endl;
        cout << "LICZBA PODZIALOW WYNOSI: " << n << endl;
        cout << "PRAWDZIWA WARTOSCI CALKI WYNOSI: " << prawdziwa_calka << endl;
        pole = metoda_simsona(n,xp,xk,dx);
        cout << "CALKA OZNACZONA OBLICZONA METODA SIMSONA WYNOSI: " << pole << endl;
        cout << "BLAD BEZWZGLEDNY WYNOSI: " << fblad_bezwzgledny(blad_bezwzgledny,prawdziwa_calka,pole) << endl;
        cout << "BLAD WZGLEDNY WYNOSI: " << fblad_wzgledny(blad_bezwzgledny,blad_wzgledny,prawdziwa_calka) << "%" << endl;
        cout << setw(100) << setfill('-') << "\n";
    }
    if(metoda==4)
    {
        cout << "OGRANICZENIE DOLNE WYNOSI: " << xp << endl;
        cout << "OGRANICZENIE GORNE WYNOSI: " << xk << endl;
        cout << "LICZBA PODZIALOW WYNOSI: " << n << endl;
        cout << "PRAWDZIWA WARTOSCI CALKI WYNOSI: " << prawdziwa_calka << endl;
        pole = metoda_monte_carlo(n,xp,xk);
        cout << "CALKA OZNACZONA OBLICZONA METODA MONTE CARLO WYNOSI: " << pole << endl;
        cout << "BLAD BEZWZGLEDNY WYNOSI: " << fblad_bezwzgledny(blad_bezwzgledny,prawdziwa_calka,pole) << endl;
        cout << "BLAD WZGLEDNY WYNOSI: " << fblad_wzgledny(blad_bezwzgledny,blad_wzgledny,prawdziwa_calka) << "%" << endl;
        cout << setw(100) << setfill('-') << "\n";
    }
    return 0;
}

void IntroduceMe()
{
    cout      << "PROGRAM KOMPILUJE SIE NA IDE: " << endl
			  << "MICROSOFT VISUAL CODE NA KOMPILATORZE MINGW - GNU GCC 6.3.0" << endl
			  << "PROGRAM DOTYCZY OBLICZANIA CALKI OZNACZONEJ Z FUNKCJI Y=|10+cos(x)|" << endl;
}

double funkcja(double x)
{
    return abs(10+cos(x));
}

double metoda_prostokatow(double n,int xp,double dx)
{
    double pole = 0;
    for(int i=0; i<n; i++)
    {
        pole = pole + (funkcja(xp+i*dx));
    }
    pole = pole*dx;
    return pole;
}

double metoda_trapezow(double n, int xp, int xk, double dx)
{
    double pole = 0;
    for(int i=1; i<n; i++)
    {
        pole = pole + funkcja(xp+i*dx);
    }
    pole = (pole + funkcja(xp)+funkcja(xk)/2)*dx;
    return pole;
}

double metoda_simsona(double n, int xp, int xk, double dx)
{
    double pole = 0, polowa = 0;
    for(int i=1; i<n; i++)
    {
        double x = xp + i*dx;
        polowa += funkcja(x-(dx/2));
        if(i<n)
        {
            pole += funkcja(x);
        }
    }
    pole = (dx/6)*(funkcja(xp)+funkcja(xk)+2*pole+4*polowa);
    return pole;
}

double metoda_monte_carlo(double n, int xp, int xk)
{
    double dx = xk - xp;
    double pole = 0;
    double random_number = 0;
    for(int i=1; i<= n; i++)
    {
        random_number = (double)rand()/RAND_MAX;
        pole += funkcja(random_number*dx);
    }
    pole = dx * pole / n;
    return pole;
}

double fblad_bezwzgledny(double& blad_bezwzgledny, double& prawdziwa_calka, double& pole)
{
    blad_bezwzgledny = abs(prawdziwa_calka - pole);
    return blad_bezwzgledny;
}

double fblad_wzgledny(double& blad_bezwzgledny, double& blad_wzgledny, double& prawdziwa_calka)
{
    blad_wzgledny = abs(blad_bezwzgledny/prawdziwa_calka)*100;
    return blad_wzgledny;
}