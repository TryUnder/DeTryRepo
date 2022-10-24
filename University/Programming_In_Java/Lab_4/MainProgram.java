import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class MainProgram {
	
	public static void addUser(ArrayList<Player> arrayListOfPlayers, ArrayList<String> teams) {
		String name, team_name;
		int age, goals;
		double ave_n_minutes;
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("\nCzy chcesz wprowadzic nowego uzytkownika?: Yes/No");
		while(scanner.nextLine().equals("Yes")) {
			
			System.out.println("Podaj imie: ");
			name = scanner.nextLine();
			System.out.println("Podaj nazwe zespolu: ");
				team_name = scanner.nextLine();
				try {
					for(var i=0; i<teams.size(); ++i) {
						if (team_name.equals(teams.get(i))){
							break;
						} else if (i==teams.size()-1) {
							throw new IllegalArgumentException("Wprowadzono zawodnika z nieistniejacym klubem. Koncze dzialanie");
						}
					}	
			}catch(IllegalArgumentException e){
				System.out.println(e); 
				return;
			}

			try {
				System.out.println("Podaj wiek: ");
				age = Integer.parseInt(scanner.next());
				System.out.println("Podaj liczba goli");
				goals = Integer.parseInt(scanner.next());
			}catch(NumberFormatException e) {
				System.out.println("Podano nieprawidlowy format liczbowy");
				break;
			}

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
		teams.add("Warta Czestochowa");
		teams.add("Gryf Poznan");
		teams.add("Pilica Piotrkow Trybunalski");
		teams.add("Wisla Katowice");
		teams.add("San Krakow");
		
		System.out.println("\nLista klubow przed sortowaniem: \n");
		teams.forEach(System.out::println);
		
		System.out.println("\nLista klubow po sortowaniu: \n");
		Collections.sort(teams);
		teams.forEach(System.out::println);
		
		ArrayList<Player> arrayListOfPlayers = new ArrayList<Player>();
		addUser(arrayListOfPlayers, teams);
	}
}
