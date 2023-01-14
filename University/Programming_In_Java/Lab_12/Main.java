public class Main {
    public static void main(String[] args) {
        Resources resources = new Resources();
        for (int i = 1; i <= 3; i++) {
            Supplier supplier = new Supplier(resources, i);
            supplier.setName("Dostawcy");
            supplier.start();
        }
        for (int i = 1; i <= 2; i++) {
            ProductionLine productionLine = new ProductionLine(resources, i);
            productionLine.setName("Producenta");
            productionLine.start();
        }
    }
}