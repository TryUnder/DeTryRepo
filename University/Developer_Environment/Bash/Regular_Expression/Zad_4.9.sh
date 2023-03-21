#!/bin/bash

# Ścieżka /usr/share/dict/words w systemie Linux definiuje dostęp do pliku 
# zawierającego listę słów. Wykorzystując polecenie grep oraz wyrażenia regularne
# wyświetlić słowa zaczynające się i kończące identyczną samogłoską 
# (np. owadobójczo). W rozwiązaniu umieścić należy jedynie wywołanie 
# polecenia grep wraz z wszystkimi argumentami.

grep -iE '^([aeiou]).*\1$' /usr/share/dict/words