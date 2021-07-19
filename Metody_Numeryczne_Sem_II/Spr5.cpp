#include <iostream>
#include <cmath>
#include <time.h>
#include <ctime>
#include <math.h>
#include <iomanip>
using namespace std;
/**************************************************************************************************/
void IntroduceMe();
double **AddingMatrix(int rows, int columns, int down, int up);
void OptOut(double **Matrix, int rows, int columns);
float *GaussianEliminationAlgorithm(double **Matrix, int rows, int columns);
void MemoryCleanUp(double **Matrix, float *PointerToVector, int rows);
/**************************************************************************************************/
int main()
{   
    srand(time(NULL));
    int rows, columns, down, up;
    IntroduceMe();
    cout << "PODAJ LICZBE WIERSZY MACIERZY: ";                      cin >> rows;
	cout << "PODAJ LICZBE KOLUMN MACIERZY: ";                       cin >> columns;
    //cout << "PODAJ DOLNY PRZEDZIAL LOSOWANIA ELEMENTOW MACIERZY: "; cin >> down;
    //cout << "PODAJ GORNY PRZEDZIAL LOSOWANIA ELEMENTOW MACIERZY: "; cin >> up;
    double **Matrix = AddingMatrix(rows,columns,down,up);
    OptOut(Matrix,rows,columns);
    float *PointerToVector = GaussianEliminationAlgorithm(Matrix,rows,columns);
    MemoryCleanUp(Matrix,PointerToVector,rows);
    return 0;
}
/**************************************************************************************************/
void IntroduceMe()
{
    cout      << "PROGRAM KOMPILUJE SIE NA IDE: " << endl
			  << "MICROSOFT VISUAL CODE NA KOMPILATORZE MINGW - GNU GCC 6.3.0" << endl
			  << "PROGRAM DOTYCZY ROZWIAZYWANIA UKLADOW ROWNAN LINIOWYCH METODA ELIMINACJI GAUSSA." << endl << endl; 
}
/**************************************************************************************************/
double **AddingMatrix(int rows, int columns, int down, int up)
{
    if(rows != columns)
    {
	    cout << "NIESTETY NIE MOGE STWORZYC UKLADU ROWNAN LINIOWYCH Z POWODU ZLYCH ZALOZEN: "<< rows <<"x" <<columns << endl;
	    cout << "SPROBUJ JESZCZE RAZ." << endl;
	    abort();
    }
    else
    {
        double ** MainMatrix = new double*[rows];
        for(unsigned int i=0; i<rows; i++)
        {
            MainMatrix[i] = new double[columns+1];
            for(unsigned int j=0; j<columns+1; j++)
            {
                //MainMatrix[i][j] = down+ rand()% abs(up-down);
                cin >> MainMatrix[i][j];
            }
        }
        return MainMatrix;
    }
}
/**************************************************************************************************/
void OptOut(double **Matrix, int rows, int columns)
{
    cout << endl << "WYLOSOWANA MACIERZ: " << endl;
    for(unsigned int i=0; i<rows; i++)
    {
        for(unsigned int j=0; j<columns; j++)
        {
            cout << Matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl << "WEKTOR WYRAZOW WOLNYCH: " << endl;
    for(unsigned int i=0; i<rows; i++)
    {
        for(unsigned int j=0; j<columns+1; j++)
        {
            if(j==columns)
            cout << Matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl << "MACIERZ UZUPELNIEN: " << endl;
    for(unsigned int i=0; i<rows; i++)
    {
        for(unsigned int j=0; j<columns+1; j++)
        {
            cout << Matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
/**************************************************************************************************/
float *GaussianEliminationAlgorithm(double **Matrix, int rows, int columns)
{
    cout << fixed << showpoint;
float *VectorOfUnknowns = new float[rows];
for(unsigned int i=0; i<rows; i++) 
    {                   
        for(unsigned int j=i+1; j<rows; j++)
        {
            if(abs(Matrix[i][i]) < abs(Matrix[j][i]))
            {
                for(unsigned int k=0; k<rows+1; k++)
                {
                    /* zamieniamy mat[i][k] z mat[j][k] */
                    Matrix[i][k]=Matrix[i][k]+Matrix[j][k];
                    Matrix[j][k]=Matrix[i][k]-Matrix[j][k];
                    Matrix[i][k]=Matrix[i][k]-Matrix[j][k];
                }
            }
      }
    }
    cout << endl;
    // tutaj odbywa się główna akcja
    for(unsigned int i=0; i<rows-1; i++)
    {
        for(unsigned int j=i+1; j<rows; j++)
        {
            float f=Matrix[j][i]/Matrix[i][i];
            for(unsigned int k=0; k<rows+1; k++)
            {
              Matrix[j][k]=Matrix[j][k]-f*Matrix[i][k];
            }
        }
    }
    cout << "MACIERZ SCHODKOWA : " << endl; //po angl to row echoleon form
    for(unsigned int i=0; i<rows; i++)
    {
        for(unsigned int j=0; j<columns+1; j++)
        { 
                cout << Matrix[i][j] << "\t";
        }
        cout << endl;
    }
   cout << endl;
    
    if(Matrix[rows-1][rows-1]==0)
    {
        cout << "UKLAD SPRZECZNY - BRAK ROZWIAZAN !" << endl;
        abort();
    }
    else
    {
        cout << "UKLAD OZNACZONY. LICZE NIEWIADOME " << endl;
    /* dzielimy od konca i uzyskujemy wartosci niewiadomych */
    for(int i=rows-1; i>=0; i--)          
    {                     
        VectorOfUnknowns[i]=Matrix[i][rows];
                    
        for(unsigned int j=i+1; j<rows; j++)
        {
          if(i!=j)
          {
              VectorOfUnknowns[i]=VectorOfUnknowns[i]-(Matrix[i][j]*VectorOfUnknowns[j]);
          }          
        }
              VectorOfUnknowns[i]=VectorOfUnknowns[i]/Matrix[i][i];  
    }

    cout << endl << "ROZWIAZANIE UKLADU: " << endl << endl;
    for(unsigned int i=0; i<rows; i++)
    {
      cout<< "X[" << i << "] WYNOSI: " << VectorOfUnknowns[i]<<"\n";
    }
    
    return VectorOfUnknowns;}
    
}
/**************************************************************************************************/
void MemoryCleanUp(double **Matrix, float *PointerToVector, int rows)
{
for(unsigned int i=0; i<rows; i++)
    delete [] Matrix[i];
        delete [] Matrix;
    delete [] PointerToVector;
}
/**************************************************************************************************/