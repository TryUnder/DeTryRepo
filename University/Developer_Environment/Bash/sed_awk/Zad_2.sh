#!/usr/bin/bash

# Utworzyć wyrażenie regularne akceptujące wyłącznie nazwy plików wykorzystywane wsystemie
# DOS (8 znaków a-z A-Z _ oraz trzy znaki rozszerzenia) i je przetestować.
# W pliku z rozwiązaniem umieścić pełne wywołanie sed.

sed -En 's/^([a-zA-Z0-9_]{1,8}\.[a-zA-Z0-9]{3})/\1/p' $1
