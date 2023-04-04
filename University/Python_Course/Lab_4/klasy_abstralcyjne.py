from abc import ABC, abstractmethod

class Ssak(ABC):

    @abstractmethod
    def mow(self):
        pass

class Kot(Ssak):

    def mow(self):
        print("Miau")

class Pies(Ssak):

    def mow(self):
        print("Hau")

class Krowa(Ssak):

    def ide(self):
        print("Krowa idzie")

    def mow(self):
        print("Muu")

kot1 = Kot()
pies1 = Pies()
krowa1 = Krowa()

zwierzeta_lista = [kot1, pies1, krowa1]

for zwierz in zwierzeta_lista:
    zwierz.mow()