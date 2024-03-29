﻿namespace Car
{
    public class Car
    {
        private string _brand;
        private string _model;
        private int _doorCount;
        private float _engineVolume;
        private double _avgConsump;
        private static int _carCount = 0;
        private string _registrationNumber;
        public string Brand { get { return _brand; } set { _brand = value; } }
        public string Model { get { return _model; } set { _model = value; } }
        public float EngineVolume { get { return _engineVolume; } set { _engineVolume = value; } }
        public double AvgConsump { get { return _avgConsump; } set { _avgConsump = value; } }
        public Car()
        {
            _brand = "none";
            _model = "none";
            _doorCount = 0;
            _engineVolume = 0.0f;
            _avgConsump = 0.0d;
            _registrationNumber = "XX00000";
            _carCount++;
        }

        public Car(string brand, string model, int doorCount,
                   float engineVolume, double avgConsump, string registrationNumber)
        {
            _brand = brand;
            _model = model;
            _doorCount = doorCount;
            _engineVolume = engineVolume;
            _avgConsump = avgConsump;
            _registrationNumber = registrationNumber;
            _carCount++;
        }

        public double CalculateConsump(double roadLength)
        {
            return (_avgConsump * roadLength) / 100.0;
        }

        public double CalculateCost(double roadLength, double petrolCost)
        {
            return CalculateConsump(roadLength) * petrolCost;
        }

        public void Details()
        {
            System.Console.WriteLine(this);
        }

        public static void DisplayCarCount()
        {
            System.Console.WriteLine(_carCount);
        }

        public override string ToString()
        {
            return $"Car | Brand: {_brand}, Model: {_model}, NumOfDoors:" +
                $" {_doorCount}, EngineVol: {_engineVolume}, AvgConsump:" +
                $" {_avgConsump}, RegistrationNumber: {_registrationNumber}";
        }

        public static void Main()
        {
            Car car1 = new Car();
            car1.Details();
            car1.Brand = "Fiat";
            car1.Model = "126p";
            car1._doorCount = 2;
            car1.EngineVolume = 650;
            car1.AvgConsump = 6.0;
            car1._registrationNumber = "KR12345";
            car1.Details();
            Car car2 = new Car("Syrena", "105", 2, 0.8f, 7.6d, "WE1234");
            car2.Details();
            System.Console.WriteLine(car1);
            double routeConsumption = car2.CalculateConsump(500);
            System.Console.WriteLine($"Route consumption: {routeConsumption} l");
            double routeCost = car2.CalculateCost(500, 5);
            System.Console.WriteLine($"Route cost: {routeCost}");
            Car.DisplayCarCount();
            System.Console.WriteLine("\r\n=========================================\r\n");
        }
    }
}
