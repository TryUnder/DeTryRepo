#!/bin/bash

# Napisać skrypt, który przyjmując na standardowe wejście informacje o kontach 
# zapisane w formacie passwd, wypisze te konta których domyślną powłoką jest bash. 
# Przykład wywołania:
#    cat /etc/passwd | ./konta.sh
# może dać w wyniku (w zależności od istniejących kont):
#    sp1
#    sp2
#    ...

awk -F: '/bash/{print $1}' 