#!/bin/bash
#Utworzyć skrypt, który tworzy kopię zapasową katalogu podanego jako argument. Kopia zapasowa powinna być spakowana w archiwum tar. Nazwa kopii zapasowej musi zawierać datę i godzinę jej utworzenia. Uwzględnić pełną obsługę błędów (sprawdzenie, czy wywołano z argumentem; sprawdzenie, czy dany katalog istnieje, itp.)

if test $# -ne 1; then
    echo "Uruchom skrypt z jednym argumentem wywołania skryptu, będacym nazwą katalogu, którego chcemy zrobić kopie zapasową."
else
    if [ -d $1 ]; then
        cp $1 $(date +%F::%H:%M).tar -r
else
    echo "Plik nie jest katalogiem"
    fi
fi
