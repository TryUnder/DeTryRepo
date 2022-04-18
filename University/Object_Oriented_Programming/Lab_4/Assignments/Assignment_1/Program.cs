using System;
namespace Assignment_1{
    public class Program{
        public static void Main(){
            Student student1 = new Student("Jan","Kowalski", new DateTime(1995, 1, 1), "Informatyka", 1);
            Console.WriteLine(student1);
            Student student2 = new Student("Piotr","Nowak", new DateTime(1990, 1, 1), "Matematyka", 3, 2);
            Console.WriteLine(student2);
            Person student3 = new Student("Adam", "Bednarski", new DateTime(1993, 1, 1), "Informatyka", 1, 2);
            Console.WriteLine(student3);
        }
    }
}