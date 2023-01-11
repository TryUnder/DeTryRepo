public class Program {
    public static void main(String[] args) {
        final int zrodlo = 2;
        Klasa klasa = new Klasa(50000, zrodlo);
        Runnable producent = () -> {
            try {
                klasa.procesProducenta();
            } catch (InterruptedException e) {}
        };

        Runnable dostawca = () -> {
            try {
                klasa.procesDostawcy();
            }catch(InterruptedException e) {}
        };

        Thread thread1 = new Thread(producent);
        Thread thread2 = new Thread(producent);

        Thread thread3 = new Thread(dostawca);
        Thread thread4 = new Thread(dostawca);
        Thread thread5 = new Thread(dostawca);

        thread1.setName("Producent 1");
        thread2.setName("Producent 2");

        thread3.setName("Dostawca 1");
        thread4.setName("Dostawca 2");
        thread5.setName("Dostawca 3");

        thread1.start();
        thread3.start();
        thread2.start();

        thread4.start();
        thread5.start();

    }
}
