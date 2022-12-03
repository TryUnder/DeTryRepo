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
        for (int j = 0; j < 4; ++j) {
            userPoint.add(board.new Point(new Scanner(System.in).nextInt(), new Scanner(System.in).nextInt()));
            userPointPairList.add(new Pair(userPoint.get(j).getX(), userPoint.get(j).getY()));
            board.printBoard(userPointPairList);
            if (board.checkGuess(userPointPairList, truePair) == false) {
                board.checkDistance(userPointPairList, truePair);
            } else {
                System.out.println("Punkt trafiony");
            }
        }
        

    }
}
