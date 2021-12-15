#include <iostream>
#include <string>
using namespace std;
#define PURE_VIRTUAL = 0

class pomiar {
protected:
  string m_opis;
  size_t m_size;
  double* m_pomiar;
public:
  pomiar(): m_opis(" \" \" "), m_size(0), m_pomiar(nullptr) {}
  pomiar(const string& opis): m_opis(opis), m_size(0), m_pomiar(nullptr) {}
  pomiar(const string& opis, const double* ptr1, const double* ptr2)
        :m_opis(opis), m_size(ptr2 - ptr1 > 0 ? ptr2 - ptr1 : 0),
         m_pomiar(new double[m_size]) {
           for(size_t i=0; i<m_size; ++i){
             m_pomiar[i] = *ptr1;
             ptr1++;
           }
         }
 virtual ~pomiar(){
   delete [] m_pomiar;
 }

  virtual string pokaz_opis() const PURE_VIRTUAL;
  virtual double oblicz_wynik() const PURE_VIRTUAL;

   pomiar& operator = (const pomiar& obj){
    if(this != &obj){
      m_opis = obj.m_opis;
      delete [] m_pomiar;
      this->m_size = obj.m_size;
      this->m_pomiar = new double[m_size];
      for(size_t i=0; i<m_size; ++i){
        m_pomiar[i] = obj.m_pomiar[i];
      }
    }
    return *this;
  }
  friend ostream& operator << (ostream& stream, const pomiar& obj){
    stream << obj.pokaz_opis() << obj.m_opis;
    return stream;
  }
  friend pomiar& operator + (const string& str, pomiar& obj){
    obj.m_opis=str+obj.m_opis;
    return obj;
  }
  friend pomiar& operator += (pomiar& obj, const string& str){
    obj.m_opis=obj.m_opis+str;
    return obj;
  }
  friend pomiar& operator *= (pomiar& obj, const double& modifier){
    for(size_t i=0; i<obj.m_size; ++i){
      obj.m_pomiar[i] = obj.m_pomiar[i] * modifier;
    }
    return obj;
  }
  friend pomiar& operator += (pomiar& obj, const double& modifier){
    for(size_t i=0; i<obj.m_size; ++i){
      obj.m_pomiar[i] = obj.m_pomiar[i] + modifier;
    }
    return obj;
  }
};

class ciezar : public pomiar {
public:
  ciezar(): pomiar() {}
  ciezar(const string& opis): pomiar(opis) {}
  ciezar(const string& opis, const double* ptr1, const double* ptr2)
       : pomiar(opis,ptr1,ptr2) {}

  virtual string pokaz_opis() const override {
    return "Ciezar - ";
  }
  virtual double oblicz_wynik() const override {
    double sum=0;
      for(size_t i=0; i<m_size; ++i){
        sum+=m_pomiar[i];
    }
    //if(sum==0) throw string("brak danych");
    return sum;
  }
};

class temp : public pomiar {
public:
  temp(): pomiar() {}
  temp(const string& opis): pomiar(opis) {}
  temp(const string& opis, const double* ptr1, const double* ptr2)
       : pomiar(opis,ptr1,ptr2) {}
  virtual string pokaz_opis() const override {
    return "Temp - ";
  }
  virtual double oblicz_wynik() const override {
    double avg=0;
    for(size_t i=0; i<m_size; ++i){
      avg+=m_pomiar[i];
    }
    //if(m_size==0) throw string("NIE DZIEL PRZEZ ZERO");
    return avg/m_size;
  }
};

void pokaz_wszystko(ostream& stream, const pomiar& obj){
  stream << obj << ", WYNIK: " << obj.oblicz_wynik() <<  endl;
}

int main(){
  double dane[] = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8 };

  //... zdefiniuj tablicę tab
  pomiar* tab[sizeof(dane)/sizeof(dane[0])];
  tab[0] = new ciezar("cytryny") ;
  tab[1] = new temp("poranki", dane+3, dane+6);
  tab[2] = new ciezar("jabłka", dane+1, dane+3) ;
  tab[3] = new temp("wieczory", dane+1, dane+9);
  tab[4] = new ciezar;

  cout << "********** 1 **********" << endl;
  for (int i=0; i<5; ++i)
    cout << *tab[i] << endl ;


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

}
