# 23. Sprawdz zawartosc zmiennej TERM za pomoca echo oraz set i grep. Jakie sa róznice
# w wynikach?

echo $TERM
set | grep "xterm"

# echo wyświetla tekst ze standardowego wejścia
# set wyświetla wszystkie zmienne środowiskowe systemu
# set z grepem pozwala wyświetlić interesujące nas zmienne
