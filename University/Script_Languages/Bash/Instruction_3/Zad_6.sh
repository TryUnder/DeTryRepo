# 6. W katalogu domowym stwórz plik o nazwie data. Stwórz z niego skrypt
# wyświetlający datę w formacie RRRR-MM-DD.

touch %HOME/data.sh
chmod +x %HOME/data.sh 
echo "date \"+%Y-%m-%d\"" > %HOME/data.sh