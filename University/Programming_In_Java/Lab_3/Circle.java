package University.Programming_In_Java.Lab_3;

public class Circle extends Figure {
	private double r;
 
	public Circle() {
		super();
		r = 0.0;
	}
 
	public Circle(String Color, double R) {
		super(Color, 0.0,0.0);
		r = R;
	}
 
	public double getR() { return r; }
 
	public double countCircumference(double R) {
		return 2 * Math.PI * r;
	}
 
	public double count_surface(double R) {
		return Math.PI * Math.pow(r, 2);
	}
 
	public void viewData() {
		super.viewData();
	}
}
