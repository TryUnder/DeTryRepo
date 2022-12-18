import java.util.ArrayList;
import java.util.Scanner;
import java.time.LocalDate;
import java.util.stream.*;
import java.util.Comparator;
import java.util.LinkedHashMap;
import java.util.Collections;
import java.io.*;
import java.util.Map;
import java.util.List;

public class Program {
    
    public static Scanner openFile(File file) {
        Scanner scanner;
        try {
            scanner = new Scanner(file);
        } catch(FileNotFoundException e) {
            scanner = null;
            e.printStackTrace();
        }
        return scanner;
    }

    public static void parseForInfo(ArrayList<Fish> fishes, Scanner scanner) {
        while(scanner.hasNext()) {
            int day = scanner.nextInt();
            int month = scanner.nextInt();
            int year = scanner.nextInt();
            LocalDate date = LocalDate.of(year, month, day);
            fishes.add(new Fish(date, scanner.next(), scanner.next(), scanner.nextDouble(), Double.parseDouble(scanner.next())));
        }
    }

    public static void main(String[] args) {
        ArrayList<Fish> fishes = new ArrayList<Fish>();
        File file = new File("fishing.txt");
        Scanner scanner = openFile(file);
        parseForInfo(fishes, scanner);

        System.out.println("1.Dane wszystkich polowow: \n");
        fishes.stream().forEach(System.out::println);

        System.out.println("\n2.Dane wszystkich polowow kolejno po wedkarzu i dacie polowu: \n");
        fishes.stream().sorted(Comparator.comparing(Fish::getAnglerData).thenComparing(Fish::getFishingDate)).forEach(System.out::println);
    
        System.out.println("\n3.Unikatowe nazwy gatunkow ryb: \n");
        fishes.stream().map(Fish::getSpecie).distinct().forEach(System.out::println);

        System.out.println("\n4.Dane polowow szczupakow o wadze od 1 do 2 kg. (od najnowszego polowu): \n");
        fishes.stream().filter(e -> e.getWeight() > 1.0 && e.getWeight() < 2.0 && e.getSpecie().equals("szczupak")).sorted(Comparator.comparing(Fish::getFishingDate).reversed()).forEach(System.out::println);
    
        System.out.println("\n5.Polowy pogrupowane po dniu tygodnia: \n");
        
        fishes.stream()
            .sorted(Comparator
                .comparing(e -> e.getFishingDate().getDayOfWeek()))
                    .collect(Collectors.groupingBy(e -> e.getFishingDate().getDayOfWeek().toString(),
                                                             LinkedHashMap::new, Collectors.toList()))
                        .values().forEach(System.out::println);

        System.out.println("\n6.Informacje z zakresu ile ryb o dlugosci powyzej 50cm zlowil dany wedkarz: \n");
    
        fishes.stream()
            .filter(e -> e.getLength() > 50.0)
                .collect(Collectors
                    .groupingBy(e -> e.getAnglerData(), Collectors.counting()))
                        .forEach((key, value) -> System.out.println("Rybak: " + key + " zlapal: " + value + " rybki"));
    
        System.out.println("\n7.Informacje o lacznej wadze zlowionych szczupakow i sandaczy: \n");

        System.out.println("Laczna waga wynosi: " + fishes.stream()
            .filter(e -> (e.getSpecie().equals("szczupak") || e.getSpecie().equals("sandacz")))
                .mapToDouble(e -> { return e.getWeight(); }).sum());
    
        System.out.println("\n8.Informacje o sredniej dlugosci ryb zlowionych w poszczegolne dni tygodnia" +
                                "uzupelnione danymi z zakresu ile zlowiono w danym dniu ryb i ile wynosily najmniejsze" +
                                "i najwieksze odnotowane w danym dniu wartosci dlugosci ryb\n");
        System.out.println("\nSrednie dlugosci ryb zlowionych w poszczegolne dni tygodnia: \n");
    
        Map<Object, List<Fish>> grouping2 = fishes.stream()
            .sorted(Comparator.comparing(e -> e.getFishingDate().getDayOfWeek()))
                .collect(Collectors.groupingBy(e -> Fish.parseDaysString(e.getFishingDate().getDayOfWeek().toString()),
                LinkedHashMap::new, Collectors.toList()));

                    grouping2.forEach((key, value) -> {
                        System.out.printf("Srednia dlugosc zlowionych ryb w: %s wynosi: %.2f kg, liczba ryb: %d waga min: %.2f kg waga max: %.2f kg %n", 
                        key, 
                        value.stream().mapToDouble(e -> { return e.getLength(); }).average().getAsDouble(),
                        value.stream().count(),
                        value.stream().mapToDouble(e -> { return e.getWeight(); }).min().getAsDouble(),
                        value.stream().mapToDouble(e -> { return e.getWeight(); }).max().getAsDouble()
            );
        }); 
    }       
}
