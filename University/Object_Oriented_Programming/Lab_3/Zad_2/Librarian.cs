using System;
namespace Zad_2{
    public class Librarian : Person{
        public DateTime HireDate { get; set; }
        public decimal Salary { get; set; }
        public Librarian(){
            HireDate = new DateTime(2000,1,1);
            Salary = 0;
        }
        public Librarian(string firstName, string lastName, DateTime hireDate, decimal salary):
            base(firstName,lastName){
            HireDate = hireDate;
            Salary = salary;
        }
        public override string ToString()
        {
            return $"{base.ToString()} Hire date: {HireDate} Salary: {Salary}";
        }
    }
}