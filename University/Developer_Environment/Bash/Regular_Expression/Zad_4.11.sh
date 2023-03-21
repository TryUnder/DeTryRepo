#!/bin/bash

# Ścieżka /usr/share/dict/words w systemie Linux definiuje dostęp do pliku 
# zawierającego listę słów. Wykorzystując polecenie grep oraz wyrażenia regularne 
# wyświetlić słowa zawierające zarówno sekwencje znaków „yes” oraz „no” 
# (niekoniecznie w tej kolejności, np. antyestrogenom). W rozwiązaniu 
# umieścić należy jedynie wywołanie polecenia grep wraz z wszystkimi argumentami.

grep -iE '^(?=.*yes)(?=.*no).*$' /usr/share/dict/words