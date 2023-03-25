#!/usr/bin/bash

# Napisać skrypt wykorzystujący edytor sed, który będzie wyodrębniał z pliku
# tekstowego liczby rzeczywiste zapisane w postaci wykładniczej, np.: 1.666e-01.
# W pliku z rozwiązaniem umieścić pełne wywołanie sed.

sed -En 's/[a-z ]*([1-9]\.[1-9]*e[-+][0-9]*)[a-z ]*/\1/p' $1
