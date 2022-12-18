import java.time.LocalDate;

public class Fish {
    private LocalDate fishingDate;
    private String fishSpecie;
    private String anglerData;
    private double fishWeight;
    private double fishLength;
    
    public Fish(LocalDate fishingDate,
                String fishSpecie, String anglerData,
                double fishWeight, double fishLength) {    
        this.fishingDate = fishingDate;
        this.fishSpecie = fishSpecie;
        this.anglerData = anglerData;
        this.fishWeight = fishWeight;
        this.fishLength = fishLength;
    }

    public String getAnglerData() { return anglerData; }
    public LocalDate getFishingDate() { return fishingDate; }
    public String getSpecie() { return fishSpecie; }
    public double getWeight() { return fishWeight; }
    public double getLength() { return fishLength; }

    public static String parseDaysString(String dayOfTheWeek) {
        switch(dayOfTheWeek) {
            case "MONDAY"     : return "PONIEDZIALEK";
            case "TUESDAY"    : return "WTOREK";
            case "WEDNESDAY"  : return "SRODA";
            case "THURSDAY"   : return "CZWARTEK";
            case "FRIDAY"     : return "PIATEK";
            case "SATURDAY"   : return "SOBOTA";
            case "SUNDAY"     : return "NIEDZIELA";
            default           : return "BLAD";
        }
    }

    @Override public String toString() {
        return "Polow: " + fishingDate.toString() + " (" + parseDaysString(fishingDate.getDayOfWeek().toString()) + ") gatunek: " + fishSpecie
               + " wedkarz: " + anglerData + " waga: " + fishWeight + " dlugosc: " + fishLength;
    }
}
