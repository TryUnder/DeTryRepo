using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kolokwium_1
{
    public interface IPrint
    {
        public string ID { get; set; }
        public virtual void Print()
        {
            Console.WriteLine($"ID: {ID}");
        }
    }
}
