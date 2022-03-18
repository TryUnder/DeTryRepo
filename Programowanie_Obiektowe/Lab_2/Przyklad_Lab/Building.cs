using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_2
{
    public class Building
    {
        protected string _address;
        public string Address => _address;
        public Building(string address)
        {
            _address = address;
        }

        public virtual decimal CalculateElectricityCost(decimal baseElectricityCost)
        {
            return baseElectricityCost;
        }

        public override string ToString()
        {
            return $"Building | Address: {_address}";
        }
    }
}
