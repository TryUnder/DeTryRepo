class Student:
    def __init__(self, imie, nazwisko):
        self.imie = imie
        self.nazwisko = nazwisko

    def przedstaw_sie(self):
        print("Nazywam się " + self.imie + " " + self.nazwisko)

student1 = Student("Jan", "Kowalski")
student1.przedstaw_sie()
