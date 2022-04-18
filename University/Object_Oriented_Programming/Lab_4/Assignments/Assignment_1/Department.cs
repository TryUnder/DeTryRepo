using System;
using System.Collections.Generic;

namespace Assignment_1{
    public class Department{
        public string Name;
        public Person Dean { get; set; }
        public IList<OrganizationUnit> OrganizationUnits { get; set; }
        public IList<Subject> Subjects { get; set; }
        public IList<Student> Students { get; set; }
        public Department(string name, Person dean, IList<Subject> subjects, IList<Student> students){
            Name = name;
            Dean = dean;
            Subjects = new List<Subject>(subjects);
            Students = new List<Student>(students);
        }

        public override string ToString(){
            string department = $"DepartmentName: {Name}";
            return department;
        }
    }
}