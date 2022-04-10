using System;
using System.Text;
using System.Collections.Generic;
namespace Zad_1{
    public class Catalog{
		public IList<Item> Items { get; set; }
		public string ThematicDepartment { get; set; }
	
		public Catalog(IList<Item> items){
	    	Items = new List<Item>(items);
	    	ThematicDepartment = "none";
		}
    
		public Catalog(string thematicDepartment, IList<Item> items){
	    	Items = new List<Item>(items);
	    	ThematicDepartment = thematicDepartment;
		}

		public void AddItem(Item item){
	    	Items.Add(item);
		}

		public override string ToString(){
	    	StringBuilder str_list = new StringBuilder();
	    	foreach(var i in Items){
			str_list.Append(i+"\n");
	    	}
	    	return $"Catalog: {ThematicDepartment} Lista: {str_list}";
		}

		public void ShowAllItems(){
	    	Console.WriteLine(this);
		}
    	}
}
