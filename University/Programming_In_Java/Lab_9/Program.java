import java.util.TreeMap;
import java.util.Map;

public class Program {
    public static void main(String[] args) {
        Pack pack = new Pack();
        for(Figure fig : Figure.values()) {
            for (Colour colour : Colour.values()) {
                pack.add((fig.get()), colour.toString());
            }
        }

        System.out.println(pack);
    }
}
