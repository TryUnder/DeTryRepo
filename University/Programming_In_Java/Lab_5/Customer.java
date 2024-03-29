//package University.Programming_In_Java.Lab_5;

public class Customer {
    private int id;
    private String name;
    private String surname;
    private String address;

    public Customer(int Id, String Name, String Surname, String Address) {
        id = Id;
        name = Name;
        surname = Surname;
        address = Address;
    }

    public void PrintCustomerInfo() {
        System.out.println("Customer id: " + id + "\n " + name + " " + surname + address);
    }

    public int getId() {
        return id;
    }

    public String PrintCustomerInfoForBuilder() { 
        return new String("\nCustomer id: " + id + " " + name + " " + surname + address + "\n");
    }
}
