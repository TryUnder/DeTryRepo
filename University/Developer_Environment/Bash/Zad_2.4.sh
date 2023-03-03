#!/bin/bash

if [ -f /etc/passwd ]; then
    echo "Plik istnieje. Nazwy uzytkownika na komputerze: "
    cut -d: -f1 /etc/passwd
else
    echo "Plik nie istnieje"
fi    
