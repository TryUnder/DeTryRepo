#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cfloat>

using namespace std;

double** przydziel_pamiec(int n, int m) {
  double** tab = new double*[n];
  for (int i = 0; i < n; ++i)
    tab[i] = new double[m];
  return tab;
}

void zwolnij_pamiec(double** tab, int n, int m) {
  for (int i = 0; i < n; ++i)
    delete[] tab[i];
  delete[] tab;
}

void zapisz_macierz(char* nazwa, double** tab, int n, int m) {
  if (tab) {
    ofstream out(nazwa, ios::app);
    out << '\n' << n << ' ' << m << '\n';
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
	       out << tab[i][j] << ' ';
      out << '\n';
    }
  }
}

void wczytaj_macierze(char* nazwa,
		      double** tab1, int& n1, int& m1,
		      double** tab2, int& n2, int& m2) {
  ifstream plik(nazwa);
  plik >> n1 >> m1;
  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < m1; ++j)
      plik >> tab1[i][j];
  }

  plik >> n2 >> m2;
  for (int i = 0; i < n2; ++i) {
    for (int j = 0; j < m2; ++j)
      plik >> tab2[i][j];
  }

}

double** dodawanie(double** tab1, int n1, int m1,
		   double** tab2, int n2, int m2, int& n, int& m) {
  if (n1 == n2 && m1 == m2) {
    n = n1;
    m = m1;
    double** tab = new double*[n];
    for (int i = 0; i < n; ++i) {
      tab[i] = new double[m];
      for (int j = 0; j < m; ++j)
	       tab[i][j] = tab1[i][j] + tab2[i][j];
    }
    return tab;
  } else {
    n = m = 0;
    return NULL;
  }
}

double** mnozenie(double** tab1, int n1, int m1,
		  double** tab2, int n2, int m2, int& n, int& m) {
  if (m1 == n2) {
    n = n1;
    m = m2;
    double** tab = przydziel_pamiec(n, m);
    double suma = 0.0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	       suma = 0.0;
	        for (int k = 0; k < m1; ++k) {
	           suma = tab1[i][k]*tab2[k][j];
	        }
	        tab[i][j] = suma;
      }
    }
    return tab;
  } else {
    n = m = 0;
    return NULL;
  }
}

int main(int argc, char* argv[]) {
  if (argc > 1) {

    int A_n = 0, A_m = 0, B_n = 0, B_m = 0;
    double** A = przydziel_pamiec(A_n, A_m);
    double** B = przydziel_pamiec(B_n, B_m);
    wczytaj_macierze(argv[1], A, A_n, A_m, B, B_n, B_m);

    int C_n, C_m;
    double** C = dodawanie(A, A_n, A_m, B, B_n, B_m, C_n, C_m);
    zapisz_macierz(argv[1], C, C_n, C_m);

    int D_n, D_m;
    double** D = mnozenie(A, A_n, A_m, B, B_n, B_m, D_n, D_m);
    zapisz_macierz(argv[1], D, D_n, D_m);

    zwolnij_pamiec(A, A_n, A_m);
    zwolnij_pamiec(B, B_n, B_m);
    zwolnij_pamiec(C, C_n, C_m);
    zwolnij_pamiec(D, D_n, D_m);
  } else {
    cerr << "./program nazwa_pliku\n";
  }
  return 0;
}
