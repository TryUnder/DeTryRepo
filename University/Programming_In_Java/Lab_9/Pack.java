import java.util.ArrayList;
import java.util.TreeMap;
import java.util.Map;

public class Pack {
    private ArrayList<Pair<String, String>> pack;
    
    public Pack() { pack = new ArrayList<Pair<String, String>>(); }
    public void add(String figure, String colour) {
        pack.add(new Pair(figure.toString(), colour.toString()));
    }

    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        for(Pair<String, String> pair : pack) {
            stringBuilder.append(pair.getFst() + " " + pair.getSnd() + "\n");
        }
        return stringBuilder.toString();
    }
}
