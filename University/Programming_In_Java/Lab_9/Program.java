import java.util.TreeMap;
import java.util.Map;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Random;

public class Program {
    public static void main(String[] args) {
        Pack pack = new Pack();
        for(Figure fig : Figure.values()) {
            for (Colour colour : Colour.values()) {
                pack.add((fig.get()), colour.toString());
            }
        }
        System.out.println("\nTalia Bazowa: \n");
        System.out.println(pack);

        //Collections.shuffle(pack.getPack());

        //System.out.println("Talia pomieszana: \n");
        //System.out.println(pack);

        Player albert = new Player("Albert", pack.getPack());
        Player robert = new Player("Robert", pack.getPack());
        Collections.shuffle(pack.getPack());
        ArrayList<Pair<String, String>> deletedPairs = new ArrayList<Pair<String, String>>();
        for(int i = 0; i < 2; ++i) {
            deletedPairs = albert.setHand(pack.getPack(), deletedPairs);
            System.out.println("\nReka alberta: " + albert + "\n");
            System.out.println(pack);
            //robert.setHand(pack.getPack());
        }
        System.out.println("Deleted Pairs: " + deletedPairs);
        //System.out.println(new Random().nextInt(5));
        //pack.getPack().removeIf(e -> e.getSnd() == "HEART");
        //System.out.println(pack);

        //System.out.println("Reka alberta: " + albert + "\n");
        //System.out.println(robert);
        //albert.deleteDuplicates(pack.getPack());
        //robert.deleteDuplicates(pack.getPack());

        //System.out.println("Talia po usunieciu\n" + pack);
    }
}
