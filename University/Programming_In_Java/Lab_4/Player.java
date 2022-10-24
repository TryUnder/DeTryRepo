import java.util.ArrayList;

public class Player {
	private String name;
	private String team_name;
	private int age;
	private int m_goals;
	private double ave_n_minutes;
	
	public Player(String Name, String Team_name, int Age, int m_Goals, double Ave_n_minutes) {
		name = Name;
		team_name = Team_name;
		age = Age;
		m_goals = m_Goals;
		ave_n_minutes = Ave_n_minutes;
	}
	
	public static void toString(String data) {
		System.out.println(data);
	}
	
}
