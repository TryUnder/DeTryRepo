from abc import ABC, abstractmethod
import math

class Ksztalt(ABC):
    def oblicz_pole(self):
        pass
    
    def oblicz_obwod(self):
        pass

class Prostokat(Ksztalt):
    def __init__(self, bok1, bok2):
        if bok1 <= 0 or bok2 <= 0:
            raise ValueError
        else:
            self.bok1 = bok1
            self.bok2 = bok2

    def oblicz_pole(self):
        return self.bok1 * self.bok2

    def oblicz_obwod(self):
        return 2 * self.bok1 + 2 * self.bok2

class Okrag(Ksztalt):
    def __init__(self, r):
        if r <= 0:
            raise ValueError
        else:
            self.r = r

    def oblicz_pole(self):
        return math.pi * math.pow(self.r,2)

    def oblicz_obwod(self):
        return 2 * math.pi * self.r


try:
    okrag1 = Okrag(3)
    print("Obwod okregu wynosi: " + str(okrag1.oblicz_obwod()))
    print("Pole okregu wynosi: " + str(okrag1.oblicz_pole()))

    prostokat1 = Prostokat(2,3)
    print("Obwod prostokata wynosi: " + str(prostokat1.oblicz_obwod()))
    print("Pole prostokatu wynosi: " + str(prostokat1.oblicz_pole()))

    okrag2 = Okrag(-1)
    print(okrag2.oblicz_pole())

    prostokat2 = Prostokat(-2, 4)
    print(prostokat2.oblicz_pole())

except ValueError:
    print("Podales nieprawidlowe parametry")
