using System;
using System.Collections.Generic;

namespace Mock_Exam_1_Ver_2{
    public class Zarzad{
        public List<Lokal> Lokale { get; set; }

        public Zarzad(List<Lokal> lokale){
            Lokale = new List<Lokal>(lokale);
        }

        public void WypiszWszystkieLokale(){
            List<Lokal>.Enumerator enumeratorLokali = Lokale.GetEnumerator();
            foreach(var i in Lokale){
                enumeratorLokali.MoveNext();
                Console.WriteLine($"Lokal nr: {Lokale.IndexOf(enumeratorLokali.Current)+1}"); 
                Console.WriteLine(i);
            }
        }

        public override string ToString(){
            this.WypiszWszystkieLokale();
            return null;
        }

        public void DodajNowyLokal(Lokal nowyLokal){
            Lokale.Add(nowyLokal);
        }
    }
}