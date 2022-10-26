import java.util.ArrayList;

public class Player {
	private String name;
	private String team_name;
	private int age;
	private int m_goals;
	private double ave_n_minutes;
	
	public Player(String Name, String Team_name, int Age, int m_Goals, double Ave_n_minutes) {
		if (Name.isBlank()) throw new IllegalArgumentException("Bad name");
		if (Age < 16 || Age > 60) throw new ArithmeticException("Bad age");
		if (m_Goals < 0) throw new IllegalArgumentException("Bad number of goals");
		if (Ave_n_minutes < 0 || Ave_n_minutes > 90) throw new IllegalArgumentException("Bad spending time on field");
		name = Name;
		team_name = Team_name;
		age = Age;
		m_goals = m_Goals;
		ave_n_minutes = Ave_n_minutes;
	}
	
	public String toString() {
		return "Name: " + name + " team name: " + team_name + " age: " + age + " m_goals: " + m_goals + " ave n minutes: " + ave_n_minutes;
	}
	
}
