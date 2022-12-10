public class Pair<T, U> {
    T first;
    U second;

    public Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    public Pair() {}

    public T getFst() { return first; }
    public U getSnd() { return second; }
    public void setFst(T first) { this.first = first; }
    public void setSnd(U second) { this.second = second; }
    public void add(T first, U second) { this.first = first; this.second = second; }

    public boolean compare(Pair<T,U> obj) {
        return (this.getFst() == obj.getFst() && this.getSnd() == obj.getSnd()) ? true : false;
    }
}
