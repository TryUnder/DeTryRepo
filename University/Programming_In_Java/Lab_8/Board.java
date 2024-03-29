import java.lang.StringBuilder;
import java.util.ArrayList;
import java.util.Collections;
import java.lang.Math;

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
        public int getY() { return y; }

        public String toString() {
            return "X:" + x + " Y:" + y; 
        }
    }

    public void printBoard(ArrayList<Pair<Integer, Integer>> userPointPairList) {
        StringBuilder stringBuilder = new StringBuilder();
        String temp;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) { loop:
                for (int k = 0; k < userPointPairList.size(); ++k) {
                    temp = "(" + (i+1) + "," + (j+1) + ")" + " ";
                    if (i+1 == userPointPairList.get(k).getFst() && j+1 == userPointPairList.get(k).getSnd()) {
                        temp = "  X   ";
                        stringBuilder.append(temp);
                        break loop;
                    }
                    if (k == userPointPairList.size() - 1)
                        stringBuilder.append(temp);
                }
            }
            stringBuilder.append("\n");
        }
        System.out.println(stringBuilder.toString());
    }

    public boolean checkGuess(ArrayList<Pair<Integer, Integer>> userPointPairList, Pair<Integer, Integer> truePoint) {
        for (Pair<Integer, Integer> pair : userPointPairList) {
            if (pair.compare(truePoint) == true) {
                return true;
            }
        }
        return false;
    }

    public int checkDistance(ArrayList<Pair<Integer, Integer>> userPointPairList, Pair<Integer, Integer> truePoint) {
        ArrayList<Integer> distance = new ArrayList<Integer>();   
        ArrayList<Integer> localDistance = new ArrayList<Integer>();   
        for (int i = 0; i < userPointPairList.size(); ++i) {
            distance.add(Math.abs(userPointPairList.get(i).getFst() - truePoint.getFst()) + Math.abs(userPointPairList.get(i).getSnd() - truePoint.getSnd()));
        }

        localDistance.add(Math.abs(userPointPairList.get(userPointPairList.size() - 1).getFst() - truePoint.getFst()) + Math.abs(userPointPairList.get(userPointPairList.size() - 1).getSnd() - truePoint.getSnd()));
        localDistance.add(Math.abs(userPointPairList.get(userPointPairList.size() - 2).getFst() - truePoint.getFst()) + Math.abs(userPointPairList.get(userPointPairList.size() - 2).getSnd() - truePoint.getSnd()));

        System.out.println("Minimalna odleglosc wynosi: " + Collections.min(distance));
        System.out.print("Lokalna minimalna odleglosc wynosi: " + Collections.min(localDistance));
        if (localDistance.get(localDistance.size() - 1) == localDistance.get(localDistance.size() - 2)) {
            System.out.println(" - Punkty sa w takiej samej odleglosci");
        } else if (localDistance.get(localDistance.size() - 1) < localDistance.get(localDistance.size() - 2)) {
            System.out.println(" - Blizej jest punkt A");
        } else {
            System.out.println(" - Blizej jest punkt B");
        }
        return Collections.min(localDistance); 
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
