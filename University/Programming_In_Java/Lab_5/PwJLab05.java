//package University.Programming_In_Java.Lab_5;

// D:\P.R.I.V\Uczelnia\Semestr_V\Programowanie_w_Javie\PwJ_Lab05\customers.txt
// D:\P.R.I.V\Uczelnia\Semestr_V\Programowanie_w_Javie\PwJ_Lab05\purchases.txt
// D:\P.R.I.V\Uczelnia\Semestr_V\Programowanie_w_Javie\PwJ_Lab05\inovoices.txt

import javax.lang.model.type.NullType;
import javax.swing.JOptionPane;
import java.io.*;
import java.util.*;

public class PwJLab05 {
    public static Scanner openFilePartially(File file) {
        Scanner scanner;
        try {
            scanner = new Scanner(file);
        } catch (FileNotFoundException e) {
            scanner = null;
        }
        return scanner;
    }

    public static void checkId(ArrayList<Customer> customers, ArrayList<Purchase> purchases) {
        for(int i = 0; i < purchases.size(); ++i) {
            for (int j = 0; j < customers.size(); ++j) {
                if (purchases.get(i).getId() == customers.get(j).getId()) {
                    break;
                } else {
                    if (j == customers.size() - 1) {
                        System.out.println("Bledne id: " + purchases.get(i).getId() + " usuwam rekord.");
                        purchases.remove(purchases.get(i));
                    }
                }
            }
        }
    }

    public static void generateInvoice(ArrayList<Customer> customers, ArrayList<Purchase> purchases) {
        int[] numberOfTransactions = new int[customers.size()];
        double[] totalSumInvoice = new double[customers.size()];
        String numOfTrans, totalSumInvoiceString;
        StringBuilder stringBuilder = new StringBuilder();
        for(int i = 0; i < customers.size(); ++i) {
            System.out.print("Invoice.\n");
            customers.get(i).PrintCustomerInfo();
            stringBuilder.append("Invoice.");
            stringBuilder.append(customers.get(i).PrintCustomerInfoForBuilder());
            for(int j = 0; j < purchases.size(); ++j) {  
                if (purchases.get(j).getId() == i + 1) {
                    numberOfTransactions[i] += 1;
                    //System.out.println("Cena: " + purchases.get(j).getNumberOfItems() + " " + purchases.get(j).getPrice());
                    totalSumInvoice[i] += (purchases.get(j).getNumberOfItems() * purchases.get(j).getPrice());
                }
            }
            numOfTrans = Integer.toString(numberOfTransactions[i]);
            totalSumInvoiceString = Double.toString(totalSumInvoice[i]);
            stringBuilder.append("Number of transactions: " + numOfTrans + "\n");
            stringBuilder.append("Do zaplaty: " + totalSumInvoiceString + "\n");
            if (numberOfTransactions[i] != 0){
                //System.out.println("Number of transactions: " + numberOfTransactions[i]);
                System.out.println("Total cost: " + totalSumInvoice[i]);
            }
        }
        JOptionPane.showMessageDialog(null, stringBuilder);
    }

    public static ArrayList<Customer> AddingAndParsingForCustomers(File fileCustomers) {
        Scanner inputFileCustomers = openFilePartially(fileCustomers);
        ArrayList<Customer> customers;

        int counter = 0;
        String line = null;

        while (inputFileCustomers.hasNextLine()) {
            line = inputFileCustomers.nextLine();
            counter += 1;
        }
        customers = new ArrayList<Customer>(counter);
        inputFileCustomers.close();
        inputFileCustomers = openFilePartially(fileCustomers);

        for (int i = 0; i < counter; ++i) {
            customers.add(new Customer(inputFileCustomers.nextInt(), inputFileCustomers.next(),
                                       inputFileCustomers.next(), inputFileCustomers.nextLine()));
        }

        System.out.println("CUSTOMERS: ");
        for (int i = 0; i < customers.size(); ++i) {
            customers.get(i).PrintCustomerInfo();
        }
        inputFileCustomers.close();
        return customers;
    }

    public static void AddingAndParsingForPurchases(File filePurchases, ArrayList<Customer> customers) {
        Scanner inputFilePurchases = openFilePartially(filePurchases);
        ArrayList<Purchase> purchases;

        int counter = 0;
        String line = null;

        while(inputFilePurchases.hasNextLine()) {
            line = inputFilePurchases.nextLine();
            counter += 1;
        }

        //System.err.println(counter);
        inputFilePurchases.close();
        inputFilePurchases = openFilePartially(filePurchases);
        
        File file = new File("D:\\P.R.I.V\\Uczelnia\\Semestr_V\\Programowanie_w_Javie\\PwJ_Lab05\\purchases2.txt");
        try {
            for(int i = 0; i < counter; ++i) {
                line = inputFilePurchases.nextLine();
                if (line.contains(",")) {
                    line = line.replace(',','.');
                    if (!file.exists()) {
                        file.createNewFile();
                        FileWriter fileWriter = new FileWriter(file, true);
                        fileWriter.write(line + "\n");
                        fileWriter.close();
                    } else {
                        FileWriter fileWriter = new FileWriter(file, true);
                        fileWriter.write(line + "\n");
                        fileWriter.close();
                    }
                }
            }
        }catch(IOException e) {
            System.out.println("Wystapil problem.");
            e.printStackTrace();
        }

        purchases = new ArrayList<Purchase>(counter);
        inputFilePurchases.close();
        inputFilePurchases = openFilePartially(filePurchases);
        
        if (file.exists()) {
            inputFilePurchases.close();
            inputFilePurchases = openFilePartially(file);
        }

        for (int i = 0; i < counter; ++i) {
            purchases.add(new Purchase((inputFilePurchases.nextInt()), inputFilePurchases.next(),
                                       inputFilePurchases.nextInt(), inputFilePurchases.nextDouble()));
        }

        checkId(customers, purchases);
        
        System.out.println("PURCHASES: ");
        for (int i = 0; i < purchases.size(); ++i) {
            purchases.get(i).PrintPurchaseInfo();
        }
        PwJLab05.generateInvoice(customers, purchases);
        inputFilePurchases.close();
    }

    public static void main(String[] args) throws IOException {
        File fileCustomers, filePurchases, fileInvoices;
        String fileDirCustomers, fileDirPurchases, fileDirInvoices;

        do {
            //fileDirCustomers = JOptionPane.showInputDialog("Wprowadz sciezke do pliku zawierajacego dane o klientach (customers.txt)");
            //fileDirPurchases = JOptionPane.showInputDialog("Wprowadz sciezke do pliku zawierajacego dane o zakupach (purchases.txt)");
            //fileDirInvoices = JOptionPane.showInputDialog("Wprowadz sciezke do pliku zawierajacego dane o fakturach (invoices.txt)");
            fileDirCustomers = "D:\\P.R.I.V\\Uczelnia\\Semestr_V\\Programowanie_w_Javie\\PwJ_Lab05\\customers.txt";
            fileDirPurchases = "D:\\P.R.I.V\\Uczelnia\\Semestr_V\\Programowanie_w_Javie\\PwJ_Lab05\\purchases.txt";
            fileDirInvoices = "D:\\P.R.I.V\\Uczelnia\\Semestr_V\\Programowanie_w_Javie\\PwJ_Lab05\\inovoices.txt";

            fileCustomers = new File(fileDirCustomers);
            filePurchases = new File(fileDirPurchases);
            fileInvoices = new File(fileDirInvoices);

            if (!fileCustomers.exists())
                System.out.println("Sciezka do pliku z klientami jest bledna. Podaj jeszcze raz");
            if (!filePurchases.exists())
                System.out.println("Sciezka do pliku z zakupami jest bledna. Podaj jeszcze raz");
            if (!fileInvoices.exists())
                System.out.println("Sciezka do pliku z fakturami jest bledna. Podaj jeszcze raz");
        
        } while (!fileCustomers.exists() || !filePurchases.exists() || !fileInvoices.exists());
        
        ArrayList<Customer> customers = PwJLab05.AddingAndParsingForCustomers(fileCustomers);
        PwJLab05.AddingAndParsingForPurchases(filePurchases, customers);
    }
}