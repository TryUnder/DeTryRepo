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

        Collections.shuffle(pack.getPack());

        System.out.println("Talia pomieszana: \n");
        System.out.println(pack);

    }
}
