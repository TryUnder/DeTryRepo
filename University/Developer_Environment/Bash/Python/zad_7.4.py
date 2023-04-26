#!/usr/bin/python3

from random import randrange

rng_value = randrange(11)

for i in range(5):
    player_value = input("Podaj liczbe do odgadniecia: ")
    if int(player_value) == int(rng_value):
        print("Gratuluje! Wygrales gre.")
        break
print("Nie udalo ci sie wygrac gry. System Wylosowal: ", rng_value)
