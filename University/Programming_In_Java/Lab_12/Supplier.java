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
                // select a random source
                int sourceNum = rand.nextInt(2) + 1;
                int resourceAmount = rand.nextInt(201) + 100;
                // check if there is enough resources in the source
                if ((sourceNum == 1 && resources.sourceACurrent < resourceAmount) || (sourceNum == 2 && resources.sourceBCurrent < resourceAmount)) {
                    System.out.println("<-> D:Thread[" + Thread.currentThread().getName() + "] Awaiting delivery of " + resourceAmount + " pcs. to the warehouse of raw materials (current in warehouse no. " + resources.resourceStorageCurrent + ")");
                    resources.sourceASem.release();
                    resources.sourceBSem.release();
                    resources.resourceSem.release();
                    Thread.sleep(rand.nextInt(1000) + 500);
                    continue;
                }
                if (sourceNum == 1) {
                    resources.sourceACurrent -= resourceAmount;
                    System.out.println("Thread[" + Thread.currentThread().getName() + "]: I took " + resourceAmount + " units from source 0 (" + resources.sourceACurrent + " left in stock)");
                } else {
                    resources.sourceBCurrent -= resourceAmount;
                    System.out.println("Thread[" + Thread.currentThread().getName() + "]: I took " + resourceAmount + " units from source 1 (" + resources.sourceBCurrent + " left in stock)");
                }
                resources.resourceStorageCurrent += resourceAmount;
                System.out.println("Thread[" + Thread.currentThread().getName() + "]: I delivered " + resourceAmount + " pcs. Stock of raw materials is " + resources.resourceStorageCurrent + " pcs.");
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