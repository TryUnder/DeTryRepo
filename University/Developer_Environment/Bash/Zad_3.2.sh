#!/bin/bash

#Napisać skrypt, który dla wszystkich plików, których nazwa kończy się rozszerzeniem .sh,
#sprawdzi czy pierwsza linia zawiera odwołanie do interpretera bash
#(dodatkowo: sprawdzić, czy ścieżka do interpretera jest prawidłowa).

if [ "$(head -1 $0)" == "#!/bin/bash" ] ; then
  for plik in $(ls) ; do
    if [[ "$plik" == *.sh ]]; then
      if [ "$(which bash)" == "#!/bin/bash)" ] ; then
        echo "Ścieżka do interpretera jest prawidłowa"
      else
        echo "Ścieżka do interpretera jest nieprawidłowa"
      fi
    fi
  done
else
    echo "Pierwsza linia nie zawiera odwołania do interpretera bash"
fi
