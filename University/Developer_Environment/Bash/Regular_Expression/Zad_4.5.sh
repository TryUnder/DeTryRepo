#!/bin/bash

# Ścieżka /usr/share/dict/words w systemie Linux definiuje dostęp do pliku zawierającego listę słów.
# Wykorzystując polecenie grep oraz wyrażenia regularne wyświetlić słowa
# zawierające co najmniej pięć kolejnych znaków nie będących samogłoskami (np. zmarszczka).
# W rozwiązaniu umieścić należy jedynie wywołanie polecenia grep wraz z wszystkimi argumentami.

grep -E '[bcdfghjklmnprstwkxBCDFGHJKLMNPRSTWKX]{5,}' /usr/share/dict/words
