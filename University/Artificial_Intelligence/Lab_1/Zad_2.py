def find_number(b,c): 
    base_number = b 
    counter = c

    i = input("Podaj liczbe: ")
    i = int(i)
    if base_number > i:
        print("Liczba jest wieksza")
        find_number(base_number,counter+1)
    elif base_number == i:
            print ("Zgadles! i zajelo ci to:",counter, "prób")
    else:
        print("Liczba jest mniejsza")
        find_number(base_number,counter+1)
find_number(50,1)