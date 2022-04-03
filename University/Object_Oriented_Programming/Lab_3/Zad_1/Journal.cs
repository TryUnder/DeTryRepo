using System;
namespace Zad_1{
    public class Journal : Item{
	
	public int Number { get; set; }
        public Journal() {}
        public Journal(int id, string title, string publisher, DateTime dateOfIssue, int number)
            : base(id, title, publisher, dateOfIssue) {
        Number = number;
        }
        
        public override string ToString(){
            Console.Write(base.ToString());
            return $" Number: {Number}";      
        }
  
        public override string GenerateBarCode(){
            return Guid.NewGuid().ToString();
        }
    }
}
