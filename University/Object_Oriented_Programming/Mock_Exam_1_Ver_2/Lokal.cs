using System;

namespace Mock_Exam_1_Ver_2{
    public abstract class Lokal : IInfo, ILokal{
        public string Adres { get; set; }
        public bool Prad { get; set; }
        public bool Woda { get; set; }
        public bool Wynajety { get; set; }

        public Lokal(string adres, bool prad, bool woda){
            Adres = adres;
            Prad = prad;
            Woda = woda;
        }

        public virtual void Wypisz(){
            Console.WriteLine($"Adres: {Adres}, Prad: {Prad}, Woda: {Woda}, Wynajety: {Wynajety}");
        }

        public virtual bool Wynajmowalne(){
            if(Wynajety==false)
                return true;
            return false;
        }

        public override string ToString(){
            this.Wypisz();
            return null;
        }
    }
}