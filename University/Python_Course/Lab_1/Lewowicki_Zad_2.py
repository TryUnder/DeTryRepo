import os

imie=input("Prosze o podanie imienia")
sciezka=input("Prosze o podanie sciezki do pliku")
plik_istnieje = os.path.exists(sciezka)
if plik_istnieje == 1:
    with open(sciezka, 'a+') as zy:
        zy.write(imie)
else:
    print("Plik nie istnieje!")
    with open(sciezka, 'w') as xx:
        xx.write(imie)