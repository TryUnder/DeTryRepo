using System;

namespace Mock_Exam_1_Ver_3{
    public class Owoce : Spozywczy{
        public float Masa { get; set; }

        public Owoce(string nazwa, float? cena, int rok_termin, float masa)
            : base(nazwa, cena, rok_termin){
            Masa = masa;
        }

        public override void Wypisz(){
            base.Wypisz();
            Console.WriteLine($"Masa: {Masa}");
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