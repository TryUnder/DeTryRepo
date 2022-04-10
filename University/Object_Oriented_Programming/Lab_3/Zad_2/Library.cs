using System;
using System.Collections.Generic;
using System.Text;
namespace Zad_2{
    public class Library{
        public string Address { get; set; }
        public IList<Librarian> Librarians { get; set; }
        public IList<Catalog> Catalogs { get; set; }
        public Library(string address, IList<Librarian> librarians, IList<Catalog> catalogs){
            Address = address;
            Librarians = new List<Librarian>(librarians);
            Catalogs = new List<Catalog>(catalogs);
        }
        public void AddLibrarian(Librarian librarian){
            Librarians.Add(librarian);
        }
        public void ShowAllLibrarians(){
            StringBuilder librarians = new StringBuilder();
            foreach(var i in Librarians){
                librarians.Append(i);
            }
            System.Console.WriteLine(librarians);
        }
        public override string ToString()
        {
            return $"{this}";
        }
    }
}