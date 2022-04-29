using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kolokwium_1
{
    public class Program
    {
        public static void Main()
        {
            Console.WriteLine("--------------------------------------");
            InvoiceItem invoiceitem1 = new InvoiceItem(2000.0f, "Kowalski", 10.0f, 20000.0f);
            Console.WriteLine(invoiceitem1);
            Console.WriteLine("Klasa InvoiceItem działa");
            Console.WriteLine("--------------------------------------");

            InvoiceItem invoiceitem2 = new InvoiceItem(1000.0f, "Zarebski", 1.0f, 1000.0f);
            Console.WriteLine(invoiceitem2);
            Console.WriteLine("--------------------------------------");

            User user = new User("1", "Janusz");
            Console.WriteLine(user);
            Console.WriteLine("Klasa User Działa");
            Console.WriteLine("--------------------------------------");

            List<InvoiceItem> invoiceitems = new List<InvoiceItem>();
            invoiceitems.Add(invoiceitem1);
            invoiceitems.Add(invoiceitem2);

            Invoice invoice = new Invoice(new DateTime(2022, 04, 28), invoiceitems, 3000.0f, "1");
            Console.WriteLine(invoice);

        }
    }
}
