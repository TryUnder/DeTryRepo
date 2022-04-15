using System;
using System.Linq;
using System.Collections.Generic;
namespace Zad_2{
    public class Program{
		public static void Main(){
        	Item item1 = new Journal(1, "JAISCR", "Springer", new DateTime(2000, 1, 1), 1);            
        	Author author = new Author("Robert", "Cook", "Polish");                    
	    	Item item2 = new Book(2, "Agile C#", "Springer", new DateTime(2015, 1, 1), 500, new List<Author>() {author});
	    
			var jorunalBarCode = ((Journal)item1).GenerateBarCode();
			var bookBarCode = ((Book)item2).GenerateBarCode();
			Console.WriteLine($"{item1} \r\n Barcode {jorunalBarCode}\n");
			Console.WriteLine($"{item2} \r\n Barcode {bookBarCode}\n");

			IList<Item> items = new List<Item>();
			items.Add(item1);
			items.Add(item2);
			Catalog catalog = new Catalog("IT C# development", items);
			catalog.AddItem(new Journal(3,"Neurocomputing", "IEEE", new DateTime(2020, 1, 1), 1));
			Console.WriteLine(catalog);
			catalog.ShowAllItems();

			Console.WriteLine("++++++++++++++++++++++++++++++++++++++++++\n");
			string searchedValue = "Agile C#";
			Item foundedItemById = catalog.FindItem(item => item.Id == 1);
			Item foundedItemByTitle = catalog.FindItem(item => item.Title == searchedValue);
			Item foundedItemByDateRange = catalog.FindItem(item => item.DateOfIssue >= new DateTime(2014, 12, 31) &&
															   item.DateOfIssue <= new DateTime(2015, 12, 31));
			Console.WriteLine(foundedItemById);
			Console.WriteLine(foundedItemByTitle);
			Console.WriteLine(foundedItemByDateRange);
			Console.WriteLine("++++++++++++++++++++++++++++++++++++++++++\n");
			Item foundedItemByIdOld = catalog.FindItemBy(1);
			Item foundedItemByTitleOld = catalog.FindItemBy(searchedValue);
			System.Console.WriteLine(foundedItemByIdOld);
			System.Console.WriteLine(foundedItemByTitleOld);
			Console.WriteLine("++++++++++++++++++++++++++++++++++++++++++\n");
			Person librarian = new Librarian("John", "Kowalsky", DateTime.Now.Date, 2000);
			Library library = new Library("Czestochowa, Armii Krajowej 36", new List<Librarian>(), new List<Catalog>());
			library.AddLibrarian((Librarian)librarian);
			library.ShowAllLibrarians();

			Catalog catalog2 = new Catalog("Novels", new List<Item>());
			library.AddCatalog(catalog2);
			library.AddCatalog(catalog);
			
			Item newItem = new Book(4, "Song of Ice and Fire", "Publisher", new DateTime(2011, 1, 1), 800, new List<Author>(){ author });
			library.AddItem(newItem, "Novels");
		}
    }
}
