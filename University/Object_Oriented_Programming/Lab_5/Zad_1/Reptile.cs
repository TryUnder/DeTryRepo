using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.BLL
{
    public class Reptile : Animal
    {
        public bool Venomous { get; set; }
        public Reptile(string food, int legscount, string origin, string species
            ,bool venomous) 
            : base(food, legscount, origin, species)
        {
            Venomous = venomous;
        }

        public override string ToString()
        {
            base.ToString();
            Console.WriteLine($"Venomous:{Venomous}");
            return null;
        }
    }
}
