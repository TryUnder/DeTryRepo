#include <iostream>
using namespace std;
#define PURE_VIRTUAL =0

class robot{
public:
  static int liczba_obiektow;
  virtual void praca() const PURE_VIRTUAL;
  virtual ~robot(){}
  friend ostream& operator << (ostream& stream, const robot& entity){
    entity.praca();
    return stream;
  }
};

class rt1 : public robot{
private:
  string* m_text;
public:
  rt1(): m_text(new string("POLOZONO")) {liczba_obiektow++;};
  rt1(const string& text): m_text(new string(text)) {liczba_obiektow++;};
  rt1(const rt1& entity){
    this->m_text = new string(*(entity.m_text));
    liczba_obiektow++;
  }

  virtual void praca() const override {
    cout << *m_text << endl;
  }

  ~rt1() { delete m_text;liczba_obiektow--; }
};

class rt2 : public robot {
private:
  string* m_text;
  unsigned int m_hit;
public:
  rt2(): m_text(new string("ROBOT_NIEZAPROGRAMOWANY")), m_hit(0) {liczba_obiektow++;};
  rt2(const string& text, const unsigned int hit): m_text(new string(text)), m_hit(hit) {liczba_obiektow++;};
  ~rt2() { delete m_text; liczba_obiektow--; }

  virtual void praca() const override {
    if(m_hit == 0) {throw string("robot niezaprogramowany");}
    if(m_hit != 0) {cout << *m_text << " " << m_hit << endl;}
  }

};
int robot::liczba_obiektow=0;
int main(){

  const rt1 odbior("odebrano gotowy produkt");

  robot* linia[5];

  linia[0] = new rt1("polozono");
  linia[1] = new rt2("uderzono",5);
  linia[2] = new rt2("prawo",4);
  linia[3] = new rt2("uderzono",7);
  linia[4] = new rt1(odbior);

  for(int i=0; i<5; ++i){
    linia[i]->praca();
  }
cout << "********** 3 **********" << endl;
  for(int i=0; i<5; ++i){
    cout << *linia[i];
    delete linia[i];
  }

  cout << "Liczba robotow: " << robot::liczba_obiektow << endl;
  linia[0] = new rt1;
  linia[1] = new rt2;
  linia[2] = new rt1;
  linia[3] = new rt2;
  linia[4] = new rt1(odbior);
  cout << "Liczba robotow: " << robot::liczba_obiektow << endl;
  for(int i=0; i<5; ++i){
    try{cout << *linia[i];
    }catch(const string& e){ cout << e << endl;}
  }
}
