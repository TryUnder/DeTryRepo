public abstract class Animal implements Dietician {
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
        return ((int)this.getBMI() >= 30) 
        ? viewAlarm() + this.name + " Age: " + this.age + " Weight: " + this.weight + " BMI: " + this.bmi
        : "Zwierze: " + this.name + " Age: " + this.age + " Weight: " + this.weight + " BMI: " + this.bmi;
    }

    public double getBMI() {
        return bmi;
    }

    public String getPersonal() {
        return name;
    }

    public void setBMI(double bmi) {
        this.bmi = Math.round(bmi);
    }

    public int getAge() {
        return age;
    }

    public double getWeight() {
        return weight;
    }   
}
