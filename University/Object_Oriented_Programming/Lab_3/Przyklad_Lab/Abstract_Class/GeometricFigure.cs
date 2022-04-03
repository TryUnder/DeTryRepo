using System;
namespace Abstract_Class{
    public abstract class GeometricFigure{
        protected string _name;
        public string Name { get => _name; set => _name = value; }

        public GeometricFigure(string name){
            _name = name;
        }

        public override string ToString(){
            return $"Name: {_name}";
        }

        public abstract double CalculateArea();
    }
}
