using System;
using System.IO;
namespace Functor{
    public class Functor{
        public static double Divide(int a, int b){
            var result = (double) a / b;
            Console.WriteLine($"Divide: {a}/{b}={result}");
            return result;
        }

        public static double Multiply(int a, int b){
            var result = a * b;
            Console.WriteLine($"Multiply: {a}*{b}={result}");
            return result;
        }

        public static double Add(int a, int b){
            var result = a + b;
            Console.WriteLine($"Add: {a}+{b}={result}");
            return result;
        }

        public static double Subtract(int a, int b){
            var result = a - b;
            Console.WriteLine($"Subtract: {a}-{b}={result}");
            return result;
        }

        public static void PrintMessageToConsole(string message){
            Console.WriteLine(message);
        }

        public static void PrintMessageToFile(string message){
            File.AppendAllText(@"./messages.txt", $"{message}\r\n");
        }

        public static void Main(){
            // (funktor/obiekt funkcyjny/wskaźnik na funkcje) (func) o typie zwracanym określonym (double)

            Func<int, int, double> funcAction = new Func<int, int, double>(Add);
            funcAction += Multiply;
            funcAction += Subtract;
            funcAction += Divide;
            var result = funcAction(100,20);
            Console.WriteLine(result);
            funcAction -= Divide;
            result = funcAction(100,20);
            Console.WriteLine(result);

            // (funktor/obiekt funkcyjny/wskaźnik na funkcje) (action) o typie zwracanym nieokreślonym (void)

            Action<string> messageAction = new Action<string>(PrintMessageToConsole);
            messageAction += PrintMessageToFile;
            messageAction(".NET is great");
        }
    }
}