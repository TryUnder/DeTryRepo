#include <iostream>
using namespace std;

class K1{
private:
  string* p1;
public:
  K1(): p1(new string{"brak"}){};

  string& GetP1() const {
    return *p1;
  }

};

class K2{
private:
  K1 txt[2];
  int p2;
public:
  K2(): txt(), p2(0){};
  K2(const string& arg1, const string& arg2, const double& arg3):
  txt(), p2(arg3){
    txt[0].GetP1() = arg1;
    txt[1].GetP1() = arg2;
  }

  friend ostream& operator << (ostream& out, const K2& obj){
    out << obj.txt[0].GetP1() << " " << obj.txt[1].GetP1() << " " << obj.p2 << endl;
    return out;
  }

  friend K2 operator +(K2& lv, const double& rval){
    K2 temp = lv;
    temp.p2 = lv.p2 + rval;
    return temp;
  }
};

int main(){
  K2 ob1,ob2;
  cout << ob1 << endl;
  const K2* wsk1 = new K2("Ala", "Koala", 15);
  cout << *wsk1 << endl;
  const K2 ob3(*wsk1);
  cout << ob3 << endl;
  delete wsk1;
  wsk1 = 0;

  const K2* wsk2 = new K2(ob3);
  cout << *wsk2 << endl;
  ob2 = *wsk2;
  cout << ob2 << endl;
  cout << ob2+10 << endl;
}
