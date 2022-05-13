using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5.BLL
{
    public class Cage
    {
        public double Size { get; set; }
        public bool CleaningNeeded { get; set; }
        public List<Animal> Animals { get; set; }
        public Cage(double size, bool cleaningNeeded, List<Animal> animals)
        {
            Size = size;
            CleaningNeeded = cleaningNeeded;
            Animals = new List<Animal>(animals);
        }

        public override String ToString()
        {
            Console.WriteLine($"Size:{Size}, CleaningNeeded:{CleaningNeeded}");
            foreach (var i in Animals)
            {
                Console.WriteLine(i);
            }
            return null;
        }

    }
}
