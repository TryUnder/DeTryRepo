import Zad_8_3

def LongestLine(fileName):
    with open(fileName, 'r') as read_file:
        longest = max(read_file, key=len)
        print("Najdluzsza linia w pliku: ", longest)

if __name__ == '__main__':
    import sys
    if len(sys.argv) < 1:
        print("Podaj nazwe pliku")

    Zad_8_3.zliczLinie(sys.argv[1])
    Zad_8_3.zliczZnaki(sys.argv[1])
    print("----")
    LongestLine(sys.argv[1])