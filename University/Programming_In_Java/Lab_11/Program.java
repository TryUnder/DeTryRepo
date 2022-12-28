import java.io.IOException;
import java.nio.file.Paths;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.Map;
import java.util.List;
import java.util.LongSummaryStatistics;
import java.util.TreeMap;
import java.util.function.Function;
import java.util.IntSummaryStatistics;
import java.util.stream.Collectors;
import java.util.regex.Pattern;
import java.util.stream.*;

public class Program {
    public static void main(String[] args) throws IOException {
        Pattern pattern = Pattern.compile("\\PL+");

        Map<String, Long> wordCounts = Files.lines(Paths.get("BajkaCK.txt"))
            .flatMap(lambda -> pattern.splitAsStream(lambda))
            .collect(Collectors.groupingBy(String::toUpperCase,
            TreeMap::new, Collectors.counting()));

        String pureText = new String(Files.readAllBytes(Paths.get("BajkaCK.txt")), StandardCharsets.UTF_8);
        List<String> pureTextList = List.of(pureText.split("\\PL+"));

        wordCounts.entrySet().stream().collect(
            Collectors.groupingBy(entry -> entry.getKey().charAt(0), TreeMap::new,
            Collectors.toList())).forEach((key, value) -> {
                System.out.printf("\nWyrazy na litere %C: ", key);
                value.stream().forEach(word -> System.out.printf("%s (%d) ", word.getKey(), word.getValue()));
            });
        
            //IntSummaryStatistics summary = pureTextList.stream().mapToInt(e -> Integer.parseInt(e)).summaryStatistics();
            //System.out.println(summary.getCount());

            LongSummaryStatistics stats = wordCounts.entrySet().stream().mapToLong(x -> x.getValue()).summaryStatistics();
            System.out.printf("\n\nLaczna liczba slow: %d", stats.getSum());
        }    
}
