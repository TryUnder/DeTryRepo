# 16. Napisz skrypt, który w zależności od podanego parametru wyświetli następujące 
# komunikaty:
# pomoc: „Nie ma dostepnej pomocy”
# usun: „Nie ma nic do usuniecia”
# kopiuj: „Nie ma plikow do kopiowania”
# Jeśli podany parametr nie będzie pasował do wymienionych należy wyświetlić jego
# nazwę.

case $1 in
        "pomoc") echo "Nie ma dostepnej pomocy";;
        "kopiuj") echo "Nie ma nic do skopiowania";;
        "usun") echo "Nie ma nic do usuniecia";;
        *) echo $0
esac