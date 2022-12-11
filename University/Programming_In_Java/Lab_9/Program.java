import java.util.Collections;
import java.util.ArrayList;
import java.util.Random;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Scanner;

public class Program {

    public static void sortCards(Player player) {
        Collections.sort(player.getHand(), new Comparator<Pair<String, String>>() {
            public int compare(Pair<String, String> s1, Pair<String, String> s2) {
                return toInt(s1) - toInt(s2);
            }
        });
    }

    public static int toInt(Pair<String, String> pair) {
        switch(pair.getFst()) {
            case "Jack": return 11;
            case "Queen": return 12;
            case "King": return 13;
            case "Ace": return 14;
            default: return Integer.parseInt(pair.getFst());
        }
    }

    public static void main(String[] args) {
        Pack pack = new Pack();
        for(Figure fig : Figure.values()) {
            for (Colour colour : Colour.values()) {
                pack.add((fig.get()), colour.toString());
            }
        }
        int numberOfCards = 5;
        System.out.println("\nTalia Bazowa: \n");
        System.out.println(pack);

        Player albert = new Player("Albert", pack.getPack());
        Player robert = new Player("Robert", pack.getPack());
        Collections.shuffle(pack.getPack());
        ArrayList<Pair<String, String>> deletedPairs = new ArrayList<Pair<String, String>>();

        for(int i = 0; i < numberOfCards; ++i) {
            deletedPairs = albert.setHand(pack.getPack(), deletedPairs);
            deletedPairs = robert.setHand(pack.getPack(), deletedPairs);
        }   
        
        sortCards(albert);
        sortCards(robert);

        System.out.println("Reka alberta: " + albert + "\n");
        System.out.println("Reka roberta: " + robert + "\n");

        System.out.println("Czy chcesz wymienic karty graczu Albert?: TAK/NIE");
        while (new Scanner(System.in).next().equals("TAK")) {
            sortCards(albert);
            deletedPairs = albert.exchangeCards(pack.getPack(), deletedPairs);
            System.out.println("\nTwoje nowe karty: " + albert);
            System.out.println("Czy chcesz wymienic karty graczu Albert?: TAK/NIE");
        }

        System.out.println("Czy chcesz wymienic karty graczu Robert?: TAK/NIE");
        while (new Scanner(System.in).next().equals("TAK")) {
            sortCards(albert);
            deletedPairs = albert.exchangeCards(pack.getPack(), deletedPairs);
            System.out.println("\nTwoje nowe karty: " + albert);
            System.out.println("Czy chcesz wymienic karty graczu Albert? Wpisz: TAK/NIE");
        }

        albert.calculateScore();

    }
}
