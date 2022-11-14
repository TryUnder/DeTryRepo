public class Dog extends Animal {
    private int factor;
    
    public Dog(String name, double weight, int age, int factor) {
        super(name, weight, age);
        this.factor = factor;
        this.setBMI();
    }

    public String toString() {
        return "Dog";
    }

    public void setBMI() {
        double bmi;
        switch (this.factor) {
            case 1:
                bmi = Math.pow(this.getWeight(),2) * this.getWeight();
                 
        }
    }
}
