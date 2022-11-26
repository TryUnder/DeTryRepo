import java.util.*;

public class Program {
	public static void main(String[] args) {
		var eTab = new ArrayList<Employee>();
		eTab.add(new Employee("Nowak Jan", 1.0, 5200.0, 24, "Kierowca"));
		eTab.add(new Employee("Piech Anna", 0.7, 4800.0, 29, "Księgowa"));
		eTab.add(new Employee("Jach Ewa", 1.2, 6000.0, 27, "Księgowa"));
		eTab.add(new Employee("Rak Piotr", 1.25, 4000.0, 21, "Kierowca"));
		eTab.add(new Employee("Maj Jan", 0.5, 7000.0, 52, "Kierownik"));
		eTab.add(new Employee("Bak Olga", 1.0, 6000.0, 29, "Księgowa"));
		
		System.out.println("Na starcie: ");
		
		// for(Employee e : eTab) {
		// 	System.out.println(e);
		// 	Accountant accountant = () -> {
		// 		if (e.getAge() <= 26) {
		// 			e.setSalary(e.getSalaryFTE() * e.getfte() * (1 - 0.09));
		// 		} else {
		// 			e.setSalary(e.getSalaryFTE() * e.getfte() * (1 - 0.18 - 0.09));
		// 		}
		// 	};
		// 	accountant.countSalary();
		// }
		
		System.out.println("Po obliczeniu pensji: ");
		
		for(Employee e : eTab) {
			System.out.println(e);
		}
	}
}
