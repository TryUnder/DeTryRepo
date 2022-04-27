using System;

namespace Mock_Exam_1_Ver_2{
    public class Dom : Mieszkalny{
        public float rozmiarDzialki { get; set; }
        public Dom(string adres, bool prad, bool woda, int pokoj, float rozmiardzialki)
            : base(adres, prad, woda, pokoj){
            rozmiarDzialki = rozmiardzialki;
        }

        public override bool Wynajmowalne(){
            return base.Wynajmowalne();
        }

        public override void Wypisz(){
            base.Wypisz();
            Console.WriteLine($"Rozmiar dzialki: {rozmiarDzialki}");
        }

        public override string ToString(){
            this.Wypisz();
            return null;
        }
    }
}