# Zad_23. Stwórz plik z zawartością o nazwie główny i utwórz dowiązanie symboliczne o nazwie symbol i trwałe o nazwie tr# wałe

touch $HOME/plik_source
echo "Jakaś zawartość" > $HOME/plik_source
ln -s $HOME/plik_source $HOME/sym
ln $HOME/plik_source $HOME/hard
