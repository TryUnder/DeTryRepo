#!/bin/bash

# Utworzyć skrypt prezentujący sposób wydania reszty za pomocą monet 
# wykorzystujący najmniejszą ich liczbę (o nominałach 5, 2, 1):
#    ./reszta.sh 2 10
# (reszta z 10 dla kwoty 2), powinno dać w wyniku:
#    5 2 1

sekwencja=(1 2 5)

kwota=$1
cena=$2

cena=$((cena-kwota))
while (( $cena != 0 )); do
    max=0
    for i in "${sekwencja[@]}"; do
        if (( $i <= $cena )); then
            max=$((i))
        fi
    done
    cena=$((cena-max))
    echo -n "$max "
done
echo ""