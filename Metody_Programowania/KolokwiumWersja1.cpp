#include <iostream>
using namespace std;

class K1{
private:
  string* p1;
public:
  K1(): p1(new string[2]{"brak","brak"}){};
  K1(const string arg1, const string arg2):
    p1(new string[2] {arg1,arg2}) {};

  string fout(const int i) const {
    return p1[i];
  }
  K1(string* p):
  p1(new string[2]){};

};

class K2{
private:
  K1 w1;
  double w2;
public:
  K2(): w1(), w2(0){};
  K2(const string arg1, const string arg2, const double arg3): w1(arg1,arg2), w2(arg3){};

  friend ostream& operator << (ostream& out, const K2& obj){
    out << obj.w1.fout(0) << " " << obj.w1.fout(1) << " za: " << obj.w2 << endl;
    return out;
  }

  friend const K2 operator -(const K2& la, const double lowered_price){
    K2 K2x;
    K2x.w2 = la.w2 - lowered_price;
    return K2x;
  }
};

int main(){
  K2 ob1,ob2;
  const K2* wsk1 = new K2("kawa", " z mlekiem", 4.50);
  const K2 ob3(*wsk1);
  delete wsk1;
  wsk1 = 0;

  const K2* wsk2 = new K2(ob3);
  ob2=*wsk2;
  cout << ob1 << endl;
  delete wsk2;
  wsk2=0;
  cout << ob2;
  cout << ob2-1.25;
  cout << "****** 3 *****\n" << endl;
/*
  K2 tab[4];
  for(int i=0; i<4; ++i){
    tab[i]+=1;
    cout << tab[i];
  }
  cout << "***** 4 *****\n" << endl;
  */
}
