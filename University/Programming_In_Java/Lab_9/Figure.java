public enum Figure {  
    N9(9),
    N10(10),
    Jack(11),
    Queen(12),
    King(13),
    Ace(14);

    private int number;

    Figure(int number) {
        this.number = number;
    }

    public String get() { if (this.number <= 10) return Integer.toString(this.number);
                       else return get(number).toString(); }
    public static Figure get(int number) { switch (number) {
        case 11:
            return Jack;
        case 12:
            return Queen;
        case 13:
            return King;
        case 14:
            return Ace;
        default:
            return Ace;
    }}
 };
