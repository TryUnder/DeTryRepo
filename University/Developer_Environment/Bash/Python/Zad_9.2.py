#!/usr/bin/python3

import csv, sys
import xml.etree.ElementTree as ET

class Osoba:
    def __init__(self, nr, email, rok, imie):
        self.nr = nr
        self.email = email
        self.rok = rok
        self.imie = imie
    
    def wypisz(self):
        print("Nr: ", self.nr)
        print("Email: ", self.email)
        print("Rok: ", self.rok)
        print("Imie: ", self.imie)

class Osoby:
    def __init__(self, listaOsob):
        self.listaOsob = listaOsob

    def __iter__(self):
        return iter(self.listaOsob)

    def wypisz(self):
        for osoba in self.listaOsob:
            osoba.wypisz()

    def sortThings(self, key):
        self.listaOsob.sort(key=key)

class FileIO:
    def wczytajDane(plik):
        try:
            dane = list(csv.reader(open(plik), delimiter = ';'))
            listaOsob = []
            for osoba in dane:
                listaOsob.append(Osoba(osoba[0], osoba[1], osoba[2], osoba[3]))
            return listaOsob
        except IOError:
            plik.close()
            exit()

    def zapiszDane(plik, listaOsob):
        try:
            with open(plik, "w", newline="") as file_output:
                to_write = csv.writer(file_output, delimiter=";")
                for osoba in listaOsob:
                    to_write.writerow([osoba.nr, osoba.email, osoba.rok, osoba.imie])
        except IOError:
            plik.close()
            exit()

def sortFun(x):
    match x:
        case 1:
            osoby.sortThings(lambda osoba: osoba.nr)
        case 2:
            osoby.sortThings(lambda osoba: osoba.email)
        case 3:
            osoby.sortThings(lambda osoba: osoba.rok)
        case 4:
            osoby.sortThings(lambda osoba: osoba.imie)
        case _:
            print("Nie ma takiej opcji")

def saveToXML(listaOsob):
    root = ET.Element("osoby")
    for osoba in listaOsob:
        el_osoba = ET.SubElement(root, "osoba")
        el_nr = ET.SubElement(el_osoba, "nr")
        el_nr.text = osoba.nr
        el_email = ET.SubElement(el_osoba, "email")
        el_email.text = osoba.email
        el_rok = ET.SubElement(el_osoba, "rok")
        el_rok.text = osoba.rok
        el_imie = ET.SubElement(el_osoba, "imie")
        el_imie.text = osoba.imie
    try:
        tree = ET.ElementTree(root)
        tree.write("wynik2.xml")
    except IOError:
        exit()

osoby = Osoby(FileIO.wczytajDane(sys.argv[1]))
x = int(input("Podaj po czym sortowac: 1 - nr, 2 - email, 3 - rok, 4 - imie: "))
sortFun(x)
osoby.wypisz()
FileIO.zapiszDane("wynik.csv", osoby)

# 9.2

saveToXML(osoby)