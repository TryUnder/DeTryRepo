public interface Dietician {
    public static final int ALARM = 30;
    
    public double getBMI();
    public int getAge();
    public void setBMI();
    default public String viewAlarm() {
        return "SOS";
    }
}