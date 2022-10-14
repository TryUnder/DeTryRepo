
public class Human {
	private int age;
	private double weight;
	private double height;
	private String name;
	private String gender;
	
	public Human() {
		age = 0;
		weight = 0;
		height = 0;
		name = "none";
		gender = "none";
	}
	
	public Human(String Name, int Age, double Weight, double Height, String Gender) {
		age = Age;
		weight = Weight;
		height = Height;
		name = Name;
		gender = Gender;
	}
	
	public int getAge() { return age; }
	public double getWeight() { return weight; }
	public double getHeight() { return height; }
	public String getName() { return name; }
	public String getGender() { return gender; }
	
	public void setWeight(double Weight) { weight = Weight; }
	public void setHeight(double Height) { height = Height; }
	
	public void viewAge() { System.out.println("Age: " + age); }
	public void viewName() { System.out.println("Name: " + name); }

    public static void showHumanData(Human[] human1) {
        for(Human humans : human1){
            System.out.println("Personalia: " + humans.getName() + " Wiek: " + humans.getAge()
                                + " Waga: " + humans.getWeight() + " Plec: " + humans.getGender()
								+ " Wysokosc: " + humans.getHeight());
        }
    }
}