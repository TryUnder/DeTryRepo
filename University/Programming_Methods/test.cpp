#include <iostream>
#include <vector>
#include <memory>
 
class Digits{
private:
    std::vector<std::shared_ptr<int>> m_vec;
    std::vector<std::shared_ptr<int>> m_vec2;
 
public:
    Digits() 
    // Inicjalizacja elementów na liście inicjalizacyjnej samego wektora m_vec
    // A potem przeniesienie m_vec do m_vac2 za pomocą konstruktura wektora (nie listy)
    : m_vec { std::make_shared<int>(1) }, m_vec2 (std::move(m_vec)) {}
 
    Digits(const int& digit) 
    // Inicjalizacja elementów na liście inicjalizacyjnej samego wektora
    : m_vec 
    { 
        std::make_shared<int>(digit),
        std::make_shared<int>(666) 
    }
 
    {
        // Bezpośrednia Inicjalizacja składowej. Tak się powinno to robić.
        m_vec.push_back(std::make_shared<int>(1));
 
        // Inicjalizacja składowej za pomocą Gettera.
        // Funkcje stworzy kopie wektora doda do niej element. 
        // A potem go porzuci, bo nigdzie nie jest zapisany poza ramką funkcji.
        GetVec().push_back(std::make_shared<int>(2));
 
        // Inicjalizacja składowej a pomocą Gettera pobierającego referencje do vectora.
        // Pobiera m_vec i dodaje do niej nowy element. Można, tylko po co ? Nie ma to sensu używania
        // go z wnętrza. Ale jak się ktoś uprze, to w ten sposób.
        GetVecRef().push_back(std::make_shared<int>(3));
 
        // Nie zadziała bo vector nie ma przeładowania operatora "=" do kopiowania.
        // Nawet jak by mógł to wykonywanie kopii dużych obiektów jest nieefektywne i wolne.
        // Po co robić kopie, ktorą trzeba zaraz zwracać, to głupie. Wiekszość obiektów z klasy
        // standardowej nawe to nie zezwoli
        
// ==> m_vec = GetVec().push_back( std::make_shared<int>(digit) ); 
 
        // Tu podobnie. Brak przeładowania '=' dla klasy wektor.
        // Odwołujemy się do referencji m_vec, by przypisać nią do siebie samej.
        // Pomimo bezsensownosci, teretycznie da się przypisać referencje do referencji.
        // Taka konstrucka powinna do m_vec zwrócić 'void' by przerwać cykliczność
        // Teoretycznie legane, w praktyce bezsensowne i doprowadza do błędów o których się nie wiesz.
        
// ==> m_vec = GetVecRef().push_back( std::make_shared<int>(digit) );
    }
 
    std::vector<std::shared_ptr<int>> GetVec ()  {
        return m_vec;
    }
 
    std::vector<std::shared_ptr<int>> &GetVecRef ()  {
        return m_vec;
    }
 
    std::vector<std::shared_ptr<int>> &GetVecRef2 ()  {
        return m_vec2;
    }
};
 
int main(){
    int digit = 10;
    Digits a(digit);
    std:: cout << "Pobieranie i wyświetlanie referencji" << std::endl;
    for (auto element: a.GetVecRef() ) //Pobieranie referencji.
    {
        std::cout << *element << std::endl;
        // Wynik:
        // 10  => zmienna digit przekaza przez konstruktor do listy inicjalizacyjnej;
        // 666 => zmienna przekaza bezpośrednio w liście inicjalizacyjnej wektora;
        // 1   => Zmienna dodana w ciele konstruktora za pomocą push_back() operując bezpośredno na polu m_vec
        // 2   !> Nigdy tego nie zobaczysz, bo funkcja stworzyła kopie wektora, który potem się rozpłynął
        // 3   => Zmienna dodana za pomocą Gettera pobierającego referencje do pola i wykonaniu na nieh push_backu()
    }
    // Modyfiakcja wnętrza klasy
    std:: cout << "Dodawanie elementu do wektora w klasie" << std::endl;
    a.GetVecRef().push_back(std::make_shared<int>(999));
    a.GetVecRef().push_back(std::make_shared<int>(888));
    a.GetVecRef().push_back(std::make_shared<int>(777));
 
    std::cout << std::string(10, '-') << std::endl;
    std:: cout << "Pobieranie i wyświetlanie referencji z klasy" << std::endl;
    for (auto element: a.GetVecRef() )
    {std::cout << *element << std::endl ;} // 999 znajdzie się wewnątrz klasy
 
    // Przechwycenie kopii wektora wykonanej przez GetVac()
    std:: cout << "Przechwycenie kopii wektora" << std::endl;
    std::vector<std::shared_ptr<int>> kopia = a.GetVec();
 
    std::cout << std::string(10, '-') << std::endl;
    // Nic co dodamy do kopii, nie będzie miało wpływu na orginalne pole m_vac
     std:: cout << "Wyślietlanie kopii wektora" << std::endl;
    for (auto element: kopia )
    {std::cout << *element << std::endl ;}
 
    // ================================================
    std::cout << std::string(10, '=') << std::endl;
    Digits b;
    
    
    // Dla konstruktora domyślnego m_vec został przeniesiony do m_vec2
    // m_vec będzie pusty
    std::cout << "Vector m_vec" << std::endl;
    
    for (auto element: b.GetVecRef() )
    {std::cout << *element << std::endl ;}
 
    std::cout << std::string(10, '-') << std::endl;
 
    // Dane z m_vec zostaną przeniesione do m_vec2
    std::cout << "Vector m_vec2" << std::endl;
    
    for (auto element: b.GetVecRef2() )
    {std::cout << *element << std::endl ;}
 
}