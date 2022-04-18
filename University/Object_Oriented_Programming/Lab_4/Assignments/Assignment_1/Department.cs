using System;
using System.Collections.Generic;

namespace Assignment_1{
    public class Department{
        public string Name;
        public Person Dean { get; set; }
        public IList<OrganizationUnit> OrganizationUnits { get; set; }
        public IList<Subject> Subjects { get; set; }
        public IList<Student> Students { get; set; }
        public Department(string name, Person dean, IList<Subject> subjects, IList<Student> students, IList<OrganizationUnit> organizationUnits){
            Name = name;
            Dean = dean;
            Subjects = new List<Subject>(subjects);
            Students = new List<Student>(students);
            OrganizationUnits = new List<OrganizationUnit>(organizationUnits);
        }

        public override string ToString(){
            string stringBuilder = $"DepartmentName: {Name}, ";
            List<OrganizationUnit>.Enumerator enumeratorOrganizationUnit = (OrganizationUnits as List<OrganizationUnit>).GetEnumerator();
            foreach(var i in OrganizationUnits){
                enumeratorOrganizationUnit.MoveNext();
                stringBuilder += $"\nOrganizationUnit: {OrganizationUnits.IndexOf(enumeratorOrganizationUnit.Current)+1}\n\n\t\t {i.ToString()}";
            }
            stringBuilder += $"\nSubjects: ";

            foreach(var i in Subjects)
                stringBuilder += $"\n{i}";
            stringBuilder += $"\n\nStudents: ";

            foreach(var i in Students)
                stringBuilder += $"\n{i}";
            return stringBuilder;
        }
    }
}