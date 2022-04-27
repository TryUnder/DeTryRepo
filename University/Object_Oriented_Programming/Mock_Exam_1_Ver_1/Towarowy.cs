using System;

namespace Mock_Exam_1_Ver_1{
    public class Towarowy : Wagonik{
        public string Ladunek { get; set; }
        public Towarowy()
            :base(){
            Ladunek = "brak";
        }

        public Towarowy(float masa, string nazwa, string ladunek)
            :base(masa, nazwa){
            Ladunek = ladunek;        
        }

        public override string Typ(){
            return this.GetType().Name;
        }

        public override void WypiszInfo(){
            base.WypiszInfo();
            Console.WriteLine($"Ładunek: {Ladunek}");        
        }

        public override string ToString(){
            this.WypiszInfo();
            return null;
        }
    }
}