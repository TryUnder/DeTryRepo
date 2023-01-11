import java.util.Random;

public class Klasa {
    private int surowiec[];
    private int magazynSurowcow;
    private int produktA;
    private int produktB;
    private int produktC;

    public Klasa(int surowiec, final int zrodlo) {
        this.surowiec = new int[zrodlo];
        for (int i = 0; i < 2; ++i) {
            this.surowiec[i] = surowiec; 
        }
        this.magazynSurowcow = 0;
        produktA = 0;
        produktB = 0;
        produktC = 0;
    }

    public int getMagazynSurowcow() { return magazynSurowcow; }
    public static String getProduct(int value) { 
        switch(value) {
            case 0: return "Produkt A"; 
            case 1: return "Produkt B";
            case 2: return "Produkt C";
            default: return "Blad";
        }
    }

    public static int getValue(int ktory) {
        switch(ktory) {
            case 0: return 120;
            case 1: return 250;
            case 2: return 500;
            default: return 0;
        }
    }

    public static boolean check(Pair<Integer, Integer> pair) {
        if ((pair.getFst() == 0 && pair.getSnd() < 120) || 
            (pair.getFst() == 1 && pair.getSnd() < 250) ||
            (pair.getFst() == 2 && pair.getSnd() < 500)) {
                return false;
            } else {
                return true;
            }
    }

    public static Integer checkValue(Pair<Integer, Integer> pair) {
        switch(pair.getFst()) {
            case 0: if (pair.getSnd() >= 120) return 120;
            case 1: if (pair.getSnd() >= 250) return 250;
            case 2: if (pair.getSnd() >= 500) return 500;
            default: return 0;
        }
    }

    public synchronized void setProduct(Pair<Integer, Integer> pair) throws InterruptedException {
        switch(pair.getFst()) {
            case 0:
                produktA += 1;
                System.out.println("Magazyn przed w funkcji" + magazynSurowcow);
                magazynSurowcow = magazynSurowcow - 120;
            case 1: 
                produktB += 1;
                System.out.println("Magazyn przed w funkcji" + magazynSurowcow);
                magazynSurowcow = magazynSurowcow - 250;
            case 2: 
                produktC += 1;
                System.out.println("Magazyn przed w funkcji" + magazynSurowcow);
                magazynSurowcow = magazynSurowcow - 500;
        }
    }

    public static Pair<Integer, Integer> setPair(Pair<Integer, Integer> pair) {
        switch(pair.getFst()){
            case 0: return new Pair<Integer, Integer>(pair.getFst(), 120);
            case 1: return new Pair<Integer, Integer>(pair.getFst(), 250);
            case 2: return new Pair<Integer, Integer>(pair.getFst(), 500);
            default: return new Pair<Integer, Integer>(pair.getFst(), 0);
        }
    }
    
    public synchronized void procesProducenta() throws InterruptedException {
        Random random = new Random();
        int ktory = random.nextInt(3);
        Pair<Integer, Integer> pair = new Pair<Integer, Integer>(ktory, 0);
        if (Klasa.check(pair) == false) {
            System.out.println(Thread.currentThread().getName() + 
                ": Czekam na materialy, chce wyprodukowac: " + Klasa.getProduct(pair.getFst()));
            pair = Klasa.setPair(pair);
        }

        for (int i = 0; i<1; ++i){/*  (Klasa.check(pair) == false) {*/
            aktualizujSurowce(pair);
            wait();
            //aktualizujSurowce(Klasa.getValue(pair.getFst()));
            System.out.println("Jestem zablokowany " + Thread.currentThread().getName());
        }
        System.out.println("Jestem odblokowany" + Thread.currentThread().getName());
    }

    public void aktualizujSurowce(Pair<Integer, Integer> pair) throws InterruptedException {
        if (magazynSurowcow >= checkValue(pair) && magazynSurowcow != 0) {
            System.out.println(pair.getSnd());
            //notifyAll();
            setProduct(pair);
            pair.setSnd(0);
        }
        //magazynSurowcow -= number;
        
    }

    public synchronized void pobierzSurowiec(int liczbaSurowcow, int zrodlo) throws InterruptedException {
        surowiec[zrodlo] -= liczbaSurowcow;
    }  

    public synchronized void dostarczSurowiec(int liczbaSurowcow) throws InterruptedException {
        magazynSurowcow += liczbaSurowcow;
        //notifyAll();
    }

    public synchronized void procesDostawcy() throws InterruptedException {
        if (surowiec[0] != 0 && surowiec[1] != 0) {
            Random random = new Random();
            int liczbaSurowcow = random.nextInt(100, 300);
            int zrodlo = random.nextInt(2);
            pobierzSurowiec(liczbaSurowcow, zrodlo);
            System.out.println(Thread.currentThread().getName() + 
                ": Pobralem " + liczbaSurowcow + " jednostek ze zrodla: " + zrodlo + " (w magazynie pozostalo: " +
                surowiec[zrodlo] + " szt.)");
            dostarczSurowiec(liczbaSurowcow);
            System.out.println(Thread.currentThread().getName() +
                ": Dostarczylem " + liczbaSurowcow + " Stan magazynu surowcow to " + magazynSurowcow);
        }
    }
}
