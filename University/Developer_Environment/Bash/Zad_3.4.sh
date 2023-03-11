#!/bin/bash

# Utworzyć skrypt, który po wywołaniu uruchomi wszystkie pliki wykonywalne w danym katalogu i jego podkatalogach. 
# Skrypt przyjmuje jeden argument będący nazwą katalogu.

if [ $# -eq 1 ]; then
    if [ -d $1 ]; then
        cd "$1"
        for plik in $(find . -type f -executable) ; do
            "$plik" 
        done
    else 
        echo "Podany argument nie jest katalogiem"
    fi
else
    echo "Program wymaga jednego argumentu, bedacego sciezka do folderu"
fi