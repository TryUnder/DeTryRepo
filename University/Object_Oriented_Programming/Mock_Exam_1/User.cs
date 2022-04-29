using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kolokwium_1
{
    public class User : IPrint
    {
        public string ID { get; set; }
        public string Name { get; set; }

        public User(string id, string name)
        {
            ID = id;
            Name = name;
        }

        public virtual void Print()
        {
            Console.WriteLine($"ID: {ID}, Name: {Name}");
        }

        public override string ToString()
        {
            this.Print();
            return null;
        }
    }
}
