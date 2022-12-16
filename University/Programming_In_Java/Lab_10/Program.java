import java.util.ArrayList;
import java.util.Scanner;
import java.time.LocalDate;
import java.util.stream.*;
import java.util.Comparator;
import java.util.Collections;
import java.io.*;

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
        //fishes.stream().collect(Collectors.groupingBy(Fish::getFishingDate::parseDays))
         fishes.stream().collect(Collectors.collectingAndThen(Collectors.groupingBy(e -> Fish.parseDays(e.getFishingDate().getDayOfWeek().toString())), Collections.sort(fishes, Comparator.comparing(e -> e.getFishingDate().getDayOfWeek().toString())))).values().forEach(System.out::println);    
        //Fish.parseDays(e.getFishingDate().getDayOfWeek().toString())), Comparator.comparing(e -> e.getFishingDate().getDayOfWeek().toString()))).values().forEach(System.out::println);
    }
}
