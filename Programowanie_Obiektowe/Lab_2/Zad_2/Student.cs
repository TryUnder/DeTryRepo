using System;
using System.Collections.Generic;
using System.Linq;
namespace Zad_2{
    public class Student : Person{
        private int _year;
        private int _group;
        private int _indexId;
        private List<Grade> _grades;

        public int Year { get { return _year; } set { _year = value; }}
        public int Group { get { return _group; } set { _group = value; }}
        public int IndexId { get { return _indexId; } set { _indexId = value; }}
        public List<Grade> Grades { get { return _grades; } set { _grades = value; }}
        public Student()
            : base(){
            _year = 0;
            _group = 0;
            _indexId = 0;
            _grades = new List<Grade>();
        }

        public Student(string firstName, string lastName, DateTime dateOfBirth, int year, int groupp, int indexId)
            : base(firstName, lastName, dateOfBirth){
            _year = year;
            _group = groupp;
            _indexId = indexId;
            _grades = new List<Grade>();
        }

        public override string ToString(){
            Console.WriteLine(base.ToString());
            this.DisplayGrades();
            return $" Year: {_year} Group: {_group}, IndexId: {_indexId}\n";
        }

        public void AddGrade(string subjectName, double vvalue, DateTime date){
            Grade grade = new Grade(subjectName, vvalue, date);
            _grades.Add(grade);
        }

        public void AddGrade(Grade grade){
            _grades.Add(grade);
        }

        public void DisplayGrades(){
            foreach(var i in _grades){
                Console.WriteLine(i);
            }
        }

        public void DeleteGrade(string subjectName, double vvalue, DateTime date){
            var found = _grades.FirstOrDefault(i => i.SubjectName == subjectName 
                        && i.Value == vvalue && i.Date == date);
                if(_grades.Contains(found))
                    _grades.Remove(found);
        }

        public void DeleteGrades(string subjectName){
            _grades.RemoveAll(i => i.SubjectName.Contains(subjectName));         
        }

    }
}
