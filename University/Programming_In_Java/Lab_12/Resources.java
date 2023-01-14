import java.util.concurrent.Semaphore;
 
// zasoby dzielone
public class Resources {
    int resourceStorageCapacity = 5000;
    int resourceStorageCurrent = 0;
    int productStorageCapacity = 10000;
    int productStorageCurrent = 0;
    int sourceACapacity = 50000;
    int sourceACurrent = 50000;
    int sourceBCapacity = 50000;
    int sourceBCurrent = 50000;
    int productACount = 0;
    int productBCount = 0;
    int productCCount = 0;
 
    Semaphore resourceSem = new Semaphore(1);
    Semaphore productSem = new Semaphore(1);
    Semaphore sourceASem = new Semaphore(1);
    Semaphore sourceBSem = new Semaphore(1);
}