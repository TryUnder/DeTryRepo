using System;

namespace Mock_Exam_1_Ver_3{
    public class Napoje : Spozywczy, IInfo, IInfoTowar{
        public float Pojemnosc { get; set; }

        public Napoje(string nazwa, float cena, float pojemnosc)
            : base(nazwa, cena, null){
            Pojemnosc = pojemnosc;
        }

        public override void Wypisz(){
            base.Wypisz();
            Console.WriteLine($"Pojemnosc: {Pojemnosc}");
        }

        public override string ToString(){
            this.Wypisz();
            return null;
        }

        public override bool Przeterminowany()
        {
            return base.Przeterminowany();
        }

        public override float? Sprzedano()
        {
            return base.Sprzedano();
        }

        public override float? Zysk()
        {
            return base.Zysk();
        }

    }
}