import java.io.IOException;
import java.nio.file.Paths;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.Map;
import java.util.List;
import java.util.TreeMap;
import java.util.stream.Collectors;
import java.util.regex.Pattern;

public class Program {
    public static void main(String[] args) throws IOException {
        Pattern pattern = Pattern.compile("\\PL+");

        Map<String, Long> wordCounts = Files.lines(Paths.get("BajkaCK.txt"))
            .flatMap(lambda -> pattern.splitAsStream(lambda))
            .collect(Collectors.groupingBy(String::toUpperCase,
            TreeMap::new, Collectors.counting()));

        wordCounts.entrySet().stream().collect(
            Collectors.groupingBy(entry -> entry.getKey().charAt(0), TreeMap::new,
            Collectors.toList())).forEach((key, value) -> {
                System.out.printf("\nWyrazy na litere %C: ", key);
                value.stream().forEach(word -> System.out.printf("%s (%d) ", word.getKey(), word.getValue()));
            });
        
            
    }    
}
