#include <iostream>
#include <vector>
using namespace std;
#define PURE_VIRTUAL =0

class robot{
public:
static int l_ob;
static int l_obiektow() { return l_ob; }
virtual void praca() const PURE_VIRTUAL;
};

class r1 : public robot {
public:
  r1(){l_ob++;}
  ~r1(){l_ob--;}

virtual void praca() const override {
  cout << "r1" << endl;
}

};

class r2 : public robot {
public:
virtual void praca() const override {
  cout << "r2" << endl;
}
r2(){l_ob++;}
~r2(){l_ob--;}
};

class line{
private:
vector <robot*> ve;
public:
line(): ve() {};
line(const int& size): ve(size) {
  cout << "Wartości wektora ve : ";
  for(size_t i=0; i<ve.size(); ++i){
    cout << ve.at(i) << ", ";
  }
  cout << endl;
};

void dodaj_ostatni(const robot*& entity){
  ve.push_back(entity);
}

~line(){cout << "~line()" << endl; }
};

int robot::l_ob = 0;
void liczba_obiektow(){
  cout << "Liczba_obiektów = " << robot::l_obiektow() << endl;
}

int main()try{
  #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
  #endif
  {
    liczba_obiektow();
    { line l1 ;    }
    { line l2(5) ; }
    liczba_obiektow();
    cout << "--==**1**==--" << endl;
    line lp1, lp2;

    liczba_obiektow();

    lp1.dodaj_ostatni(new r1);
    /*
    lp1.dodaj_ostatni(new r1);
    lp1.dodaj_ostatni(new r2);
    lp1.dodaj_ostatni(new r2);
    //liczba_obiektow();
    lp2=lp1;
    //liczba_obiektow();
    {
      line lp3;
      //liczba_obiektow();
      lp3.dodaj_ostatni(new r1);
      lp3.dodaj_ostatni(new r2);
      lp3.dodaj_ostatni(new r1);
      lp3.dodaj_ostatni(new r2);
      //liczba_obiektow();
      lp3.usun_ostatni();
      //liczba_obiektow();
      cout << "--==**2**==--" << endl;
      //liczba_obiektow();
      lp3.do_roboty();
      //liczba_obiektow();
      lp1 = lp3;
      cout << "--==**2a**==--" << endl;
      //liczba_obiektow();
    }
    //liczba_obiektow();
    cout << "--==**3**==--" << endl;
    lp1.do_roboty();
    cout << "--==**4**==--" << endl;

    wsk TabAdrRob[] = {new r2, new r2};
    //liczba_obiektow();
    line lp4(TabAdrRob, TabAdrRob+2 );
    lp4.dodaj_ity(1, new r1);  r1
    //liczba_obiektow();
    lp4.do_roboty();
    cout << "--==**5**==--" << endl;
    //liczba_obiektow();
    lp4 = lp2;
    lp4.do_roboty();
    cout << "--==**6**==--" << endl;
    line lp6(lp1);
    lp6.usun_ity(1);
    //Usuń robot na pozycji o indeksie 1
    lp6.do_roboty();
    cout << "--==**7**==--" << endl;

    //liczba_obiektow();
    delete TabAdrRob[0];
    delete TabAdrRob[1];
  }
  liczba_obiektow();
  //Tutaj liczba obiektów powinna być równa zero.
  //Jeśli jest inaczej musisz popracować nad swoim programem.
  #ifdef _WIN32
    system("PAUSE");
  #endif
  return 0;
}
*/
}}
catch(...){
  cout << "Ooooops!\nCoś poszło nie tak.\n";
}
