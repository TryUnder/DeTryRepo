using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kolokwium_1
{
    public class InvoiceItem
    {
        public float Amount { get; set; }
        public string Name { get; set; }
        public float Price { get; set; }
        public float Value { get; set; }

        public InvoiceItem(float amount, string name, float price, float value)
        {
            Amount = amount;
            Name = name;
            Price = price;
            Value = value;
        }

        public void Wypisz()
        {
            Console.WriteLine($"Amount: {Amount}, Name: {Name}, Price: {Price}, Value: {Value}");
        }

        public override string ToString()
        {
            this.Wypisz();
            return null;
        }
    }
}
