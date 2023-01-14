import java.util.Random;
import java.util.concurrent.Semaphore;

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
                if (sourceNum == 1 && resources.sourceACurrent >= resourceAmount) {
                    resources.sourceACurrent -= resourceAmount;
                } else if (sourceNum == 2 && resources.sourceBCurrent >= resourceAmount) {
                    resources.sourceBCurrent -= resourceAmount;
                } else {
                    resources.resourceSem.release();
                    resources.sourceASem.release();
                    resources.sourceBSem.release();
                    continue;
                }
                // check if there is enough space in the resource storage
                if (resources.resourceStorageCurrent + resourceAmount > resources.resourceStorageCapacity) {
                    resourceAmount = resources.resourceStorageCapacity - resources.resourceStorageCurrent;
                }
                resources.resourceStorageCurrent += resourceAmount;
                System.out.println("Supplier " + supplierNum + " transported " + resourceAmount + " resources from source " + sourceNum + " to the resource storage.");
                resources.resourceSem.release();
                resources.sourceASem.release();
                resources.sourceBSem.release();
                Thread.sleep(rand.nextInt(1000) + 500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}