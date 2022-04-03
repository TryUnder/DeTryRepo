using System;
namespace Abstract_Class{
    public class Circle : GeometricFigure{
        private double _radius;
        
        public double Radius { get => _radius; set => _radius = value; }
        public Circle(string name, double radius)
            : base(name){
            _radius = radius;    
        }

        public override string ToString(){
            return $"Circle | {base.ToString()}, Radius: {_radius}";
        }

        public override double CalculateArea(){
            return Math.PI * Math.Pow(_radius, 2);
        }
    }
}
