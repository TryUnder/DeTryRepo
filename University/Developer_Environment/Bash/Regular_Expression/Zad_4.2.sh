#!/bin/bash

# Ścieżka /usr/share/dict/words w systemie Linux definiuje dostęp do pliku zawierającego listę słów.
# Wykorzystując polecenie grep oraz wyrażenia regularne wyświetlić słowa zawierające sekwencje „yes” albo „no”
# (np. antyestetyk, adnotacja).
# W rozwiązaniu umieścić należy jedynie wywołanie polecenia grep wraz z wszystkimi argumentami.

grep -E 'yes|no' /usr/share/dict/words
