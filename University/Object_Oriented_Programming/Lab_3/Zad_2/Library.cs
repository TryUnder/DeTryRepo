using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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

        public void AddCatalog(Catalog catalog){
            Catalogs.Add(catalog);
        }

        public void AddItem(Item item, string thematicDepartment){
            Catalog cat = new Catalog(thematicDepartment, new List<Item>(){ item }); // czy to tak?
        }

        public void ShowAllItems(){
            StringBuilder library = new StringBuilder();
            foreach(var i in Catalogs){
                library.Append(i);
            }
            Console.WriteLine(library);
        }

        public override string ToString()
        {
            if(this.GetType() == typeof(Library)){
                this.ShowAllItems();
                this.ShowAllLibrarians();
                return null;
            }
            else {
                return $"{this}";
            }
        }
    }
}