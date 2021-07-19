#include <iostream>
#include <windows.h>
#include <cmath>

#define LOG(message) std::cout << message << std::endl;
class CashPoint {
private:
	static short int i;
	unsigned int m_PIN;
	bool m_privilage = false;
	long double m_cash = 0;
	void ClearScreen() {
		std::cout << "\033[2J\033[1;1H";
	}
public:
	void SetPin(unsigned short int& PIN)
	{
		m_PIN = PIN;
		LOG("PIN zostal ustawiony");
		Sleep(1000); LOG("2");
		Sleep(1000); LOG("1");
		Sleep(1000);
		ClearScreen();
	}
	void VerifyPin(unsigned short int& PIN)
	{
		unsigned short int userpin;
		if (m_PIN == PIN)
		{
			m_privilage = true;
		}
		if (m_privilage)
		{
			LOG("Dostep zostal przyznany");
			std::cout << std::endl;
		}
		if (!m_privilage)
		{
			i++;
			LOG("sPIN  niepoprawny. Wprowadz ponownie");
			std::cin >> userpin;
			if (i == 2)
			{
				std::terminate();
			}
			VerifyPin(userpin);
		}
	}

	void Show_Balance()
	{
		std::cout << "Na koncie jest: " << m_cash << " zl" << std::endl << std::endl;
		ShowOptions();
	}

	void Deposit_Cash()
	{
		LOG("Wplata: ");
		long double Deposit;
		std::cin >> Deposit;
		if (Deposit > 0)
		{
			Update_Cash(Deposit);
		}
		std::cout << std::endl;
		ShowOptions();
	}

	void Withdraw_Cash()
	{
		LOG("Wyplata: ");
		long double Withdraw;
		std::cin >> Withdraw;
		if (m_cash - fabs(Withdraw) >= 0)
		{
			Update_Cash(-fabs(Withdraw));
		}
		std::cout << std::endl;
		ShowOptions();
	}

	void ShowOptions()
	{
		bool choice;
		LOG("Czy chcesz kontynuowac?");
		LOG("1 - TAK");
		LOG("0 - NIE");
		std::cin >> choice;
		if (choice) ShowMenu();
		else Exit();
	}

	void Exit()
	{
		return;
	}

	void Update_Cash(const long double Money)
	{
		m_cash += Money;
	}

	void ShowMenu()
	{
		LOG("WPISZ: ");
		LOG("0 - Wyswietl stan konta")
			LOG("1 - Wplac srodki na konto")
			LOG("2 - Wyplac srodki z konta")
			LOG("3 - Zakoncz dzialanie")
			unsigned short int choice;
		std::cin >> choice;
		if (choice == 0) Show_Balance();
		if (choice == 1) Deposit_Cash();
		if (choice == 2) Withdraw_Cash();
		if (choice == 3) Exit();
	}
};

short int CashPoint::i = 0;

int main()
{
	CashPoint user;
	unsigned short int userpin;
	LOG("Ustaw PIN do karty");
	std::cin >> userpin;
	user.SetPin(userpin);
	LOG("Wprowadz PIN do karty");
	std::cin >> userpin;
	user.VerifyPin(userpin);
	user.ShowMenu();
	return 0;
}