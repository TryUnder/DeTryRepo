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
import java.util.DoubleSummaryStatistics;
import java.util.IntSummaryStatistics;
import java.util.stream.Collectors;
import java.util.regex.Pattern;
import java.util.stream.*;
import java.util.function.Function;

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
            LongSummaryStatistics stats2 = wordCounts.entrySet().stream().mapToLong(x -> x.getKey().length()).summaryStatistics();
            LongSummaryStatistics stats3 = wordCounts.entrySet().stream().mapToLong(x -> x.getKey().length()).distinct().summaryStatistics();
            DoubleSummaryStatistics avg = wordCounts.entrySet().stream().mapToDouble(x -> x.getValue() * x.getKey().length()).summaryStatistics();
            System.out.printf("\n\nLaczna liczba slow: %d\nLiczba roznych slow: %d\nMinimalna dlugosc slowa: %d\nMaksymalna dlugosc slowa: %d\nSrednia dlugosc slow: %f",
                             stats.getSum(), stats3.getSum(), stats2.getMin(), stats2.getMax(), avg.getSum()/stats.getSum());
        
        
            System.out.println("\n\nPierwsze 10 slow tekstu(+ dlugosc poszczegolnych slow): ");
            pureTextList.stream().limit(10).forEach(e -> System.out.print(e + " "));
            System.out.println();
            pureTextList.stream().limit(10).forEach(e -> System.out.print(e.length() + " "));
            System.out.println();
            System.out.println("\nOstatnie 10 slow tekstu(+ dlugosc poszczegolnych slow): ");
            pureTextList.stream().skip(stats.getSum() - 10).forEach(e -> System.out.print(e + " "));    
            System.out.println();
            pureTextList.stream().skip(stats.getSum() - 10).forEach(e -> System.out.print(e.length() + " "));        
        
            System.out.println("\n");
            System.out.printf("Dlugosc Liczba_wystapien\n");
            pureTextList.stream().collect(Collectors.groupingBy(e -> e.length(), Collectors.counting()))
                .forEach((key, value) -> {
                    System.out.println(key + " " + value);
                });

            System.out.println("\nSuma(laczna liczba liter): ");
            
            //System.out.println(IntStream.range(pureTextList.stream()., 10).sum());
            //pureTextList.stream().map(e -> e.replaceAll(", ", "")).takeWhile(e -> e.length() > 0);

            System.out.println(pureTextList.stream().mapToInt(String::length).sum());
    }    
}
