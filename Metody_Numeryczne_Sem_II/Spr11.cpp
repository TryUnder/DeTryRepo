#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void IntroduceMe();
double function(double x);
double bisection(double a, double b, double epsilon0, double epsilon1, int iter, double wartosc_dokladna);
double falsi(double a, double b, double epsilon0, double epsilon1, int iter, double wartosc_dokladna);
double secant(double a, double b, double epsilon0, double epsilon1, int iter, double wartosc_dokladna);
double fblad_wzgledny(double& blad_bezwzgledny, double& wartosc_dokladna, double& wartosc_przyblizona);
double fblad_wzgledny(double& blad_bezwzgledny, double& blad_wzgledny, double& wartosc_dokladna);

int main()
{
    IntroduceMe();
    double epsilon0 = 0.0001,epsilon1 = 0.001, wartosc_dokladna = 2.0943948960782;
    cout << "EPSILON0: " << epsilon0 << endl;
    cout << "EPSILON1: " << epsilon1 << endl;
    int iter = 20;
    cout << "LICZBA ITERACJI: " << iter << endl << endl;
    double a=1.5,b=2.5;
    double rozw_bisekcja = bisection(a,b,epsilon0,epsilon1,iter,wartosc_dokladna);
    double rozw_falsi = falsi(a,b,epsilon0,epsilon1,iter,wartosc_dokladna);
    double rozw_secant = secant(a,b,epsilon0,epsilon1,iter,wartosc_dokladna);
    return 0;
}

void IntroduceMe()
{
    cout      << "PROGRAM KOMPILUJE SIE NA IDE: " << endl
			  << "MICROSOFT VISUAL CODE NA KOMPILATORZE MINGW - GNU GCC 6.3.0" << endl
			  << "PROGRAM DOTYCZY OBLICZANIA PIERWIASTKOW ROWNANIA" << endl
              << "F(X) = tanh(x^2)*sin(3*x)/12" << endl
              << "METODA: BISEKCJI,FALSI,SIECZNYCH" << endl
              << "PRZEDZIAL -> A: 1.5  B: 2.5" << endl
              << "LOKALIZACJA PIERWIASTKA DOKLADNA: 2.0943948960782" << endl;
}

double function(double x)
{
    return (tanh(pow(x,2))/12)*sin(3*x);
}

double fblad_bezwzgledny(double& blad_bezwzgledny, double& wartosc_dokladna, double& wartosc_przyblizona)
{
    blad_bezwzgledny = fabs(wartosc_dokladna - wartosc_przyblizona);
    return blad_bezwzgledny;
}

double fblad_wzgledny(double& blad_bezwzgledny, double& blad_wzgledny, double& wartosc_dokladna)
{
    blad_wzgledny = fabs(blad_bezwzgledny/wartosc_dokladna)*100;
    return blad_wzgledny;
}

double bisection(double a, double b, double epsilon0, double epsilon1, int iter, double wartosc_dokladna)
{
    cout << "OBLICZAM PIERWIASTEK METODA BISEKCJI" << endl;
    double x,tmp,blad_bezwzgledny,blad_wzgledny;
    for(int i=1; i<=iter; i++)
    {
        x = (a+b)/2;
        if(function(x)*function(a)>0)a=x;
        else b = x;
        cout << "PIERWIASTEK W ITERACJI NR: " << i << " WYNOSI: " << setprecision(10) <<  x << endl;
        if(i==1)if(fabs(function(x))<epsilon0)
        {
            cout << "PRZERYWAM DZIALANIE PROGRAMU - SPELNIONY WARUNEK DLA EPSILON0" << endl;
            break;
        }
        if(fabs(function(x)-function(tmp))<epsilon1)
        {
            cout << "PRZERYWAM DZIALANIE PROGRAMU - SPELNIONY WARUNEK DLA EPSILON1" << endl;
            break;
        }
        tmp = x;
    }
    blad_bezwzgledny = fblad_bezwzgledny(blad_bezwzgledny,wartosc_dokladna,x);
    blad_wzgledny = fblad_wzgledny(blad_bezwzgledny,blad_wzgledny,wartosc_dokladna);
    cout << "BLAD BEZWZGLEDNY WYNOSI: " << blad_bezwzgledny << endl;
    cout << "BLAD WZGLEDNY WYNOSI: " << blad_wzgledny << "%" << endl << endl << endl;
    return x;
}

double falsi (double a, double b, double epsilon0, double epsilon1, int iter, double wartosc_dokladna)
{
    cout << "OBLICZAM PIERWIASTEK METODA FALSI" << endl;
    double *X = new double [iter];
    double tmp,blad_bezwzgledny,blad_wzgledny;
    for(int i=1; i<=iter; i++)
    {
        if(i==1)
        {
            X[i] = ((a*function(b))-(b*function(a)))/(function(b)-function(a));
        }
        if((function(a)*function(X[i]))>=0)
        {
            X[i+1] = ((X[i]*function(a))-(a*function(X[i])))/(function(a)-function(X[i]));
        }
        if((function(b)*function(X[i]))>=0)
        {
            X[i+1] = ((X[i]*function(b))-(b*function(X[i])))/(function(b)-function(X[i]));
        }
        tmp = X[i];
        cout << "PIERWIASTEK W ITERACJI NR: " << i << " WYNOSI: " << setprecision(10) <<  X[i] << endl;
        if(i==1)if(fabs(function(X[i]))<epsilon0)
        {
            cout << function(X[i]) << endl;
            cout << "PRZERYWAM DZIALANIE PROGRAMU - SPELNIONY WARUNEK DLA EPSILON0" << endl;
            break;
        }
        if(fabs(X[i+1]-X[i])<epsilon1)
        {
            cout << "PRZERYWAM DZIALANIE PROGRAMU - SPELNIONY WARUNEK DLA EPSILON1" << endl;
            break;
        }        
    }
    blad_bezwzgledny = fblad_bezwzgledny(blad_bezwzgledny,wartosc_dokladna,tmp);
    blad_wzgledny = fblad_wzgledny(blad_bezwzgledny,blad_wzgledny,wartosc_dokladna);
    cout << "BLAD BEZWZGLEDNY WYNOSI: " << blad_bezwzgledny << endl;
    cout << "BLAD WZGLEDNY WYNOSI: " << blad_wzgledny << "%" << endl << endl << endl;
    delete [] X;
    return tmp;
}

double secant(double a, double b, double epsilon0, double epsilon1, int iter, double wartosc_dokladna)
{
    cout << "OBLICZAM PIERWIASTEK METODA SIECZNYCH" << endl;
    double tmp,blad_bezwzgledny,blad_wzgledny,wartosc,funkcja0,funkcja1,funkcja2;
	int iter2 = 1;
	do
	{
		funkcja0=function(a);
		funkcja1=function(b);
		if(funkcja0==funkcja1)
		{
			cout<<"BLAD - ZLY PRZEDZIAL POCZATKOWY";
			exit(0);
		}
        tmp = wartosc;
		wartosc=b - (b - a) * funkcja1/(funkcja1-funkcja0);
		funkcja2=function(wartosc);
		cout<<"PIERWIASTEK W ITERACJI NR: " << iter2 << " WYNOSI: " << wartosc << endl;
        if(fabs(wartosc-tmp)<epsilon1)
        {
            cout << "PRZERYWAM DZIALANIE PROGRAMU - SPELNIONY WARUNEK DLA EPSILON1" << endl;
            break;
        }  
		a=b;
		funkcja0=funkcja1;
		b=wartosc;
		funkcja1=funkcja2;
		iter2=iter2+1;
		if(iter2>iter)
		{
		    cout << "KONCZE DZIALANIE PROGRAMU - NIE ZBIEGA DO ROZWIAZANIA" << endl;
		    exit(0);
		}
	}while(fabs(funkcja2)>epsilon0);
    cout << "PRZERYWAM DZIALANIE PROGRAMU - SPELNIONY WARUNEK DLA EPSILON0" << endl;
    blad_bezwzgledny = fblad_bezwzgledny(blad_bezwzgledny,wartosc_dokladna,wartosc);
    blad_wzgledny = fblad_wzgledny(blad_bezwzgledny,blad_wzgledny,wartosc_dokladna);
    cout << "BLAD BEZWZGLEDNY WYNOSI: " << blad_bezwzgledny << endl;
    cout << "BLAD WZGLEDNY WYNOSI: " << blad_wzgledny << "%" << endl << endl << endl;
    return wartosc;
}