#include <string>
#include <vector>

class BazowaG{
public:
    virtual void op1() = 0;
    virtual void op2() = 0;
    virtual double op3(double a) = 0;
    virtual ~BazowaG() = 0;
};

class KlasaF : public BazowaG{
private:
    std::string nap;
    int x;
    int y;
public:
    KlasaF();
    void op1();
    void op2();
    double op3(double a);
};

class CzescA{
private:
    int l1;
    int l2;
    BazowaG* obiektG;
    CzescB* obiektB;
public:
    CzescA();
    CzescB op1(int a);
    ~CzescA(){
        delete obiektB;
    }
};

class CzescB{
private:
    int cs;
public:
    CzescB();
    void op1();
    bool op2(double a);
    int op3();
};

class KlasaC{
private:
    int lp;
    std::string np;
    double wt;
    std::vector<CzescB*> obiektB;
    KlasaD& obiektD;
public:
    KlasaC();
    void op1();
    ~KlasaC();
};

class KlasaD{   
private:
    int lp;
    std::string np;
    double wt;
    KlasaE* obiektE;
public:
    KlasaD();
    void op1();
    ~KlasaD(){
        delete obiektE;
    }
};

class KlasaE{
private:
    std::string nap;
    std::vector<CzescA*> obiektA;
public:
    KlasaE();
    CzescA op1(int a, std::string b);
    void op2(double a);
    ~KlasaE(){
        for (auto i = 0; obiektA.size(); ++i) {
            delete obiektA[i];
        }
    }
};

