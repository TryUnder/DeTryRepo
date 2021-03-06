using System;
namespace Zad_1{
    public class Author{
	public string FirstName { get; set; }
	public string LastName { get; set; }
	public string Nationality { get; set; }

	public Author() {
	    FirstName = "None";
	    LastName = "None";
	    Nationality = "None";
	}

	public Author(string firstName, string lastName, string nationality){
	    FirstName = firstName;
	    LastName = lastName;
	    Nationality = nationality;
	}

	public override string ToString(){
	    return $"First Name: {FirstName} | Last Name: {LastName} Nationality: {Nationality}";
	}
    }
}
