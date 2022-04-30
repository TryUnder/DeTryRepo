# 26. Czy wsród zmiennych srodowiskowych istnieja zmienne USER, UID, DIR,
# HOSTNAME, PWD. Jesli tak wyprowadz ich wartosc oraz nazwy do pliku (polecenia
# set i grep).

set > $HOME/env_var
grep 'USER\|UID\|DIR\|HOSTNAME\|PWD' $HOME/env_var > $HOME/founded_var
cat $HOME/founded_var
