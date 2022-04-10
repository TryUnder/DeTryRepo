using System;
using System.Text;
using System.Linq;
using System.Collections.Generic;
using System.Linq.Expressions;
namespace Zad_2{
    public class Catalog : IItemManagement{
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

		public Item FindItem(Expression<Func<Item,bool>> lambd){
			var a = lambd.Compile();
			var Result = this.FirstOrDefault(a);
			return Result;
		}

		//public Item FindItemBy(int id){
			
		//}
    }
}
