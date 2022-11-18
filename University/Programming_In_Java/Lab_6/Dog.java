public class Dog extends Animal {
    private int factor;
    
    public Dog(String name, double weight, int age, int factor) {
        super(name, weight, age);
        this.factor = factor;
        this.setBMI();
    }

    public String toString() {
        return super.toString() + " Factor: " + this.factor;
    }

    public void setBMI() {
        double bmi = 0;
        switch (this.factor) {
            case 1:
                bmi = Math.pow(this.getWeight(), 2) * this.getWeight();
                break;
            case 2:
                bmi = Math.pow(this.getWeight(), 2);
                break;
            case 3:
                bmi = this.getWeight() + 10;
                break;
            default:
                break;
        }
        if (bmi != 0) {
            super.setBMI(bmi);
        }
    }
}
