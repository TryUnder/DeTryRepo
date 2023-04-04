from abc import ABC, abstractmethod
import math

class Ksztalt(ABC):
    def oblicz_pole(self):
        pass
    
    def oblicz_obwod(self):
        pass

class Prostokat(Ksztalt):
    def __init__(self, bok1, bok2):
        self.bok1 = bok1
        self.bok2 = bok2

    def oblicz_pole(self):
        return self.bok1 * self.bok2

    def oblicz_obwod(self):
        return 2 * self.bok1 + 2 * self.bok2

class Okrag(Ksztalt):
    def __init__(self, r):
        self.r = r

    def oblicz_pole(self):
        return math.pi * math.pow(self.r,2)

    def oblicz_obwod(self):
        return 2 * math.pi * self.r

okrag1 = Okrag(3)
print(okrag1.oblicz_pole())