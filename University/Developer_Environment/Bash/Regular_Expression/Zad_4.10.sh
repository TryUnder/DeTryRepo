#!/bin/bash

# Ścieżka /usr/share/dict/words w systemie Linux
# definiuje dostęp do pliku zawierającego listę słów.
# Wykorzystując polecenie grep oraz wyrażenia
# regularne wyświetlić słowa zawierające sylabę
# „cie” (np. ablaktujcie).
# W rozwiązaniu umieścić należy jedynie wywołanie
# polecenia grep wraz z wszystkimi argumentami.

grep -E --color=auto '(...).*\1' /usr/share/dict/words
