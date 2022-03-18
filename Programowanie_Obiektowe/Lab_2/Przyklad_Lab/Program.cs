using System;
using System.Collections.Generic;
using System.Linq;
namespace Lab_2
{
    public class Program
    {
        public static void Main()
        {
            Building bud1 = new Building("ul. Kwiatowa 8");
            ResidentialBuilding bud2 = new ResidentialBuilding("ul. Armii Krajowej 8", 50);
            Console.WriteLine($"Budynek, address: {bud1.Address}");
            Console.WriteLine($"Budynek mieszkalny, address: {bud2.Address}, " +
                              $" residents count: {bud2.ResidentsCount}");

            Console.WriteLine($"Bud2 | Electricity cost: {bud2.CalculateElectricityCost(20)}");
            Console.WriteLine($"Bud1 | Electricity cost: {bud1.CalculateElectricityCost(20)}");
            
            Console.WriteLine();
            Console.WriteLine(bud1);
            Console.WriteLine(bud2);
            Console.WriteLine();
        
            Building bud3 = new ResidentialBuilding("Tulipanowa 15", 150);
            Console.WriteLine(bud3);
            Console.WriteLine($"Bud3 | Electricity cost: {bud3.CalculateElectricityCost(20)}");
            
            List<Building> buildingList = new List<Building>();
            buildingList.Add(bud1);
            buildingList.Add(bud3);
            buildingList.Insert(0, bud2);
            Console.WriteLine($"Building count: {buildingList.Count}");
        
            Building budReference = buildingList[1];
            ResidentialBuilding budReference2 = buildingList[0] as ResidentialBuilding;
            budReference2.ResidentsCount = 4;

            Console.WriteLine($"residents count: {bud2.ResidentsCount}");
        
            //wyszukiwanie elementów z listy
            var foundedBuilding = buildingList.FirstOrDefault(b => b.Address == "Tulipanowa 15");
            Console.WriteLine(foundedBuilding);
        
            //wyszukiwanie elementów z listy pasujących do predykatów lambdy
            var foundedBuildings = buildingList.Where(b => b.Address == "owa");
            Console.WriteLine(foundedBuildings);
        }
    }
}
