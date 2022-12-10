import java.util.TreeMap;
import java.util.Map;
import java.util.Collections;

public class Program {
    public static void main(String[] args) {
        Pack pack = new Pack();
        for(Figure fig : Figure.values()) {
            for (Colour colour : Colour.values()) {
                pack.add((fig.get()), colour.toString());
            }
        }
        System.out.println("Talia Bazowa: \n");
        System.out.println(pack);

        //Collections.shuffle(pack.getPack());

        //System.out.println("Talia pomieszana: \n");
        //System.out.println(pack);

        Player albert = new Player("Albert", pack.getPack());
        Player robert = new Player("Robert", pack.getPack());

        for(int i = 0; i < 5; ++i) {
            albert.setHand(pack.getPack());
            robert.setHand(pack.getPack());
        }
        //pack.getPack().removeIf(e -> e.getSnd() == "HEART");
        //System.out.println(pack);
        //System.out.println(albert);
        //System.out.println(robert);
        albert.deleteDuplicates(pack.getPack());
        robert.deleteDuplicates(pack.getPack());

        System.out.println(pack);
    }
}
