using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kolokwium_1
{
    public class Client : User
    {
        public string Address { get; set; }
        public Client(string adres, string id, string name)
            : base(id, name)
        {
            Address = adres;
        }
    }
}
