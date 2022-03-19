using System;
namespace Abstract_Class{
    public class Rectangle : GeometricFigure{
        private double _sideA;
        private double _sideB;

        public double SideA { get => _sideA; set => _sideA = value; }
        public double SideB { get => _sideB; set => _sideB = value; }

        public Rectangle(string name, double sideA, double sideB)
            : base(name){
            _sideA = sideA;
            _sideB = sideB;
        }
        
        public override string ToString(){
            return $"Rectangle {base._name} | SideA: {_sideA} | SideB: {_sideB}";
        }

        public override double CalculateArea(){
            return _sideA * _sideB;
        }
    }
}
