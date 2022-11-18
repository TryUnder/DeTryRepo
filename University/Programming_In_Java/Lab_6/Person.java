public class Person implements Dietician {
    private String personalData;
    private int age;
    private double height;
    private double weight;
    private double bmi;

    public Person(String personalData, int age, double height, double weight) {
        this.personalData = personalData;
        this.age = age;
        this.height = height;
        this.weight = weight;
        this.setBMI();
    }
    
    public String toString() {
        return (this.bmi >= 30)
        ? this.viewAlarm() + "Osoba: " + this.personalData + " Wiek: " + age + " Wysokosc: " + height + " Waga: " + weight + " BMI: " + bmi
        : "Osoba: " + this.personalData + " Wiek: " + age + " Wysokosc: " + height + " Waga: " + weight + " BMI: " + bmi;
    }

    public int getAge() {
        return age;
    }

    public double getBMI() {
        return bmi;
    }

    public String getPersonal() {
        return personalData;
    }

    public void setBMI() {
        this.bmi = Math.round(weight / Math.pow((height * 0.01), 2));
    }

}
