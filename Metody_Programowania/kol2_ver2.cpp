#include <iostream>
using namespace std;
#define PURE_VIRTUAL =0

class komunikator {
public:
  static int liczba_obiektow;
  virtual void Show() const PURE_VIRTUAL;
  friend ostream& operator << (ostream& stream, const komunikator& entity){
    entity.Show();
    return stream;
  }
  virtual ~komunikator(){};
};

class k1 : public komunikator {
private:
  string* m_text;
public:
  k1(): m_text(new string("Brak danych")) {liczba_obiektow++;};
  k1(const string& text): m_text(new string(text)) {liczba_obiektow++;};
  k1(const k1& entity): m_text(new string(*entity.m_text)){liczba_obiektow++;};
  virtual void Show() const override {
    cout << *m_text << endl;
  }
  ~k1() { delete m_text;liczba_obiektow--; }
};

class k2 : public komunikator {
private:
  string* m_text;
  double m_temp;
public:
  k2(): m_text(new string("Brak danych")), m_temp(0) {liczba_obiektow++;};
  k2(const string& text, const double& temp): m_text(new string(text)), m_temp(temp){liczba_obiektow++;};
  virtual void Show() const override {
    if(m_temp == 0){throw string("Brak danych");}
    if(m_temp != 0){cout << *m_text << " " << m_temp << endl;}
  }
  ~k2(){ delete m_text;liczba_obiektow--; }

  friend k2& operator += (k2& entity, const double& modifier){
    entity.m_temp += modifier;
    return entity;
  }
};

int komunikator::liczba_obiektow=0;

int main(){
  const k1 koniec("Koniec komunikatow");
  komunikator* linia[5];
  linia[0] = new k1("Temperatury powietrza: ");
  linia[1] = new k2("Czestochowa ",-5);
  linia[2] = new k1("Opady sniegu (cm): ");
  linia[3] = new k2("Katowice",10);
  linia[4] = new k1(koniec);

  for(int i=0; i<5; ++i){
    cout << *linia[i];
  }

  cout << "********** 3 *********" << endl;
  *(static_cast<k2*>(linia[1])) += 2;
  *(static_cast<k2*>(linia[3])) += 2;

  for(int i=0; i<5; ++i){
    cout << *linia[i];
    delete linia[i];
  }
  cout << "********** 4 **********" << endl;

  cout << "Liczba dzialajacych obiektow : " << komunikator::liczba_obiektow << endl;
  linia[0] = new k1("Temperatury powietrza: ");
  linia[1] = new k2;
  linia[2] = new k1("Opady sniegu (cm): ");
  linia[3] = new k2;
  linia[4] = new k1(koniec);

  cout << "Liczba dzialajcych obiektow :" << komunikator::liczba_obiektow << endl;

  for(int i=0; i<5; ++i){
    try{cout << *linia[i];
    }catch(const string& e){ cout << e << endl; }
  }
  cout << "********** 5 **********" << endl;
}
