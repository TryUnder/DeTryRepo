using System;

namespace Assignment_1{
    public class Student : Person{
        private static int id = 0;
        //final grade to update
        public int Semester { get; set; }
        public int Group { get; set; }
        public int IndexId { get; set; }
        public string Specialization { get; set; }
        public double AverageGrades { get; set; }
        public Student(string firstName, string lastName, DateTime dateOfBirth, string specialization, int group, int semester = 1)
            : base(firstName, lastName, dateOfBirth){

            Specialization = specialization;
            Group = group;
            Semester = semester;
            ++id;
            IndexId = id;
        }

        public override string ToString()
        {
            string student = $"{base.ToString()} Id: {IndexId}, Specialization: {Specialization}, Group: {Group}, Semester: {Semester}";
            return student;
        }
    }
}