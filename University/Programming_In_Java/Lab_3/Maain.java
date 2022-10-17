package University.Programming_In_Java.Lab_3;

import java.util.Scanner;
 
public class Maain {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Wprowadz promien okregu: ");
		double d = scanner.nextDouble();
 
		if (d>0) {
			Circle circle = new Circle("Zielony", d);
			circle.setCircumference(circle.countCircumference(d));
			circle.setSurface(circle.count_surface(d));
			circle.viewData();
		}
		
		System.out.println("Wprowadz boki prostokata: ");
		d = scanner.nextDouble();
		double p = scanner.nextDouble();
 
		if (d > 0 && p > 0) {
			Rectangle rectangle = new Rectangle("Czerwony", d, p);
			rectangle.setCircumference(rectangle.count_Circumference());
			rectangle.setSurface(rectangle.count_surface());
			rectangle.viewData();
		}
 
		System.out.println("Wprowadz boki trojkata: ");
	
		d = scanner.nextDouble();
		p = scanner.nextDouble();
		double s = scanner.nextDouble();
		
		if (d+p>s && p+s>d && d+s>p && d>0 && p>0 && s>0) {
			Triangle triangle = new Triangle("Fioletowy",d,p,s);
			triangle.setCircumference(triangle.count_Circumference());
			triangle.setSurface(triangle.count_surface());
			triangle.viewData();
		} else {
			System.out.println("Trojkat o takich bokach nie może powstać");
		}
		scanner.close();
	}
}
 