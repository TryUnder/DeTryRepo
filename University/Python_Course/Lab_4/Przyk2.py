class Prostokat:
    def __init__(self, bok1, bok2):
        if bok1 < 0 or bok2 < 0:
            raise ValueError
        else:
            self.bok1 = bok1
            self.bok2 = bok2

    def policz_obwod(self):
        return (2 * self.bok1 + 2 * self.bok2)

class Boisko(Prostokat):
    def __init__(self, bok1, bok2):
        if bok1 < 90 or bok1 > 120 or bok2 < 45 or bok2 > 90:
            raise ValueError
        else:
            super().__init__(bok1, bok2)

    def policz_obwod(self):
        return (2 * self.bok1 + 2 * self.bok2) * 1.1

try:
    prostokat = Prostokat(-2,10)
    print(prostokat.policz_obwod())

except ValueError:
    print("Blad")
