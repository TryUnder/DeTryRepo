using System;

namespace Mock_Exam_1_Ver_3{
    public class Chemia : Towar{
        public bool Niebezpieczny { get; set; }
        public int? Rok_Termin { get; set; }

        public Chemia(string nazwa, float masa, int rok_termin, bool niebezpieczny)
            : base(nazwa, masa){
            Rok_Termin = rok_termin;
            Niebezpieczny = niebezpieczny;
        }

        public override void Wypisz(){
            base.Wypisz();
            Console.WriteLine($"Czy Niebezpieczny?: {Niebezpieczny}");
        }

        public override string ToString(){
            this.Wypisz();
            return null;
        }

        public override bool Przeterminowany(){
            return Rok_Termin < 2020 ? true : false;
        }
    }
}