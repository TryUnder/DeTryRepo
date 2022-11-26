import java.util.*;


// interface Accountant {
// 	public static final int ageLimit = 26;
// 	public static final double ratePIT = 0.18;
// 	public static final double hcc = 0.09;

// 	public abstract void countSalary(double netSalary);
// }

public class Program {
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

		System.out.println("\nPo posortowaniu wg position, age, netSalary: \n");

		Collections.sort(eTab, (e1, e2) -> e1.getPosition().compareTo(e2.getPosition()));
		
		eTab.forEach(employee -> System.out.println(employee));
	}
}
