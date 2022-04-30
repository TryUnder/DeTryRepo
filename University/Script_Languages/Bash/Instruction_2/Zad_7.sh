#7. - Utwórz pliki o nazwach politechnika, czestochowa. Dla pierwszego pliku ustaw prawa
#     na rw-rw-r-- dla drugiego na rw-r--r-- dla trzeciego r--r--r--. Wykonaj to za pomoca
#     polecenia chmod i parametru w postaci liczby ósemkowej.

touch $HOME/politechnika
touch $HOME/czestochowa
touch $HOME/void

chmod 664 $HOME/politechnika
chmod 644 $HOME/czestochowa
chmod 444 $HOME/void
