#include <string>
#include <vector>

class Klasa1 {
public:
	Klasa1();
private:
	int atr1;
	int atr2;
	int atr3;
	Klasa2& alfa;
	Klasa5 *klasa5;
	Klasa9 tab[10];
};

class Klasa2 {
public:
	Klasa2();
	virtual ~Klasa2();
	virtual bool metoda1(long par2, double par1) = 0;
};

class Klasa3 : public Klasa2 {
public:
	Klasa3();
	bool metoda1(long par2, double par1);
private:
	int atr1;
};

class Klasa4 : public Klasa2 {
public:
	Klasa4();
	bool metoda1(long par2, double par1);
private:
	float atr2;
};

class Klasa5 : public Klasa6 {
private:
	std::vector<Klasa7*> vec;
public:
	Klasa5();
	virtual ~Klasa5() {
	    for (size_t i = 0; i < vec.size(); ++i)
		delete vec[i];
	}
};

class Klasa6 {
public:
	Klasa6();
	virtual ~Klasa6();
	void op1(float par2, bool par1);
protected:
	std::string napis1;
};

class Klasa7 {
public:
	Klasa7();
};

class Klasa8 : public Klasa2 {
public:
	Klasa8();
	bool metoda1(long par2, double par1);
private:
	char atr3;
};

class Klasa9 {
private:
	std::vector<Klasa10*> tab1;
	std::vector<Klasa11*> tab2;
public:
	Klasa9();
	virtual ~Klasa9();
};

class Klasa10 {
private:
	std::string tab[4];
public:
	Klasa10();
	virtual ~Klasa10();
};

class Klasa11 {
public:
	Klasa11();
	virtual ~Klasa11();
	Klasa11 *m_Klasa11;
};
