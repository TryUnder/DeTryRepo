import java.util.TreeMap;
import java.util.Map;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Random;
import java.util.Comparator;
import java.util.LinkedList;
public class Program {

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

        // System.out.println("Reka alberta: " + albert + "\n");
        // System.out.println("Reka roberta: " + robert + "\n");
        // Collections.sort(albert.getHand(), new Comparator<Pair<String, String>>() {
        //     public int compare(Pair<String, String> s1, Pair<String, String> s2) {
        //         return toInt(s1) - toInt(s2);
        //     }
        // });

        // Collections.sort(robert.getHand(), (e1, e2) -> {
        //     return toInt(e1) - toInt(e2);
        // });
        System.out.println("Reka alberta: " + albert + "\n");
        System.out.println("Reka roberta: " + robert + "\n");
        //System.out.println(pack);
    }
}
