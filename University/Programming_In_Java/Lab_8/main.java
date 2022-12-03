import java.util.Scanner;
import java.util.ArrayList;

public class main {
    public static void main(String[] args) {
        Board board = new Board();
        System.out.println(board);
        Pair<Integer, Integer> truePair = new Pair<Integer, Integer>(1,2);
        Board.Point truePoint = board.new Point(truePair.getFst(), truePair.getSnd());

        Pair<Integer, Integer> userPointPair = new Pair<Integer, Integer>();
        ArrayList<Pair<Integer, Integer>> userPointPairList = new ArrayList<Pair<Integer, Integer>>();
        
        ArrayList<Board.Point> userPoint = new ArrayList<Board.Point>();
        ArrayList<Point> point = new ArrayList<Point>();
        for (int i = 0; i < 3; ++i) {
        System.out.println("Runda nr: ");
        System.out.println("Wprowadz wspolrzedne punktu A");
        userPoint.add(board.new Point(new Scanner(System.in).nextInt(), new Scanner(System.in).nextInt()));
        userPointPairList.add(new Pair(userPoint.get(i).getX(), userPoint.get(i).getY()));
        System.out.println("Wprowadz wspolrzedne punktu B");
        userPoint.add(board.new Point(new Scanner(System.in).nextInt(), new Scanner(System.in).nextInt()));
        userPointPairList.add(new Pair(userPoint.get(i).getX(), userPoint.get(i).getY()));
        board.printBoard(userPointPairList);
        point.add(new Point((i+1), 1));
        if (board.checkGuess(userPointPairList, truePair) == false) {
            board.checkDistance(userPointPairList, truePair);
            } else {
                System.out.println("Punkt trafiony");
            }
        }
    }
}
