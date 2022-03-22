using System;
using System.Collections.Generic;
namespace Zad_1{
    public class Program{
        public static void Main(){
            Item item1 = new Journal(1, "JAISCR", "Springer", new DateTime(2000, 1, 1), 1);            
            Author author = new Author("Robert", "Cook", "Polish");                    
	    Item item2 = new Book(2, "Agile C#", "Springer", new DateTime(2015, 1, 1), 500, new List<Author>() {author});
	    
	    ((Book)item2).AddAuthor(author);
	    var bookBarCode = ((Book)item2).GenerateBarCode();
	    var journalBarCode = ((Journal)item1).GenerateBarCode();
	    Console.WriteLine($"{item1} \r\n Barcode {journalBarCode}");
	    Console.WriteLine($"{item2} \r\n Barcode {bookBarCode}");
	    IList<Item> items = new List<Item>();
	    items.Add(item1);
	    items.Add(item2);
	    Catalog catalog = new Catalog("IT C# development", items);
	    Console.WriteLine(catalog);
	    string searchedValue = "Agile C#";
	    Item foundedItemById = catalog.FindItem(item => item.Id == 1);
	    Item foundedItemByTitle = catalog.FindItem(item => item.Title == searchedValue);
	    Item foundedItemByDateRange = catalog.FindItem(item => item.DateOfIssue >= new DateTime(2014, 12, 31)
								&& item.DateOfIssue <= new DateTime(2015, 12, 31));
	    Console.WriteLine("++++++++++++++++++++++++++++++++++");
	    Console.WriteLine(foundedItemById);
	    Console.WriteLine(foundedItemByTitle);
	    Console.WriteLine(foundedItemByDateRange);
	}
    }
}
