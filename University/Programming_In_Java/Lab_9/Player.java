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
        hand.add(new Pair(pack.get(new Random().nextInt(6)).getFst(), pack.get(new Random().nextInt(4)).getSnd()));
        pack.remove(hand.getLast());
    }

    public void deleteDuplicates(ArrayList<Pair<String, String>> pack) {
        for (int i = 0; i < pack.size(); ++i) {
            for (int j = 0; j < hand.size(); ++j) {
                pack.removeIf(e -> e.getFst() == hand.get(i).getFst() && 
                e.getSnd() == e.getSnd() );
                
            }
        }
    }

    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        hand.forEach(element -> stringBuilder.append(element.getFst() + " " + element.getSnd() + ", "));
        return stringBuilder.toString();
    }
}
