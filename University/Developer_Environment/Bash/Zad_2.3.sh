#!/bin/bash

#Zmodyfikowac skrypt z zadania 2.2. Wywołać skrypt bez żadnych argumentów - wówczas skrypt powinien wypisać Witaj + nazwa użytkownika

if test $# -eq 0 ; then
    echo "Witaj: $ $(whoami)"
else
    echo "Przekazany argument: $1"
fi
