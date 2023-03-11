# Napisz program, który przyjmie od użytkownika ścieżkę do pliku i sprawdzi czy plik faktycznie istnieje. 
# W przypadku kiedy plik nie istnieje użytkownik powinien otrzymać odpowiednią informacje zwrotną. 
# Korzystając z poprzedniego programu doimplementuj funkcjonalność, która będzie zwracać rozszerzenie do pliku.

import os 

sciezka=input("Proszę wprowadzić scieżkę do pliku: ") 
file_exist = os.path.exists(sciezka) 
if file_exist == 1:
    print(file_exist)
    root,extension=os.path.splitext(sciezka)
                                            
    print(extension)
else:
    print("Ścieżka nie istnieje!")