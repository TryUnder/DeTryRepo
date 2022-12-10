import java.util.ArrayList;
import java.util.TreeMap;
import java.util.Map;

public class Pack {
    private ArrayList<Pair<String, String>> pack;
    
    public Pack() { pack = new ArrayList<Pair<String, String>>(); }
    public void add(String figure, String colour) {
        pack.add(new Pair(figure.toString(), colour.toString()));
    }

    public ArrayList<Pair<String, String>> getPack() { return pack; }

    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        for(int i = 1; i < pack.size() + 1; ++i) {
            stringBuilder.append(pack.get(i-1).getFst() + " " + pack.get(i-1).getSnd() + ", ");
            if (i % 4 == 0)
                stringBuilder.append("\n");
        }
        return stringBuilder.toString();
    }
}
