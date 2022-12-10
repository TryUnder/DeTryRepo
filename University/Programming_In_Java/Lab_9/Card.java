import java.util.TreeMap;

public class Card {
    private TreeMap<String, String> card;

    public Card(String key, String value) {
        this.card.put(key, value);
    }
}
