using System;
using System.Collections.Generic;

namespace Mock_Exam_1_Ver_2{
    public class Program{
        public static void Main(){
            Lokal lokal = new Komercyjny("Nadrzeczna 57, Częstochowa", true, false);
            Console.WriteLine($"{lokal}Czy lokal jest wynajmowalny?: {lokal.Wynajmowalne()}\n");

            Lokal dom = new Dom("Warszawska 43/25 11-200 Częstochowa", true, true, 5, 200);
            Console.WriteLine($"{dom}Czy dom jest wynajmowalny?: {dom.Wynajmowalne()}\n");

            Lokal mieszkanie = new Mieszkanie("Tomaszowa 11 07-227 Łódź", true, true, 5, 2);
            Console.WriteLine($"{mieszkanie}Czy mieszkanie jest wynajmowalne?: {mieszkanie.Wynajmowalne()}\n");

            Lokal[] arr = new Lokal[]{lokal,dom,mieszkanie};
            Console.WriteLine("--------------------------------------------------------------");

            List<Lokal> lokale = new List<Lokal>();
            lokale.AddRange(arr);

            Zarzad zarzad = new Zarzad(lokale);

            Console.WriteLine(zarzad);
            Console.WriteLine("--------------------------------------------------------------");
            //Lokal dom = new Dom("Szara 10/15 47-005 Gniezno", true, true, 7, 320);
            zarzad.DodajNowyLokal(new Dom("Szara 10/15 47-005 Gniezno", true, true, 7, 320));
            Console.WriteLine(zarzad);
            Console.WriteLine("--------------------------------------------------------------");

            Console.WriteLine($"Szukam lokalu po adresie: Tomaszowa 11:");
            Console.WriteLine(zarzad.WyszukajLokalPoAdresie(mieszkanie.Adres));
            Console.WriteLine("Lokal znaleziony. Usuwam");
            zarzad.UsunLokal(zarzad.WyszukajLokalPoAdresie(mieszkanie.Adres));
            Console.WriteLine("--------------------------------------------------------------");
            Console.WriteLine(zarzad);
            Console.WriteLine("--------------------------------------------------------------");
            Console.WriteLine("Usuwam wszystkie lokale");
            zarzad.UsunWszystkieLokale();
            zarzad.WypiszWszystkieLokale();
            Console.WriteLine("--------------------------------------------------------------");
        }
    }
}