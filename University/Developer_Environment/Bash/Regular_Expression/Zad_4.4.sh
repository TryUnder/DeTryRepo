#!/bin/bash

# Ścieżka /usr/share/dict/words w systemie Linux definiuje dostęp do pliku zawierającego listę słów.
# Wykorzystując polecenie grep oraz wyrażenia regularne wyświetlić słowa zawierające dokładnie jedną,
# dowolną samogłoskę (np. bazgrz).
# W rozwiązaniu umieścić należy jedynie wywołanie polecenia grep wraz z wszystkimi argumentami.

grep -E '^[bcdfghjklmnprstwkxBCDFGHJKLMNPRSTWKX]*[aeiouyAEIOUY]{1}[bcdfghjklmnprstwkxBCDFGHJKLMNPRSTWKX]*$' /usr/share/dict/words
