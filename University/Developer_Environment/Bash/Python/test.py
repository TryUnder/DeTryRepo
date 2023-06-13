import sys
import random
import os

# ciagZnakow = input()

# for znak in ciagZnakow:
#     print(znak, end="\n")

# ciagZnakow = "abcdefg"
# lista = []

# for znak in ciagZnakow:
#     print(znak, "->", ord(znak))
#     lista.append(ord(znak))   
# print(lista)

# for i in range(int(sys.argv[1])):
#     for j in range(int(sys.argv[1])):
#         print(int(i+1) * int(j+1), end=" ")
#     print()

# rand = random.randint(1, 10)

# for i in range(5):
#     traf = int(input("Podaj liczbe: "))
#     if traf == rand:
#         print("Zgadles!")
#         break
#     elif i+1 == 5:
#         print("Przegrales!")

# def wypisz(liczbaCiagowZnakow, liczbaZnakow):
#     for i in range(liczbaCiagowZnakow):
#         ciag=[]
#         for j in range(liczbaZnakow):
#             ciag.append(chr(random.randint(0, 1000)))
#         print(ciag)

# wypisz(5,10)

# def openFile():
#     newString = ""
#     with open("bledny.patch", "r") as openFile:
#         for line in openFile:
#             newString += line.upper()
#         return newString

# def saveFile(newString):
#     with open("toSave.txt", "w") as saveFile:
#         saveFile.write(newString)

# newString = openFile()
# saveFile(newString)

# def convertToWindows():
#     with open("macierze.txt", "w", newline="\r\n") as readWrite:
#         readWrite.write("siema")

# def convertToUnix():
#     with open("macierze.txt", "w", newline="\n") as readWrite:
#         readWrite.write("siema")

# convertToUnix()

def zliczLinie():
    with open("bledny.patch", "r") as openFile:
        lines = openFile.readlines()
        print(len(lines))

def zliczZnaki():
    with open("bledny.patch", "r") as openFile:
        content = openFile.read()
    return len(content)
