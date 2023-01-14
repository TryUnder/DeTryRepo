import java.util.Random;

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
                resources.productSem.acquire();
                // wybor produktu
                int productNum = rand.nextInt(3) + 1;
                int resourceAmount;
                int productAmount;
                if (productNum == 1) {
                    resourceAmount = 120;
                    productAmount = 1;
                    resources.productACount++;
                } else if (productNum == 2) {
                    resourceAmount = 250;
                    productAmount = 1;
                    resources.productBCount++;
                } else {
                    resourceAmount = 500;
                    productAmount = 1;
                    resources.productCCount++;
                }

                if (resources.resourceStorageCurrent < resourceAmount) {
                    resourceAmount = resources.resourceStorageCurrent;
                    productAmount = resourceAmount / (productNum == 1 ? 120 : (productNum == 2 ? 250 : 500));
                    System.out.println("Watek[" + Thread.currentThread().getName() + "-" + Thread.currentThread().getId() + "]: Czekam na materialy");
                    resources.resourceSem.release();
                    resources.productSem.release();
                    Thread.sleep(rand.nextInt(1000) + 500);
                    continue;
                }
                resources.resourceStorageCurrent -= resourceAmount;

                if (resources.productStorageCurrent + productAmount > resources.productStorageCapacity) {
                    productAmount = resources.productStorageCapacity - resources.productStorageCurrent;
                }
                resources.productStorageCurrent += productAmount;
                System.out.println("Watek[" + Thread.currentThread().getName() + "-" + Thread.currentThread().getId() + "]: Wyprodukowalem produkt " + productNum + " i dodalem do zbioru. Balans produktow A " + resources.productACount + "sztuk, B: " + resources.productBCount + "sztuk, C: " + resources.productCCount + "sztuk.");
                resources.resourceSem.release();
                resources.productSem.release();
                Thread.sleep(rand.nextInt(1000) + 500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}