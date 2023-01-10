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
    
    public synchronized void procesProducenta() throws InterruptedException {
        Random random = new Random();
        int ktory = random.nextInt(3);
        while (magazynSurowcow < 120) {
            System.out.println(Thread.currentThread().getName() + 
            ": Czekam na materialy, chce wyprodukowac: " + Klasa.getProduct(ktory));
            wait();
        }
        System.out.println("DZIALA!");
    }

    public void transfer(int liczbaSurowcow, int zrodlo) {
        magazynSurowcow += liczbaSurowcow;
        surowiec[zrodlo] -= liczbaSurowcow;
    }    

    public void procesDostawcy() {
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
