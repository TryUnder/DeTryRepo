using System;
namespace Abstract_Class{
    public class Program{
        public static void Main(){
            GeometricFigure circle1 = new Circle("circle", 10.0D);
            Console.WriteLine($"{circle1}, Area: {circle1.CalculateArea()}");
            GeometricFigure rectangle1 = new Rectangle("rectangle", 10.0D, 10.0D);
            Console.WriteLine($"{rectangle1}, Area: {rectangle1.CalculateArea()}");
        }    
    }
}
