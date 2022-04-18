using System;
using System.IO;
// delegacja bez typu zwracanego
namespace Second_Delegate{
    public class Delegate{
        public delegate void PrintMessageAction(string message);

        public static void PrintMessageToConsole(string message){
            Console.WriteLine(message);
        }

        public static void PrintMessageToFile(string message){
            File.AppendAllText(@"./messages.txt", $"{message}\r\n");
        }

        public static void Main(string[] args){
            PrintMessageAction printMessageAction = new PrintMessageAction(PrintMessageToConsole);
            printMessageAction("Hello World");
            printMessageAction += PrintMessageToFile;
            printMessageAction("Welcome in C# world");
        }
    }
}