import java.util.Scanner;
import java.util.ArrayList;

public class main {
    public static void main(String[] args) {
        Board board = new Board();
        System.out.println(board);
        Board.Point truePoint = board.new Point(1,2);

        Board.Point userPoint = board.new Point();
        
        // userPoint.setX(new Scanner(System.in).nextInt());
        // userPoint.setY(new Scanner(System.in).nextInt());
        Pair<Integer, Integer> userPointPair = new Pair<Integer, Integer>();
        ArrayList<Pair<Integer, Integer>> userPointPairList = new ArrayList<Pair<Integer, Integer>>();
        for (int i = 0; i < 2; ++i) {
            //userPoint.setX(new Scanner(System.in).nextInt());
            //userPoint.setY(new Scanner(System.in).nextInt());
            //userPointPair.add(userPoint.getX(), userPoint.getY());
            //userPointPairList.add(userPointPair);
        }
        System.out.println(userPointPairList.get(0).getFst().toString() + userPointPairList.get(0).getSnd().toString());
        System.out.println(userPointPairList.get(1).getFst().toString() + userPointPairList.get(1).getSnd().toString());
        //board.printBoard(userPointPairList);
    }
}
