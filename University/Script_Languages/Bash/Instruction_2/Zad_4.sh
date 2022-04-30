#Zad_4.	- Utwórz w katalogu domowym pliki o nazwie informacja, wprowadz do niego swoją nazwę użytkownika. Ustaw prawa do odczytu i zapisu tylko dla właściciela pliku. Spróbuj odczytać pliki informacja z katalogów domowych innych użytkowników. Jaki skutek?

touch $HOME/info.txt
whoami > $HOME/info.txt
chmod u+rw $HOME/info.txt
