import java.util.*;

public class Program {
    public static void main(String[] args){
        Dietician[] tab = new Dietician[]
        {
            new Person("Kowalski Jan", 45, 178, 83),
            new Dog("Yeti", 6.0, 4, 2),
            new Dog("Sonia", 5.1, 7, 2),
            new Person("Mucha Joanna", 24, 169, 61),
            new Dog("Azor", 11.3, 5, 3),
            new Person("Gala Piotr", 34, 184, 91),
            new Person("Piech Anna", 56, 163, 88),
            new Dog("Meps", 16.9, 8, 3),
            new Person("Adamus Jacek", 21, 176, 94),
            new Dog("Reks", 2.8, 3, 1)
        };

            System.out.println("Lista w pierwotnej kolejnosci: \n");

        for (Dietician t : tab) {
            System.out.println(t);
        }

        Arrays.sort(tab, new Comparator<Dietician>() {
            public int compare(Dietician dieticianL, Dietician dieticianR) {
                return Double.compare(dieticianL.getBMI(), dieticianR.getBMI());
            }
        });

        System.out.println("\nLista uporzadkowana wg wartosci BMI: \n");

        for (Dietician t : tab) {
            System.out.println(t);
        }

        System.out.println("\nLista uporzadkowana wg gatunku i wieku \n");
        
        Arrays.sort(tab, new Comparator<Dietician>(){
            public int compare(Dietician dieticianL, Dietician dieticianR) {

                return String.valueOf(dieticianL.getClass()).length() - String.valueOf(dieticianR.getClass()).length();
            }
        });

        Arrays.sort(tab, new Comparator<Dietician>(){
            public int compare(Dietician dieticianL, Dietician dieticianR) {
                return dieticianL.getAge() - dieticianR.getAge();
            }
        });

        for (Dietician t : tab) {
            System.out.println(t);
        }

    }
}
