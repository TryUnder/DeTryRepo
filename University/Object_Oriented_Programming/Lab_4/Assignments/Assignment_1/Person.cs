using System;
namespace Assignment_1{
    public abstract class Person{
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public DateTime DateOfBirth { get; set; }

        public Person(string firstName, string lastName, DateTime dateOfBirth){
            FirstName = firstName;
            LastName = lastName;
            DateOfBirth = dateOfBirth;
        }

        public override string ToString()
        {
            string person = $"FirstName: {FirstName} LastName: {LastName}, DateOfBirth: {DateOfBirth}";
            return person;
        }
    }
}