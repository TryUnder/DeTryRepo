import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class MainProgram {
	
	public static void addUser(ArrayList<Player> arrayListOfPlayers, ArrayList<String> teams) {
		String name, team_name;
		int age, goals;
		double ave_n_minutes;
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Czy chcesz wprowadziæ nowego u¿ytkownika? Yes/No");
		while(scanner.nextLine().equals("Yes")) {
			
			System.out.println("Podaj imie: ");
			name = scanner.nextLine();
			System.out.println("Podaj nazwe zespo³u: ");
			//for(String team : teams) {
				
			//}
			team_name = scanner.nextLine();
			System.out.println("Podaj wiek: ");
			try {
				age = Integer.parseInt(scanner.next());
			}catch(NumberFormatException e) {
				System.out.println("Proszê podaæ ponownie wiek");
				age = Integer.parseInt(scanner.next());
			}
			System.out.println("Podaj liczbê goli");
			goals = scanner.nextInt();
			System.out.println("Podaj ave n minutes");
			ave_n_minutes = scanner.nextDouble();
			
			try {
				arrayListOfPlayers.add(new Player(name, team_name, age, goals, ave_n_minutes));
			} catch (IllegalArgumentException e) {
				System.out.println(e);
			}
		}
		System.out.println("Koniec");
	}
	
	public static void main(String[] args) {
	
		ArrayList<String> teams = new ArrayList<String>();
		teams.add("Warta Czêstochowa");
		teams.add("Gryf Poznan");
		teams.add("Pilica Piotrków Trybunalski");
		teams.add("Wis³a Katowice");
		teams.add("San Kraków");
		
		System.out.println("Lista klubów przed sortowaniem: \n");
		teams.forEach(System.out::println);
		
		System.out.println("Lista klubów po sortowaniu: \n");
		Collections.sort(teams);
		teams.forEach(System.out::println);
		
		ArrayList<Player> arrayListOfPlayers = new ArrayList<Player>();
		addUser(arrayListOfPlayers);
	}
}
