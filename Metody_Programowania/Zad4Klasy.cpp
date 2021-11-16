#include <iostream>
using namespace std;

class point {
private:
	double tab[3];
public:
	point() : tab { 0, 0, 0 }{};
	point(double* wsk) : tab{ *wsk,*(wsk + 1),*(wsk + 2) } {};
	point(double x, double y, double z) : tab{x,y,z} {}

	friend ostream& operator <<(ostream& out, const point& obj);
	const double& operator[] (const int& rozmiar) const {
		return tab[rozmiar];
	}
}; 

ostream& operator <<(ostream& out, const point& obj) {
	out << obj.tab[0] << " " << obj.tab[1] << " " << obj.tab[2];
	return out;
}

int main() {
	double x[2][3] = { {1.0, 1.0, 1.0},
					{1.0, 2.0, 3.0} };
	
	point p1(x[0]), p2(x[1]);
	
	const point p3(0.4, 0.2, 0.1);
	
	cout << p1 << ", " << p2 << '\n';
	
	cout << p3[0] << ' ' << p3[1] << ' ' << p3[2] << '\n';
	/*
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
	*/
	return 0;
}