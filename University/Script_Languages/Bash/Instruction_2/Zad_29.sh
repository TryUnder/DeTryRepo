# 29. Za pomoca man znajdz opis polecenia find i wyszukaj wszystkie pliki w katalogu
# domowym zawierajace litere s. Wyniki przeslij do pliku o nazwie lista

find $HOME -name "*s*" > $HOME/lista

# "wszystkie pliki w katalogu domowym" = rekursywnie
