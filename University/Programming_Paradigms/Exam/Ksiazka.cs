/*
 * 
3.C#: Stwórz klasy na podstawie przykładów:


    var ksiazki = new [] {

         new Ksiazka {Tytul = "Pan Tadeusz", RokWydania = 1998, Gatunek = 1, Cena = 30},

         new Ksiazka {Tytul = "Potop", RokWydania = 1991, Gatunek = 1, Cena = 40},

         new Ksiazka {Tytul = "W pustyni i w puszczy", RokWydania = 1990, Gatunek = 2, Cena = 30},

         new Ksiazka {Tytul = "Lalka", RokWydania = 1990, Gatunek = 1, Cena = 50},

         new Ksiazka {Tytul = "Programowanie funkcyjne w języku C#", RokWydania = 2019, Gatunek = 3, Cena = 71.20},

         new Ksiazka {Tytul = "Programowanie funkcyjne z JavaScriptem", RokWydania = 2017, Gatunek = 3, Cena = 29.40},

};         

    var gatunki = new [] {

         new Gatunek { id = 1, Nazwa = "Literatura piękna" },

         new Gatunek { id = 2, Nazwa = "Przygodowa" },

         new Gatunek { id = 3, Nazwa = "Programowanie" },

 new Gatunek { id = 4, Nazwa = "Projektowanie stron WWW" }

    };

Napisz zapytanie Linq, które dla każdego gatunku określi cenę najdroższej książki, która do niego należy. 
Jeżeli nie ma książek w danym gatunku zapytanie powinno zwrócić 0.

*/ 

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    public class Ksiazka
    {
        public string Tytul { get; set; }
        public int RokWydania { get; set; }
        public int Gatunek { get; set; }
        public decimal Cena { get; set; }
        public Ksiazka(string tytul = "Brak tytułu", int rokWydania = 2003, int gatunek = 1, decimal cena = 50.00M)
        {
            Tytul = tytul;
            RokWydania = rokWydania;
            Gatunek = gatunek;
            Cena = cena;
        }
    }
}

// Gatunek

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    public class Gatunek
    {
        public int id { get; set; }
        public string Nazwa { get; set; }
        public Gatunek(int aid = 1, string nazwa = "Brak nazwy")
        {
            id = aid;
            Nazwa = nazwa;
        }
    }
}


// Program

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Linq.Expressions;
using System.Collections;
namespace Test
{
    class Program
    {

        public static void Main()
        {
            var ksiazki = new[]
            {
                new Ksiazka {Tytul = "Pan Tadeusz", RokWydania = 1998, Gatunek = 1, Cena = 30},
                new Ksiazka {Tytul = "Potop", RokWydania = 1991, Gatunek = 1, Cena = 40 },
                new Ksiazka {Tytul = "W pustyni i w puszczy", RokWydania = 1990, Gatunek = 2, Cena = 30 },
                new Ksiazka {Tytul = "Lalka", RokWydania = 1990, Gatunek = 1, Cena = 50},
                new Ksiazka {Tytul = "Programowanie funkcyjne w jezyku C#", RokWydania = 2019, Gatunek = 3, Cena = 71.20m},
                new Ksiazka {Tytul = "Programowanie funkcyjne w JavaScriptem", RokWydania = 2017, Gatunek = 3, Cena = 29.40m }
            };

            var gatunki = new[]
            {
                new Gatunek { id = 1, Nazwa = "Literatura piękna" },
                new Gatunek { id = 2, Nazwa = "Przygodowa" },
                new Gatunek { id = 3, Nazwa = "Programowanie" },
                new Gatunek { id = 4, Nazwa = "Projektowanie stron WWW" }
            };

            // 1 - JOIN, grupowanie po gatunkach, przeliczanie listy ksiazek w każdym obiekcie grupowania

            var GatunekIKsiazki = gatunki.Join(ksiazki, x => x.id, y => y.Gatunek, (x, y) => new
            {
                gatunek = x.Nazwa,
                tytul = y.Tytul
            }).GroupBy(x => x.gatunek);

            foreach (var item in GatunekIKsiazki)
            {
                Console.WriteLine(item.Key + ": ");
                foreach (var ksiazka in item)
                {
                    Console.WriteLine($"{ksiazka.tytul}");
                }
            }

            // 2 - JOIN, grupowanie po gatunkach, wyświetlenie gatunku + liczby książek (z transformacją group by obiektu)
            var GatLKs = ksiazki.Join(gatunki, x => x.Gatunek, y => y.id, (x, y) => new
            {
                Gatunek = y.Nazwa,
                Cena = x.Tytul
            }).GroupBy(x => x.Gatunek).Select(x => new { Gatunek = x.Key, Liczba = x.Count()});

            foreach (var item in GatLKs)
            {
                Console.WriteLine($"{item.Gatunek}: {item.Liczba}");
            }

            // 3 - najdrozsza ksiazka dla poszcz. gatunków

            var GatunekNajdrKsiazka = ksiazki.Join(gatunki, x => x.Gatunek, y => y.id, (x, y) => new
            {
                Gatunek = y.Nazwa,
                Cena = x.Cena
            }).GroupBy(x => x.Gatunek).Select(x => new { Gatunek = x.Key, MaxCena = x.Max(x => x.Cena) });

            foreach (var item in GatunekNajdrKsiazka)
            {
                Console.WriteLine($"Gatunek: {item.Gatunek}, Max. Cena: {item.MaxCena}");
            }
            
        }
    }
}
