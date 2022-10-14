import java.util.Random;
import java.util.ArrayList;
import java.util.List;

public class PwJ_Lab2 {
	
	public static int valueChange(int lowerBound, int upperBound) {
		return (int)(Math.random() * (upperBound - lowerBound)) + lowerBound;
	}
	
	public static double avgWeight(Human[] human1, String Gender) {
		double sumWeight = 0.0;
        int personCounter = 0;
        
        for(Human human : human1) {
			switch(Gender) {
				case "Mr":
					if(human.getGender().equals("Mr")) {
						sumWeight += human.getWeight();
						personCounter++;
					}
                    break;
				case "Ms":
					if(human.getGender().equals("Ms")) {
						sumWeight += human.getWeight();
						personCounter++;
                    }
                    break;
                case "All":
                    if((human.getGender().equals("Ms")) || (human.getGender().equals("Mr"))) {
                        sumWeight += human.getWeight();
                        personCounter++;
                    }
                    break;
			}
		}
		
		if (personCounter != 0) {
            return sumWeight / personCounter;
        }
		
		return 0.0;
	}
	
	public static void viewAvgWeight(Human[] human, String gender) {
		switch(gender){
            case "Mr":
                System.out.println("Srednia waga mezczyzn: " + avgWeight(human,gender));
                break;
            case "Ms":
                System.out.println("Srednia waga kobiet: " + avgWeight(human,gender));
                break;
            case "All":
                System.out.println("Srednia waga wszystkich osob: " + avgWeight(human,gender));
                break;
        }           
    }

    public static ArrayList<Human> sortArrayList(Human[] humansArray) {
        ArrayList<Human> humans = new ArrayList<Human>(humansArray.length);
        
        for(var i = 0; i<humansArray.length; ++i)
            humans.add(humansArray[i]);
        
        for(int z = humans.size(); z > 1; z--) {
            for (int k = humans.size(); k > 1; k--) {
                if(humans.get(k-1).getHeight() > humans.get(k-2).getHeight()) {
                    var temp = humans.get(k-1);
                    humans.set(k-1,humans.get(k-2)); 
                    humans.set(k-2,temp);
                }
            }
        }
        return humans;
    }

    public static void presentSortedArrayListDescending(ArrayList<Human> arrayListOfHumans) {
        for(int i = 0; i<arrayListOfHumans.size(); ++i){
            System.out.println("Wysokosc: " + arrayListOfHumans.get(i).getGender() + " " + arrayListOfHumans.get(i).getName() + " wynosi: " + arrayListOfHumans.get(i).getHeight());
        }
    }
	
	public static void main(String[] args) {
		int size = 5;
		Human[] human = new Human[size];
		human[0] = new Human("Jan Nowak", 32, 78.4, 175, "Mr");
		human[1] = new Human("Olga Polak", 34, 62.1, 167, "Ms");
		human[2] = new Human("Anna Jaworska", 21, 58.3, 164, "Ms");
		human[3] = new Human("Tomasz Adamczyk", 56, 89.4, 181, "Mr");
		human[4] = new Human("Roman Tokarz", 19, 76.9, 183, "Mr");

        viewAvgWeight(human,"Ms");
		viewAvgWeight(human,"Mr");
        viewAvgWeight(human,"All");
    	Human.showHumanData(human);

        for(var humans: human) {
            humans.setWeight(humans.getWeight() + valueChange(-10,10));            
            humans.setHeight(humans.getHeight() + valueChange(-20,20));
        }

        System.out.println("\nDane po aktualizacji: ");
        Human.showHumanData(human);
        System.out.println("");

        viewAvgWeight(human,"Ms");
		viewAvgWeight(human,"Mr");
        viewAvgWeight(human,"All");

        ArrayList<Human> arrayListOfHumans = sortArrayList(human);
        presentSortedArrayListDescending(arrayListOfHumans);
    }
}