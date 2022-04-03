#include <iostream>
using namespace std;

class B {
private:
	string* m_string;
public:
	B(const string& arg1="brak") : m_string(new string(arg1)) {}
	B(const B& entity) : m_string(new string(entity.GET_DEREFERENCED_M_STRING())) {}

	string* GET_ADDRESS_M_STRING() const {
		return m_string;
	}
	string*& GET_MODIFIABLE_LVALUE() {
		return m_string;
	}
	string GET_DEREFERENCED_M_STRING() const {
		return *m_string;
	}

	virtual void Print() const {
		cout << *m_string << endl;
	}

	friend ostream& operator << (ostream& stream, const B& entity) {
		entity.Print();
		return stream;
	}

	B& operator =(const B& entity){
		//if(this != &entity) nie w tym przypadku 145
			*GET_MODIFIABLE_LVALUE() = entity.GET_DEREFERENCED_M_STRING();
			return *this;
	}
   virtual ~B() { delete m_string; }
};

class P1 : public B {
protected:
	B m_obj;
public:
	P1(const string& arg1="brak", const string& arg2="brak") : B(arg2), m_obj(arg1) {}
	P1(const P1& entity) : B(entity), m_obj(entity.m_obj) {}
	P1(const P1* entity) : B(*entity), m_obj(entity->m_obj) {}

	string txt1() const {
		return m_obj.GET_DEREFERENCED_M_STRING() + " ";
	}
	string txt2() const {
		return GET_DEREFERENCED_M_STRING();
	}

	virtual void Print() const override {
		cout << m_obj.GET_DEREFERENCED_M_STRING() << " "
				 << GET_DEREFERENCED_M_STRING() << endl;
	}

	friend ostream& operator << (ostream& stream, const P1& entity) {
		cout << entity.txt1() << " " << entity.txt2();
		return stream;
	}

	friend P1& operator +(const string& arg1, P1& entity){
		*entity.GET_MODIFIABLE_LVALUE() = arg1 + (*entity.GET_MODIFIABLE_LVALUE());
		return entity;
	}

	friend P1& operator +(P1& entity, const string& arg1){
		*entity.GET_MODIFIABLE_LVALUE() += arg1;
		return entity;
	}

	P1& operator=(const P1& entity){
		//if(this != &entity) tutaj nie zadziala, bo 145 operuje na tych samych danych
			*m_obj.GET_MODIFIABLE_LVALUE()=entity.m_obj.GET_DEREFERENCED_M_STRING();
			B::operator=(entity);
			return *this;
	}
};

class P2 : public P1 {
protected:
	double m_double;
public:
	P2(const string& arg1="brak", const string& arg2="brak", const double& arg3=0)
		: P1(arg2, arg1), m_double(arg3) {}
	P2(const P2& entity) : P1(entity), m_double(entity.m_double) {}

	string txt1() const {
		return GET_DEREFERENCED_M_STRING();
	}
	string txt2() const {
		return m_obj.GET_DEREFERENCED_M_STRING();
	}
	double w1() const {
		return m_double;
	}

	virtual void Print() const override {
		cout << GET_DEREFERENCED_M_STRING() << " "
				 << m_obj.GET_DEREFERENCED_M_STRING() << " " << m_double << endl;
	}

	friend ostream& operator << (ostream& stream, const P2& entity) {
		cout << entity.txt1() << " " << entity.txt2() << " " << entity.w1();
		return stream;
	}
};

int main() {
	const P1* wsk1 = new P1("coffee", "bar");
	const P2* wsk2 = new P2("white", "coffe", 1.50);
	const P1* wsk3 = new P1("thank", "you");

	B ob1("---------");
	cout << wsk1->txt1() << " " << wsk1->txt2() << endl;
	cout << wsk2->txt1() << " " << wsk2->txt2() << " " << wsk2->w1() << endl;
	cout << *wsk3 << endl << endl;

	P1 x = *wsk1; delete wsk1; wsk1 = 0;
    P2 y = *wsk2; delete wsk2; wsk2 = 0;
	P1 z = *wsk3; delete wsk3; wsk3 = 0;

	B* tab1[4];
	tab1[0] = new B(ob1);
	tab1[1] = new P1(y);
	tab1[2] = new B(ob1);
	tab1[3] = new B(ob1);

	for(int i=0; i<4; ++i){
		cout << *tab1[i];
		delete tab1[i];
	}
	cout << endl;
	tab1[0] = &x;
	tab1[1] = &y;
	tab1[2] = &z;
	tab1[3] = &ob1;

	*static_cast<P1*>(tab1[0])="<" + *static_cast<P1*>(tab1[0]) + ">";
	for(int i=0; i<4; ++i){
		cout << *tab1[i];
	}
	return 0;
}
