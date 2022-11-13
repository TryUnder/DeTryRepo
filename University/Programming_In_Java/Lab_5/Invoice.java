import java.util.*;

public class Invoice {
    private Customer customer;
    private ArrayList<Purchase> purchase;

    public Invoice(Customer customer, ArrayList<Purchase> purchase) {
        this.customer = customer;
        this.purchase = purchase;
    }

    //public ArrayList<Purchase> setPurchase(Purchase Purchasex) {
      //  purchase = Purchasex;
    //}
}
