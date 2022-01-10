#include <iostream>
using namespace std;
#define PURE_VIRTUAL =0

class B {
public:
  friend ostream& operator << (ostream& stream, const B& entity){
    entity.pokaz_opis();
    return stream;
  }

  virtual void pokaz_opis () const PURE_VIRTUAL;
  virtual ~B() {}
};

class P1 : public B {
public:
  string* m_string;
public:
  P1(const string& _string = "brak"): m_string(new string(_string)) {}
  string GetName() const {return *m_string;}
  virtual void pokaz_opis() const override{
    cout << *m_string << endl;
  }
  void SetValue(const string& text) const {
    *m_string = text;
  }
  friend const P1& operator + (const string& _string, const P1& entity){
    *entity.m_string = _string + (*entity.m_string);
    return entity;
  }

  P1& operator =(const P1& entity){
     if(this != &entity){
       if(m_string != nullptr){
         delete m_string;
       }
       this->m_string = new string(*entity.m_string);
     }
    return *this;
   }
   P1(const P1& other) : P1(*other.m_string) {}

  ~P1() {delete m_string;}
};

class P2 : public B {
protected:
  P1* m_pointer;
public:
  P2(const string& _string = "Zgredek_nie_chce_pana"): m_pointer(new P1(_string)) {}
  P2(const P2& entity) : m_pointer(new P1(*entity.m_pointer)) {}
  P2& operator=(const P2& entity){
    if(this != &entity){
      if(m_pointer != nullptr){
        delete m_pointer;
      }
      m_pointer = new P1(*entity.m_pointer);
    }
    return *this;
  }

  P2& operator += (const string& _string){
    *m_pointer->m_string = *m_pointer->m_string + _string;
    return *this;
  }

  string two_GetName() const { return m_pointer->GetName(); }
  virtual void pokaz_opis() const override {
    cout << two_GetName() << endl;
  }

  ~P2() {delete m_pointer;}
};

class P3 : public P2 {
private:
  int m_number;
public:
  P3(const string& _string = "brak", const int& number = 0): P2(_string), m_number(number) {}
  P3& operator=(const P3& entity){
    if (this != &entity){
      m_number = entity.m_number;
      P2::operator=(entity);
    }
    return *this;
  }

  P3(const P3& entity):  P2(entity), m_number(entity.m_number) {}
  P3& operator += (const int& number){
    m_number += number;
    return *this;
  }

  virtual void pokaz_opis () const override {
    cout << *m_pointer << " " << m_number << endl;
  }

};

void kopia_danych(B* tab1[3], B* tab2[3], const int& m_int){
  for(int i=0; i<m_int; ++i){
    *tab2[i] = *tab1[i];
  }
}

int main(){
  const P1* wsk1 = new P1("Ala");
  const P2* wsk2 = new P2("koty");
  const P3* wsk3 = new P3("ma",2);

  P1 x; x = *wsk1; delete wsk1;
  P2 y; y = *wsk2; delete wsk2;
  P3 z; z = *wsk3; delete wsk3;

  B* tab1[3];
  tab1[0] = new P1(x);
  tab1[1] = new P3(z);
  tab1[2] = new P2(y);

  for(int i=0; i<3; ++i){
    cout << *tab1[i];
  }

  for(int i=0; i<3; ++i){
    delete tab1[i];
  }
  cout << "********** 3 **********" << endl;

  x = "Mala " + x;
  z += 2;
  tab1[0] = new P1(x);
  tab1[1] = new P3(z);
  tab1[2] = new P2(y);

  for(int i=0; i<3; ++i){
    cout << *tab1[i];
  }

  cout << "********** 4 **********" << endl;
  B* tab2[3];
  tab2[0] = new P1(x);
  tab2[1] = new P3(z);
  tab2[2] = new P2(y);
  *static_cast<P2*>(tab2[2]) += " i psa.";
  cout << "PRZED KOPIA:" << endl;
  for(int i=0; i<3; ++i){
    cout << *tab2[i];
  }

  kopia_danych(tab1,tab2,3);
  cout << "PO KOPII: " << endl;
  for(int i=0; i<3; ++i){
    cout << *tab2[i];
  }

  for(int i=0; i<3; ++i){
  delete tab1[i];
  delete tab2[i];
  }

  cout << "********** 5 **********" << endl;
}
