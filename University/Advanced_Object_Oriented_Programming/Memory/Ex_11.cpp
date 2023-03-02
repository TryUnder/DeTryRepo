#include <iostream>
#include <string>

using namespace std;

struct A
{
    string m_name;

    A() {
        cout << "default-ctor" << endl;
    }

    A(const string &name): m_name(name) {
        cout << "direct-ctor: " << m_name << endl;
    }
    
    A(const A &a): m_name(a.m_name) {
        cout << "copy-ctor: " << m_name << endl;
    }

    ~A() {
        cout << "dtor: " << m_name << endl;
    }
};

int main() {
    A foo();

    {
        A a;
        A b{};
        A c = A();
        A d = A{};
    }

    cout << " XxxX " << endl;
    
    {
        A a("a");
        A b{"b"};
        A c = A("c");
    }
}