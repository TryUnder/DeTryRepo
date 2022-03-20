#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
using naturalne = uint;
using naturalne = unsigned;
class uint{
private:
    unsigned v;
public:
      uint(): v(0) {};
      uint(const unsigned& a): v(a) {};
      operator unsigned () const { return v; }
      friend ostream& operator << (ostream& out, const uint& r){
        return out << r.v;
      }
      friend istream& operator >> (istream& in, uint& r){
        return in >> r.v;
      }
};

class point{
  double x,y;
public:
  point(): x(0), y(0){};
  point(const double& a, const double& b): x(a), y(b){};
  double distance(const point& a) const;
  friend class polygon;
  friend istream& operator>>(istream&, point&);
  friend ostream& operator<<(ostream&, const point&);
};

double point::distance(const point& a) const{
  double c2 = (a.x-x)*(a.x-x)+(a.y-y)*(a.y-y);
  if(c2<1e-20)
    return 0;
    return sqrt(c2);
}

istream& operator>>(istream& in, point& p){ return in >> p.x >> p.y;}
ostream& operator<<(ostream& out, const point& p){ return out << p.x << ' ' << p.y; }

class polygon{
private:
size_t m_nodes;
double* m_tab;

public:
  polygon(): m_nodes(0), m_tab(new double[0]){};
  polygon(size_t nodes, double* tab):
  m_nodes(nodes>0 ? nodes : 0), m_tab(new double[nodes]) {};

  void read(ifstream& fin){

};

struct blad {
  string txt;
  unsigned lp;
  blad(): lp(0){};
  blad(const string& a, unsigned b): txt(a), lp(b){};
};

int main (int argc, char* argv[])try {

  if (argc !=2) throw int(0);
  if (strlen(argv[1]) < 5 ) throw int(1);
  if (string(argv[1]+(strlen(argv[1])-3))!="txt") throw 2 ;

  ifstream file(argv[1]);
  if(!file) throw int (3);
  {
    polygon poly;
    poly.read(file);
    //try{
      //poly.read(file);
      //cout<< "obwód : " << poly.obwod()<< endl;
      //cout<< "pole  : " << poly.pole()<< endl;
    //}
    //catch ( const string& e ){ cout << e << endl;}
  //  catch ( const blad&   e ){ cout << e ;}
    //file.close();
  }


  return 0;
}
catch (int err){
  switch (err) {
    case 0: cout << err <<": Zła liczba parametrów programu.\n";
    break;
    case 1: cout << err <<": Zła nazwa pliku z danymi.\n";
    break;
    case 2: cout << err <<": Złe rozszerzenie pliku z danymi - musi być *.txt .\n";
    break;
    case 3: cout << err <<": Brak pliku o nazwie "<< argv[1] << " .\n";
  }
}
catch ( ... ) { cout << "Nieznana sytuacja wyjątkowa.\n"; }
