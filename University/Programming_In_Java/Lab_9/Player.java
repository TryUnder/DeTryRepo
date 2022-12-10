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
        Random random = new Random();
        int rand = random.nextInt(6);
        int rand2 = random.nextInt(4);
        hand.add(new Pair(pack.get(rand).getFst(), pack.get(rand2).getSnd()));
        pack.removeIf(e -> e.getFst() == hand.get(rand).getFst() && e.getSnd() == hand.get(rand2).getSnd());
    }

    public void deleteDuplicates(ArrayList<Pair<String, String>> pack) {
        
    }

    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        hand.forEach(element -> stringBuilder.append(element.getFst() + " " + element.getSnd() + ", "));
        return stringBuilder.toString();
    }
}
