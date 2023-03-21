#!/bin/bash

# Ścieżka /usr/share/dict/words w systemie Linux definiuje dostęp do pliku zawierającego listę słów.
# Wykorzystując polecenie grep oraz wyrażenia regularne wyświetlić słowa zawierające występujące na przemian samogłoski
# i inne znaki (np. esemesować).
# W rozwiązaniu umieścić należy jedynie wywołanie polecenia grep wraz z wszystkimi argumentami.

grep -E '^([bcdfghjklmnprstwkxBCDFGHJKLMNPRSTWKX]{1}[aeiouyAEIOUY]{1})+$' /usr/share/dict/words
