using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.BLL
{
    public class Bird : Animal
    {
        public double Strength { get; set; }
        public double WingSpread { get; set; }
        public double MaxFlightLength { get; set; }

        public Bird(string food, int legscount, string origin, 
            string species, double strength, double wingspread)
            : base(food, legscount, origin, species)
        {
            Strength = strength;
            WingSpread = wingspread;
            MaxFlightLength = strength * wingspread;     
        }

        public override String ToString()
        {
            base.ToString();
            Console.WriteLine($"Strength:{Strength}, WingSpread:{WingSpread}, MaxFlightLength{MaxFlightLength}");
            return null;
        }

        public void Fly()
        {

        }
    }
}
