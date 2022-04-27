using System;

namespace Mock_Exam_1_Ver_1{
    public class Osobowy : Wagonik{
        public int Miejsca { get; set; }
        public int Zajete { get; set; }

        public Osobowy()
            : base(){
            Miejsca = 0;
            Zajete = 0;
        }

        public Osobowy(float masa, string nazwa, int miejsca, int zajete)
            : base(masa, nazwa){
            Miejsca = miejsca;
            Zajete = zajete;
        }

        public override string Typ(){
            return this.GetType().Name;
        }

        public override void WypiszInfo(){
            base.WypiszInfo();
            Console.WriteLine($"Miejsce: {Miejsca}, Zajete: {Zajete}");
        }

        public override string ToString(){
            this.WypiszInfo();
            return null;
        }
    }
}