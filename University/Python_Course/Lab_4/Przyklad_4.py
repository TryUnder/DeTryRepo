class Banknot:
    def __init__(self, nominal, wladca):
        self.nominal = nominal
        self.wladca = wladca

    def __str__(self):
        return f"Wartosc Banknotu:{self.nominal} Wladca na Banknocie:{self.wladca}"

    def __eq__(self, other):
        return self.nominal == other.nominal

    def __gt__(self, other):
        return self.nominal > other.nominal

    def __lt__(self, other):
        return self.nominal < other.nominal

banknot10 = Banknot(10, "Mieszko")
banknot20 = Banknot(20, "Chrobry")
print(banknot10)

print(banknot10 == banknot20)
print(banknot10 > banknot20)
print(banknot10 < banknot20)