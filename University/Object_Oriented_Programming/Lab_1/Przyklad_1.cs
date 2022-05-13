public class House
{
    const int _windowCount = 10;
    private double _area;
    private string _owner;
    private readonly string _address;
    private static int _houseCount;

    public House()
    {
        _address = "none";
        Area = 0;
        _houseCount++;
    }

    public House(string address, double area, int doorCount, string owner)
    {
        _address = address;
        _area = area;
        DoorCount = doorCount;
        _owner = owner;
        _houseCount++;
    }

    public House(House house)
    {
        _address = house._address;
        _area = house._area;
        DoorCount = house.DoorCount;
        _owner = house._owner;
        _houseCount++;
    }

    public static int HouseCount => _houseCount;

    public double Area
    {
        get { return _area; }
        set { _area = value; }
    }

    public string Address => _address;

    public int DoorCount { get; set; }
    public string Owner
    {
        get => _owner;
        set => _owner = value;
    }

    public decimal CalculateTax(decimal taxValuePerSquareMeter)
    {
        return taxValuePerSquareMeter * (decimal)_area;
    }

    public override string ToString()
    {
        return $"House Address: {_address}, Owner: {_owner}, Area: {_area}, Door count:{DoorCount}";
    }

    public static void Main()
    {
        House house = new House();
        house.Area = 100;
        house.DoorCount = 7;
        house.Owner = "Michał Nowakowski";
        var tax = house.CalculateTax(25);
        System.Console.WriteLine($"{house.DoorCount}, {house.Address}, {house.Area}, {house.Owner}, | Tax: {tax}");

        House h2 = new House("ul. Testowa 1", 200, 14, "Anna Nowakowska");
        System.Console.WriteLine($"{h2.DoorCount},{h2.Address}, {h2.Area}, {h2.Owner}");
        House h3 = new House()
        {
            DoorCount = 8,
            Area = 150,
            Owner = "Stanisław Bednarski"
        };
        System.Console.WriteLine($"{h3.DoorCount},{h3.Address},{h3.Area},{h3.Owner}");
        System.Console.WriteLine(h3);
        System.Console.WriteLine($"House count: {House.HouseCount}");
    }
}