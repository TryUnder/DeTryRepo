namespace Mock_Exam_1_Ver_2{
    public class Komercyjny : Lokal{
        public Komercyjny(string adres, bool prad, bool woda)
            :base(adres,prad,woda){}

        public override void Wypisz(){
            base.Wypisz();
        }

        public override bool Wynajmowalne(){
            return base.Wynajmowalne();
        }
    }
}