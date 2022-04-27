namespace Mock_Exam_1_Ver_2{
    public abstract class Mieszkalny : Lokal{
        public int Pokoj { get; set; }
        
        public Mieszkalny(string adres, bool prad, bool woda, int pokoj)
            : base(adres, prad, woda){
            Pokoj = pokoj;
        }

        public override bool Wynajmowalne()
        {
            return base.Wynajmowalne();
        }

        public override void Wypisz()
        {
            base.Wypisz();
        }

        public override string ToString()
        {
            this.Wypisz();
            return null;
        }
    }
}