#include <iostream>
using namespace std;

class osoba{
protected:
  string m_nazwisko;
  unsigned int m_liczba_lat;
public:
  osoba(): m_nazwisko("brak"), m_liczba_lat(0){};
  osoba(const string& nazwisko, const unsigned int& liczba_lat):
        m_nazwisko(nazwisko), m_liczba_lat(liczba_lat){};
  osoba(const osoba& entity){
    m_nazwisko = entity.m_nazwisko;
    m_liczba_lat = entity.m_liczba_lat;
  }
        virtual void pokaz() const {
          cout << m_nazwisko << " " << m_liczba_lat << endl;
        }

  osoba& operator=(const osoba& entity){
    this->m_nazwisko = entity.m_nazwisko;
    this->m_liczba_lat = entity.m_liczba_lat;
    return *this;
  }
};

class pracownik : public osoba{
private:
  string m_stanowisko;
  unsigned int m_placa;
public:
  pracownik(): osoba(), m_stanowisko("brak"), m_placa(0) {};
  pracownik(const string& nazwisko, const unsigned int& liczba_lat,
            const string& stanowisko, const unsigned int& placa):
            osoba(nazwisko,liczba_lat), m_stanowisko(stanowisko), m_placa(placa){};

  pracownik(const pracownik& entity): osoba(entity){
      this->m_stanowisko = entity.m_stanowisko;
      this->m_placa = entity.m_placa;
  }

  pracownik& operator =(const pracownik& entity){
      this->osoba::operator=(entity);
      this->m_stanowisko = entity.m_stanowisko;
      this->m_placa = entity.m_placa;
      return *this;
  }

  string nazwisko() const {
    return m_nazwisko;
  }

  unsigned int liczba_lat() const {
    return m_liczba_lat;
  }

  string stanowisko() const {
    return m_stanowisko;
  }

  unsigned int placa() const {
    return m_placa;
  }


  virtual void pokaz() const override {
    cout << m_nazwisko << " " << m_liczba_lat << " " << m_stanowisko << " " << m_placa << endl;
  }
};

int main(){
  osoba os("Dolas", 26);

    os.pokaz();

    const pracownik pr1("Dyzma", 35, "mistrz", 1250.0);

    cout << pr1.nazwisko() << pr1.liczba_lat();

    cout << pr1.stanowisko() << pr1.placa();

    pracownik pr2(pr1);

    pr2.pokaz();

    pracownik pr3("Kos", 45, "kierownik", 2999.0);

    pr3.pokaz();

    pr3 = pr2;

    pr3.pokaz();

    osoba* w = &os;

    w->pokaz();

    w = &pr3;

    w->pokaz();

    static_cast<pracownik*>(w)->pokaz();

  return 0;
}
