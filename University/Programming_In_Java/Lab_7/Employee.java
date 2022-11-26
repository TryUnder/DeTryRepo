
public class Employee {
	private String name;
	private int age;
	private double fte;
	private double salaryFTE;
	private double netSalary;
	private String position;
	
	public Employee(String name, double fte, double salaryFTE, 
			int age, String position) {
		this.name = name;
		this.fte = fte;
		this.salaryFTE = salaryFTE;
		this.age = age;
		this.position = position;
	}

	public double getSalaryFTE() {
		return salaryFTE;
	}

	public double getfte() {
		
	}

	public int getAge() {
		return age;
	}

	public void setSalary(double netSalary) {
		this.netSalary = netSalary;
	}

	public String toString() {
		return name + " lat:" + age + " " + position 
				+ " placa podstawowa: " + salaryFTE + " pensja: " + netSalary;
	}
}
