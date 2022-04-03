#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class B {
private:
  unique_ptr<string> m_string;
public:
  B(const string& arg1="brak") 
    : m_string(new string(arg1)) {}
  B(const B& entity)
    : m_string(new string(entity.Get_string())) {}

    string Get_string() const {
      return *m_string.get();
    }

    friend ostream& operator << (ostream& stream, const B& entity){
    stream << entity.Get_string();
    return stream;
  }
    
};

class P1 : public B{
protected:
  B m_obj;
public:
  P1(const string& arg1="brak", const string& arg2="brak")
    : B(arg1), m_obj(arg2) {}
  P1(const P1& entity) : B(entity.Get_string()), m_obj(entity.m_obj.Get_string()) {}

  string txt1() const {
    return Get_string();
  }
  string txt2() const {
    return m_obj.Get_string();
  }

  friend ostream& operator << (ostream& stream, const P1& entity){
    stream << entity.txt1() << " " << entity.txt2() << endl;
    return stream;
  }
};

class P2 : public P1{
protected:
  double m_double;
public:
  P2(const string& arg1="brak", const string& arg2="brak", const double& arg3=0)
    : P1(arg1,arg2), m_double(arg3) {}
  P2(const P2& entity) 
    : P1(entity.Get_string(), entity.m_obj.Get_string()), m_double(entity.w1()) {}

  double w1() const {
    return m_double;
  }

  friend ostream& operator << (ostream& stream, const P2& entity){
    stream << entity.txt1() << " " << entity.txt2() << " " << entity.w1() << endl;
    return stream;
  }
};

int main(){
  unique_ptr<P1> wsk1{new P1{"coffee","bar"}};
  unique_ptr<P2> wsk2{new P2{"white", "coffee", 1.50}};
  unique_ptr<P1> wsk3{new P1{"thank","you"}};
  B ob1("----------");

  cout << wsk1->txt1() << " " << wsk1->txt2() << endl;
  cout << wsk2->txt1() << " " << wsk2->txt2() << " " << wsk2->w1() << endl;
  cout << *wsk3 << endl;

  P1 x = *wsk1.get();
  //wsk1.release();
  P2 y = *wsk2.get();
  //wsk2.release();
  P1 z = *wsk3.get();
  //wsk3.release();

  vector<unique_ptr<B>>tab1(4);
  tab1.insert(tab1.begin(),make_unique<B>(ob1));
  cout << *tab1.at(0) << endl;
}
