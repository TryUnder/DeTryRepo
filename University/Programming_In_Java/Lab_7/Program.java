import java.util.*;
import java.io.*;
import java.util.Scanner;
import javax.swing.JOptionPane;


public class Program {

	public static void SaveToFile(ArrayList <Employee> eTab, String fileDir) {
		File file = new File(fileDir);
		Scanner scanner;
		try {
			scanner = new Scanner(file);
		} catch (FileNotFoundException e) {
			scanner = null;
		}
	
		StringBuilder stringBuilder = new StringBuilder();
		eTab.forEach(e -> {
			stringBuilder.append(e.toString() + new String("\n"));
		});
	
		try {
			if (!file.exists()){
				file.createNewFile();
				FileWriter fileWriter = new FileWriter(file, true);
				fileWriter.write(stringBuilder.toString());
				fileWriter.close();
			}
		} catch (IOException e) {
			System.out.println("Nastapil problem z zapisem do pliku");
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		var eTab = new ArrayList<Employee>();
		eTab.add(new Employee("Nowak Jan", 1.0, 5200.0, 24, "Kierowca"));
		eTab.add(new Employee("Piech Anna", 0.7, 4800.0, 29, "Ksiegowa"));
		eTab.add(new Employee("Jach Ewa", 1.2, 6000.0, 27, "Ksiegowa"));
		eTab.add(new Employee("Rak Piotr", 1.25, 4000.0, 21, "Kierowca"));
		eTab.add(new Employee("Maj Jan", 0.5, 7000.0, 52, "Kierownik"));
		eTab.add(new Employee("Bak Olga", 1.0, 6000.0, 29, "Ksiegowa"));
		
		System.out.println("Na starcie: \n");
		
		eTab.forEach(employee -> System.out.println(employee));

		eTab.forEach(employee -> {
			if (employee.getAge() < employee.ageLimit) 
				employee.countSalary(employee.getSalaryFTE() *
				employee.getfte() * (1 - employee.hcc));
			 else {
				employee.countSalary(employee.getSalaryFTE() *
				employee.getfte() * (1 - employee.ratePIT - employee.hcc));
			}
		});
		
		System.out.println("\nPo obliczeniu pensji: \n");
		
		eTab.forEach(employee -> System.out.println(employee));

		System.out.println("\nPo posortowaniu wg netSalary niemalejaco: \n");
		
		Collections.sort(eTab, (e1, e2) -> e2.getAge() - e1.getAge());

		eTab.forEach(employee -> System.out.println(employee));

		System.out.println("\nPo posortowaniu wg position age netSalary: \n");

		Collections.shuffle(eTab);

		Comparator <Employee> customComparator1 =  (e1, e2) -> {
			return e1.getPosition().compareTo(e2.getPosition());
		};

		Comparator <Employee> customComparator2 = (e1, e2) -> {
			return e2.getAge() - e1.getAge();
		};

		Comparator <Employee> customComparator3 = (e1, e2) -> {
			return Double.compare(e2.getNetSalary(), e1.getNetSalary());
		};

		Collections.sort(eTab, customComparator1);
		Collections.sort(eTab, customComparator2);
		Collections.sort(eTab, customComparator3);

		eTab.forEach(employee -> System.out.println(employee));
		
		Collections.shuffle(eTab);

		System.out.println("\nPo posortowaniu wg age position salaryFTE: \n");

		Collections.sort(eTab, Comparator.comparing(Employee::getAge, Comparator.reverseOrder())
			.thenComparing(Employee::getPosition)
			.thenComparing(Employee::getSalaryFTE, Comparator.reverseOrder())
			);

		eTab.forEach(employee -> System.out.println(employee));
		String fileDir = JOptionPane.showInputDialog("Wprowadz sciezke do zapisu");
		SaveToFile(eTab, fileDir);
	}
}
