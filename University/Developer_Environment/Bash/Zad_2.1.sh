#!/bin/bash

if test $# -ne 1; then
    echo "Podaj argument, który jest plikiem"
elif [ -f $1 ]; then
    tac $1
fi
