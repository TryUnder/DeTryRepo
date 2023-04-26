def zliczLinie(name):
    count = 0
    with open(name, 'r') as file_read:
        for line in file_read:
            count += 1
        print (count)

def zliczZnaki(name):
    count = 0
    with open(name, 'r') as file_read:
        for i in file_read:
            count += len(i)
        print(count)

if __name__ == '__main__':
    import sys
    if len(sys.argv) < 1:
        print("Podaj nazwe pliku")

    zliczLinie(sys.argv[1])
    zliczZnaki(sys.argv[1])
