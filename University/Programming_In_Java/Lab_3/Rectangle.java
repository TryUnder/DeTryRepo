package University.Programming_In_Java.Lab_3;

    public class Rectangle extends Figure {
        private double a;
        private double b;
     
        public Rectangle(String Color) {
            super();
            a = 0.0;
            b = 0.0;
        }
     
        public Rectangle(String Color, double A, double B) {
            super(Color, 0.0, 0.0);
            a = A;
            b = B;
        }
     
        public double count_Circumference( ) {
            return a * b;
        }
     
        public double count_surface() {
            return 2 * a + 2 * b;
        }
     
        public void viewData() {
            super.viewData();
        }
    }
