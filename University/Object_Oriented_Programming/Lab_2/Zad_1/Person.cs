using System;
namespace Zad_1{
    public class Person{
        
        protected string _firstName;
        protected string _lastName;
        protected DateTime _dateOfBirth;
        
        public string FirstName { get { return _firstName; } set { _firstName = value; }}
        public string LastName { get { return _lastName; } set { _lastName = value; }}
        public DateTime DateOfBirth { get { return _dateOfBirth; } set { _dateOfBirth = value; }}
        
        public Person(){
            _firstName = "none";
            _lastName = "none";
            _dateOfBirth = new DateTime(2022,03,18);
        }
        public Person(string firstName, string lastName, DateTime dateOfBirth){
            _firstName = firstName;
            _lastName = lastName;
            _dateOfBirth = new DateTime();
            _dateOfBirth = dateOfBirth;
        }

        public override string ToString(){
            return $"Name: {_firstName} LastName: {_lastName} Birth: {_dateOfBirth}";
        }

        public virtual void Details(){
            Console.WriteLine(this);
        }
    }
}

