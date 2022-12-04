import java.util.Scanner;
import java.util.ArrayList;
import java.util.Random;

public class main implements GameScoring {

    public static double sumPoints(ArrayList<Point> points) {
        double score = 0.0;
        for (int i = 0; i < points.size(); ++i) {
            score += points.get(i).getScore();
        }
        return score;
    }

    public static void main(String[] args) {
        Board board = new Board();
        System.out.println(board);
        Pair<Integer, Integer> truePair = new Pair<Integer, Integer>((int)((Math.random() * (8 - 1)) + 1), (int)((Math.random() * (8 - 1)) + 1));
        Board.Point truePoint = board.new Point(truePair.getFst(), truePair.getSnd());

        Pair<Integer, Integer> userPointPair = new Pair<Integer, Integer>();
        ArrayList<Pair<Integer, Integer>> userPointPairList = new ArrayList<Pair<Integer, Integer>>();
        
        ArrayList<Board.Point> userPoint = new ArrayList<Board.Point>();
        ArrayList<Point> points = new ArrayList<Point>();
        double score = 0.0;
        for (int i = 0; i < 5; ++i) {
            System.out.println("Runda nr: " + (i+1));
            System.out.println("Wprowadz wspolrzedne punktu A");
            userPoint.add(board.new Point(new Scanner(System.in).nextInt(), new Scanner(System.in).nextInt()));
            userPointPairList.add(new Pair(userPoint.get(userPoint.size() - 1).getX(), userPoint.get(userPoint.size() - 1).getY()));
            System.out.println("Wprowadz wspolrzedne punktu B");
            userPoint.add(board.new Point(new Scanner(System.in).nextInt(), new Scanner(System.in).nextInt()));
            userPointPairList.add(new Pair(userPoint.get(userPoint.size() - 1).getX(), userPoint.get(userPoint.size() - 1).getY()));
            board.printBoard(userPointPairList);
            if (board.checkGuess(userPointPairList, truePair) == false) {
                int distance = board.checkDistance(userPointPairList, truePair);
                points.add(new Point(10 - distance, (i + 1)));
            } else {
                points.add(new Point(scorePoints[i], (i + 1)));
                System.out.println("Punkt trafiony w rundzie nr " + points.get(points.size() - 1).getRound() + " - Koniec gry");
                score = sumPoints(points);
                System.out.println("Zdobyto: " + score + " punktow");
                return;
            }
        }
        score = sumPoints(points);
        System.out.println("Nie udalo sie wygrac gry.\n Zdobyto: " + score + " punktow");
    }
}
