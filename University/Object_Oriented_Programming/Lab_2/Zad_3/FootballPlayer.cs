using System;
namespace Zad_3{
    public class FootballPlayer : Player{
        public FootballPlayer(string firstName, string lastName, DateTime dateOfBirth, string position, string club, int scoredGoals)
            : base(firstName, lastName, dateOfBirth, position, club, scoredGoals) {}
        
        public override void ScoreGoal(){
            base.ScoreGoal();
            Console.WriteLine("Football player scored goal!");
        }
    }
}
