using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.BLL
{
    public class Zoo
    {
        public string Name { get; set; }   
        public List<Employee> Employees { get; set; }
        public List<Cage> Cages { get; set; }
        public List<Animal> Animals { get; set; }

        public Zoo(string name, List<Employee> employees, List<Cage> cages, List<Animal> animals)
        {
            Name = name;
            Employees = new List<Employee>(employees);
            Cages = new List<Cage>(cages);
            Animals = new List<Animal>(animals);
        }

        public override string ToString()
        {
            foreach (var i in Employees)
            {
                Console.WriteLine(i);
            }

            foreach (var i in Cages)
            {
                Console.WriteLine(i);
            }

            foreach(var i in Animals)
            {
                Console.WriteLine(i);
            }

            return null;
        }

        public Cage BuildCage(double size, bool cleaningNeeded)
        {
            return new Cage(size, cleaningNeeded, Animals);
        }

        public void ExpandCage(Cage cage)
        {
            Cages.Add(cage);
        }

    }
}
