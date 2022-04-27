using System;

namespace Mock_Exam_1_Ver_1{
    public abstract class Wagonik : IInfo{
        public float Masa { get; set; }
        public string Nazwa { get; set; }

        public Wagonik(){
            Masa = 0;
            Nazwa = "Brak";
        }

        public Wagonik(float masa, string nazwa){
            Masa = masa;
            Nazwa = nazwa;
        }

        public virtual string Typ(){
            return this.GetType().Name;
        }

        public virtual void WypiszInfo(){
            Console.WriteLine($"Nazwa: {Nazwa}, Masa: {Masa}");
        }

        public override string ToString()
        {
            this.WypiszInfo();
            return null;
        }
    }
}