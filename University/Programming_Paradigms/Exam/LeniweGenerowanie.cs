using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    public struct Punkt
    {
        public double X { get; set; }
        public double Y { get; set; }
        public double Z { get; set; }
        public Punkt(double x = 0.0, double y = 0.0, double z = 0.0)
        {
            X = x;
            Y = y;
            Z = z;
        }

        public override string ToString()
        {
            return $"x = {X}, y = {Y}, z = {Z}";
        }
    }
    public static class KolFunctions
    {
        public static IEnumerable<Punkt> LosowychPunktow2D(this int licznik)
        {
            var wylosowana = new Random();
            for (var i = 0; i < licznik; ++i)
            {
                var x = ((double)wylosowana.Next(0, 99)) / 10;
                var y = ((double)wylosowana.Next(0, 99)) / 10;
                var z = ((double)wylosowana.Next(0, 99)) / 10;
                yield return new Punkt(x, y, z);
            }
        }

        public static IEnumerable<Punkt> Punkty3D(this int licznik)
        {
            var wylosowana = new Random();
            for (var i = 0; i < licznik; ++i)
            {
                var x = wylosowana.Next(-20, 20);
                var y = wylosowana.Next(-20, 20);
                var z = wylosowana.Next(-20, 20);
                yield return new Punkt(x, y, z);
            }
        }

        public static IEnumerable<Punkt> Punktow3DZPrzerwaniemGenerowania(this int licznik)
        {
            var wylosowana = new Random();
            for (var i = 0; i< licznik; ++i)
            {
                var z = wylosowana.Next(-20, 20);
                if (z < 0)
                    yield break;
                var y = wylosowana.Next(-20, 20);
                var x = wylosowana.Next(-20, 20);
                yield return new Punkt(x, y, z);
            }
        }

        public static IEnumerable<int> MySelect(this IEnumerable<int> licznik, Expression<Func<int, int>> lambda)
        {
            var decompiled = lambda.Compile();
            return licznik.Select(decompiled);
        }

        public static IEnumerable<int> MyWhere(this IEnumerable<int> licznik, Expression<Func<int, bool>> lambda)
        {
            var decompiled = lambda.Compile();
            return licznik.Where(decompiled);
        }

        public static IEnumerable<int> GenerujPodczasWczytywania()
        {
            while (true)
            {
                if (!int.TryParse(Console.ReadLine(), out int a))
                {
                    yield break;
                }
                else yield return a;
            }
        }

        public static Punkt Punkt3DZSumyNWspolrzednych(this int licznik)
        {
            var kolekcja = licznik.Punkty3D();
            var x = kolekcja.Sum(x => x.X);
            var y = kolekcja.Sum(y => y.Y);
            var z = kolekcja.Sum(z => z.Z);
            return new Punkt(x, y, z);
        }
    }
}

// main

/*
 1.C#: Napisz funkcję generującą leniwą kolekcję losowych punktów w przestrzeni trójwymiarowej.
       Funkcja powinna być napisana w taki sposób, aby możliwe było następujące wywołanie:

        var kolekcja = 100.LosowychPunktow2D()

gdzie liczba określa ilość punktów koniecznych do wygenerowania
 * */

namespace Test
{
    class Program
    {

        public static void Main()
        {
            // Leniwe generowanie (yield)
            
            // 1)
            var kolekcja = 20.LosowychPunktow2D();
            foreach(var i in kolekcja)
            {
                Console.WriteLine($"x = {i.X} y = {i.Y} z = {i.Z}");
            }

            Console.WriteLine("xxx");
            
            // 2)
            var kolekcja3d = 30.Punktow3DZPrzerwaniemGenerowania().ToList();
            foreach (var i in kolekcja3d)
                Console.WriteLine(i);
            Console.WriteLine(kolekcja3d.Count);

            // 3)
            var punkt = 20.Punkt3DZSumyNWspolrzednych();
            Console.WriteLine(punkt);

            // 4)
            var c = Enumerable.Range(0, 10).Select(n => n * n); // generacja przedziału liczb z przekształceniem

            // 5)
            var a = KolFunctions.GenerujPodczasWczytywania().MySelect(x => x * 2);

            foreach (var item in a)
                Console.WriteLine("Przekształcona liczba: " + item.ToString());
        }
    }
}
