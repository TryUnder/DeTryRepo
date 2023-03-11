#!/bin/bash

# Napisać skrypt wczytujący tekst ze standardowego wejścia i wyświetlający tę 
# linię tekstu, która zawiera najwięcej znaków wraz z liczbą znaków w tej linii. 
# Skrypt ma naśladować działanie programu wc wywołanego z opcją –max-line-length, 
# nie wykorzystując jednak tego programu. Przykład wywołania:
# cat plik | ./dlugosc.sh
# wynik wywołania:
# 27: for i in $(seq $a -1 1); do

text=""
max=0
numer_lini=0
maksymalna_dlugosc_lini=0
while read line; do
    numer_lini=$((numer_lini+1))
    text="$line"
    if [ ${#text} -gt $max ]; then
        max=${#text}
        maksymalna_dlugosc_lini=$numer_lini
    fi
done

echo "Najdłuższy wiersz nr: $maksymalna_dlugosc_lini ma długość: $max"