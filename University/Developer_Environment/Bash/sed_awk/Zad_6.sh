#!/usr/bin/awk -f

# Dany jest plik w postaci:

# Jan Kowalski;123456;5.0
# Anna Nowak;123457;5.0
# itd...

# Utworzyć skrypt awk konwertujący ten plik do postaci:

# student=Jan Kowalski
# nr indeksu=123456
# ocena=5.0
# student=Anna Nowak
# nr indeksu=123457
# ocena=5.0
# ...

BEGIN {
    FS = ";"
    RS = "\n"
}

{
    print "student="$1"\n""nr indeksu="$2"\n""ocena="$3
}