#include <iostream>
using namespace std;

class K1{
private:
  string* p1;
public:
  K1(): p1(new string[2]){
    p1[0] = "brak";
    p1[1] = "brak";
  };
  K1(const string arg1, const string arg2){
      p1 = new string[2];
      p1[0] = arg1;
      p1[1] = arg2;
    };


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
};

int main(){
  K2 ob1,ob2;
  const K2* wsk1 = new K2("kawa", " z mlekiem", 4.50);
//  const K2 ob3(*wsk1);
}
