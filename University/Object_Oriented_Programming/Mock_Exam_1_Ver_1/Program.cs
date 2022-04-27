using System;
using System.Collections.Generic;

namespace Mock_Exam_1_Ver_1{
    public class Program{
        public static void Main(){
            Wagonik wagonik = new Osobowy(20, "osobowy", 5, 4);
            Wagonik wagonik2 = new Towarowy();
            Wagonik wagonik3 = new Towarowy(2000, "Towarowy", "Jakis Ladunek");
            Wagonik wagonik4 = new Lokomotywa(3000, "Nazywam sie lokomotywa", 30);
            Wagonik wagonik5 = new Lokomotywa(4000, "Nazywam sie inna lokomotywa", 40);

            Console.WriteLine(wagonik);
            Console.WriteLine(wagonik2);
            Console.WriteLine(wagonik3);
            Console.WriteLine(wagonik4);
            Console.WriteLine(wagonik5);

            List<Wagonik> lista_wagonikow = new List<Wagonik>();
            lista_wagonikow.Add(wagonik3);
            lista_wagonikow.Add(wagonik4);
            lista_wagonikow.Add(wagonik5);

            // List<Wagonik> lista_lokomotyw = new List<Lokomotywa>();
            // lista_lokomotyw.Add(wagonik4);
            // lista_lokomotyw.Add(wagonik5);

            Sklad sklad = new Sklad(lista_wagonikow, new List<Lokomotywa>());
        }
    }
}