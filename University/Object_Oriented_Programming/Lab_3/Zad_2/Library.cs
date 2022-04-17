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
            foreach(var i in Librarians){
                Console.WriteLine(i);
            }
        }

        public void AddCatalog(Catalog catalog){
            Catalogs.Add(catalog);
        }

        public void AddItem(Item item, string thematicDepartment){
            for(int i=0; i<Catalogs.Count; ++i){
                if(Catalogs[i].ThematicDepartment == thematicDepartment){
                    Catalogs[i].AddItem(item);
                }
            }
        }

        public void ShowAllItems(){
            for(int i=0; i<Catalogs.Count; ++i){
                Catalogs[i].ShowAllItems();
            }
        }

        public Item FindItemBy(int id){
            for(int i=0; i<Catalogs.Count; ++i){
                var result = Catalogs[i].Items.Where(i => i.Id == id);
            }
            return result;
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