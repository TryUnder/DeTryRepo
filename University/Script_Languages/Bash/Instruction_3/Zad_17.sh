# 17. W pliku .bash_logout umieść polecenie usuwające wszystkie pliki z katalogu
# domowego. Wyloguj się i zaloguj ponownie. Jaki efekt?

echo "rm -v $HOME/*" >> .bash_logout