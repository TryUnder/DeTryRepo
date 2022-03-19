using System;
namespace Interface{
    public class Drum : IMusicalInstrument{
        public void Play(){
            Console.WriteLine("Bum bum bum");
        }    

        public string Name => "Drum";
    }
}
