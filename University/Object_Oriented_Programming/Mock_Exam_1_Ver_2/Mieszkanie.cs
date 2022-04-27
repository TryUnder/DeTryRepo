using System;

namespace Mock_Exam_1_Ver_2{
    public class Mieszkanie : Mieszkalny{
        public int Pietro { get; set; }
        
        public Mieszkanie(string adres, bool prad, bool woda, int pokoj, int pietro)
            : base(adres, prad, woda, pokoj){
            Pietro = pietro;
        }

        public override void Wypisz(){
            base.Wypisz();
            Console.WriteLine($"Liczba pieter: {Pietro}");
        }
    }
}