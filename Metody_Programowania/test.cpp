#include <iostream>
#include <cmath>
using namespace std;

class punkt {
private:
    double m_x, m_y;
public:
    punkt() : m_x(0), m_y(0) {};
    punkt(const double x, const double y) : m_x(x), m_y(y) {};

     double& x()  {
        return m_x;
    }
     double& y()  {
        return m_y;
    }

     double odleglosc(const punkt& rval) const {
         return sqrt(pow(rval.m_x - this->m_x, 2) + pow(rval.m_x - this->m_x, 2));
     }

     friend ostream& operator << (ostream& cout, const punkt& obj) {
         cout << "(" << obj.m_x << "," << obj.m_y << ")";
         return cout;
     }
     punkt& operator[](int rozmiar) {
         punkt point;
         return point[rozmiar];
     }
};


class wielobok {
private:
    size_t m_size;
    punkt* m_point;
public:
    wielobok() : m_size(0), m_point(new punkt()) {};
    wielobok(const punkt* point1, const punkt* point2) :
    m_size((point2-point1)>=0 ? (point2-point1):0),
    m_point(m_size >= 0 ? new punkt[m_size] : new punkt()) {
        for (size_t i = 0; i < m_size; ++i) {
            m_point[i] = *point1;
            point1++;
        }
    };

};

int main() {
    punkt p(2, 3);

    cout << p.x() << ' ' << p.y() << '\n';

    p.x() = 1;
    p.y() = 1;
    cout << p.x() << ' ' << p.y() << '\n';

    cout << p.odleglosc(punkt()) << "\n\n";

    const punkt t[] = { punkt(0, 0), punkt(0, 1), punkt(1, 1), punkt(1, 0) };
    for (size_t i = 0; i < sizeof(t) / sizeof(punkt); ++i)
        cout << i + 1 << ")  " << t[i] << endl;

    cout << "\n*****\n";
    wielobok w1(t, t + 4);

    cout << w1.obwod() << '\n';
    /*
    w1[1] = punkt(0.5, 0.5);
    cout << w1.obwod() << '\n';
    cout << "***\n\n";


    wielobok w2;
    w2 = wielobok(t, t + 3);
    cout << w2.obwod() << '\n';

    for (size_t i = 0; i < w2.ilosc(); ++i)
        cout << w2[i].x() << ' ' << w2[i].y() << '\n';

    cout << "\n*****\n";
    wielobok w3(w2);
    w3[1] = punkt(0, -1);
    w3[2] = punkt(-1, -1);
    for (size_t i = 0; i < w3.ilosc(); ++i)
        cout << w3[i] << endl;
    cout << "***\n\n";

    cout << "\n*****\n";
    cout << w2 << "***\n" << w3;
    cout << "*****\n\n";
  
    cout << w2.obwod() - w3.obwod() << "\n\n";
    */
}
