#include <iostream>
using namespace std;

class adres {
private:
	string m_miasto, m_ulica;
	unsigned int m_numer_budynku;
public:
	adres(string miasto, string ulica, unsigned int numer_budynku) :
		m_miasto(miasto), m_ulica(ulica), m_numer_budynku(numer_budynku) {};

	adres() : m_miasto("brak"), m_ulica("brak"), m_numer_budynku(0) {};

	friend ostream& operator <<(ostream& wypisz, const adres& ob) {
		wypisz << ob.m_miasto << " " << ob.m_ulica << " " << ob.m_numer_budynku << endl;
		return wypisz;
	}

	string& Miasto() {
		return m_miasto;
	}
	string& Ulica() {
		return m_ulica;
	}
	unsigned int& NumerBudynku() {
		return m_numer_budynku;
	}
};

class osoba {
private:
	string m_imie;
	unsigned int m_wiek;
	adres* m_adr = nullptr;
public:
	osoba(string imie, unsigned int wiek, adres adresx) :
		m_imie(imie), m_wiek(wiek), m_adr(&adresx) {};

	osoba() :
		m_imie("brak"),
		m_wiek(0) {
		adres* adresx = new adres;
		m_adr = adresx;
	};

	friend ostream& operator <<(ostream& wypisz, const osoba& obiekt) {
		wypisz << obiekt.m_imie << " " << obiekt.m_wiek << endl
			<< obiekt.m_adr->Miasto() << " " << obiekt.m_adr->Ulica() << " "
			<< obiekt.m_adr->NumerBudynku() << endl;
		return wypisz;
	}

	string& miasto() {
		return m_adr->Miasto();
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