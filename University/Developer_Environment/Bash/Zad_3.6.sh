#!/bin/bash

# Utworzyć skrypt umożliwiający wielokrotne kopiowanie, tzn. 
# skopiowanie jednego pliku źródłowego jako wielu plików docelowych, np:
# ./wielokrotne_copy.sh zrodlo nazwa1 nazwa2 nazwa3 ...
# skopiuje plik o nazwie zrodlo do plików nazwa1, nazwa2, nazwa3, itd...

if [ $# -gt 1 ]; then
    zrodlo="$1"
    shift
    for plik in "$@"; do
        cp "$zrodlo" "$plik"
    done
else
    echo "Podaj pierwszy parametr zrodlo do skopiowania i dalej n parametrow gdzie chcesz skopiowac plik"
fi