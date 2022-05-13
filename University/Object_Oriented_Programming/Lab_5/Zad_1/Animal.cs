using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.BLL
{
    public class Animal
    {
        public string Species { get; set; }
        public string Food { get; set; }
        public string Origin { get; set; }
        public int LegsCount { get; set; }
        
        public Animal(string food, int legsCount, string origin, string species)
        {
            Food = food;
            LegsCount = legsCount;
            Origin = origin;
            Species = species;
        }

        public override string ToString()
        {
            Console.WriteLine($"Species:{Species}, Food:{Food}, Origin:{Origin}, LegsCount:{LegsCount}");
            return null;
        }
    }
}
