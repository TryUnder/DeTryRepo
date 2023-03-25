#!/usr/bin/awk -f

# Utworzyć skrypt awk wypisujący dany plik tekstowy w taki sposób,
# że w każdej linii kolejność słów jest odwrócona.

{
    for (i=length($0); i>0; i--) {
        printf "%s", substr($0, i, 1)
    }

    printf "\n"
}