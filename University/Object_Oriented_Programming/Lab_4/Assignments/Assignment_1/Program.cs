using System;
namespace Assignment_1{
    public class Program{
        public static void Main(){
            Console.WriteLine("************************************************************************");
            Student student1 = new Student("Jan","Kowalski", new DateTime(1995, 1, 1), "Informatyka", 1);
            Student student2 = new Student("Piotr","Nowak", new DateTime(1990, 1, 1), "Matematyka", 3, 2);
            Person student3 = new Student("Adam", "Bednarski", new DateTime(1993, 1, 1), "Informatyka", 1, 2);
            Console.WriteLine(student1);
            Console.WriteLine(student2);
            Console.WriteLine(student3);

            Console.WriteLine("************************************************************************");
            Subject subject1 = new Subject("Programowanie obiektowe", "Informatyka", 4, 30);
            Subject subject2 = new Subject("Bazy danych", "Informatyka", 4, 30);
            Subject subject3 = new Subject("Algebra", "Matematyka", 1, 15);
            Subject subject4 = new Subject("Analiza", "Matematyka", 1, 30);
            Console.WriteLine(subject1);
            Console.WriteLine(subject2);
            Console.WriteLine(subject3);
            Console.WriteLine(subject4);

            Console.WriteLine("************************************************************************");
        }
    }
}