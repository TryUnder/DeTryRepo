using System;
using System.Linq;
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

        public Lokal WyszukajLokalPoAdresie(string adres){
            return Lokale.FirstOrDefault(i => i.Adres == adres);
        }

        public void UsunLokal(Lokal lokal){
            foreach(var i in Lokale){
                if(lokal.Adres == i.Adres){
                    Lokale.Remove(lokal);
                    break;
                }
            }
        }

        public void UsunWszystkieLokale(){
            if(Lokale != null)
                Lokale.Clear();
        }
    }
}