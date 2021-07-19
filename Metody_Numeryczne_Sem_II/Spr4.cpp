#include <iostream>
#include <cmath>
using namespace std;
/**************************************************************************************************/
int main()
{        cout << "PROGRAM KOMPILUJE SIE NA IDE: " << endl
			  << "MICROSOFT VISUAL CODE NA KOMPILATORZE MINGW - GNU GCC 6.3.0" << endl
			  << "PROGRAM DOTYCZY ROZWIAZYWANIA UKLADOW ROWNAN METODA THOMASA." << endl << endl; 
/**************************************************************************************************/
int rows,columns;
    cout << "PODAJ LICZBE WIERSZY MACIERZY: ";
	cin >> rows;
	cout << "PODAJ LICZBE KOLUMN MACIERZY: ";
	cin >> columns;
    if((rows != columns) || (rows < 3 || columns < 3))
		{
			cout << "NIESTETY NIE MOGE WYZNACZYC NIEWIADOMYCH METODA THOMASA DLA MACIERZY: "<< rows <<"x" <<columns << endl;
            cout << "STOPIEN MACIERZY WSPOLCZYNNIKOW != STOPNIA MACIERZY NIEWIADOMYCH !" << endl;
			cout << "SPROBUJ JESZCZE RAZ." << endl;
            int stopien_niewiadomych = rows;
			return 0;
		}
/**************************************************************************************************/        
        if(rows && columns == 3)
        {
            double D[rows];
            cout << "WCZYTAJ MACIERZ ZGODNIE Z Z WARUNKAMI DLA JAKICH MOGA BYC OBLICZONE NIEWIADOME METODA THOMASA." << endl;
            double ** MainMatrix = new double * [rows];
		        for(unsigned int i = 0; i<rows; ++i)
		            {
			        MainMatrix[i] = new double [columns];
			            for(unsigned int j = 0; j<columns; ++j)
			            {
				            cout << "PODAJ T[" << i << "][" << j << "] ";
				            cin >> MainMatrix[i][j];
			            }
			            cout << endl;
		            }
                    cout << "WCZYTANA MACIERZ: " << endl;
                for(unsigned int i = 0; i<rows; ++i)
		            {
			            for(unsigned int j = 0; j<columns; ++j)
			            {
                            cout << MainMatrix[i][j] << "\t";
                            if(MainMatrix[0][0]==0)
                            {
                            cout << "NIE MOGE OBLICZYC NIEWIADOMYCH ! B1=0";
                            return 0;
                            }
			            }
			            cout << endl;
		            }
                    cout <<endl;
                    cout << "WCZYTAJ KOLUMNE WYRAZOW WOLNYCH: " << endl;
                    for(unsigned int i=0; i<rows; ++i)
                    {
                        cout << "D[" << i << "] ";
                        cin >> D[i];
                    }
                    cout << endl;
                    for(unsigned int i=0; i<rows; ++i)
                    {
                        cout << "D[" << i << "] " << "WYNOSI: " << D[i] << endl;
                    }
                    cout << endl;
                    double WektorA[rows] = {0, MainMatrix[1][0], MainMatrix[2][1]};
                    double WektorB[rows] = {MainMatrix[0][0], MainMatrix[1][1], MainMatrix[2][2]};
                    double WektorC[rows] = {MainMatrix[0][1], MainMatrix[1][2],0};
                    double Beta[3];
                    Beta[0]=-WektorC[0]/WektorB[0];
                    cout << "BETA[0] " << "WYNOSI: " << Beta[0] << endl;
                    for(unsigned int i=1; i<rows; ++i)
                    {
                        Beta[i]=-WektorC[i]/(WektorA[i]*Beta[i-1]+WektorB[i]);
                        cout << "BETA["<< i <<"]" << " WYNOSI: " << Beta[i] << endl;
                    }
                    cout << endl;
                    double Gamma[rows];
                    Gamma[0] = D[0]/WektorB[0];
                    cout << "GAMMA[0] " << "WYNOSI: " << Gamma[0] << endl;
                    for(unsigned int i=1; i<3; ++i)
                    {
                        Gamma[i]=(D[i]-WektorA[i]*Gamma[i-1])/(WektorA[i]*Beta[i-1]+WektorB[i]);
                        cout << "GAMMA["<< i <<"]" << " WYNOSI: " << Gamma[i] << endl;
                    }
                    cout << endl;
                    double Ex[rows];
                    for(int i=rows-1; i>=0; --i)
                    {
                        if(i==rows-1)
                        {
                        Ex[i]=Gamma[i];
                        cout << "x["<< i <<"]" << " WYNOSI: " << Ex[i+1] << endl;
                        continue;
                        }
                        Ex[i] = Beta[i]*Ex[i+1]+Gamma[i];
                        cout << "x["<< i <<"]" << " WYNOSI: " << Ex[i] << endl;
                    }
        }
/**************************************************************************************************/        
        if(rows && columns == 5)
        {
            double D[rows];
            cout << "WCZYTAJ MACIERZ ZGODNIE Z Z WARUNKAMI DLA JAKICH MOGA BYC OBLICZONE NIEWIADOME METODA THOMASA." << endl;
            double ** MainMatrix = new double * [rows];
		        for(unsigned int i = 0; i<rows; ++i)
		            {
			        MainMatrix[i] = new double [columns];
			            for(unsigned int j = 0; j<columns; ++j)
			            {
				            cout << "PODAJ T[" << i << "][" << j << "] ";
				            cin >> MainMatrix[i][j];
			            }
			            cout << endl;
		            }
                    cout << "WCZYTANA MACIERZ: " << endl;
                for(unsigned int i = 0; i<rows; ++i)
		            {
			            for(unsigned int j = 0; j<columns; ++j)
			            {
                            cout << MainMatrix[i][j] << "\t";
                            if(MainMatrix[0][0]==0)
                            {
                            cout << "NIE MOGE OBLICZYC NIEWIADOMYCH ! B1=0";
                            return 0;
                            }
			            }
			            cout << endl;
		            }
                    cout <<endl;
                    cout << "WCZYTAJ KOLUMNE WYRAZOW WOLNYCH: " << endl;
                    for(unsigned int i=0; i<rows; ++i)
                    {
                        cout << "D[" << i << "] ";
                        cin >> D[i];
                    }
                    cout << endl;
                    for(unsigned int i=0; i<rows; ++i)
                    {
                        cout << "D[" << i << "] " << "WYNOSI: " << D[i] << endl;
                    }
                    cout << endl;
                    double WektorA[rows] = {0, MainMatrix[1][0], MainMatrix[2][1], MainMatrix[3][2], MainMatrix[4][3]};
                    double WektorB[rows] = {MainMatrix[0][0], MainMatrix[1][1], MainMatrix[2][2], MainMatrix[3][3], MainMatrix[4][4]};
                    double WektorC[rows] = {MainMatrix[0][1], MainMatrix[1][2], MainMatrix[2][3], MainMatrix[3][4], 0};
                    double Beta[rows];
                    Beta[0]=-WektorC[0]/WektorB[0];
                    cout << "BETA[0] " << "WYNOSI: " << Beta[0] << endl;
                    for(unsigned int i=1; i<rows; ++i)
                    {
                        Beta[i]=-WektorC[i]/(WektorA[i]*Beta[i-1]+WektorB[i]);
                        cout << "BETA["<< i <<"]" << " WYNOSI: " << Beta[i] << endl;
                    }
                    cout << endl;
                    double Gamma[rows];
                    Gamma[0] = D[0]/WektorB[0];
                    cout << "GAMMA[0] " << "WYNOSI: " << Gamma[0] << endl;
                    for(unsigned int i=1; i<rows; ++i)
                    {
                        Gamma[i]=(D[i]-WektorA[i]*Gamma[i-1])/(WektorA[i]*Beta[i-1]+WektorB[i]);
                        cout << "GAMMA["<< i <<"]" << " WYNOSI: " << Gamma[i] << endl;
                    }
                    cout << endl;
                    double Ex[rows];
                    for(int i=rows-1; i>=0; --i)
                    {
                        if(i==rows-1)
                        {
                        Ex[i]=Gamma[i];
                        cout << "x["<< i <<"]" << " WYNOSI: " << Ex[i+1] << endl;
                        continue;
                        }
                        Ex[i] = Beta[i]*Ex[i+1]+Gamma[i];
                        cout << "x["<< i <<"]" << " WYNOSI: " << Ex[i] << endl;
                    }
        }
/**************************************************************************************************/
         if(rows && columns == 7)
        {
             double D[rows];
            cout << "WCZYTAJ MACIERZ ZGODNIE Z Z WARUNKAMI DLA JAKICH MOGA BYC OBLICZONE NIEWIADOME METODA THOMASA." << endl;
            double ** MainMatrix = new double * [rows];
		        for(unsigned int i = 0; i<rows; ++i)
		            {
			        MainMatrix[i] = new double [columns];
			            for(unsigned int j = 0; j<columns; ++j)
			            {
				            cout << "PODAJ T[" << i << "][" << j << "] ";
				            cin >> MainMatrix[i][j];
			            }
			            cout << endl;
		            }
                    cout << "WCZYTANA MACIERZ: " << endl;
                for(unsigned int i = 0; i<rows; ++i)
		            {
			            for(unsigned int j = 0; j<columns; ++j)
			            {
                            cout << MainMatrix[i][j] << "\t";
                            if(MainMatrix[0][0]==0)
                            {
                            cout << "NIE MOGE OBLICZYC NIEWIADOMYCH ! B1=0";
                            return 0;
                            }
			            }
			            cout << endl;
		            }
                    cout <<endl;
                    cout << "WCZYTAJ KOLUMNE WYRAZOW WOLNYCH: " << endl;
                    for(unsigned int i=0; i<rows; ++i)
                    {
                        cout << "D[" << i << "] ";
                        cin >> D[i];
                    }
                    cout << endl;
                    for(unsigned int i=0; i<rows; ++i)
                    {
                        cout << "D[" << i << "] " << "WYNOSI: " << D[i] << endl;
                    }
                    cout << endl;
                    double WektorA[rows] = {0, MainMatrix[1][0], MainMatrix[2][1], MainMatrix[3][2], MainMatrix[4][3], MainMatrix[5][4], MainMatrix[6][5]};
                    double WektorB[rows] = {MainMatrix[0][0], MainMatrix[1][1], MainMatrix[2][2], MainMatrix[3][3], MainMatrix[4][4], MainMatrix[5][5], MainMatrix[6][6]};
                    double WektorC[rows] = {MainMatrix[0][1], MainMatrix[1][2], MainMatrix[2][3], MainMatrix[3][4],  MainMatrix[4][5], MainMatrix[5][6], 0};
                    double Beta[rows];
                    Beta[0]=-WektorC[0]/WektorB[0];
                    cout << "BETA[0] " << "WYNOSI: " << Beta[0] << endl;
                    for(unsigned int i=1; i<rows; ++i)
                    {
                        Beta[i]=-WektorC[i]/(WektorA[i]*Beta[i-1]+WektorB[i]);
                        cout << "BETA["<< i <<"]" << " WYNOSI: " << Beta[i] << endl;
                    }
                    cout << endl;
                    double Gamma[rows];
                    Gamma[0] = D[0]/WektorB[0];
                    cout << "GAMMA[0] " << "WYNOSI: " << Gamma[0] << endl;
                    for(unsigned int i=1; i<rows; ++i)
                    {
                        Gamma[i]=(D[i]-WektorA[i]*Gamma[i-1])/(WektorA[i]*Beta[i-1]+WektorB[i]);
                        cout << "GAMMA["<< i <<"]" << " WYNOSI: " << Gamma[i] << endl;
                    }
                    cout << endl;
                    double Ex[rows];
                    for(int i=rows-1; i>=0; --i)
                    {
                        if(i==rows-1)
                        {
                        Ex[i]=Gamma[i];
                        cout << "x["<< i <<"]" << " WYNOSI: " << Ex[i+1] << endl;
                        continue;
                        }
                        Ex[i] = Beta[i]*Ex[i+1]+Gamma[i];
                        cout << "x["<< i <<"]" << " WYNOSI: " << Ex[i] << endl;
                    }
        }
/**************************************************************************************************/
        if((rows && columns != 3) && (rows && columns != 5) && (rows && columns != 7))
        {
            cout << "PROGRAM NIE PRZEWIDUJE ROZWIAZANIA ROWNANIA DLA TEJ MACIERZY.";
        }
}
/**************************************************************************************************/
