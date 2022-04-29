# Zad_26. Jaki jest typ pliku dla dowiązania symbolicznego, a jaki dla trwałego?

# typ pliku dla dowiązania symbolicznego to link, a dla trwałego taki sam jak ówczesny plik
# Tak na prawdę nie ma praktycznie różnicy pomiędzy hard linkiem a oryginalnym plikiem. Trzeba się postarać, by odkryć różnice.
# Pliki są tworami wirtualnymi. Nie przechowują informacji per se. To takie abstrakcyjne uchwyty na węzły w systemie plików.
# Więc tworząc plik, tworzy się tak na prawdę wirtualny uchwyt które wskazuje na iNode.
# Jeśli wiele plików wskazuje na jeden iNode, to jest to hard link
# Skasowanie pliku nie kasuje danych, tylko odbezpiecza przestrzeń przed zamazaniem pozwalając, by w jej miejsce zapisać coś nowego.
