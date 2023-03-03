#include <iostream>
#include <string>

using namespace std;

struct A
{
  A()
  {
    cout << "default-ctor" << endl;
  }

  A(const A &a)
  {
    cout << "copy-ctor" << endl;
  }

  ~A()
  {
    cout << "dtor" << endl;
  }
};

A foo(bool flag) {
    //14.
    A a, b;
    /*
    W związku z tym, że nie wiadomo jakie obiekty mają być zwrócone, oba muszą zostać stworzone.
    */

    return flag ? a : b;
}

int main() {
    foo(true);
}