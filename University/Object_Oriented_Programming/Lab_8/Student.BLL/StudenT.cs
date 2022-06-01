using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Student.BLL
{
    public class StudenT
    {
        public string Firstname { get; set; }
        public string Surname { get; set; }
        public string Faculty { get; set; }
        public int Id { get; set; }

        public StudenT(string firstName="brak", string surname="brak", string faculty="brak", int id = 0)
        {
            Firstname = firstName;
            Surname = surname;
            Faculty = faculty;
            Id = id;
        }
    }
}
