from collections import Counter


with open("listaimion.txt", "r") as readFile:
    words = readFile.read().strip().split()

statystyka = Counter(words)

for slowo, liczbaWystapien in statystyka.items():
    print(f"Słowo '{slowo} występuje {liczbaWystapien} razy.'")