/*
SPRAWOZDANIE NR.2 WYZNACZNIKI
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
void czy_moge_obliczyc_wyznacznik();
int obliczam_wyznacznik_stopnia_1();
int obliczam_wyznacznik_stopnia_2();
void obliczam_wyznacznik_stopnia_3_z_sarrusa_i_laplacea();
int obliczam_wyznacznik_stopnia_4();
int wyznacznik_rekursja_stopien_4(int T[4][4], int n);
int main()
{
	std::cout << "PROGRAM KOMPILUJE SIE NA IDE: " << std::endl
			  << "MICROSOFT VISUAL STUDIO COMMUNITY 2019 WERSJA: 16.9.0" << std::endl
			  << "UWAGA - WAZNE !! -> NA INNYCH KOMPILATORACH NP CODEBLOCKS MOZE URYWAC LINIE!!" << std::endl
			  << "PROGRAM DOTYCZY OBLICZANIA WYZNACZNIKOW MACIERZY." << std::endl << std::endl;

	srand(time(NULL));
	czy_moge_obliczyc_wyznacznik();
	std::cout << obliczam_wyznacznik_stopnia_1();
	std::cout << "WYZNACZNIK WYNOSI: " << obliczam_wyznacznik_stopnia_2();
	obliczam_wyznacznik_stopnia_3_z_sarrusa_i_laplacea();
	std::cout << "WYZNACZNIK WYNOSI: " << obliczam_wyznacznik_stopnia_4();
}
void czy_moge_obliczyc_wyznacznik()
{
	int n, m;
	n = rand();
	m = rand();
	if (n == m)std::cout << "Z MACIERZY O WYMIARACH:  T[" << n << "][" << m << "]" << " MOGE OBLICZYC WYZNACZNIK" << std::endl << "PONIEWAZ: " << n << " == " << m << std::endl << std::endl;
	else {
		std::cout << "Z MACIERZY O WYMIARACH:  T[" << n << "][" << m << "]" << " NIE MOGE OBLICZYC WYZNACZNIKA" << std::endl << "PONIEWAZ: " << n << " =/= " << m << std::endl <<std::endl;
	}
}
int obliczam_wyznacznik_stopnia_1()
{
	std::cout << "ROZPOCZYNAM PROCES OBLICZANIA WYZNACZNIKA STOPNIA 1" << std::endl;
	int T[1][1];
	T[0][0] = rand()%41 -20;
	std::cout << "ELEMENT [0][0] MACIERZY T: \t" << T[0][0]
		<< std::endl << "A JEJ WYZNACZNIK : \t";
	return T[0][0];
}
int obliczam_wyznacznik_stopnia_2()
{
	std::cout << std::endl << std::endl;
	std::cout << "ROZPOCZYNAM PROCES OBLICZANIA WYZNACZNIKA STOPNIA 2 Z MACIERZY: " << std::endl;
	int iloczyn1 = 1;
	int iloczyn2 = 1;
	int roznica_wyznacznik;
	int T[2][2];
	for (unsigned int i = 0; i < 2; i++)
	{
		for (unsigned int j = 0; j < 2; j++)
		{
			T[i][j] = rand() %90+10;
			std::cout << T[i][j] << "\t";
			if (i == j)iloczyn1 = iloczyn1 * T[i][j];
			if (i != j)iloczyn2 = iloczyn2 * T[i][j]; 
		}
		std::cout << std::endl <<std::endl;
	}
	roznica_wyznacznik = iloczyn1 - iloczyn2;
	return roznica_wyznacznik;
}
void obliczam_wyznacznik_stopnia_3_z_sarrusa_i_laplacea()
{
	//METODA SARRUSA
	std::cout << std::endl << std::endl;
	std::cout << "ROZPOCZYNAM PROCES OBLICZANIA WYZNACZNIKA STOPNIA 3 METODA SARRUSA Z MACIERZY: " << std::endl;
	int roznica_wyznacznik,roznica_wyznacznik2;
	int T[3][3];
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			T[i][j] = rand()%50 +50;
			std::cout << T[i][j] << "\t";
		}
		std::cout << std::endl << std::endl;
	}
	roznica_wyznacznik = ((T[0][0] * T[1][1] * T[2][2]) + (T[0][1] * T[1][2] * T[2][0]) + (T[0][2] * T[1][0] * T[2][1]))
						-((T[0][2] * T[1][1] * T[2][0]) + (T[0][0] * T[1][2] * T[2][1]) + (T[0][1] * T[1][0] * T[2][2]));
	std::cout << "WYZNACZNIK WYNOSI: "<< roznica_wyznacznik;

	//METODA LAPLACEA
	std::cout << std::endl << std::endl;
	std::cout << "ROZPOCZYNAM PROCES OBLICZANIA WYZNACZNIKA STOPNIA 3 METODA LAPLACEA Z MACIERZY: " << std::endl;
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			std::cout << T[i][j] <<"\t";
		}
		std::cout << std::endl << std::endl;
	}
	roznica_wyznacznik2 = (T[0][0] * (-1) * (-1) * ((T[1][1] * T[2][2]) - (T[2][1] * T[1][2])))
						 +(T[1][0] * (-1) * (-1) * (-1) * ((T[0][1]*T[2][2])-(T[2][1]*T[0][2])))
						 +(T[2][0] * (-1) * (-1) * (-1) * (-1) * ((T[0][1]*T[1][2])-(T[1][1]*T[0][2])));

	std::cout << "WYZNACZNIK WYNOSI: " << roznica_wyznacznik2;
}
int obliczam_wyznacznik_stopnia_4()
{
	int roznica_wyznacznik;
	std::cout << std::endl << std::endl;
	std::cout << "ROZPOCZYNAM PROCES OBLICZANIA WYZNACZNIKA STOPNIA 4 Z MACIERZY: " << std::endl;
	int T[4][4];
	for (unsigned int i = 0; i < 4; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			T[i][j] = (0+rand() %10 +0);
			std::cout << T[i][j] << "\t";
		}
		std::cout << std::endl << std::endl;
	}
	int n = 4;
	return wyznacznik_rekursja_stopien_4(T, n);
}

int wyznacznik_rekursja_stopien_4(int T[4][4], int n) 
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
				wyz = wyz + (pow(-1, x) * T[0][x] * wyznacznik_rekursja_stopien_4(podmacierz, n - 1));
			}
		}
		return wyz;
}