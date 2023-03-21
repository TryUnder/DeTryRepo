#!/bin/bash

# Ścieżka /usr/share/dict/words w systemie Linux definiuje dostęp do pliku zawierającego listę słów.
# Wykorzystując polecenie grep oraz wyrażenia regularne wyświetlić słowa zawierające co najmniej
# cztery wystąpienia znaku „o” (np. anamorfozowo).
# W rozwiązaniu umieścić należy jedynie wywołanie polecenia grep wraz z wszystkimi argumentami.

grep -E '([[:alpha:]]*[o][[:alpha:]]*){4,}' /usr/share/dict/words
