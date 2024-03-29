﻿using System;
using Lab5.BLL;

namespace Lab5.App
{
    public class Program
    {
        public static void Main()
        {
            Zoo zoo = new Zoo("Slaski ogrod zoologiczny", new List<Employee>(),
                                                          new List<Cage>(),
                                                          new List<Animal>());

            Animal dog = new Mammal("flesh", 4, "Europe", "Gray Wolf", "Europe");
            Animal cow = new Mammal("grass", 4, "Europe", "B. taurus", "Europe");
            Animal crocodile1 = new Reptile("flesh", 4, "Africa", "C. niloticus", false);
            Animal cobra = new Reptile("flesh", 0, "Africa", "Serpentes", true);
            Cage cage1 = new Cage(4, false, new List<Animal> { dog, cow, crocodile1 });
            Console.WriteLine(cage1);
            Animal horse = new Mammal("Grass", 4, "North America, Europe", "E. ferus", "Europa");
            Animal falcon = new Bird("flesh", 2, "Europe", "Falconidae", 1.2, 125);
            (falcon as Bird).Fly();
            Cage cage2 = new Cage(3, false, new List<Animal> { horse, falcon });
            Console.WriteLine(cage2);
            Cage cage3 = new Cage(10, false, new List<Animal>());
            Console.WriteLine(cage3);
            Cage cage4 = zoo.BuildCage(10, false);
            zoo.ExpandCage(cage4);
        }
    }
}
