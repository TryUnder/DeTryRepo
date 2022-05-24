# 7. Stwórz skrypt nadający prawo do zapisu dla grupy, plikowi podanemu jako parametr
# (wywołanie: skrypt nazwapliku). Jeśli nazwa pliku nie zostanie podana wyświetl
# komunikat o błędzie.

if [ -r $1 ]; then chmod g+w $1; else echo "Podaj prawidlowa nazwe pliku"; fi