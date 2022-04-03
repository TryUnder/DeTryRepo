public struct Point
{
    public int X { get; set; }
    public int Y { get; set; }
    public override string ToString()
    {
        return $"X: {X}, Y: {Y}";
    }
}

class Nullable
 {
    public static void Main()
    {
        int a = 1;
        int b = a;
        a = 5;
        int? x = null;
        int? y = x;
        x = 5;
        System.Nullable<int> z = null;
        Point p1 = new Point();
        Point p2 = p1;
        p1.X = 200;
        System.Console.WriteLine(p1);

        object s = 1.ToString();
        object o1 = 1; // boxing int to object
        int c = (int)o1; // unboxing object to int
    }
 }
