using System;
namespace Zad_1{
    public class Student : Person{
        private int _year;
        private int _group;
        private int _indexId;
        
        public int Year { get { return _year; } set { _year = value; }}
        public int Group { get { return _group; } set { _group = value; }}
        public int IndexId { get { return _indexId; } set { _indexId = value; }}

        public Student()
            : base(){
            _year = 0;
            _group = 0;
            _indexId = 0;
        }

        public Student(string firstName, string lastName, DateTime dateOfBirth, int year, int groupp, int indexId)
            : base(firstName, lastName, dateOfBirth){
            _year = year;
            _group = groupp;
            _indexId = indexId;
        }

        public override string ToString(){
            Console.Write(base.ToString());
            return $" Year: {_year} Group: {_group}, IndexId: {_indexId}";
        }
    }
}
