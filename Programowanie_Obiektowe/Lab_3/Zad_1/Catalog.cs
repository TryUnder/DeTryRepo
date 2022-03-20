using System;
using System.Collections.Generic;
namespace Zad_1{
    public class Catalog{
	public IList<Item> Items { get; set; }
	public string ThematicDepartment { get; set; }
	
	public Catalog(IList<Item> items){
	    Items = new List<Item>(items);
	}
    }
}
