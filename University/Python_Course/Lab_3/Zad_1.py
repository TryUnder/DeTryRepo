# Zad_1 - Wyjatki

def odwroc_wart_Zad_1(tablica: list, indeks: int) -> float:
    try:
        return 1/tablica[indeks]

    except ZeroDivisionError:
        print("Element listy nie może być zerem")
        print("...")
    except IndexError:
        print("Podany indeks jest spoza zakresu tablicy")
        print("...")

    finally:
        print("Tutaj wykonały się instrukcje z klauzuli finally")


# Zad_2 - Wyjatki

def odwroc_wart_Zad_2(tablica: list, indeks: int) -> float:
    try:
        wartosc = 1/tablica[indeks]

    except ZeroDivisionError:
        print("Element listy nie może być zerem")
        print("...")
    except IndexError:
        print("Podany indeks jest spoza zakresu tablicy")
        print("...")
    else:
        print("Tutaj wykonały się instrukcje z else")

    finally:
        print("Tutaj wykonały się instrukcje z klauzuli finally")
    
    return wartosc
    
print("\nZad_1\n")

print(odwroc_wart_Zad_1([1,2,3,0], 2))

print("\nZad_2\n")

odwroc_wart_Zad_2([0,2,0,4,5], 4)

# Zad_3 - Funkcje wbudowane

def sumOfNumbers(lista: list) -> int:
    sum = 0
    for i in range(len(lista)):
        if isinstance(lista[i], int) and (lista[i] > 0):
            sum += lista[i]
    return sum

print("\nZad_3\n")

print("Suma:", sumOfNumbers(['1', 2, '3', 4, 5, '-1', '-2', -3, -4, -5]))

print("\nZad_4\n")

a = ['abba', 'queen', 'acdc', 'soad']
b = [1988, 1981, 1973, 1999]

# do lambdy przekazujemy customowy comparator, w którym sami definiujemy kolejność sortowania

def compare(x):
    return b[a.index(x)]

def sortList(listaA: list, listaB: list):
    return sorted(listaA, key=compare)

print(sortList(a, b))