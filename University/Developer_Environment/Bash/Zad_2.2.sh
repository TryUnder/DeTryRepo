#!/bin/bash

# Napisać skrypt przyjmujący jeden argument i wypisujący tekst Witaj + przekazany argument.
# W przypadku, gdy skrypt wywołany jest bez argumentów powinien wypisać sposób jego użycia

if test $# -ne 1 ; then
    echo "Podaj argument podczas wywolywania skryptu."
    echo "Program wypisze Hello i zawartosc tego argumentu."
else
    echo "Witaj $1"
fi
