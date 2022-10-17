package University.Programming_In_Java.Lab_3;

public class Triangle extends Figure {
	private double a;
	private double b;
	private double c;
 
	public Triangle() {
		super();
		a = 0.0;
		b = 0.0;
		c = 0.0;
	}
 
	public Triangle(String Kolor, double A, double B, double C) {
		super(Kolor,0.0,0.0);
		a = A;
		b = B;
		c = C;
	}
 
	public double count_Circumference() {
		return a + b + c;
	}
 
	public double count_surface() {
		double p = (a+b+c)/2;
		return Math.sqrt(p * (p - a) * (p - b) * (p - c));
	}
 
	public void viewData() {
		super.viewData();
	}
}
