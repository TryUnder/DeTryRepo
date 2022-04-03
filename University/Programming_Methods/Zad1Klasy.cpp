#include <iostream>
using namespace std;

class punkt {
private:
    double m_x, m_y, m_z;
public:
    punkt(double x1 = 0, double y1 = 0, double z1 = 0) : m_x(x1), m_y(y1), m_z(z1) {};
    double& x() { return m_x; }
    double& y() { return m_y; }
    double& z() { return m_z; }
    const double& x() const { return m_x; }
    const double& y() const { return m_y; }
    const double& z() const { return m_z; }
};

class prostokat {
private:
    punkt m_punkt;
    double m_a, m_b;
public:
    prostokat(double x = 0, double y = 0, double z = 0, double a = 0, double b = 0) :
        m_punkt(x, y, z), m_a(a), m_b(b) {};
    prostokat(punkt p, double a, double b) : m_punkt(p), m_a(a), m_b(b) {};
    double& x() { return m_punkt.x(); }
    double& y() { return m_punkt.y(); }
    double& z() { return m_punkt.z(); }
    double& a() { return m_a; }
    double& b() { return m_b; }
    const double& x() const { return m_punkt.x(); }
    const double& y() const { return m_punkt.y(); }
    const double& z() const { return m_punkt.z(); }
    const double& a() const { return m_a; }
    const double& b() const { return m_b; }
    double pole() const { return  m_a * m_b; }
};

class graniastoslup {
private:
    punkt m_punkt;
    prostokat m_prostokat;
    double m_a, m_b, m_h;
public:
    graniastoslup(double x = 0, double y = 0, double z = 0,
        double a = 0, double b = 0, double h = 0) : m_punkt(x, y, z),
        m_a(a), m_b(b), m_h(h) {};

    graniastoslup(punkt p, double a = 0, double b = 0, double h = 0) :
        m_punkt(p), m_a(a), m_b(b), m_h(h) {};

    graniastoslup(prostokat pr, double h = 0) : m_prostokat(pr),
        m_h(h) {};
    double objetosc() { return (m_a * m_b) * m_h; }
    double objetosc() const { return (m_prostokat.a() * m_prostokat.b()) * m_h; }

    double& x() { return m_punkt.x(); }
    double& y() { return m_punkt.y(); }
    double& z() { return m_punkt.z(); }
    double& a() { return m_a; }
    double& b() { return m_b; }
    double& h() { return m_h; }
    const double& x() const { return m_prostokat.x(); }
    const double& y() const { return m_prostokat.y(); }
    const double& z() const { return m_prostokat.z(); }
    const double& a() const { return m_prostokat.a(); }
    const double& b() const { return m_prostokat.b(); }
    const double& h() const { return m_h; }
};

int main()
{
    punkt p1, p2(1, 2, 3);
    const punkt p3(1.1, 2.2, 3.3);
    //p1.PokazPunkt();
    //p2.PokazPunkt();
    //p3.PokazPunkt();

    cout << p1.x() << endl;
    cout << p2.x() << endl;

    cout << p3.x() << endl;
    //
    cout << p3.x() << '\t' << p3.y() << '\t' << p3.z() << endl;//

    p1.x() = 1; p1.y() = 10; p1.z() = 100;//

    cout << p1.x() << '\t' << p1.y() << '\t' << p1.z() << endl;

    prostokat pr1, pr2(1, 2, 3, 10.5, 20.5);

    const prostokat pr3(p2, 5, 5);

    pr1.x() = 2; pr1.y() = 20; pr1.x() = 200; pr1.a() = 10; pr1.b() = 10;

    cout << pr1.x() << '\t' << pr1.y() << '\t' << pr1.z() << '\t'//
        << pr1.a() << '\t' << pr1.b() << '\t' << endl;//
    cout << pr1.pole() << endl;//


    cout << pr3.x() << '\t' << pr3.y() << '\t' << pr3.z() << '\t'//
        << pr3.a() << '\t' << pr3.b() << '\t' << endl;//

    cout << pr3.pole() << endl;//

    graniastoslup g1, g2(1, 2, 3, 10.5, 20.5, 30.5), g3(p2, 100, 200, 300);

    const graniastoslup g4(pr3, 5);

    cout << g4.x() << '\t' << g4.y() << '\t' << g4.z() << '\n'
        << g4.a() << '\t' << g4.b() << '\t' << g4.h() << '\n'
        << g4.objetosc() << endl;

    g1.a() = 10; g1.b() = 10; g1.h() = 10;

    cout << g1.x() << '\t' << g1.y() << '\t' << g1.z() << '\n'
        << g1.a() << '\t' << g1.b() << '\t' << g1.h() << '\n'
        << g1.objetosc() << endl;

}