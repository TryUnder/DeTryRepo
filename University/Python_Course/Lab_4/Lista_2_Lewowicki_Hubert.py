# Zad.1

studenci = ['Przystalski', 'Kowalska', 'Bolito', 'Wozniak', 'Kowalski', 'Nowak']

for student in studenci:
    print(student)

print("\n")

# Zad.2

for student in studenci:
    if student=="Bolito":
        print(student) 
    
# Zad.3    

print("\n")
imie = 'Bolito'

for i in range(len(studenci)):
    if imie==studenci[i]:
        print(imie)
        break
    elif i==len(studenci)-1:
        print("Osoba o takim nazwisku nie jest studentem")

# Zad.4

def LaczWyrazy(imie: str, nazwisko: str):
    return imie+nazwisko

print(LaczWyrazy("Agata","Hubert"))

# Zad.5

def WypiszParzyste(liczby: int):
    tablicaLiczb = []
    for i in range(liczby + 1):
        if i != 0 and i%2 == 0:
            tablicaLiczb.append(i)
    print(tablicaLiczb)

WypiszParzyste(10)

# Zad.6

slownik1 = {1: "Hubert", 2: "Paweł", 3: "pistacje"}
slownik2 = {4: "Tekila", 5: "mikrpfpb", 6: "pilka", 7: "Kropka"}

def addDict(dict1, dict2):
    dict3 = dict1.copy()
    dict3.update(dict2)
    return dict3

print(addDict(slownik1, slownik2))

# Zad.7

def squareFunc(numbers):
    numbersSquaredList = []
    for i in range(len(numbers)):
        numbersSquaredList.append(numbers[i] * numbers[i])
    return numbersSquaredList

numbers = [1,2,3,4,5,6,7,8,9]
print(squareFunc(numbers))
