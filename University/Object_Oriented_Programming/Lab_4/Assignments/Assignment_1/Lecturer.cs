using System;

namespace Assignment_1{
    public class Lecturer : Person{
        public string AcademicTitle { get; set; }
        public string Position { get; set; }
        public Lecturer(string firstName, string lastName, DateTime dateOfBirth, string academicTitle, string position)
            : base(firstName, lastName, dateOfBirth){
            
            AcademicTitle = academicTitle;
            Position = position;
        }

        public override string ToString(){
            string lecturer = $"{base.ToString()}, AcademicTitle: {AcademicTitle}, Position: {Position}";
            return lecturer;
        }
    }
}