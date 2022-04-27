using System;

namespace Mock_Exam_1_Ver_3{
    public abstract class Towar : IInfo, IInfoTowar{
        public float? Cena { get; set; }
        public string Nazwa { get; set; }
        public float? Sprzedanych { get; set; }

        public Towar(string nazwa, float? cena){
            Cena = cena;
            Nazwa = nazwa;
        }

        public virtual void Wypisz(){
            Console.WriteLine($"Nazwa: {Nazwa} Cena: {Cena} Sprzedanych: {Sprzedanych}");
        }

        public abstract bool Przeterminowany();
        public virtual float? Sprzedano(){
            return Sprzedanych;
        }

        public virtual float? Zysk(){
            return Sprzedanych * Cena; //a koszty gamoniu?
        }
    }
}