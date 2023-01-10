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
    
    public synchronized void procesProducenta() throws InterruptedException {
        Random random = new Random();
        int ktory = random.nextInt(3);
        Pair<Integer, Integer> pair = new Pair<Integer, Integer>(ktory, magazynSurowcow);
        if ((pair.getFst() == 0 && pair.getSnd() < 120) || 
            (pair.getFst() == 1 && pair.getSnd() < 250) ||
            (pair.getFst() == 2 && pair.getSnd() < 500)){
            System.out.println(Thread.currentThread().getName() + 
            ": Czekam na materialy, chce wyprodukowac: " + Klasa.getProduct(pair.getFst()));
            wait();
            aktualizujSurowce(Klasa.getValue(pair.getFst()));
            //System.out.println("DZIALA!" + Thread.currentThread().getName());
        }
        System.out.println("DZIALA!" + Thread.currentThread().getName());
    }

    public void aktualizujSurowce(int number) {
        System.out.println("xxx");
        magazynSurowcow -= number;
    }

    public synchronized void pobierzSurowiec(int liczbaSurowcow, int zrodlo) throws InterruptedException {
        surowiec[zrodlo] -= liczbaSurowcow;
    }  

    public synchronized void dostarczSurowiec(int liczbaSurowcow) {
        magazynSurowcow += liczbaSurowcow;
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
