using System;
namespace Zad_2{
    public class Person{
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public Person(){
            FirstName = "unknown";
            LastName = "unknown";
        }
        public Person(string firstName, string lastName){
            FirstName = firstName;
            LastName = lastName;
        }

        public override string ToString(){
            return $"{FirstName} {LastName}";
        }

        public void Details(){
            this.ToString();
        }
    }
}