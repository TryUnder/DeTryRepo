# 25. Stwórz zmienna o dowolnej nazwie oraz wartosci. Wyswietl jej wartosc i wyprowadz
# ja do pliku.

test=2
echo $test
set | grep "test" > $HOME/var
echo $test >> $HOME/var
cat $HOME/var
