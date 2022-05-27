# 3. Napisz skrypt, który dla wszystkich plików w katalogu domowym ustawi prawo do
# odczytu dla wszystkich.

for i in $HOME/*
do 
    chmod ugo+r $i
done