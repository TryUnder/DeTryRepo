with open("test.txt", "r") as readFile:
    lista_osob = readFile.readlines()

zestaw = []

for osoba in lista_osob:
    osoba = osoba.strip().split()
    zestaw.append(osoba)

print(zestaw)

def klucz_sortowania(osoba):
    return osoba[1]

lista_osob = sorted(zestaw, key=klucz_sortowania)

print(lista_osob)