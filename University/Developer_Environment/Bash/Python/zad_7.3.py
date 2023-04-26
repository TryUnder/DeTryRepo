#!/usr/bin/python3

rozmiar_1 = input("Podaj wymiar tabliczki mnożenia: ")
rozmiar_2 = rozmiar_1

print("Tabliczka mnożenia do: ", rozmiar_1)

for i in range(int(rozmiar_1) + 1):
    for j in range(int(rozmiar_2) + 1):
        if i != 0 and j != 0:
            print(i * j, end=' ')
    print()
