public class Point {
    private double score;
    private int num_rounds;

    public Point(double score, int num_rounds) {
        this.score = score;
        this.num_rounds = num_rounds;
    }

    public double getScore() {
        return score;
    }

    public int getRound() {
        return num_rounds;
    }
}
