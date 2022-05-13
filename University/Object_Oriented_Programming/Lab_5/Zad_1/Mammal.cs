using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.BLL
{
    public class Mammal : Animal
    {
        string NaturalHabitat { get; set; }
        public Mammal(string food, int legscount, string origin,
                      string species, string naturalhabitat)
            : base(food, legscount, origin, species)
        {
            NaturalHabitat = naturalhabitat;
        }

        public override string ToString()
        {
            base.ToString();
            Console.WriteLine($"Natural Habitat:{NaturalHabitat}");
            return null;
        }
    }
}
