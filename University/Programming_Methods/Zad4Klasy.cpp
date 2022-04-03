#include <iostream>
#include <cmath>
using namespace std;

class point {
private:
	double tab[3];
public:
	point() : tab { 0, 0, 0 }{};
	point(double* wsk) : tab{ *wsk,*(wsk + 1),*(wsk + 2) } {};
	point(double x, double y, double z) : tab{x,y,z} {}

	friend ostream& operator <<(ostream& out, const point& obj) {
		out << obj.tab[0] << " " << obj.tab[1] << " " << obj.tab[2];
		return out;
	}

	const double& operator[] (const int& rozmiar) const {
		return tab[rozmiar];
	}

	friend const point operator +(const point& la, const point& ra) {
		point p;
		for (int i = 0; i < la.size(); ++i) 
			p.tab[i] = la.tab[i] + ra.tab[i];		
		return p;
	}

	friend const point operator -(const point& la, const point& ra) {
		point p;
		for (int i = 0; i < la.size(); ++i)
			p.tab[i] = la.tab[i] - ra.tab[i];
		return p;
	}

	friend const point operator *(const double& pi, const point& ra) {
		point p;
		for (int i = 0; i < ra.size(); ++i)
			p.tab[i] = pi * ra.tab[i];
		return p;
	}

	friend const point operator *(const point& la, const double& pi) {
		point p;
		for (int i = 0; i < la.size(); ++i) 
			p.tab[i] = la.tab[i] * pi;
		return p;
	}

	friend bool operator <(const point& la, const point& ra) {
		return (la.distance() < ra.distance());
	}

	friend bool operator ==(const point& la, const point& ra) {
		double eps = 1e-10;
		return fabs(la.distance() - ra.distance())<eps;
	}

	friend istream& operator >>(istream& in, point& obj) {
		cout << "Podaj x: "; in >> obj.tab[0];
		cout << "Podaj y: "; in >> obj.tab[1];
		cout << "Podaj z: "; in >> obj.tab[2];
		return in;
	}

	double distance(const point& obj) const {
		return sqrt(pow(obj.tab[0] - this->tab[0], 2) + pow(obj.tab[1] - this->tab[1], 2));
	}

	double distance() const {
		point p;
		return sqrt(pow(this->tab[0]-p.tab[0], 2) + pow(this->tab[1]-p.tab[1], 2));
	}

	int size() const {
		return static_cast<int>(sizeof(this->tab) / sizeof(this->tab[2]));
	}
}; 

int main() {
	double x[2][3] = { {1.0, 1.0, 1.0},
					{1.0, 2.0, 3.0} };
	
	point p1(x[0]), p2(x[1]);
	
	const point p3(0.4, 0.2, 0.1);
	
	cout << p1 << ", " << p2 << '\n';
	
	cout << p3[0] << ' ' << p3[1] << ' ' << p3[2] << '\n';
	
	cout << p1.distance(point()) << endl;
	
	cout << p3.distance(p1) << endl;
	
	cout << p1 + p2 << endl;
	
	cout << p1 - p3 << endl;
	
	cout << 3.14 * p2 << endl;
	
	cout << p2 * 3.14 << endl;
	
	cout << (p1 < p3) << endl;
	
	cout << (p1 == point(1.0, 1.0, 1.0)) << endl;
	
	cin >> p1;
	cout << p1 << '\n';
	
	return 0;
}