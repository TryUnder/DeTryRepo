public class Animal implements Dietician {
    private String name;
    private double weight;
    private int age;
    private double bmi;

    public Animal(String name, double weight, int age) {
        this.name = name;
        this.weight = weight;
        this.age = age;
        this.setBMI();
    }

    public String toString() {
        return name +  " " + weight + " " + age + " " + bmi;
    }

    public double getBMI() {
        return bmi;
    }

    public void setBMI() {
        this.bmi = 2;
    }

    public int getAge() {
        return age;
    }

    public double getWeight() {
        return weight;
    }
}
