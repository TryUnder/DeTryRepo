using System;
namespace Delegate{
    public class Delegate{
        public delegate double OperatorAction(int x, int y);

        public static double Divide(int a, int b){
            var result = (double) a / b;
            Console.WriteLine($"Divide: {a}/{b}={result}");
            return result;
        }

        public static double Add(int a, int b){
            var result = a + b;
            Console.WriteLine($"Sum: {a}+{b}={result}");
            return result;
        }

        public static double Subtract(int a, int b){
            var result = a - b;
            Console.WriteLine($"Subtract: {a}-{b}={result}");
            return result;
        }

        public static double Multiply(int a, int b){
            var result = a * b;
            Console.WriteLine($"Multiply: {a}*{b}={result}");
            return result;
        }

        public static void Main(string[] args){
            OperatorAction actions = new OperatorAction(Add);
            actions += Multiply;
            actions += Subtract;
            actions += Divide;
            actions(100,5);
            var result = actions(50,50);
            Console.WriteLine(result);
        }
    }
}