# 14. Znajdź błędy w skrypcie:
# if [-d plik ]; then
# mv plik plik2
# elif [ -f plik3 ] then
# mw plik3 plik4
# fi
# Opisz działanie skryptu.

if [ -d $1 ]; 
then
    mv $1 $2;
elif [ -f $3 ]; 
then
    mv $3 $4;
fi

# Jeżeli ścieżka do katalogu w postaci argumentu $1 istnieje, to skopiuj folder $1 do folderu $2.
# W przeciwnym razie jeżeli trzeci argument ma postać normalnego pliku to przenieś go do folderu $4