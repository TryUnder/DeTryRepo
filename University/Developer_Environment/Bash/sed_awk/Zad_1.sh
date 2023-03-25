#!/usr/bin/bash

# Przy pomocy narzędzia sed w pliku tekstowym zastąpić wszystkie prawidłowe adresy e-mail ciągiem znaków
# 'nobody@example.com'. W pliku z rozwiązaniem umieścić pełne wywołanie sed.

sed 's/[a-zA-Z]*[1-9]*@[a-zA-Z.0-9]*/nobody@example.com/' $1
