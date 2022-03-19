using System;
namespace Zad_2{
    public class Grade{
        private string _subjectName;
        private DateTime _date;
        private double _value;

        public string SubjectName { get { return _subjectName; } set { _subjectName = value; }}
        public DateTime Date { get { return _date; } set { _date = value; }}
        public double Value { get { return _value; } set { _value = value; }}

        public Grade(){
            _subjectName = "none";
            _date = new DateTime(2022,18,3);
            _value = 0;
        }

        public Grade(string subjectName, double vvalue, DateTime date){
            _subjectName = subjectName;
            _date = date;
            _value = vvalue;
        }

        public override string ToString(){
            return $"Subject: {_subjectName} Date: {_date} Value: {_value}";
        }

        public virtual void Details(){
            Console.WriteLine(this);
        }
    }
}
