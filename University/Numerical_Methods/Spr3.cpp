#include <iostream>
#include <ctime>
#include <time.h>
#include <cmath>
using namespace std;

void start();
int stopien_macierzy(unsigned int stopien);
void metoda_gaussa_jordana();
main()
{
    srand(time(NULL));
   unsigned int stopien,wybor,metoda;
   double wyznacznik;
    double D1[3][3];
    double T5[5][5];
    double tmp[3][3];
    double reversematrix[3][3];
   start();
   stopien = stopien_macierzy(stopien);
if(stopien == 3)
{
       cout << "WCZYTYWAC Z KLAWIATURY CZY LOSOWAC? " << endl
            << "1 \t - WCZYTYWANIE" << endl
            << "2 \t - LOSOWANIE" << endl;
            cin >> wybor;
            cout << "JAKA METODA CHCESZ OBLICZYC MACIERZ ODWROTNA? " << endl 
                 << "WPISZ 1 \t- METODA DOPELNIEN ALGEBRAICZNYCH " << endl << 
                 "WPISZ 2 \t - METODA GAUSSA-JORDANA" << endl;
            cin >> metoda;
            if(wybor == 1)
            {
                if(metoda == 1)
                {
                    // wczytuje elemementy macierzy i wyswietla na ekranie
                    cout << "PROSZE WCZYTAC ELEMENTY MACIERZY" << endl;
            int **T3= new int*[stopien];
            for(unsigned int i=0;i<stopien;++i)
            {
                T3[i]=new int[stopien];
                for(unsigned int j=0;j<stopien;++j)
                {
                    cin >> T3[i][j];
                }
            }
                cout << "MACIERZ stopnia: " << stopien << endl;
             for(unsigned int i=0;i<stopien;++i)
            {
                for(unsigned int j=0;j<stopien;++j)
                {
                   cout << T3[i][j] << "\t";
                }
                cout << endl;
            }
            
            //obliczam wyznacznik
            wyznacznik = ((T3[0][0] * T3[1][1] * T3[2][2]) + (T3[0][1] * T3[1][2] * T3[2][0]) + (T3[0][2] * T3[1][0] * T3[2][1]))
						-((T3[0][2] * T3[1][1] * T3[2][0]) + (T3[0][0] * T3[1][2] * T3[2][1]) + (T3[0][1] * T3[1][0] * T3[2][2]));
                        cout << endl << "WYZNACZNIK WYNOSI: " << wyznacznik << endl << endl;
            if(wyznacznik == 0)
            {
                cout << "MACIERZ ODWROTNA NIE ISTNIEJE" << endl;
                return 0;
            }
            // obliczam macierz dopełnień 
                D1[0][0]=(T3[1][1]*T3[2][2])-(T3[2][1]*T3[1][2]);
                D1[0][1]=-((T3[1][0]*T3[2][2])-(T3[2][0]*T3[1][2]));
                D1[0][2]=(T3[1][0]*T3[2][1])-(T3[2][0]*T3[1][1]);
                D1[1][0]=-((T3[0][1]*T3[2][2])-(T3[2][1]*T3[0][2]));
                D1[1][1]=((T3[0][0]*T3[2][2])-(T3[2][0]*T3[0][2]));
                D1[1][2]=-((T3[0][0]*T3[2][1])-(T3[2][0]*T3[0][1]));
                D1[2][0]=((T3[0][1]*T3[1][2])-(T3[1][1]*T3[0][2]));
                D1[2][1]=-((T3[0][0]*T3[1][2])-(T3[1][0]*T3[0][2]));
                D1[2][2]=((T3[0][0]*T3[1][1])-(T3[1][0]*T3[0][1]));
                cout << "MACIERZ DOPELNIEN: " <<endl;
                for (unsigned int i=0;i<stopien;i++)
                {
                    for(unsigned int j=0;j<stopien;j++)
                    {
                        cout << D1[i][j];
                        cout << "\t";
                    }
                    cout << endl;
                }
                //transpozycja
                cout << endl;
                cout << "TRANSPONOWANA MACIERZ DOPELNIEN: " << endl;
                 for (unsigned int i=0;i<stopien;i++)
                {
                    for(unsigned int j=0;j<stopien;j++)
                    {
                        tmp[i][j]=D1[j][i];
                        cout << tmp[i][j] << "\t";
                    }
                    cout << endl;
                }
                // drukujemy macierz odwrotna
                cout << endl << "MACIERZ ODWROTNA: " << endl;
                 for (unsigned int i=0;i<stopien;i++)
                {
                    for(unsigned int j=0;j<stopien;j++)
                    {
                        reversematrix[i][j] = (1/wyznacznik) * tmp[i][j];
                        cout << reversematrix[i][j] << "\t";
                    }
                    cout << endl;
                }
                //usuwamy pamiec
                for (int i = 0; i < stopien; ++i)
    {
        delete[] T3[i];
    }
    delete[] T3;

            }
            }
//GAUSS-JORDAN
    if(wybor == 1)
    {
        if(metoda == 2)
        {
               metoda_gaussa_jordana();
        }
    }

}
// st.5
if(stopien == 5)
{
    int n=5;
    cout    << "WCZYTYWAC Z KLAWIATURY CZY LOSOWAC? " << endl
            << "1 \t - WCZYTYWANIE" << endl
            << "2 \t - LOSOWANIE" << endl;
            cin >> wybor;
             if(wybor == 1){cout <<"NIE MOGE WCZYTYWAC!" << endl;
                            return 1;}
            cout << "JAKA METODA CHCESZ OBLICZYC MACIERZ ODWROTNA? " << endl 
                 << "WPISZ '1' \t- METODA DOPELNIEN ALGEBRAICZNYCH " << endl << 
                 "WPISZ '2' \t - METODA GAUSSA-JORDANA" << endl;
            cin >> metoda;

       if(metoda==1)
       {
           float T5D[5][10]; //tablica stopnia 5 + dopelnienia
          int i,j,k;
          int n=5;
            float t;
            cout << "MACIERZ WYLOSOWANA PRZEZ SYSTEM STOPNIA: " << stopien << " WYNOSI: " << endl;
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        T5D[i][j]=rand()%100+0;
        cout << T5D[i][j] << "\t";  // WYPISUJE WYLOSOWANE ELEMENTY MACIERZY
    }
    cout << endl;
}
            for(i=0;i<n;i++)
            {
                for(j=n;j<2*n;j++)
                {
                    if(i==j-n)
                    T5D[i][j]=1;
                    else
                    T5D[i][j]=0;
                }
            }
                        for(i=0;i<n;i++)
                    {
                            t=T5D[i][i];
                            for(j=i;j<2*n;j++)
                            T5D[i][j]=T5D[i][j]/t;
                                for(j=0;j<n;j++)
                        {
                                    if(i!=j)
                            {
                                    t=T5D[j][i];
                                    for(k=0;k<2*n;k++)
                                    T5D[j][k]=T5D[j][k]-t*T5D[i][k];
                            }
                        }
                    }
                                    cout<< endl << endl <<"MACIERZ ODWROTNA: " << endl << endl;
                                    for(i=0;i<n;i++)
                                {
                                    for(j=n;j<2*n;j++)
                                    cout<<"\t"<<T5D[i][j];
                                        cout<<"\n";
                                }

       }
       if(metoda==2)
       {
         metoda_gaussa_jordana();
       }
}
}

void start()
{        cout << "PROGRAM KOMPILUJE SIE NA IDE: " << endl
			  << "MICROSOFT VISUAL CODE NA KOMPILATORZE MINGW - GNU GCC 6.3.0" << endl
			  << "PROGRAM DOTYCZY OBLICZANIA MACIERZY ODWROTNEJ." << endl  
              << "UWAGA! W NIEKTORYCH PODPROGRAMACH RAND ZOSTAL ZAWEZONY PO TO ZEBY PROGRAM NIE DRUKOWAL ELEMENTOW FUNKCJI EKSPONENCJALNEJ!" << endl << endl;  
}

int stopien_macierzy(unsigned int stopien)
{
    cout << "MACIERZ ODWROTNA KTOREGO STOPNIA CHCESZ WYZNACZYC ?" << endl
                     << "WPISZ: '3' -> 3x3 " << endl 
                     << "WPISZ: '5' -> 5x5 " << endl
                     << "WPISZ: '1' -> PROSTOKATNA" << endl << endl;
                    cin >> stopien;
                  while((stopien != 3) && (stopien != 5) && (stopien != 1))
                  {
                      cout << "SPROBUJ JESZCZE RAZ" << endl;
                      cin >> stopien;
                  }
                  if(stopien==1) 
                  { 
                      cout << "NIE MOGE OBLICZYC MACIERZY ODWROTNEJ Z MACIERZY PROSTOKATNEJ!";
                  return 1;
                  }
                  return stopien;
}

void metoda_gaussa_jordana()
{
    int i = 0, j = 0, k = 0, n = 0;
    float **macierz = NULL;
    float d = 0.0;
    
    cout << "PROSZE WCZYTAC WYMIAR MACIERZY: \n'1' - ST.1 \n'2' - ST.2 \nITD " << endl;
    cin >> n;
    cout << endl;
    
    // alokujemy pamiec
    macierz = new float*[2*n];
    for (i = 0; i < 2*n; ++i)
    {
        macierz[i] = new float[2*n]();
    }
    
    cout << "PROSZE WCZYTAC ELEMENTY MACIERZY: " << endl;
    if(n==5){//wczytujemy dane
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            macierz[i][j]=rand()%100+0;
        }
    }
    }
     if(n!=5){//wczytujemy dane
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            cin >> macierz[i][j];
        }
    }
    }
    cout << endl << "WCZYTANA MACIERZ: " << endl;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            cout << macierz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    
    // sprowadzamy prawa strone do macierzy jednostkowej
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < 2*n; ++j)
        {
            if(j == (i+n))
            {
                macierz[i][j] = 1;
            }
        }
    }
    
    // odwracamy
    for(i = n; i > 1; --i)
    {
        if(macierz[i-1][1] < macierz[i][1])
        {
            for(j = 0; j < 2*n; ++j)
            {
                d = macierz[i][j];
                macierz[i][j] = macierz[i-1][j];
                macierz[i-1][j] = d;
            }
        }
    }
    cout << endl;
    
    // drukujemy macierz rozszerzona
    cout << "MACIERZ ROZSZERZONA: " << endl;
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < 2*n; ++j)
        {
            cout << macierz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    
    // redukujemy do macierzy diagonalnej
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < 2*n; ++j)
        {
            if(j != i)
            {
                d = macierz[j][i] / macierz[i][i];
                for(k = 0; k < n*2; ++k)
                {
                    macierz[j][k] -= macierz[i][k]*d;
                }
            }
        }
    }
    cout << endl;
    
    // redukujemy do macierzy jednostkowej
    for(i = 0; i < n; ++i)
    {
        d = macierz[i][i];
        for(j = 0; j < 2*n; ++j)
        {
            macierz[i][j] = macierz[i][j]/d;
        }
    }
    
    // drukujemy macierz odwrotna
    cout<<"MACIERZ ODWROTNA: " << endl;
    for(i=0; i < n; ++i)
    {
        for(j = n; j < 2*n; ++j)
        {
            cout << macierz[i][j] << "\t";
        }
        cout << endl;
    }
    
    // usuwamy pamiec
    for (i = 0; i < n; ++i)
    {
        delete[] macierz[i];
    }
    delete[] macierz;
    
}
