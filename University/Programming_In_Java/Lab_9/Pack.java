import java.util.TreeMap;
import java.util.Map;

public class Pack {
    private TreeMap<String, String> pack;
    
    public Pack() {}
    void add(String key, String value) {
        pack.put(key, value);
    }

    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        for(Map.Entry<String, String> entry : pack.entrySet()) {
            stringBuilder.append(entry.getKey() + " " + entry.getValue() + "\n");
        }
        return stringBuilder.toString();
    }
}
