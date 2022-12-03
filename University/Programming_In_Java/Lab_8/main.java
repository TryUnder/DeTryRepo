import java.util.Scanner;
import java.util.ArrayList;

public class main {
    public static void main(String[] args) {
        Board board = new Board();
        System.out.println(board);
        Pair<Integer, Integer> truePair = new Pair<Integer, Integer>(1,2);
        Board.Point truePoint = board.new Point(truePair.getFst(), truePair.getSnd());

        //Board.Point userPoint = board.new Point();
        
        // userPoint.setX(new Scanner(System.in).nextInt());
        // userPoint.setY(new Scanner(System.in).nextInt());
        Pair<Integer, Integer> userPointPair = new Pair<Integer, Integer>();
        ArrayList<Pair<Integer, Integer>> userPointPairList = new ArrayList<Pair<Integer, Integer>>();
        
        ArrayList<Board.Point> userPoint = new ArrayList<Board.Point>();
        for (int i = 0; i < 2; ++i) {
            userPoint.add(board.new Point(new Scanner(System.in).nextInt(), new Scanner(System.in).nextInt()));
            //userPoint.setX(new Scanner(System.in).nextInt());
            //userPoint.setY(new Scanner(System.in).nextInt());
            userPointPairList.add(new Pair(userPoint.get(i).getX(), userPoint.get(i).getY()));
        }
        board.printBoard(userPointPairList);
        if (board.checkGuess(userPointPairList, truePair) == false) {
            board.checkDistance(userPointPairList, truePair);
        } else {
            System.err.println("Punkt trafiony");
        }

    }
}
