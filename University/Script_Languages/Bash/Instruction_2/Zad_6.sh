# Zad.6 - Utwórz plik o nazwach studia, informatyka, linux. Do pierwszego pliku ustaw prawa rwxr-xr-- dla drugiego rw-rw-rw dla trzeckiego r--r-----. Wykonaj to za pomleceniem chmod i parametrów tekstowych.

touch $HOME/studia
touch $HOME/informatyka
touch $HOME/linux

chmod u+rwx,g+rx,o+r $HOME/studia
chmod u+rw,g+rw,o+rw $HOME/informatyka
chmod u+rw,g+rw $HOME/linux


