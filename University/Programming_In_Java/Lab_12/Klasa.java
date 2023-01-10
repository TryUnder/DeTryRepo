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
        while (!(ktory == 0 && magazynSurowcow >= 120 && magazynSurowcow < 250) || 
            !(ktory == 1 && magazynSurowcow >= 250 && magazynSurowcow < 500) ||
            !(ktory == 2 && magazynSurowcow >= 500)){
            System.out.println(Thread.currentThread().getName() + 
            ": Czekam na materialy, chce wyprodukowac: " + Klasa.getProduct(ktory));
            wait();
            aktualizujSurowce(Klasa.getValue(ktory));
            System.out.println("DZIALA!" + Thread.currentThread().getName());
        }
        System.out.println("DZIALA!" + Thread.currentThread().getName());
    }

    public void aktualizujSurowce(int number) {
        magazynSurowcow -= number;
    }

    public synchronized void transfer(int liczbaSurowcow, int zrodlo) throws InterruptedException {
        magazynSurowcow += liczbaSurowcow;
        surowiec[zrodlo] -= liczbaSurowcow;
        notifyAll();
    }    

    public synchronized void procesDostawcy() throws InterruptedException {
        if (surowiec[0] != 0 && surowiec[1] != 0) {
            Random random = new Random();
            int liczbaSurowcow = random.nextInt(100, 300);
            int zrodlo = random.nextInt(2);
            transfer(liczbaSurowcow, zrodlo);
            System.out.println(Thread.currentThread().getName() + 
                ": Pobralem " + liczbaSurowcow + " jednostek ze zrodla: " + zrodlo + " (w magazynie pozostalo: " +
                surowiec[zrodlo] + " szt.)");
        }
    }
}
