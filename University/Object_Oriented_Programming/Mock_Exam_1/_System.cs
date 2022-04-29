using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kolokwium_1
{
    public class _System
    {
        public List<Client> Clients { get; set; }
        public List<Invoice> Invoices { get; set; }
        public _System(List<Client> clients, List<Invoice> invoices)
        {
            Clients = new List<Client>(clients);
            Invoices = new List<Invoice>(invoices);
        }

        public void Add(Client c)
        {
            Clients.Add(c);
        }

        public void Add(Invoice c)
        {
            Invoices.Add(c);
        }

        public Client Find(string name)
        {
            return Clients.FirstOrDefault(i => i.Name == name);
        }

        public Invoice FindById(string id)
        {
            return Invoices.FirstOrDefault(i => i.ID == id);
        }
    }
}
