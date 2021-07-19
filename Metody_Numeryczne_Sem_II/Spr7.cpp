#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void IntroduceMe();
double *AddingVectorX(unsigned int node);
double *AddingVectorY(unsigned int node);
bool Validation(double *VectorX, unsigned int node);
double LagrangeAlgorithm(double *VectorX, double *VectorY, unsigned int node, double XtoInterpolation);
void FunctionForLecture(double VariableY, double XtoInterpolation);

int main()
{
unsigned int node;
IntroduceMe();
cout << "PODAJ LICZBE WEZLOW: "; 
cin >> node;
double *VectorX = AddingVectorX(node);
double *VectorY = AddingVectorY(node);
if(Validation(VectorX,node))
    {
        cout << "NIE MOZNA ZBUDOWAC WIELOMIANU INTERPOLACYJNEGO Z TAKICH WEZLOW" << endl;
        return 1;
    }
else{cout<<"MOZNA ZBUDOWAC WIELOMIAN INTERPOLACYJNY Z TAKICH WEZLOW" << endl;}
double XtoInterpolation;
cout << "WPROWADZ ARGUMENT DLA KTOREGO CHCESZ OBLICZYC WARTOSC INTERPOLOWANA: "; cin >> XtoInterpolation;
double VariableY = LagrangeAlgorithm(VectorX,VectorY,node,XtoInterpolation);
//FunctionForLecture(VariableY,XtoInterpolation);
return 0;
}

void IntroduceMe()
{
    cout      << "PROGRAM KOMPILUJE SIE NA IDE: " << endl
			  << "MICROSOFT VISUAL CODE NA KOMPILATORZE MINGW - GNU GCC 6.3.0" << endl
			  << "PROGRAM DOTYCZY WYZNACZANIA FUNKCJI INTERPOLACYJNEJ." << endl;
}

double *AddingVectorX(unsigned int node)
{
double *VectorX = new double[node];
cout << "WPROWADZ WEKTOR X" << endl;
for(unsigned int i=0; i<node; i++)
{
    cout << "X[" << i << "]: ";
    cin >> VectorX[i];
}
cout << endl;
return VectorX;
}

double *AddingVectorY(unsigned int node)
{
double *VectorY = new double[node];
cout << "WPROWADZ WEKTOR Y" << endl;
for(unsigned int i=0; i<node; i++)
{
    cout << "Y[" << i << "]: ";
    cin >> VectorY[i];
}
cout << endl;
return VectorY;
}

bool Validation(double *VectorX, unsigned int node)
{
for(unsigned int i=0; i<node; i++)
{
    for(unsigned int j=0; j<node; j++)
    {
        if(i!=j)
        {
            if(VectorX[i]==VectorX[j])
            { 
            return true;  
            }
        }
    }
}
return false;
}

double LagrangeAlgorithm(double *VectorX, double *VectorY, unsigned int node, double x)
{

    double *FunBaz = new double[node];
    double *WspolWiel = new double[node];
    double *Licznik = new double[node];
    double WartoscFunkcjiInterpolowanej=0;
    for(int i=0; i<node; i++)
    {
        FunBaz[i] = 1;
        Licznik[i] = 1;
        for(int j=0; j<node; j++)
        {
            if(i != j)
            {
                FunBaz[i] *= (VectorX[i]-VectorX[j]);
                Licznik[i] *= (x - VectorX[j]);
            }
        }
        WspolWiel[i] = 1/FunBaz[i]*VectorY[i];
        WartoscFunkcjiInterpolowanej += (WspolWiel[i]*Licznik[i]);
    }
    cout << "W(X)= ";
    for(int i=0; i<node; i++)
    {
        cout << WspolWiel[i];
        for(int j=0; j<node; j++)
        {
            if(i != j)
            {
                cout << "*(x - " << VectorX[j] << ")";
            }
        }
        if(i<node-1)if(WspolWiel[i+1]>0) cout << "+";
    }
    cout << endl << "W("<< x << ")= " << WartoscFunkcjiInterpolowanej << endl;
    return WartoscFunkcjiInterpolowanej;
}

// void FunctionForLecture(double VariableY, double XtoInterpolation)
// {
//     cout << "FUNKCJA BAZOWA TO PIERWIASTEK TRZECIEGO STOPNIA" << endl;
//     cout << "WARTOSC FUNKCJI BAZOWEJ W PUNKCIE: " << XtoInterpolation << " WYNOSI: " << setprecision(10) << cbrt(XtoInterpolation) << endl;
//     cout << "WARTOSC FUNKCJI INTERPOLOWANEJ W PUNKCIE: " << XtoInterpolation << " WYNOSI: " << setprecision(10) << VariableY << endl;
//     cout << "BLAD BEZWZGLEDNY WYNOSI: " << setprecision(8) << fixed << abs(cbrt(XtoInterpolation)-VariableY) << endl;
//     cout << "BLAD WZGLEDNY WYNOSI: " << setprecision(8) << abs(((cbrt(XtoInterpolation)-VariableY)/cbrt(XtoInterpolation)))*100 << "%" << endl;
// }