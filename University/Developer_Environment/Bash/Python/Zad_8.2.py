#!/usr/bin/python3

import sys
import io

if len(sys.argv)<3:
    print('Podaj nazwe pliku txt wej i wyj oraz liczbe - 1 > Z Windows -> Unix')
    print('2 Z Unix > Windows')
    sys.exit(1)

with open(sys.argv[1], 'r') as file_input:
    content = file_input.read()

if int(sys.argv[2]) == 1:
    with open(sys.argv[1], 'w', newline='\n') as output:
        output.write(content)

elif int(sys.argv[2]) == 2:
    with open(sys.argv[1], 'w', newline='\r\n') as output:
        output.write(content)
