using System;
namespace Zad_3{
    public class HandballPlayer : Player{
        public HandballPlayer(string firstName, string lastName, DateTime dateOfBirth, string position, string club, int scoredGoals)
            : base(firstName, lastName, dateOfBirth, position, club, scoredGoals){}
    }
}
