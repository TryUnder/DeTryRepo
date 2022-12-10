import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Random;

public class Player {
    private String name;
    private LinkedList<Pair<String, String>> hand;

    public Player(String name, ArrayList<Pair<String, String>> pack) {
        this.name = name;
        hand = new LinkedList<>();
    }

    public void setHand(ArrayList<Pair<String, String>> pack) {
        hand.add(new Pair(pack.get(new Random().nextInt(6)).getFst(), pack.get(new Random().nextInt(6)).getSnd()));
        pack.remove(hand.getLast());
    }

    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        hand.forEach(element -> stringBuilder.append(element.getFst() + " " + element.getSnd() + ", "));
        return stringBuilder.toString();
    }
}
