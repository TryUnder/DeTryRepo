using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_2
{
    public class ResidentialBuilding : Building
    {
        private int _residentsCount;
        public int ResidentsCount
        {
            get => _residentsCount;
            set => _residentsCount = value;
        }

        public ResidentialBuilding(string address, int residentsCount)
            : base(address)
        {
            _residentsCount = residentsCount;
        }

        public override decimal CalculateElectricityCost(decimal baseElectricityCost)
        {
            return baseElectricityCost * _residentsCount;
        }

        public override string ToString()
        {
            return $"Residential Building | Address: {_address}, residents count: {_residentsCount}";
        }
    }
}
