#!/bin/bash

# Napisać skrypt wyświetlający tabliczkę mnożenia.
# Argumentem skryptu powinna być liczba określająca rozmiar tabliczki.

if [ $1 -gt 0 ] ; then
  echo -n " x |"
  for ((i=1; i<=$1; i++)) ; do
    echo -n "| "
    echo -n $i
  done

  echo ""
  echo " _"

  for ((i=1; i<=$1; i++)) ; do
    echo -n "" $i
    for ((j=1; j<=$1; j++)) ; do
      wynik=$(expr $i \* $j)
      if [[ $j -eq 1 ]] ; then
        echo -n "   " $wynik " "
      else
        echo -n $wynik " "
      fi
    done
    echo ""
  done
fi
