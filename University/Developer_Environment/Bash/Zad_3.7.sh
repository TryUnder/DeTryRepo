#!/bin/bash

# Napisać skrypt odnajdujący największy wspólny 
# dzielnik dwóch liczb przekazanych jako argumenty skryptu:
# ./nwd.sh 864 528
# powinno dać w wyniku:
#    48

if [ $# -eq 2 ]; then
    liczba_a=$1
    liczba_b=$2
    while (( $liczba_a != $liczba_b )); do
        if [ $liczba_a -gt $liczba_b ]; then
            liczba_a=$((liczba_a-liczba_b))
        else
            liczba_b=$((liczba_b-liczba_a))
        fi
    done
    echo "Najwiekszy wspólny dzielnik to: $liczba_a"
else
    echo "Podaj dwa parametry: 1 - liczba 2 - liczba"
fi