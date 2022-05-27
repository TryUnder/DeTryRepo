# 4. Napisz skrypt wypisujący tylko ilość słów w pliku tekstowym podanym jako
# parametr.

wc --words $HOME/$1 | cut -d ' ' -f 1 