# 6. Napisz skrypt, który umożliwi dodawanie rozszerzenia do pliku. Skrypt powinien
# najpierw spytać o nazwę pliku, a następnie wyświetlić listę rozszerzeń (np.: .old, _bak,
# .--001) do wyboru.

echo "Podaj sciezke do pliku"
read file

echo "Wybierz rozszerzenie"
echo "PNG - 1"
echo "JPG - 2"
echo "DOC - 3"
echo "PY  - 4"
read extension

case $extension in
    "1") mv $file $file.png ;;
    "2") mv $file $file.jpg ;;
    "3") mv $file $file.doc ;;
    "4") mv $file $file.py  ;;
    *) echo "Blad" ;;
esac