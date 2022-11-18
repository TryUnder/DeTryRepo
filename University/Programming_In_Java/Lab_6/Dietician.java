public interface Dietician {
    public static final int ALARM = 30;
    
    public double getBMI();
    public int getAge();
    public void setBMI();
    public String getPersonal();
    default public String viewAlarm() {
        return "ALARM! OTYLOSC! ";
    }
}