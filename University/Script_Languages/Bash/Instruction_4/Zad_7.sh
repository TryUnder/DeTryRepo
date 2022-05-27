# 7. Napisz skrypt wyświetlający pliki w podanym katalogu. Katalog ma być podawany po
# uruchomieniu skryptu.

echo "Podaj sciezke do katalogu"
read directory
if [ -d $directory ]; then
    for i in $directory/*; do 
        echo $i
    done
else
    echo "Zla sciezka"
fi