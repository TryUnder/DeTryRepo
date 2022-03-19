using System;
namespace Zad_1{
    public class Journal : Item{
        private int _number;

        public Journal() {}
        public Journal(int id, string title, string publisher, DateTime dateOfIssue, int number)
            : base(id, title, publisher, dateOfIssue) {
        _number = number;
        }
        
        public override string ToString(){
            base.Details();
            return $"Number: {_number}";      
        }
  
        public override string GenerateBarCode(){
            return Guid.NewGuid().ToString();
        }
    }
}
