using System.Text;
using System.Collections.Generic;

namespace Assignment_2{
    public class OrganizationUnit{
        public string Name { get; set; }
        public string Address { get; set; }
        public IList<Lecturer> Lecturers { get; set; }
        public OrganizationUnit(string name, string address, IList<Lecturer> lecturers){
            Name = name;
            Address = address;
            Lecturers = new List<Lecturer>(lecturers);
        }
        public override string ToString(){
            string stringBuilder = $"Name: {Name}, Address: {Address}";
            List<Lecturer>.Enumerator em = (Lecturers as List<Lecturer>).GetEnumerator();
            foreach(var i in Lecturers){
                em.MoveNext();
                stringBuilder += $"\nLecturer {Lecturers.IndexOf(em.Current)+1}: {em.Current}";
            }
            stringBuilder += "\n";
            return stringBuilder;
        }
    }
}