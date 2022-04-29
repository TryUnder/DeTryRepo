using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kolokwium_1
{
    public abstract class Document : IPrint
    {
        public string ID { get; set; }
        public Document(string id)
        {
            ID = id;
        }

        public virtual void Print()
        {
            Console.WriteLine($"ID: {ID}");
        }

        public override string ToString()
        {
            this.Print();
            return null;
        }
    }
}
