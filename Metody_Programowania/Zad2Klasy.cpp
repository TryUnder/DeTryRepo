#include <iostream>

using namespace std;

class adres
{
private:
    string m_miasto, m_ulica;
    unsigned int m_nr_budynku;

public:
    adres() : m_miasto("brak"), m_ulica("brak"), m_nr_budynku(0) {};

    adres(string miasto, string ulica, unsigned int nr_budynku) :
        m_miasto(miasto), m_ulica(ulica), m_nr_budynku(nr_budynku) {};

    friend ostream& operator << (ostream& cout, const adres& obj) {
        cout << obj.m_miasto << " " << obj.m_ulica << " " << obj.m_nr_budynku;
        return cout;
    }
    string& Miasto() { return m_miasto; }
    string& Ulica() { return m_ulica; }
    unsigned int& Nr_budynku() { return m_nr_budynku; }
};
class osoba
{
private:
    string m_imie;
    unsigned int m_wiek;
    adres* m_adr;

public:
    osoba() : m_imie("brak"), m_wiek(0), m_adr(new adres) {};

    osoba(string const imie, const unsigned int wiek, const adres adr) :
        m_imie(imie), m_wiek(wiek), m_adr(new adres(adr)) {}

    osoba(osoba& obj) {
        m_imie = obj.m_imie;
        m_wiek = obj.m_wiek;
        m_adr = new adres;
        *m_adr = *obj.m_adr;
    }

    ~osoba() {
        if (m_adr != nullptr) {
            delete m_adr;
            m_adr = nullptr;
        }
    }

    friend ostream& operator << (ostream& cout, const osoba& obj) {
        cout << obj.m_imie << " " << obj.m_wiek << " " << obj.m_adr->Miasto() << " " << obj.m_adr->Ulica()
            << " " << obj.m_adr->Nr_budynku();
        return cout;
    }

    string& miasto() {
        return m_adr->Miasto();
    }

    osoba& operator=(const osoba& entity) {
        if (this != &entity) {
            this->m_imie = entity.m_imie;
            this->m_wiek = entity.m_wiek;
            m_adr = new adres;
            *m_adr = *entity.m_adr;
        }
        return *this;
    }
};

int main()
{
    adres* wsk = new adres("Czêstochowa", "D¹browskiego", 73);

    cout << wsk << '\n';
    cout << *wsk << '\n';

    adres a1(*wsk);

    delete wsk;
    wsk = nullptr;

    const adres* wsk1 = new adres("£ódŸ", "Piotrkowska", 33);

    cout << a1 << '\n';
    cout << *wsk1 << '\n';

    adres a2;

    cout << a2 << '\n';

    a2 = a1;

    cout << a2 << '\n';

    osoba os1("Ala", 25, *wsk1);

    delete wsk1;
    cout << os1 << '\n';

    osoba os2(os1);

    os1.miasto() = "Zmieniono miasto osoby 1.";

    cout << os1 << endl;

    cout << os2 << '\n';

    osoba os3;

    cout << os3 << '\n';

    os3 = os2;

    os1.miasto() = "Drugi raz zmieniono miasto osoby 1.";
    cout << os3 << '\n';
}