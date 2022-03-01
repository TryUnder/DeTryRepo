namespace Lab1
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

            Garage garage1 = new Garage();
            garage1.Address = "ul. Garażowa 1";
            garage1.Capacity = 1;
            Garage garage2 = new Garage("ul. Garażowa 2", 2);
            garage1.CarIn(car1);
            garage1.Details();
            garage1.CarIn(car2);
            garage2.CarIn(car2);
            var movedCar = garage1.CarOut();
            garage2.CarIn(movedCar);
            garage2.Details();
            garage1.Details();
            garage2.CarOut();
            garage2.CarOut();
            garage2.Details();
            garage1.Details();
            System.Console.WriteLine("\r\n=========================================\r\n");
        }
    }

    public class Garage
    {
        private Car[] _cars;
        private string _address;
        private int _carsCount;
        private int _capacity;

        public string Address
        {
            get { return _address; }
            set { _address = value; }
        }

        public int Capacity
        {
            get { return _capacity; }
            set
            {
                _capacity = value;
                _cars = new Car[value];
            }
        }

        public Garage()
        {
            _cars = null;
            _address = "nieznany";
            _capacity = 0;
        }

        public Garage(string address, int capacity)
        {
            _address = address;
            _capacity = capacity;
            _cars = new Car[capacity];
        }

        public void CarIn(Car car)
        {
            if (_carsCount >= _capacity) {
                System.Console.WriteLine("Garaż jest przepełniony");
            }
            else {
                for(int i=0; i<this._capacity; ++i){
                    if(_cars[i] == null) {
                        _cars[i] = car;
                        _carsCount++;
                        break;
                    }
                }
            }
        }

        public Car CarOut() {
            if(_carsCount == 0) {
                System.Console.WriteLine("Garaż jest pusty");
            }
            else {
                for(int i=_cars.Length-1; i>=0; i--) {
                    if (this._cars[i] != null)
                    {
                        Car car = new Car();
                        car = _cars[i];
                        _cars[i] = null;
                        _carsCount--;
                        return car;
                    }
                }
            }
            return null;
        }

        public override string ToString() {
             string _string;
             _string = $"Addres: {_address}, Cars Count: {_carsCount}, Capacity: {_capacity}\n";
             foreach(var number in _cars) {
                _string += $"{number}\n";
             }
            return _string;
        }

        public void Details() {
            System.Console.WriteLine(this);
        }
    }

}
