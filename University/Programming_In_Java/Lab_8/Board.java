import java.lang.StringBuilder;
import java.util.ArrayList;

public class Board {
    
    class Point {
        private int x;
        private int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public Point() {
            this.x = 0;
            this.y = 0;
        }

        public void setX(int x) { this.x = x; }
        public void setY(int y) { this.y = y; }
        public int getX() { return x; }
        public int getY() { return y;}

        public String toString() {
            return "X:" + x + " Y:" + y; 
        }
    }

    public void printBoard(ArrayList<Pair<Integer, Integer>> userPointPairList) {
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                for (int k = 0; k < userPointPairList.size(); ++k) {
                    if (i+1 != userPointPairList.get(k).getFst() || j+1 != userPointPairList.get(k).getSnd()) {
                        stringBuilder.append("(" + (i+1) + "," + (j+1) + ")" + " ");
                    } else {
                        stringBuilder.append("  X   ");
                    }
                }
            }
            stringBuilder.append("\n");
        }
        System.out.println(stringBuilder.toString());
    }

    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("Bazowa Plansza\n\n");
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                stringBuilder.append("(" + (i+1) + "," + (j+1) + ")" + " ");
            }
            stringBuilder.append("\n");
        }
        return stringBuilder.toString();
    }
}
