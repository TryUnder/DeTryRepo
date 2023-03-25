#!/usr/bin/awk -f

# Utworzyć skrypt, który będzie filtrował poprawne adresy IP. 
# Na przykład, dla pliku w następującej postaci:

# 212.87.224.6
# 127.0.0.1
# 555.555.222.222
# 10.0.0.1
# 0.x.x.1
# 5.10.15

# skrypt powinien wypisać linie 1, 2 i 4. Rozwiązaniem może być skrypt napisany w sed bądź w awk
# (wystarczy jeden sposób, skrypt awk będzie prostszy do napisania)

function czy_poprawne_ip(ip) {
    split(ip, oktety, ".")
    for (i=1; i<=4; i++) {
        if (oktety[i] == "" || oktety[i] < 0 || oktety[i] > 255) {
            return 0
        }
    }
    return 1
}

{
    if (czy_poprawne_ip($0)) {
        print "Wzorzec rozpoznany:", $0
        print
    } else {
        print "Nie rozpoznano wzorca", $0
    }
}