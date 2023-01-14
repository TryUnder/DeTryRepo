import java.util.Random;

public class Supplier extends Thread {
    Resources resources;
    int supplierNum;
    Random rand = new Random();
 
    Supplier(Resources res, int supplierNum) {
        resources = res;
        this.supplierNum = supplierNum;
    }
 
    public void run() {
        while (true) {
            try {
                resources.sourceASem.acquire();
                resources.sourceBSem.acquire();
                resources.resourceSem.acquire();
                // wybor zrodla
                int sourceNum = rand.nextInt(2) + 1;
                int resourceAmount = rand.nextInt(201) + 100;
                // czy jest odpowiednia ilosc surowcow potrzebnych do produkcji produktu
                if ((sourceNum == 1 && resources.sourceACurrent < resourceAmount) || (sourceNum == 2 && resources.sourceBCurrent < resourceAmount)) {
                    System.out.println("<-> Watek[" + Thread.currentThread().getName() + "] Czekam na materialy w ilosci " + resourceAmount + " sztuk.  (W magazynie jest): " + resources.resourceStorageCurrent + ")");
                    resources.sourceASem.release();
                    resources.sourceBSem.release();
                    resources.resourceSem.release();
                    Thread.sleep(rand.nextInt(1000) + 500);
                    continue;
                }
                if (sourceNum == 1) {
                    resources.sourceACurrent -= resourceAmount;
                    System.out.println("Watek[" + Thread.currentThread().getName() + "-" + Thread.currentThread().getId() + "]: Pobralem " + resourceAmount + " jednostek z magazynu 0 (" + resources.sourceACurrent + " zostalo)");
                } else {
                    resources.sourceBCurrent -= resourceAmount;
                    System.out.println("Watek[" + Thread.currentThread().getName() + "-" + Thread.currentThread().getId() + "]: Pobralem " + resourceAmount + " jednostek z magazynu 1 (" + resources.sourceBCurrent + " zostalo)");
                }
                resources.resourceStorageCurrent += resourceAmount;
                System.out.println("Watek[" + Thread.currentThread().getName() + "-" + Thread.currentThread().getId() + "]: Dostarczylem " + resourceAmount + " sztuk. Stan materialow: " + resources.resourceStorageCurrent + " sztuk.");
                resources.sourceASem.release();
                resources.sourceBSem.release();
                resources.resourceSem.release();
                Thread.sleep(rand.nextInt(1000) + 500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}