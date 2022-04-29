using System;

namespace Mock_Exam_1_Ver_3{
    public class Program{
        public static void Main(){
            Towar towar1 = new Napoje("Fanta", 5.00f, 1.5f);
            Console.WriteLine(towar1);
            //Console.WriteLine(towar1.)

            Towar towar2 = new Owoce("Jabłka", 2.50f, 2015, 1.25f);
            Console.WriteLine(towar2);


        }
    }
}