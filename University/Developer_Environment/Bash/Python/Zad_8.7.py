import sys

def sortByLastName(name):
    return name.split()[-1]

def sortNames(file_path):
    names = []
    with open(file_path, 'r') as file_read:
        for line in file_read:
            partialNames = line.strip().split()
            name = " ".join(partialNames[1:])
            names.append(name)
        sorted_names = sorted(names, key=sortByLastName)
        for name in sorted_names:
            print(name)

sortNames(sys.argv[1])