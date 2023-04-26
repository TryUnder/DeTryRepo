import sys
import random

def GenerateStatements(numberWords):
    words = []
    with open('/usr/share/dict/words', 'r') as f:
        for line in f:
            word = line.strip()
            if word.isalpha():
                words.append(word)
    statement = " ".join(random.sample(words, int(numberWords))).capitalize() + "."
    return statement

numberWords = sys.argv[1]
print(GenerateStatements(numberWords))
