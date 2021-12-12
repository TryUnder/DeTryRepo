#include <iostream>
#include <string>
#include <vector>
using namespace std;

class pomiar{
private:
  string m_opis;
  double* m_pomiar;
public:
  pomiar()
      : m_opis("brak"), m_pomiar(new double(0)) {}
  pomiar(const string& opis)
      : m_opis(opis) {}
  pomiar(const string& opis, const double* ptr_1, const double* ptr_2)
      : m_opis(opis), m_pomiar(new double[ptr_2 - ptr_1 > 0 ? ptr_2-ptr_1 : 0]) {
        size_t size = ptr_2 - ptr_1;
        for(size_t i = 0; i<size; ++i){
          m_pomiar[i] = *ptr_1;
          ptr_1++;
        }
      }
  string Get_m_opis() const {
    return m_opis;
  }
  friend ostream& operator << (ostream& stream, const pomiar& obj){
    stream << obj.Get_m_opis();
    vector <double> m_pomiar;
    for(size_t i=0; i<m_pomiar.size(); ++i){
      stream << obj.m_pomiar[i] << " ";
    }
    stream << endl;
    return stream;
  }
};

class ciezar : public pomiar{
private:
public:
  ciezar(): pomiar() {}
  ciezar(const string& opis)
      : pomiar(opis) {}
  ciezar(const string& opis, const double* ptr_1, const double* ptr_2)
      : pomiar(opis,ptr_1,ptr_2) {}
};

class temp : public pomiar{
private:
public:
  temp(const string& opis, double* ptr_1, double* ptr_2)
      : pomiar(opis,ptr_1,ptr_2) {}
};

int main(){
  double dane[] = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8 };
  //... zdefiniuj tablicę tab
  pomiar* tab[sizeof(dane)/sizeof(dane[0])];

  tab[0] = new ciezar("cytryny") ;
  tab[1] = new temp("poranki", dane+3, dane+6);
  tab[2] = new ciezar("jabłka", dane+1, dane+3);
  tab[3] = new temp("wieczory", dane+1, dane+9);
  tab[4] = new ciezar;

  cout << "********** 1 **********" << endl;
  for (int i=0; i<5; ++i)
    cout << *tab[i] << endl ;
  /*

  cout << "\n********** 2 **********" << endl;

  for (int i=0; i<5; ++i)
    try{
      cout << *tab[i] << ", WYNIK : " << tab[i]->oblicz_wynik() << endl ;
    }
    catch (const string& a){
     cout << a << endl;
    }


  cout << "\n********** 2a *********" << endl;
  *tab[0] = ciezar("cytryny", dane, dane+1);
  *tab[0] = ("[kg] " + *tab[0]) += "po wyprzedaży";
  *tab[1]  = "Wiosenne " + *tab[1];
  *tab[2] += "ANTONÓWKI suszone";
  *tab[2] *= 0.1;
  *tab[3] += "po korekcie odczytu";
  *tab[3] += 0.1;

  for (int i=0; i<5; ++i)
    try{
      cout << *tab[i] << ", WYNIK : " << tab[i]->oblicz_wynik() << endl ;
    }
    catch (const string& a){
     cout << a << endl;
    }

  for (int i=0; i<5; ++i)
    delete tab[i];


  cout << "\n********** 3 **********" << endl;
  const ciezar test1("gruszki", dane, dane+9);
  const temp test2;

  //w odpowiednim miejscu zdefiniuj funkcję pokaz_wszystko(...)

  pokaz_wszystko(cout, test1);
  pokaz_wszystko(cout, test2);
  pokaz_wszystko(cout, ciezar());
  pokaz_wszystko(cout, temp("Jakaś tam", dane+8, dane+9));
  */
}
