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

    public int get() { return this.number; }
 };
