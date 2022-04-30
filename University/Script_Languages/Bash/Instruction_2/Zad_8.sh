# 8. Utwórz katalog o nazwie cwiczenie2, przenies do niego pliki z powyzszych dwóch
# punktów. Zmien prawa dostepu dla katalogu na rw------- Czy jestes w stanie przejrzec
# zawartosc katalogu?

mkdir $HOME/cwiczenie2
mv $HOME/studia $HOME/informatyka $HOME/linux $HOME/politechnika $HOME/czestochowa $HOME/void $HOME/cwiczenie2
chmod 600 $HOME/cwiczenie2
