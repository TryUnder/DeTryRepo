using System;

namespace Mock_Exam_1_Ver_2{
    public class Program{
        public static void Main(){
            Lokal lokal = new Komercyjny("Nadrzeczna 57, Częstochowa", true, false);
            Console.WriteLine($"{lokal}Czy lokal jest wynajmowalny?: {lokal.Wynajmowalne()}\n");

            Lokal dom = new Dom("Warszawska 43/25 11-200 Częstochowa", true, true, 5, 200);
            Console.WriteLine($"{dom}Czy dom jest wynajmowalny?: {dom.Wynajmowalne()}\n");

            Lokal mieszkanie = new Mieszkanie("Tomaszowa 11 07-227 Łódź", true, true, 5, 2);
            Console.WriteLine($"{mieszkanie}Czy mieszkanie jest wynajmowalne?: {mieszkanie.Wynajmowalne()}\n");
        }
    }
}