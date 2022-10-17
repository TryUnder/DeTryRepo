public class Figure {
	private String color;
	private double surface_area;
	private double circumference;
 
	Figure(){
		color = "none";
		surface_area = 0.0;
		circumference = 0.0;
	}
 
	Figure(String Color, double Surface_area, double Circumference){
		color = Color;
		surface_area = Surface_area;
		circumference = Circumference;
	}
 
	public void setSurface(double Surface_area) { surface_area = Surface_area; }
	public void setCircumference(double Circumference) { circumference = Circumference; }
 
	public double getSurface() { return surface_area; }
	public double getCircumference() { return surface_area; }
	public void viewData() {
		System.out.println("Kolor: " + color + " Surface Area: " + surface_area + " Circumference: " + circumference);
	}
}