using System;
using System.Collections.Generic;

namespace Mock_Exam_1_Ver_2{
    public class Zarzad{
        public List<Lokal> Lokale { get; set; }

        public Zarzad(List<Lokal> lokale){
            Lokale = new List<Lokal>(lokale);
        }

        void WypiszWszystkieLokale(){
            foreach(var i in Lokale){
                Console.WriteLine(i);
            }
        }

        public override string ToString(){
            this.WypiszWszystkieLokale();
            return null;
        }
    }
}