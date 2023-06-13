import random
import sys

numOfWordsInStatement = int(sys.argv[1])
generateWords = []
lines = []

with open("/usr/share/dict/words","r") as openFile:
    lines = openFile.readlines()

numOfWords = len(lines)

for i in range(numOfWordsInStatement):
    generateWords.append(lines[random.randint(0, numOfWords)].strip())
    
print(generateWords)
statement = ""

for i in range(len(generateWords)):
    if i == 0:
        statement += generateWords[i][0].upper() + generateWords[i][1:]
    elif i+1 == len(generateWords):
        statement += generateWords[i]
        statement += "."
    else:
        statement += generateWords[i] + " "

print(statement)