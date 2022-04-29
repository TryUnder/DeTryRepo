using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kolokwium_1
{
    public class Invoice : Document
    {
        public DateTime Date { get; set; }
        public List<InvoiceItem> Items { get; set; }
        public float Value { get; set; }
        public Invoice(DateTime date, List<InvoiceItem> items, float value, string id)
            : base(id){
            Date = new DateTime();
            Date = date;
            Value = value;
            Items = new List<InvoiceItem>(items);
        }

        public override void Print()
        {
            base.Print();
            Console.WriteLine($"Data: {Date}, Value: {Value}");
            foreach (var i in Items)
            {
                Console.WriteLine(i);
            }
        }

        public override string ToString()
        {
            this.Print();
            return null;
        }
    }
}
