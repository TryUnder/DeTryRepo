public class Point3D
{
    public int X { get; set; }
    public int Y { get; set; }
    public int Z { get; set; }
    public Point3D(int x, int y, int z)
    {
        X = x;
        Y = y;
        Z = z;
    }

    public override string ToString()
    {
        return $"X = {X}, Y = {Y}, Z = {Z}";
    }

    public Point3D Clone()
    {
        return (Point3D)this.MemberwiseClone();
    }
}

class ShallowCopy_3
{
    public static void Main()
    {
        Point3D point = new Point3D(1, 2, 3);
        System.Console.WriteLine(point);
        Point3D point2 = new Point3D(4, 5, 6);
        point = point2;
        System.Console.WriteLine(point);
        point.X = 10;
        point.Y = 20;
        point.Z = 30;
        System.Console.WriteLine(point2);
    }
}

