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
            FinalGrade grade1 = new FinalGrade(subject1, 4.5d, DateTime.Now.AddDays(30));
            FinalGrade grade2 = new FinalGrade(subject1, 5d, DateTime.Now.AddDays(10));
            FinalGrade grade3 = new FinalGrade(subject2, 3.5d, DateTime.Now.AddDays(50));
            FinalGrade grade4 = new FinalGrade(subject2, 3.0d, DateTime.Now.AddDays(20));
            FinalGrade grade5 = new FinalGrade(subject3, 5d, DateTime.Now.AddDays(10));
            FinalGrade grade6 = new FinalGrade(subject3, 4.0d, DateTime.Now.AddDays(10));
            FinalGrade grade7 = new FinalGrade(subject4, 4.0d, DateTime.Now.AddDays(30));
            FinalGrade grade8 = new FinalGrade(subject4, 3.5d, DateTime.Now.AddDays(20));
            Console.WriteLine(grade1);
            Console.WriteLine(grade2);
            Console.WriteLine(grade3);
            Console.WriteLine(grade4);
            Console.WriteLine(grade5);
            Console.WriteLine(grade6);
            Console.WriteLine(grade7);
            Console.WriteLine(grade8);

            Console.WriteLine("************************************************************************");
        }
    }
}