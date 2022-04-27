using System;

namespace Mock_Exam_1_Ver_2{
    public class Program{
        public static void Main(){
            Lokal lokal = new Komercyjny("Nadrzeczna 57, Częstochowa", true, true);
            Console.WriteLine(lokal);
            Console.WriteLine($"Czy lokal jest wynajmowalny?: {lokal.Wynajmowalne()}");
            
        }
    }
}