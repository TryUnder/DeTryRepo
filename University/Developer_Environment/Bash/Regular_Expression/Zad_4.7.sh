#!/bin/bash

# Ścieżka /usr/share/dict/words w systemie Linux definiuje dostęp do pliku zawierającego listę słów.
# Wykorzystując polecenie grep oraz wyrażenia regularne wyświetlić słowa zaczynające i kończące się samogłoską,
# nie zawierające samogłosek wewnątrz (np. oschły).
# W rozwiązaniu umieścić należy jedynie wywołanie polecenia grep wraz z wszystkimi argumentami.

grep -E '^[aeiouyAEIOUY][^aeiouyAEIOUY]{1,}[aeiouyAEIOUY]$' /usr/share/dict/words
