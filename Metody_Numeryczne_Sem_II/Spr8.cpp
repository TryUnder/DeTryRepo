#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void IntroduceMe();
double **AddingMainMatrix(short int dim);
bool Validation1(double **MainMatrix, short int dim);
bool Validation2(double **MainMatrix, short int dim);
double *AddingVectorOfFreeWords(short int dim);
double *AddingVectorOfUnknows(short int dim);
double **L_Extraction(double **MainMatrix, short int dim);
double **U_Extraction(double **MainMatrix, short int dim);
double **D_Extraction(double **MainMatrix, short int dim);
double *AddingMatrixDB(double **MatrixD, double *VectorOfFreeWords, short int dim);
double **AddingMatrixDL(double **MatrixD, double **MatrixL, short int dim);
double **AddingMatrixDU(double **MatrixD, double **MatrixU, short int dim);
void GaussianSeidleAlgorithm(double *MatrixDB, double **MatrixDL, double **MatrixDU, double *VectorOfUnknows, short int iter, short int dim);
void MemoryCleanUp(double **MainMatrix, double* VectorOfFreeWords, double *VectorOfUnknows, double **MatrixL, double **MatrixU, double **MatrixD, double *MatrixDB, double **MatrixDL, double **MatrixDU, short int dim);

int main()
{
IntroduceMe();
short int dim,iter,exceptionsum=0;
cout << "PODAJ WYMIAR MACIERZY: " << endl;
cin >> dim;
double **MainMatrix = AddingMainMatrix(dim);
if(Validation1(MainMatrix,dim))exceptionsum++;
else cout << "MACIERZ JEST PRZEKATNIOWO DODATANIA" << endl;
if(Validation2(MainMatrix,dim))exceptionsum++;
else cout << "MACIERZ JEST SILNIE PRZEKATNIOWO DOMINUJACA" << endl;
if((exceptionsum!=0)){cerr << "ZBYT DUZE RYZYKO - KONCZE DZIALANIE PROGRAMU" << endl;return 1;}

double *VectorOfFreeWords = AddingVectorOfFreeWords(dim);
double *VectorOfUnknows = AddingVectorOfUnknows(dim);
double **MatrixL = L_Extraction(MainMatrix,dim);
double **MatrixU = U_Extraction(MainMatrix,dim);
double **MatrixD = D_Extraction(MainMatrix,dim);
double *MatrixDB = AddingMatrixDB(MatrixD,VectorOfFreeWords,dim);
double **MatrixDL = AddingMatrixDL(MatrixD,MatrixL,dim);
double **MatrixDU = AddingMatrixDU(MatrixD,MatrixU,dim);
cout << "PODAJ LICZBE ITERACJI: " << endl;
cin >> iter;
GaussianSeidleAlgorithm(MatrixDB,MatrixDL,MatrixDU,VectorOfUnknows,iter,dim);
MemoryCleanUp(MainMatrix,VectorOfFreeWords,VectorOfUnknows,MatrixL,MatrixU,MatrixD,MatrixDB,MatrixDL,MatrixDU,dim);
return 0;
}

void IntroduceMe()
{
    cout      << "PROGRAM KOMPILUJE SIE NA IDE: " << endl
			  << "MICROSOFT VISUAL CODE NA KOMPILATORZE MINGW - GNU GCC 6.3.0" << endl
			  << "PROGRAM DOTYCZY ROZWIAZYWANIA UKLADU ROWNAN METODA GAUSSA-SEIDLA." << endl;
}

double **AddingMainMatrix(short int dim)
{
    cout << "WCZYTAJ MACIERZ: " << endl;
    double **MainMatrix = new double*[dim];
    for(int i=0; i<dim; i++)
    {
        MainMatrix[i] = new double[dim];
        for(int j=0; j<dim; j++)
        {
            cout << "PODAJ T[" << i << "][" << j << "] ";
            cin >> MainMatrix[i][j];
        }
        cout << endl;
    }
    cout << "WCZYTANA MACIERZ: " << endl;
    for(int i=0; i<dim; i++)
    {
        for(int j=0; j<dim; j++)
        {
            cout << MainMatrix[i][j] << "\t";
        }
        cout << endl;
    }
    return MainMatrix;
}

bool Validation1(double **MainMatrix, short int dim)
{
    double suma;
    for(int i=0; i<dim; i++)
    {
        suma=0.00001;
        for(int j=0; j<dim; j++)
        {
            if(i!=j)suma+=MainMatrix[i][j];
        }
        for(int k=0; k<dim; k++)
        {
            if(i==k)if(MainMatrix[i][k]!=0);
            else {cerr << "MACIERZ NIE JEST PRZEKOTNIOWO DODATNIA" << endl; return 1;}
        }
    }
    return 0;
}

bool Validation2(double **MainMatrix, short int dim)
{
    double suma;
    for(int i=0; i<dim; i++)
    {
        suma=0.0;
        for(int j=0; j<dim; j++)
        {
            if(i!=j)suma+=abs(MainMatrix[i][j]);
        }
        for(int k=0; k<dim; k++)
        {
            if(i==k)if(abs(MainMatrix[i][k])>suma);
            else {cerr << "MACIERZ NIE JEST PRZEKOTNIOWO DOMINUJACA" << endl; return 1;}
        }
    } 
    return 0;
}

double *AddingVectorOfFreeWords(short int dim)
{
    double *VectorOfFreeWords = new double [dim];
    cout << "WPROWADZ WEKTOR WYRAZOW WOLNYCH MACIERZY" << endl;
    for(int i=0; i<dim; i++)
    {
        cout << "PODAJ B[" << i <<"]: ";
        cin >> VectorOfFreeWords[i]; 
    }
    cout << endl;
    cout << "WCZYTANY WEKTOR WYRAZOW WOLNYCH: " << endl;
    for(int i=0; i<dim; i++)
    {
        cout << "B[" << i << "] = " << VectorOfFreeWords[i] << endl;
    }
    return VectorOfFreeWords;
}

double *AddingVectorOfUnknows(short int dim)
{
    cout << "WPROWADZ WARTOSCI NIEWIADOMYCH DLA ITERACJI ZEROWEJ: " << endl;
    double *VectorOfUnknows = new double [dim];
    for(int i=0; i<dim; i++)
    {
        cout << "X[" << i << "] ";
        cin >> VectorOfUnknows[i];
    }
    return VectorOfUnknows;
}

double **L_Extraction(double **MainMatrix, short int dim)
{
    double **MatrixL = new double *[dim];
    for(int i=0; i<dim; i++)
    {
        MatrixL[i] = new double [dim];
        for(int j=0; j<dim; j++)
        {
            if (i < j+1)
            {
                MatrixL[i][j] = 0;
            }
            else 
            {
                MatrixL[i][j] = MainMatrix[i][j];
            }
        }
     }
     return MatrixL;
}

double **U_Extraction(double **MainMatrix, short int dim)
{
    double **MatrixU = new double *[dim];
    for(int i=0; i<dim; i++)
    {
        MatrixU[i] = new double [dim];
        for(int j=0; j<dim; j++)
        {
            if (i+1 > j)
            {
                MatrixU[i][j] = 0;
            }
            else 
            {
                MatrixU[i][j] = MainMatrix[i][j];
            }
        }
     }
     return MatrixU;
}

double **D_Extraction(double **MainMatrix, short int dim)
{
    double **MatrixD = new double *[dim];
    for(int i=0; i<dim; i++)
    {
        MatrixD[i] = new double [dim];
        for(int j=0; j<dim; j++)
        {
            if(i==j)
            {
                MatrixD[i][j] = (1/MainMatrix[i][j]);
            }
            else
            {
                MatrixD[i][j] = 0;
            }
        }
    }
    return MatrixD;
}

double *AddingMatrixDB(double **MatrixD, double *VectorOfFreeWords, short int dim)
{
    double *MatrixDB = new double [dim];
    for(int i=0; i<dim; i++)
    {
        for(int j=0; j<dim; j++)
        {
            if(i==j)
            {
                MatrixDB[i] = MatrixD[i][j] * VectorOfFreeWords[i];
            }
        }
    }
    return MatrixDB;
}
double **AddingMatrixDL(double **MatrixD, double **MatrixL, short int dim)
{
    double **MatrixDL = new double *[dim];
    for(int i=0; i<dim; i++)
    {
        MatrixDL[i] = new double[dim];
        for(int j=0; j<dim; j++)
        {
            for(int k=0; k<dim; k++)
            {
                MatrixDL[i][j] = MatrixDL[i][j] + MatrixD[i][k] * MatrixL[k][j];
            }
        }
    }
    return MatrixDL;
}
double **AddingMatrixDU(double **MatrixD, double **MatrixU, short int dim)
{
    double **MatrixDU = new double *[dim];
    for(int i=0; i<dim; i++)
    {
        MatrixDU[i] = new double[dim];
        for(int j=0; j<dim; j++)
        {
            for(int k=0; k<dim; k++)
            {
                MatrixDU[i][j] = MatrixDU[i][j] + MatrixD[i][k] * MatrixU[k][j];
            }
        }
    }
    return MatrixDU;
}

void GaussianSeidleAlgorithm(double *MatrixDB, double **MatrixDL, double **MatrixDU, double *VectorOfUnknows, short int iter, short int dim)
{
double SumOfL;
double SumOfU;
cout << "ITERACJA NR: 0 (WCZYTANA)" << endl;
for(int i=0; i<dim; i++)
{
    cout << "X[" << i+1 << "]" << " = " << setprecision(8) << VectorOfUnknows[i] << endl;
    if(i==dim-1)cout << endl;
}
for(int i=0; i<iter; i++)
    {
        cout << "ITERACJA NR: " << i+1 << endl;
        for(int j=0; j<dim; j++)
        {
            SumOfL = 0;
            SumOfU = 0;
            for(int k=0; k<dim; k++)
            {
                SumOfL = SumOfL - MatrixDL[j][k]*VectorOfUnknows[k];
                SumOfU = SumOfU - MatrixDU[j][k]*VectorOfUnknows[k];
            }
            VectorOfUnknows[j] = MatrixDB[j] + SumOfL + SumOfU;
        }
        for (int i=0; i<dim; i++)
        {
            cout << "X[" << i+1 << "]" << " = " << setprecision(8) << VectorOfUnknows[i] << endl;
            if(i==dim-1) cout << endl;
        }
    }
}

void MemoryCleanUp(double **MainMatrix, double*VectorOfFreeWords, double*VectorOfUnknows, double **MatrixL, double **MatrixU, double**MatrixD, double *MatrixDB, double **MatrixDL, double **MatrixDU, short int dim)
{
    for(int i=0; i<dim; i++)
    {
        delete [] MainMatrix[i];
        delete [] MatrixL[i];
        delete [] MatrixU[i];
        delete [] MatrixD[i];
        delete [] MatrixDL[i];
        delete [] MatrixDU[i];
    }
            delete [] MainMatrix;
            delete [] VectorOfFreeWords;
            delete [] MatrixL;
            delete [] MatrixU;
            delete [] MatrixD;
            delete [] MatrixDB;
            delete [] MatrixDL;
            delete [] MatrixDU;
            delete [] VectorOfUnknows;
}

