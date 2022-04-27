using System;

namespace Mock_Exam_1_Ver_1{
    public class Lokomotywa : Wagonik{
        public float Ciag { get; set; }
        public Lokomotywa()
            :base(){
            Ciag = 0;
        }

        public Lokomotywa(float masa, string nazwa, float ciag)
            :base(masa, nazwa){
            Ciag = ciag;
        }

        public override string Typ(){
            return this.GetType().Name;
        }

        public override string ToString(){
            this.WypiszInfo();
            return null;
        }
    }
}