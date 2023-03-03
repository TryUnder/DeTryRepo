#!/bin/bash
# Utworzyć skrypt przyjmujący dwa argumenty, który wypisuje zawartość pliku podanego jako drugi argument, bądź w formacie
# 1 linia_pliku_podanego_jako_argument
# 2 linia_pliku_podanego_jako argument
# ...
# bądź też w odwrotnej kolejności:
# n linia_pliku_podanego_jako_argument
# n-1 linia_pliku_podanego_jako_argument
# ...
# gdzie n to liczba linii pliku.
# Sposób wypisywania powinien być możliwy do przełączania za pomocą pierwszego argumentu.

if [ $# -ne 2 ]; then
    echo "Podaj dwa argumentu wywołania skryptu: "
    echo "Pierwszy argument: określa sposób wypisywania pliku. 1 - normalna kolejność 2 - odwrotna kolejność. Wpisz w której kolejności."
    echo "Drugi argument okresla zawartosc pliku do wypisania - nazwe pliku"
else
    if [ -f $2 ]; then
        if [ $1 = 1 ]; then
            nl $2
        else
	    nl $2 | tac
	fi
    else
        echo "$2 nie jest plikiem"
    fi
fi
