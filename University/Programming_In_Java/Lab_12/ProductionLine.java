import java.util.Random;
import java.util.concurrent.Semaphore;

public class ProductionLine extends Thread {
    Resources resources;
    int lineNum;
    Random rand = new Random();
 
    ProductionLine(Resources res, int lineNum) {
        resources = res;
        this.lineNum = lineNum;
    }
 
    public void run() {
        while (true) {
            try {
                resources.resourceSem.acquire();
                System.out.println("Production Line " + lineNum + " is waiting for materials.");
                resources.productSem.acquire();
                // select a random product
                int productNum = rand.nextInt(3) + 1;
                int resourceAmount;
                int productAmount;
                if (productNum == 1) {
                    resourceAmount = 120;
                    productAmount = 1;
                } else if (productNum == 2) {
                    resourceAmount = 250;
                    productAmount = 1;
                } else {
                    resourceAmount = 500;
                    productAmount = 1;
                }
                // check if there are enough resources
                if (resources.resourceStorageCurrent < resourceAmount) {
                    resourceAmount = resources.resourceStorageCurrent;
                    productAmount = resourceAmount / (productNum == 1 ? 120 : (productNum == 2 ? 250 : 500));
                }
                resources.resourceStorageCurrent -= resourceAmount;
                System.out.println("Production Line " + lineNum + " has produced a final product using " + resourceAmount + " resources from the resource storage.");
                // check if there is enough space in the product storage
                if (resources.productStorageCurrent + productAmount > resources.productStorageCapacity) {
                    productAmount = resources.productStorageCapacity - resources.productStorageCurrent;
                }
                resources.productStorageCurrent += productAmount;
                System.out.println("Production Line " + lineNum + " has assembled " + productAmount + " units of Product " + productNum + " in the magazine. Number of products in the magazine: " + resources.productStorageCurrent);
                resources.resourceSem.release();
                resources.productSem.release();
                Thread.sleep(rand.nextInt(1000) + 500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}