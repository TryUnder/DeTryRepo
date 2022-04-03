#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
/**************************************************************************************************/

void IntroduceMe();
/**************************************************************************************************/
double **AddingMatrix(int rows, int columns);
/**************************************************************************************************/
double *AddingVectorOfFreeWords(int rows);
/**************************************************************************************************/
bool SymmetryCheck(int rows, double **Matrix);
/**************************************************************************************************/
bool PositiveDefiniteCheck(int rows, double **Matrix,int det4);
/**************************************************************************************************/
int CalculateDeterminant4(double **Matrix);
/**************************************************************************************************/
int DeterminantRecursion4(int T[4][4], int n);
/**************************************************************************************************/
void OptOut(double **Matrix, double *VectorOfMatrix, int rows);
/**************************************************************************************************/
double **CalculatingMatrixL(double **Matrix,int rows);
/**************************************************************************************************/
double **CalculatingMatrixLT(double **MatrixL,int rows);
/**************************************************************************************************/
double *CalculatingUnknowsOfMatrixLYB(double **MatrixL, double *VectorOfMatrix, int rows);
/**************************************************************************************************/
double *CalculatingUnknowsOfMatrixLTXY(double **MatrixLT, double *VectorOfUnknowsY, int rows);
/**************************************************************************************************/
int main()
{
    cout << fixed;
    IntroduceMe();
    int rows, columns, det4;
    cout << "PODAJ LICZBE WIERSZY MACIERZY: ";                      cin >> rows;
    int n = rows;
	cout << "PODAJ LICZBE KOLUMN MACIERZY: ";                       cin >> columns;
    double **Matrix = AddingMatrix(rows,columns);
    double *VectorOfMatrix = AddingVectorOfFreeWords(rows);
    OptOut(Matrix,VectorOfMatrix,rows);
    if(SymmetryCheck(rows,Matrix)) abort();
    if(rows==4)det4 << CalculateDeterminant4(Matrix);
    if(PositiveDefiniteCheck(rows,Matrix,det4)<=0) 
    {
      cout << "MACIERZ NIE JEST DODATNIO OKRESLONA - KONCZE DZIALANIE" << endl;
      abort();  
    }
    cout << "MACIERZ JEST DODATNIO OKRESLONA" << endl << endl;


    double **MatrixL = CalculatingMatrixL(Matrix,rows);
    double **MatrixLT = CalculatingMatrixLT(MatrixL,rows);
    double *VectorOfUnknowsY = CalculatingUnknowsOfMatrixLYB(MatrixL,VectorOfMatrix,rows);
    double *VectorOfUnknowsX = CalculatingUnknowsOfMatrixLTXY(MatrixLT,VectorOfUnknowsY,rows);
    return 0;
}
/**************************************************************************************************/
void IntroduceMe()
{
    cout      << "PROGRAM KOMPILUJE SIE NA IDE: " << endl
			  << "MICROSOFT VISUAL CODE NA KOMPILATORZE MINGW - GNU GCC 6.3.0" << endl
			  << "PROGRAM DOTYCZY ROZWIAZYWANIA UKLADOW ROWNAN LINIOWYCH METODA ROZKLADU CHOLESKIEGO-BANACHIEWICZA." << endl
              << "UWAGA ! W PEWNYCH MIEJSCACH ALGORYTM WPISUJE 0.0000 - ZEBY NIE POKAZYWAC LICZB E CZYLI BARDZO MALYCH LICZB USTAWIONA JEST PRECYZJA!" <<endl;
}
/**************************************************************************************************/
double **AddingMatrix(int rows, int columns)
{
    if(rows != columns)
    {
	    cout << "NIESTETY NIE MOGE STWORZYC UKLADU ROWNAN LINIOWYCH Z POWODU ZLYCH ZALOZEN: "<< rows <<"x" <<columns << endl;
	    cout << "SPROBUJ JESZCZE RAZ." << endl;
	    abort();
    }
    else
    {
        cout << "WPROWADZ ELEMENTY MACIERZY TAK ABY POWSTALA MACIERZ SYMETRYCZNA" << endl;
        double ** MainMatrix = new double*[rows];
        for(unsigned int i=0; i<rows; i++)
        {
            MainMatrix[i] = new double[columns];
            for(unsigned int j=0; j<columns; j++)
            {
                cout <<"A[" << i << "][" << j <<"] = ";
                cin >> MainMatrix[i][j];
            }
        }
        return MainMatrix;
    }
}
/**************************************************************************************************/
double *AddingVectorOfFreeWords(int rows)
{
    double *VectorOfFreeWords = new double [rows];
    cout << "WPROWADZ WEKTOR WYRAZOW WOLNYCH MACIERZY" << endl;
    for(unsigned int i=0; i<rows; i++)
    {
        cin >> VectorOfFreeWords[i]; 
    }
    cout << endl;
    return VectorOfFreeWords;
}
/**************************************************************************************************/
bool SymmetryCheck(int rows, double **Matrix)
{
    for(unsigned int i=0; i<rows; ++i)
    {
        for(unsigned int j=0; j<rows; ++j)
        {
            if(Matrix[i][j] != Matrix[j][i])
            {
                cout << "MACIERZ NIE JEST SYMETRYCZNA - KONCZE DZIALANIE";
                abort();
            }
        }
    }
    cout << "MACIERZ JEST SYMETRYCZNA" << endl;
    return 0;
}
/**************************************************************************************************/
bool PositiveDefiniteCheck(int rows, double **Matrix, int det4)
{
double determinant1,determinant2,determinant3;
   if(rows==2)
   {
    determinant1 = Matrix[0][0];
    determinant2 = Matrix[0][0]*Matrix[1][1]-Matrix[1][0]*Matrix[0][1];
    if((determinant1>0) && (determinant2>0))  return true;
    else return false;
   }
   if(rows==3)
   {
    determinant3 = ((Matrix[0][0] * Matrix[1][1] * Matrix[2][2]) + (Matrix[0][1] * Matrix[1][2] * Matrix[2][0]) + (Matrix[0][2] * Matrix[1][0] * Matrix[2][1]))
					-((Matrix[0][2] * Matrix[1][1] * Matrix[2][0]) + (Matrix[0][0] * Matrix[1][2] * Matrix[2][1]) + (Matrix[0][1] * Matrix[1][0] * Matrix[2][2]));
    determinant2 = determinant2 = Matrix[0][0]*Matrix[1][1]-Matrix[1][0]*Matrix[0][1];
    determinant1 = Matrix[0][0];
    if((determinant1>0) && (determinant2>0) && (determinant3>0)) return true;
    else return false;
   }
   if(rows==4)
   {
    determinant3 = ((Matrix[0][0] * Matrix[1][1] * Matrix[2][2]) + (Matrix[0][1] * Matrix[1][2] * Matrix[2][0]) + (Matrix[0][2] * Matrix[1][0] * Matrix[2][1]))
					-((Matrix[0][2] * Matrix[1][1] * Matrix[2][0]) + (Matrix[0][0] * Matrix[1][2] * Matrix[2][1]) + (Matrix[0][1] * Matrix[1][0] * Matrix[2][2]));
    determinant2 = determinant2 = Matrix[0][0]*Matrix[1][1]-Matrix[1][0]*Matrix[0][1];
    determinant1 = Matrix[0][0];
    if((determinant1>0) && (determinant2>0) && (determinant3>0) && (det4>0)) return true;
    else return false;   
   }
}
/**************************************************************************************************/
int CalculateDeterminant4(double **Matrix)
{
	int roznica_wyznacznik;
	int T[4][4];
	for (unsigned int i = 0; i < 4; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			T[i][j] = Matrix[i][j];
		}
	}
	int n = 4;
	return DeterminantRecursion4(T, n);
}
/**************************************************************************************************/
int DeterminantRecursion4(int T[4][4], int n) 
{
	int wyz = 0;
	int podmacierz[4][4];
	if (n == 2)
		return ((T[0][0] * T[1][1]) - (T[1][0] * T[0][1]));
	else {
		for (int x = 0; x < n; x++)
			{
				int malei = 0;
				for (int i = 1; i < n; i++)
				{
					int malej = 0;
					for (int j = 0; j < n; j++)
					{
						if (j == x)
							continue;
						podmacierz[malei][malej] = T[i][j];
						malej++;
					}
					malei++;
				}
				wyz = wyz + (pow(-1, x) * T[0][x] * DeterminantRecursion4(podmacierz, n - 1));
			}
		}
		return wyz;
}
/**************************************************************************************************/
void OptOut(double **Matrix, double *VectorOfMatrix, int rows)
{
    cout << "WCZYTANA MACIERZ: " << endl;
    for(unsigned int i=0; i<rows; i++)
    {
        for(unsigned int j=0; j<rows; j++)
        {
            cout << Matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "WEKTOR WYRAZOW WOLNYCH: " << endl;
    for(unsigned int i=0; i<rows; i++)
    {
       cout << VectorOfMatrix[i] << endl;
    }
    cout << endl;
}
/**************************************************************************************************/
double **CalculatingMatrixL(double **Matrix,int rows)
{
double addition=0;
cout << "MACIERZ L: " << endl;
double ** MatrixL = new double*[rows];
for(unsigned int i=0; i<rows; i++)
    {
        MatrixL[i] = new double[rows];
    }

    for(unsigned int i=0; i<rows; i++)
    {
        for(unsigned int j=0; j<=i; j++)
        {
            addition = 0;
            if(j == i)
            {
                for(unsigned int k=0; k<j; k++)
                {
                    addition+= (pow(MatrixL[j][k], 2));
                }
                MatrixL[j][j] = sqrt(Matrix[j][j]-addition);
            }
            else
            {
                for(unsigned int k=0; k<j; k++)
                {
                    addition+= (MatrixL[i][k] * MatrixL[j][k]);
                }
                MatrixL[i][j] = (Matrix[i][j] - addition) / MatrixL[j][j];
            }
        }
    }
    for(unsigned int i=0; i<rows; i++)
    {
        for(unsigned int j=0; j<rows; j++)
        {
            cout << MatrixL[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return MatrixL;
}
/**************************************************************************************************/
double **CalculatingMatrixLT(double **MatrixL,int rows)
{
    cout << "MACIERZ LT: " << endl;
    double **MatrixLT = new double*[rows];
    for(unsigned int i=0; i<rows; i++)
    {
        MatrixLT[i] = new double[rows];
    }

    for(unsigned int i=0; i<rows; i++)
    {
        for(unsigned int j=0; j<rows; j++)
        {
            MatrixLT[j][i] = MatrixL[i][j];
        }
    }
    for(unsigned int i=0; i<rows; i++)
    {
        for(unsigned int j=0; j<rows; j++)
        {
            cout << MatrixLT[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return MatrixLT;
}
/**************************************************************************************************/
double *CalculatingUnknowsOfMatrixLYB(double **MatrixL, double *VectorOfMatrix, int rows)
{
double *VectorOfUnknowsY = new double[rows];
double addition = 0;

cout << "WEKTOR NIEWIADOMYCH UKLADU POMOCNICZNEGO: " << endl;
    for(unsigned int i=0; i<rows; i++)
    {
        addition = 0;
        for(unsigned int j=0; j<i; j++)
        {
            addition += (MatrixL[i][j] * VectorOfUnknowsY[j]);
        }
        VectorOfUnknowsY[i] = (VectorOfMatrix[i] - addition) / MatrixL[i][i];
    }

    for(unsigned int i=0; i<rows; i++)
    {
        cout << "Y[" << i << "] WYNOSI: " << VectorOfUnknowsY[i]<< endl;
    }
cout << endl;
return VectorOfUnknowsY;
}
/**************************************************************************************************/
double *CalculatingUnknowsOfMatrixLTXY(double **MatrixLT, double *VectorOfUnknowsY, int rows)
{
double *VectorOfUnknowsX = new double[rows];
double addition = 0;

cout << "WEKTOR NIEWIADOMYCH UKLADU GLOWNEGO: " << endl;
    for(int i=rows-1; i>-1; i--)
    {
        addition = 0;
        for(int j=i+1; j<rows; j++)
        {
            addition += (MatrixLT[i][j] * VectorOfUnknowsX[j]);
        }
        VectorOfUnknowsX[i] = (VectorOfUnknowsY[i] - addition) / MatrixLT[i][i];
    }
     for(unsigned int i=0; i<rows; i++)
    {
        cout << "X[" << i << "] WYNOSI: " << VectorOfUnknowsX[i] << endl;
    }
    cout << endl;
    return VectorOfUnknowsX;
}