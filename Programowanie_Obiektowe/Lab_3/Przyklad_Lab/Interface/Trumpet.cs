using System;
namespace Interface{
    public class Trumpet : IMusicalInstrument{
        public void Play(){
            Console.WriteLine("Tratata");
        }

        public string Name => "Trumpet";
    }
}
