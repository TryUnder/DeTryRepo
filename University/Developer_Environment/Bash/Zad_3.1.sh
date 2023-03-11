#Utworzyć skrypt, który wywołany w następujący sposób:
#./skrypt plik1 plik2 plik3 ... plikn
#wypisze na standardowe wyjście zawartość plików w następujący sposób:
#    plik1:
#    zawartość pliku 1
#
#    plik2:
#    zawartość pliku 2
#    ...
#itd.

#!/bin/bash

for plik in "$@"; do
  if test -f "$plik"; then
    echo "$plik:"
    cat "$plik"
  fi
done
