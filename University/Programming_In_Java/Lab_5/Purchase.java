//package University.Programming_In_Java.Lab_5;
import java.util.*;

public class Purchase {
    private int id;
    private String purchaseType;
    private int numberOfItems;
    private double price;

    public Purchase(int Id, String PurchaseType, int NumerOfItems, double Price) {
        id = Id;
        purchaseType = PurchaseType;
        numberOfItems = NumerOfItems;
        price = Price;
    }

    public void PrintPurchaseInfo() {
        System.out.println("Purchase: " + id + " " + purchaseType + " " + "number of items: " + numberOfItems + " price: " + price);
    }

    public int getId() {
        return id;
    }

    public int getNumberOfItems() {
        return numberOfItems;
    }

    public double getPrice() {
        return price;
    }
}
