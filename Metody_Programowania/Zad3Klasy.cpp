#include <iostream>
#include <cmath>
using namespace std;

class punkt {
private:
    double m_x, m_y;
public:
    punkt(double x, double y) : m_x(x), m_y(y) {};
    punkt() : m_x(0), m_y(0) {};

    double& x() { return m_x; }
    double& y() { return m_y; }

    double odleglosc(punkt point) const {
        return sqrt(pow((m_x - point.m_x), 2) + pow(m_y - point.m_y, 2));
    }

    friend ostream& operator << (ostream& out, const punkt& t) {
        out << t.m_x << " " << t.m_y;
        return out;
    }
    double& X() {
        return m_x;
    }
    double& Y() {
        return m_y;
    }
};

class wielobok {
private:
    size_t m_size;
    punkt* m_pointer_to_point;
public:
    wielobok() : m_size(0), m_pointer_to_point(nullptr) {};
    wielobok(const punkt* first, const punkt* second) :
        m_size(second - first), m_pointer_to_point(new punkt[second - first]) {
        for (size_t i = 0; i < m_size; ++i) {
            m_pointer_to_point[i] = *first;
            first++;
            cout << m_pointer_to_point[i] << endl;
        }
    };
    double obwod() {
        double obwod = 0;
        if (m_size) {
            for (size_t i = 0; i < m_size; ++i) {
                obwod += odleglosc(m_pointer_to_point, i, m_size);
            }
            return obwod;
        }
        else {
            return 0;
        }
    }

    ~wielobok() {
        if (m_pointer_to_point != nullptr) {
            delete[] m_pointer_to_point;
            cout << "Memory released" << endl;
        }
    }
    double& x(punkt obj) {
        return obj.X();
    }
    double& y(punkt obj) {
        return obj.Y();
    }
    double odleglosc(punkt obj[], int i, int m_size) const {
        if (i == m_size - 1)return sqrt(pow((obj[0].x() - obj[i].x()), 2) + pow(obj[0].y() - obj[i].y(), 2));
        else { return sqrt(pow((obj[i + 1].x() - obj[i].x()), 2) + pow(obj[i + 1].y() - obj[i].y(), 2)); }
    }

    const size_t& ilosc() const {
        return m_size;
    }

    punkt& operator [](int roz) {
        return m_pointer_to_point[roz];
    }

    wielobok& operator =(const wielobok& r) {
        if (this != &r) {
            if (m_pointer_to_point != nullptr)
                delete[] m_pointer_to_point;
            this->m_size = r.m_size;
            if (m_size != 0) {
                this->m_pointer_to_point = new punkt[m_size];
                for (size_t i = 0; i < m_size; ++i) {
                    this->m_pointer_to_point[i] = r.m_pointer_to_point[i];
                }
            }
            return *this;
        }
    }

    friend ostream& operator << (ostream& out, const wielobok& obj) {
        out << "Jestem wielobokiem i mam: " << obj.m_size << " bokow" << endl;
        return out;
    }

};

int main() {
    punkt p(2, 3);

    cout << p.x() << ' ' << p.y() << '\n';

    p.x() = 1;
    p.y() = 1;

    cout << p.x() << ' ' << p.y() << '\n';

    cout << p.odleglosc(punkt()) << "\n\n";

    const punkt t[] = { punkt(0, 0), punkt(0, 1), punkt(1, 1), punkt(1, 0) };
    cout << sizeof(t) << endl;
    cout << sizeof(punkt) << endl;

    for (size_t i = 0; i < sizeof(t) / sizeof(punkt); ++i)
        cout << i + 1 << ")  " << t[i] << endl;

    cout << "\n*****\n";
    wielobok w1(t, t + 4);

    cout << w1.obwod() << '\n';

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
    return 0;
}