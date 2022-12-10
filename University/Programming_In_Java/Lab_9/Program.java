import java.util.TreeMap;
import java.util.Map;

public class Program {
    public static void main(String[] args) {
        for(Figure fig : Figure.values()) {
            for (Colour colour : Colour.values()) {
                System.out.println(fig + " " + colour);
            }
        }
    }
}
