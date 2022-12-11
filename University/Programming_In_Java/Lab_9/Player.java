import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Random;

public class Player {
    private String name;
    private LinkedList<Pair<String, String>> hand;
    private int rand1;
    private int rand2;

    public Player(String name, ArrayList<Pair<String, String>> pack) {
        this.name = name;
        hand = new LinkedList<>();
        rand1 = 6;
        rand2 = 4;
    }

    public LinkedList<Pair<String, String>> getHand() { return hand; }

    public ArrayList<Pair<String, String>> setHand(ArrayList<Pair<String, String>> pack, ArrayList<Pair<String, String>> deletedPairs) {
        hand.add(new Pair(pack.get(new Random().nextInt(rand1)).getFst(), pack.get(new Random().nextInt(rand2)).getSnd()));
        int t = 0;
        for (int i = 0; i < hand.size(); ++i) {
            for (int j = 0; j < deletedPairs.size(); ++j) {
                if (hand.get(i).compare(deletedPairs.get(j)) == true) {
                    t++;
                    if (t == deletedPairs.size() + 1){
                        while(hand.get(i).compare(deletedPairs.get(j)) == true) {
                            hand.removeLast();
                            hand.add(new Pair(pack.get(new Random().nextInt(rand1)).getFst(), pack.get(new Random().nextInt(rand2)).getSnd()));
                        }
                    }
                }
            }
        }
        Pair<Boolean, Integer> pair = this.findDuplicates(pack, deletedPairs);
        if (pair.getFst() == true) {
            this.deleteDuplicates(pack, pair.getSnd());
        }
        return deletedPairs;
    }

    public Pair<Boolean, Integer> findDuplicates(ArrayList<Pair<String, String>> pack, ArrayList<Pair<String, String>> deletedPairs) {
        for (int i = 0; i < pack.size(); ++i) {
            for (int j = 0; j < hand.size(); ++j) {
                if (pack.get(i).compare(hand.get(j)) == true) {
                    deletedPairs.add(pack.get(i));
                    return new Pair(true, i);
                }
            }
            if (i == pack.size() - 1) {
                return new Pair(false, i);
            }
        }
        return new Pair(false, 0);
    }

    public void deleteDuplicates(ArrayList<Pair<String, String>> pack, int i) {
        pack.remove(i);
    }

    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        hand.forEach(element -> stringBuilder.append(element.getFst() + " " + element.getSnd() + ", "));
        return stringBuilder.toString();
    }
}
