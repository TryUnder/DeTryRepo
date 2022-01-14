#include <iostream>
using namespace std;
#define PURE_VIRTUAL =0

class B {
public:
  virtual void pokaz_wszystko() const PURE_VIRTUAL;
  virtual ~B() {}
  friend ostream& operator << (ostream& stream, const B& entity){
    entity.pokaz_wszystko();
    return stream;
  }
};

class P1 : public B {
private:
  string* m_tab[2];
public:
  // VERSION 1 CONSTRUCTOR OF P1 CLASS
     P1(const string& first_arg="brak", const string& second_arg="brak"): m_tab{new string(first_arg),new string(second_arg)} {}
  // VERSION 2 CONSTRUCTOR OF P1 CLASS
  // P1(const string& first_arg="brak", const string& second_arg="brak") {
    /*
      VER 1 OF ASSIGNMENT
      m_tab[0] = new string();
     *m_tab[0] = first_arg;
      m_tab[1] = new string();
     *m_tab[1] = second_arg;

      VER 2 OF ASSIGNMENT
      m_tab[0] = new string(first_arg);
      m_tab[1] = new string(second_arg);
    }
    */

  P1& operator=(const P1& entity){
    if(this != &entity){
    // VERSION 1 OF ASSIGNMENT
    *m_tab[0] = *entity.GetValue0();
    *m_tab[1] = *entity.GetValue1();
    // VERSION 2 OF ASSIGNMENT
    //*static_cast<string*>(m_tab[0]) = *entity.GetValue0();
    //*static_cast<string*>(m_tab[1]) = *entity.GetValue1();
    }
    return *this;
  }

    string operator[](const int& iterator) const {
    if(iterator != 0 && iterator != 1) throw string("INDEKS POZA ZAKRESEM");
    return *m_tab[iterator];
  }

  // VERSION 1 OF COPY CONSTRUCTOR FOR P1 CLASS
  P1(const P1& entity): P1(*entity.GetValue0(),*entity.GetValue1()) {}
  // VERSION 2 OF COPY CONSTRUCTOR FOR P2 CLASS
  //P1(const P1& entity): m_tab{new string(*entity.GetValue0()), new string(*entity.GetValue1())} {}

  string* GetValue0() const {
    return m_tab[0];
  }
  string* GetValue1() const {
    return m_tab[1];
  }

  ~P1(){delete m_tab[0];delete m_tab[1];}
  virtual void pokaz_wszystko() const override {
    cout << *GetValue0() << " " << *GetValue1() << endl;
  }
};

class P2 : public B {
protected:
  int m_int;
  P1 m_reference;
public:
  P2(): m_int(0), m_reference(P1()) {}
  P2(const int &_int, const string& f_ag, const string& s_ag)
     : m_int(_int), m_reference(P1(f_ag,s_ag)) {}

  P2& operator=(const P2& entity){
    if(this != &entity){
      m_int = entity.m_int;
      m_reference = entity.m_reference;
    }
    return *this;
  }

  friend P2& operator +(const int& modifier, P2& entity){
    entity.m_int += modifier;
    return entity;
  }

  //KONSTRUKTOR KOPIUJACY KLASY P2 WERSJA 1
  P2(const P2& entity) : m_int(entity.m_int), m_reference(entity.m_reference) {}
  //KONSTRUKTOR KOPIUJACY KLASY P2 WERSJA 2
  //P2(const P2& entity) : P2(entity.m_int, *entity.m_reference.GetValue0(), *entity.m_reference.GetValue1()) {}

  virtual void pokaz_wszystko() const override {
    cout << m_int << " " << *m_reference.GetValue0() << " " << *m_reference.GetValue1() << endl;
  }
};

void wyswietl(B* tab1[3], const int& size) {
  for(int i=0; i<size; ++i){
    cout << *tab1[i];
  }
}

int main(){
  const P1* wsk1 = new P1("Ala", "ma ");
  const P2* wsk2 = new P2(2, "czarne", "koty");
  const P1* wsk3 = new P1("++++++","++++++");

  P1 x; cout << x; x = *wsk1; delete wsk1;
  P2 y; cout << y; y = *wsk2; delete wsk2;
  P1 z; cout << z; z = *wsk3; delete wsk3;

  B* tab1[3];
  tab1[0] = new P1(x);
  tab1[1] = new P2(y);
  tab1[2] = new P1(z);
  for(int i=0; i<3; ++i){
   cout << *tab1[i];
  }

   for(int i=0; i<3; ++i){
     delete tab1[i];
   }

   cout << "********** 3 **********" << endl;

   x[0] = "Mala Ala";
   y = 2 + y;

   tab1[0] = new P1(x);
   tab1[1] = new P2(y);
   tab1[2] = new P1(z);

   for(int i=0; i<3; ++i){
     cout << *tab1[i];
   }

   cout << "********** 4 **********" << endl;

   try{
     static_cast<P1*>(tab1[0])->operator[](3)="w domu";
   } catch(const string& err) { cout << err << endl; }

   wyswietl(tab1, 3);

   for(int i=0; i<3; ++i){
     delete tab1[i];
   }

   cout << "********** 5 **********" << endl;
   return 0;
}
