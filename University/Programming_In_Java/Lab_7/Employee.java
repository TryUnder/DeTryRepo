import java.math.BigDecimal;
import java.math.RoundingMode;
import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;

public class Employee implements Accountant{
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
		return fte;
	}

	public int getAge() {
		return age;
	}

	public String getPosition() {
		return position;
	}

	public double getNetSalary() {
		return netSalary;
	}

	public void countSalary(double netSalary) {
		this.netSalary = netSalary;
	}

	public String toString() {
		return name + " lat:" + age + " " + position 
				+ " placa podstawowa: " + salaryFTE + " pensja: "
				+ (new BigDecimal(netSalary).setScale(2, RoundingMode.HALF_UP));
	}
}
