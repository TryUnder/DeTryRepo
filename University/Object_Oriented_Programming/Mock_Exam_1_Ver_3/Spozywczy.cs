namespace Mock_Exam_1_Ver_3{
    public abstract class Spozywczy : Towar, IInfo, IInfoTowar{
        public int? RokTermin { get; set; }
        
        public Spozywczy(string nazwa, float? cena, int? rok_termin)
            : base(nazwa, cena){
            RokTermin = rok_termin;
        }

        public override void Wypisz(){
            base.Wypisz();
        }

        public override string ToString(){
            this.Wypisz();
            return null;
        }

        public override bool Przeterminowany(){
            return RokTermin < 2020 ? true : false;
        }

        public override float? Sprzedano(){
            return base.Sprzedano();
        }

        public override float? Zysk(){
            return base.Zysk();
        }

    }
}