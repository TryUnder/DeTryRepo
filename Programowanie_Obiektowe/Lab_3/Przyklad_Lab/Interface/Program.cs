using System;
namespace Interface{
    public class Program{
        public static void Main(){
            IMusicalInstrument trumpet = new Trumpet();
            trumpet.Play();
            IMusicalInstrument drum = new Drum();
            drum.Play();
        }
    }
}
