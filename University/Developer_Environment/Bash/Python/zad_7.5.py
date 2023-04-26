def validatePesel(pesel) -> bool: 
    if len(pesel) != 11 :
        return False

    multipliers = [1, 3, 7, 9, 1, 3, 7, 9, 1, 3]
    sum_t = 0

    for i in range(0, len(pesel) - 1):
        sum_t += int(pesel[i]) * multipliers[i % 4]

    modulo = sum_t % 10
    lastDigit = int(pesel[-1])

    if modulo == 0:
        return lastDigit == 0
    else: 
        return lastDigit == 10 - modulo

def getBirthDate(pesel):
    year = int(pesel[0:2])
    month = int(pesel[2:4])
    day = int(pesel[4:6])
    if month > 80:
        year += 1800
        month -= 80
    elif month > 60:
        year += 2200
        month -= 60
    elif month > 40:
        year += 2100
        month -= 40
    elif month > 20:
        year += 2000
        month -= 20
    else:
        year += 1900
    print("Data urodzenia: ", day, ".", month, ".", year)

def getSex(pesel):
    if int(int(pesel[9]) % 2) == 0:
        print("Plec: Kobieta")
    else:
        print("Plec: Mezczyzna")

pesel = "61033015337"

if validatePesel(pesel) == True:
    print("Pesel jest prawidlowy")
    getBirthDate(pesel)
    getSex(pesel)
else:
    print("Pesel jest nieprawidlowy")

