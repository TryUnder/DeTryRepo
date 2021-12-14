#include <iostream>
#include <string>
using namespace std;
#define PURE_VIRTUAL = 0

class pomiar{
protected:
  string m_opis;
  double* m_pomiar;
public:
  pomiar()
      : m_opis(" \" \" "), m_pomiar(new double(0)) {}
  pomiar(const string& opis)
      : m_opis(opis), m_pomiar(new double(0)) {}
  pomiar(const string& opis, const double* ptr_1, const double* ptr_2)
      : m_opis(opis), m_pomiar(new double[ptr_2 - ptr_1 > 0 ? ptr_2-ptr_1 : 0]) {
        size_t size = ptr_2 - ptr_1;
        for(size_t i = 0; i<size; ++i){
          m_pomiar[i] = *(ptr_1);
          //cout << m_pomiar[i] << " ";
          ptr_1++;
        }
      }

  string Get_m_opis() const {
    return m_opis;
  }

  double* Get_m_pomiar() const {
    return m_pomiar;
  }

  virtual string pokaz_opis() const PURE_VIRTUAL;
  virtual double oblicz_wynik() PURE_VIRTUAL;

  friend ostream& operator << (ostream& stream, const pomiar& obj){
    stream << obj.pokaz_opis() << obj.m_opis;
    return stream;
  }
  virtual pomiar& operator=(const pomiar& obj) PURE_VIRTUAL;
};

class ciezar : public pomiar{
private:
public:
  ciezar(): pomiar() {}
  ciezar(const string& opis)
      : pomiar(opis) {}
  ciezar(const string& opis, const double* ptr_1, const double* ptr_2)
      : pomiar(opis,ptr_1,ptr_2) {}

  virtual string pokaz_opis() const override {
    return "Ciezar - ";
  }

  virtual double oblicz_wynik() override {
    double eps=1e-1;
    double sum=0;
    for(int i=0;i<10000000;++i){
      sum += m_pomiar[i];
      if(m_pomiar[i]<eps)break;
    }
    return sum;
  }

  ciezar& operator=(const pomiar& obj) override {
    if(this != &obj){
      double eps = 1e-1;
      this->m_opis = obj.Get_m_opis();
      delete [] this->m_pomiar;
      //this->m_pomiar = new double[obj.Get_m_pomiar]
      //cout << sizeof(obj.Get_m_pomiar())/ << endl;
      double* m_pomiar2 = obj.Get_m_pomiar();
      for(int i=0; i<100; ++i){
        if(*m_pomiar2 < eps){
          double* True_m_pomiar = new double[i];
          do{
            m_pomiar2--;
            i--;
            True_m_pomiar[i] = *m_pomiar2;
            cout << True_m_pomiar[i] << endl;
          }while(i!=0);
          break;
        }
        m_pomiar2++;
      }
    }
    return *this;
  }

};

class temp : public pomiar{
private:
public:
  temp(const string& opis, const double* ptr_1, const double* ptr_2)
      : pomiar(opis,ptr_1,ptr_2) {}

  virtual string pokaz_opis() const override {
    return "Temp - ";
  }
  virtual double oblicz_wynik() override {
    double eps=1e-1;
    double avg=0;
    for(int i=0;i<10000000;++i){
      avg += m_pomiar[i];
      if(m_pomiar[i]<eps){
        if(i==0)throw string("NIE DZIELIMY PRZEZ ZERO!");
        avg /= i;
        break;
      }
    }
    return avg;
  }

  temp& operator=(const pomiar&obj) override {
    if(this != &obj){
      double eps = 1e-1;
      this->m_opis = obj.Get_m_opis();
      delete [] this->m_pomiar;
      //this->m_pomiar = new double[obj.Get_m_pomiar]
      //cout << sizeof(obj.Get_m_pomiar())/ << endl;
      double* m_pomiar2 = obj.Get_m_pomiar();
      for(int i=0; i<100; ++i){
        if(*m_pomiar2 < eps){
          double* True_m_pomiar = new double[i];
          do{
            i--;
            m_pomiar2--;
            True_m_pomiar[i] = *m_pomiar2;
            cout << True_m_pomiar[i] << endl;
          }while(i!=0);
          break;
        }
        m_pomiar2++;
      }
    }
    return *this;
  }
};

int main(){
  double dane[] = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8 };
  //... zdefiniuj tablicę tab
  pomiar* tab[sizeof(dane)/sizeof(dane[0])];
  tab[0] = new ciezar("cytryny");
  tab[1] = new temp("poranki", dane+3, dane+6);
  tab[2] = new ciezar("jabłka", dane+1, dane+3);
  tab[3] = new temp("wieczory", dane+1, dane+9);
  tab[4] = new ciezar;
  cout << "********** 1 **********" << endl;
  for (int i=0; i<5; ++i)
  cout << *tab[i] << endl;

  cout << "\n********** 2 **********" << endl;

  for (int i=0; i<5; ++i)
    try{
      cout << *tab[i] << ", WYNIK : " << tab[i]->oblicz_wynik() << endl;
    }catch(const string& a){cout << a << endl;}
  cout << "\n********** 2a *********" << endl;
  cout << *tab[1] << " " << tab[1]->oblicz_wynik() << endl;
  *tab[2] = ciezar("TEST", dane+3, dane+6);
  cout << *tab[2] << " " << tab[2]->oblicz_wynik() << endl;
  /*
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
