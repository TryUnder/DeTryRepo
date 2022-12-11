public enum ValueCards {
    HIGHT_CARD(1),
    TWO_PAIRS(2),
    THREE_OF_A_KIND(3),
    STREIGH(4),
    FLUSH(5),
    FULL_HOUSE(6),
    FOUR_OF_KIND(7),
    STRAIGHT_FLUSH(8);

    private int number;

    ValueCards(int number) {
        this.number = number;
    }

    public int getPoints() { return this.number; }
};