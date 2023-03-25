#!/bin/bash

# Za pomocą skryptu awk w dowolnym pliku źródłowym języka C++ sprawdzić 
# liczbę wystąpowania pętli (liczbę wystąpień słów kluczowych for, while, until).

zrodlo=$1


num_for=$(awk '/\<for\>/ {count++}END{print count}' "$zrodlo")
num_while=$(awk '/\<while\>/ {count++} END {print count}' "$zrodlo")
num_until=$(awk '/\<until\>/ {count++} END {print count}' "$zrodlo")

echo "Liczba wystąpień słów kluczowych for: $num_for"
echo "Liczba wystąpień while: $num_while"
echo "Liczba wystąpień until: $num_until"