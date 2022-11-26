import java.util.*;

// interface Accountant {
// 	public static final int ageLimit = 26;
// 	public static final double ratePIT = 0.18;
// 	public static final double hcc = 0.09;

// 	public abstract void countSalary(double netSalary);
// }

interface MyLambda {
	public void foo();
}

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
		
		for(Employee e : eTab) {
			System.out.println(e);
			MyLambda x = () -> {
				if (e.getAge() <= e.ageLimit) {
					e.countSalary(e.getSalaryFTE() * e.getfte() * (1 - e.hcc));
				} else {
					e.countSalary(e.getSalaryFTE() * e.getfte() * (1 - e.ratePIT - e.hcc));
				}
			};
			x.foo();
		}
		
		System.out.println("Po obliczeniu pensji: ");
		
		for(Employee e : eTab) {
			System.out.println(e);
		}
	}
}
