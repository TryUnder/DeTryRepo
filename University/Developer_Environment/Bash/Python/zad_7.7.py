import random

randSeq = input("Wprowadz, ile ciagow znakow chcesz wygenerować: ")
randChars = input("Wprowadz, z ilu znakow ma sie skladac kazdy ciag: ")

def generateStrings(randSeq, randChars):
    for i in range(0, int(randSeq)):
        randString = ""
        for j in range(0, int(randChars)):
            randString += chr(random.randint(65, 90))
        print(randString)

generateStrings(randSeq, randChars)