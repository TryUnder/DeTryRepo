using System;
using System.Linq;
using System.Collections.Generic;
namespace Zad_1{
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
		catalog.AddItem(new Journal(1,"Neurocomputing", "IEEE", new DateTime(2020, 1, 1), 1));
		Console.WriteLine(catalog);
		catalog.ShowAllItems();

		Console.WriteLine("++++++++++++++++++++++++++++++++++++++++++\n");
	}
    }
}
