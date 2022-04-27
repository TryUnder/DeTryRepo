using System;
using System.Collections.Generic;

namespace Mock_Exam_1_Ver_1{
    public class Sklad : IInfo{
        public List<Wagonik> lokomotywy { get; set; }
        public List<Wagonik> wagoniki { get; set; }

        public Sklad(){
            wagoniki = new List<Wagonik>();
            lokomotywy = new List<Lokomotywa>();
        }

        public Sklad(List<Wagonik> lista_wagonikow, List<Wagonik> lista_lokomotyw){
            wagoniki = new List<Wagonik>(lista_wagonikow);
            lokomotywy = new List<Lokomotywa>(lista_lokomotyw);
        }

        public void WypiszInfo(){
            foreach(var i in wagoniki){
                Console.WriteLine($"Wagonik: {i}");
            }
            foreach(var i in lokomotywy){
                Console.WriteLine($"Lokomotywa: {i}");
            }
        }

        public override string ToString(){
            this.WypiszInfo();
            return null;
        }

        public bool MozeJechac(){
            var sumaMasWagonikow = 0.0;
            var sumaMasCiagow = 0.0;
            foreach(var i in lokomotywy){
                sumaMasCiagow += i.Ciag;
            }
            foreach(var i in wagoniki){
                sumaMasWagonikow += i.Masa;
            }

            return sumaMasWagonikow < sumaMasCiagow ? true : false;
            //return lokomotywy.Sum(l => l.Ciag) > wagoniki.Sum(i=>i.Masa); lub to z System.Linq
        }
    }
}