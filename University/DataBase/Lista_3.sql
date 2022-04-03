--Zad.1
    --Wyświetl o jaką kwotę (wartość bezwzględna) odbiegają zarobki (pełna pensja) aktualnych
    --pracowników (tabela Pracownicy) od średniej krajowej wynoszącej 5411.45 PLN. Uzyskane
    --wartości zaokrąglij kolejno do 1-ego miejsca po przecinku stosując funkcje Round oraz do pełnych
    --100-ek stosując funkcję Trunc. Wyniki przedstaw od najlepiej do najgorzej zarabiających podając
    --m.in. ich nazwisko, zajmowane stanowisko oraz pensję (Rys. 1).
SELECT * FROM pracownicy;

SELECT
nazwisko,stanowisko,
Abs(Sum(placa+placa*dod_staz/100+Nvl(dod_funkcyjny,0)-Nvl(koszt_ubezpieczenia,0))/Count(*)-5411.45) AS "Roznica zarobkow",
Round(Abs(Sum(placa+placa*dod_staz/100+Nvl(dod_funkcyjny,0)-Nvl(koszt_ubezpieczenia,0))/Count(*)-5411.45),1) AS "Zaok1",
Trunc(Abs(Sum(placa+placa*dod_staz/100+Nvl(dod_funkcyjny,0)-Nvl(koszt_ubezpieczenia,0))/Count(*)-5411.45),-0) AS "Zaok2"
FROM pracownicy
GROUP BY stanowisko, nazwisko
ORDER BY ;

  --Zad.2
  --Wyświetl wartości płac (kolumna placa) poszczególnych pracowników pomniejszone o 17% podatek
  --(płaca netto). W osobnej kolumnie wyświetl płacę netto zaokrągloną do setek (np. 2343.12 ? 2300)
  --a w ostatniej różnice w poszczególnych płacach wynikające z rodzaju zastosowanych funkcji
  --zaokrąglających wartości płac „do setek”

SELECT nazwisko, stanowisko,
placa*0.83 AS "placa_netto",
Round(placa*0.83,-2),
Round(placa*0.83,-2)-Trunc(placa*0.83,-2)
FROM pracownicy;

  --Zad.3
  --Napisz zapytanie obliczające wartość następującego wyrażenia
  --√(11.234+4√2399+√(1234.56)+log7 log12345) oraz wartości jakie uzyska się po zastosowaniu
  --wobec tego wyrażenia funkcji Round, Trunc, Ceil oraz Floor.

SELECT
sqrt(Power(11.23,4)+sqrt(sqrt(2399+sqrt(1234.56)))+Log(Log(12345,10),7)) AS "BASIC",
Round(sqrt(Power(11.23,4)+sqrt(sqrt(2399+sqrt(1234.56)))+Log(Log(12345,10),7))) AS "ROUND",
Trunc(sqrt(Power(11.23,4)+sqrt(sqrt(2399+sqrt(1234.56)))+Log(Log(12345,10),7))) AS "TRUNC",
Ceil(sqrt(Power(11.23,4)+sqrt(sqrt(2399+sqrt(1234.56)))+Log(Log(12345,10),7))) AS "CEIL",
Floor(sqrt(Power(11.23,4)+sqrt(sqrt(2399+sqrt(1234.56)))+Log(Log(12345,10),7))) AS "FLOOR"
FROM dual;

  --Zad.4
  --Wyświetl kolejno przedział 101 lat i 11 miesięcy oraz przedział 25 dni 3 godziny 5 minut i 36.6
  --sekund oraz znacznik czasowy obejmujący łącznie oba te przedziały (Rys. 4).

SELECT
Interval '25 03:05:36.6' DAY(2) to second,
Timestamp '101-11-25 03:05:36.6'
FROM dual;

  --Zad.5
  --Wyświetl informacje o tym jaka data będzie za 4321 dni i jaka data była 4321 dni temu
  --oraz w odrębnych kolumnach ile pełnych miesięcy i ile pełnych tygodni dzieli obie daty.

SELECT
systimestamp AS "DZISIAJ",
systimestamp+4321 AS "za 4321 dni",
systimestamp-4321 AS "4321 dni temu",
Trunc(Months_between(sysdate+4321, sysdate-4321)) AS "Liczba miesiecy",
Trunc(Months_between(sysdate+4321, sysdate-4321)/7) AS "Liczba tygodni",
To_char(sysdate+4321,'YYYY-MM-DD D DD DDD DAY month w ww cc')
FROM dual;

  --Zad.6
  --Wyświetl datę i czas jaki był 1234 dni, 18 godzin i 6 minut temu oraz jaki będzie za
  --189 lat i 5 miesięcy (Rys. 6).

SELECT
To_char(Sysdate-Interval '1234 18:06:00' Day(4) to second,'YYYY-MM-DD HH:MM:SS'),
To_char(Sysdate+Interval '189-05 ' Year(3) to month,'YYYY-MM-DD HH:MM:SS')
FROM dual;

  --Zad.7
  --Wyświetl ile czasu upłynęło od 2013.12.15 21:14:09 do 2021.02.11 7:17. Wynik podaj w dwóch
  --formach/kolumnach jak na Rys. 7.

SELECT
To_date('2021-02-11','YYYY-MM-DD')-To_date('2013-12-15','YYYY-MM-DD') AS "Roznica w dniach",
Round(Months_between(To_date('2021-02-11','YYYY-MM-DD'),To_date('2013-12-15','YYYY-MM-DD'))) AS "Roznica_w_miesiacach",
(Timestamp '2021-02-11 7:17:00' - Timestamp '2013-12-15 21:14:09') YEAR TO MONTH AS "Liczba lat i miesiecy"
FROM dual;

  --Zad.8
  --W odrębnych kolumnach kolejno wyświetl aktualny rok, miesiąc, dzień oraz aktualną godzinę,
  --minutę i sekundę (jak na Rys. 8).

SELECT
Extract(YEAR FROM Sysdate) AS "ROK",
Extract(MONTH FROM Sysdate) AS "MIESIAC",
Extract(DAY FROM Sysdate) AS "DZIEN",
Extract(HOUR FROM Systimestamp) AS "GODZINA",
Extract(MINUTE FROM Systimestamp) AS "MINUTA",
Round(Extract(SECOND FROM Systimestamp)) AS "SEUNDA"
FROM dual;

  --Zad.9.
  --W oparciu o dane zawarte w tabeli Studenci wyświetl studentów, którzy dzisiaj obchodzą urodziny

SELECT*
FROM studenci
WHERE Extract(DAY FROM Sysdate) LIKE Extract(DAY FROM data_urodzenia)
AND Extract(MONTH FROM Sysdate) LIKE Extract(MONTH FROM data_urodzenia);

  --Zad.10
  --Napisz zapytanie zwracające informację jaka data będzie za 123 miesiące oraz który to będzie
  --tydzień w roku.

SELECT
To_char(Add_months(sysdate,123),'YYYY-MM-DD') AS "DATA ZA 123 MIESIACE",
Floor(To_number(To_date(Add_months(sysdate,123)) - To_date('2032-01-01','YYYY-MM-DD'))/7) AS "TYDZIEN W ROKU"
FROM dual;

  --Zad.11
  --Wyświetl datę ostatniego dnia aktualnego miesiąca oraz informację jaki to będzie dzień tygodnia
  --(słownie) np. 21/10/31 niedziela.

SELECT
To_char(Last_day(Sysdate),'YYYY-MM-DD day')
FROM dual;

  --Zad.12
  --Zaokrąglij aktualną datę kolejno do miesięcy (funkcją Round), lat (funkcją Trunc) i wieków.

SELECT
Sysdate AS "AKTUALNA DATA",
Round(Sysdate,'MM') AS "ZAOKRAGLANA DO MIESIECY",
Round(Sysdate,'YYYY') AS "ZAOKRAGLANA DO LAT",
To_char(Round(Sysdate,'CC'),'YYYY-MM-DD') AS "ZAOKRAGLANA DO WIEKOW"
FROM dual;

  --Zad.13
  --W oparciu o dane zawarte w tabeli Studenci wyświetl nazwiska i imiona studentów, których imię
  --rozpoczyna się na 'M' uporządkowanych od najstarszego do najmłodszego z informacją ile aktualnie
  --mają lat (Rys. 11). Zaproponuj dwa rozwiązania w zakresie szacowania wieku studentów: pełne
  --skończone lata oraz tzw. metodą „rocznikową”.

SELECT
imiona, nazwisko,
To_char(data_urodzenia,'YYYY-MM-DD') AS "DATA_URODZENIA",
Trunc((Sysdate-data_urodzenia)/365) AS "AKTUALNA LICZBA LAT"
FROM studenci
WHERE Upper(imiona) LIKE 'M%'
ORDER BY data_urodzenia DESC;

  --Zad.14
  --Dokonaj konwersji aktualnego znacznika czasowego do daty (zastosuj funkcję Cast; Rys. 12).

SELECT
Cast(Systimestamp AS DATE)
FROM dual;

  --Zad.15
  --W ramach zapytania dokonaj połączenia dwóch łańcuchów '987' i '654' oraz wyświetl wynik
  --różnicy otrzymanej liczby i wartości 123456 (zastosuj konwersję typów; Rys. 13).

SELECT
'987' || '654' AS "STRING ADDICTION VER 1",
Concat('987','654') AS "STRING ADDICTION VER 2",
Cast(Concat('987','654')AS INT) - 123456 AS "DIFFERENCE"
FROM dual;

  --Zad.16
  --Wyświetl aktualny wiek cyframi rzymskimi.

SELECT
To_char(Ceil(Extract(YEAR FROM Sysdate)/100),'RM') AS "WIEK"
FROM dual;

  --Zad.17
  --Wyświetl aktualną datę w postaci np. część, jest dzisiaj czwartek, 2 styczeń 2021 roku.

SELECT
'CZESC! ' || 'JEST DZISIAJ: ' || To_char(Sysdate,'DAY') || ' ' || To_char(Sysdate,'DD-MM-YYYY')
FROM dual;

  --Zad.18
  --Wyświetl wiek, kwartał, miesiąc, tydzień miesiąca oraz dzień tygodnia daty podanej w formie
  --'27-09-1959' (patrz przykład na Rys. 14).

SELECT
Ceil(To_char(Sysdate,'YYYY')/100) || ' WIEK ' || To_char(Sysdate,'Q') || ' KWARTAL '
|| To_char(sysdate,'MONTH') || To_char(sysdate,'W') || ' TYDZIEN ' || To_char(Sysdate,'DAY')
AS "SZCZEGOLY_DATY"
FROM dual;

  --Zad.19
  --W oparciu o dane zawarte w tabeli Studenci wyświetl dane studentek (patrz Rys. 15), które urodziły
  --się w wakacyjny weekend (w lipcową lub sierpniową sobotę lub niedzielę) pod warunkiem,
  --że dzień miesiąca nie jest dzielnikiem liczby 5 (np. 6.07.1999 ale 10.08.1999 już nie; Rys. 15).

SELECT
imiona, nazwisko, data_urodzenia,
To_char(data_urodzenia,'DAY'),
To_char(data_urodzenia,'YYYY-MM-DD')
FROM studenci
WHERE imiona LIKE '%a'
AND Extract(MONTH FROM data_urodzenia) IN (7,8)
AND Rtrim(To_char(data_urodzenia,'DAY')) IN ('SOBOTA','NIEDZIELA')
AND Mod(Cast(Extract(DAY FROM data_urodzenia)AS INT),5) != 0;

  --Zad.20
  --W oparciu o dane zawarte w tabeli Pracownicy wyświetl aktualnie pracujących pracowników,
  --porządkując ich według stażu pracy podanego w pełnych latach i miesiącach pracy oraz kolejności
  --alfabetycznej nazwisk (Rys. 16).

--do dokonczenia
SELECT imiona,nazwisko,stanowisko,
To_char(data_zatr,'YYYY-MM-DD') AS "DATA_ZATRUDNIENIA",
To_char(data_zwol,'YYYY-MM-DD') AS "DATA_ZWOLNIENIA",
Extract(YEAR FROM Sysdate) - Extract(YEAR FROM data_zatr) || ' lat, oraz ' ||
Cast(Extract(MONTH FROM Sysdate)AS INT) - Cast(Extract(MONTH FROM data_zatr)AS INT) || ' miesiecy' AS "Pracuje: "
FROM pracownicy
WHERE data_zwol>sysdate
OR data_zwol IS NULL;

  --Zad.23
  --W oparciu o dane zawarte w tabeli Studenci wyświetl personalia studentów (kolumny imiona
  --i nazwisko), których imię składa się dokładnie z 5 liter a nazwisko rozpoczyna od frazy Ko a kończy
  --frazą ski (patrz Rys. 18).

SELECT imiona, nazwisko
FROM studenci
WHERE
REGEXP_LIKE(imiona,'^[[:alpha:]]{5}$') AND
REGEXP_LIKE(nazwisko,'^Ko.*ski$');

  --Zad.24
  --W oparciu o dane zgromadzone w tabeli Studenci za pośrednictwem wyrażeń regularnych dokonaj
  --prezentacji zawartości kolumny adres w „zaszyfrowanej” formie, w której to każdy wyraz
  --składający się z przynajmniej 3 liter będzie zastąpiony frazą Alpha a każda cyfra/liczba będzie
  --zastąpiona frazą Digit (patrz Rys. 19).

SELECT adres, REGEXP_REPLACE(REGEXP_REPLACE(adres,'[[:alpha:]]{3,}','Alpha'),'[[:digit:]]{1,}','Digit')
FROM studenci;

  --Zad.25
  --W oparciu o dane zgromadzone w tabeli Studenci wyświetl adresy (kolumna adres) wskazujące
  --na ulice (ul. na początku adresu), których nazwa rozpoczyna się od litery D, O, P lub T,
  --a numer domu/budynku to dokładnie 188 (patrz Rys. 20).

SELECT adres FROM studenci
WHERE
REGEXP_LIKE(adres,'^ul.\s(D|O|P|T)[[:alpha:]]{1,}\s188');

  --Zad.26
  --W oparciu o dane zgromadzone w tabeli Studenci wyświetl adresy (kolumna adres),
  --w ramach których zarówno nazwy ulic lub alei jak i nazwa miejscowości składają się dokładnie
  --z dwóch przynajmniej 5-cio literowych wyrazów (patrz Rys. 21).

SELECT
adres
FROM studenci
WHERE
REGEXP_LIKE(adres,
'^(ul.|al.)\s[[:upper:]]{1}[[:alpha:]]{4,}\s[[:upper:]]{1}[[:alpha:]]{4,}\s\d{1,}\s\S{1,}\s[[:upper:]]{1}[[:alpha:]]{4,}\s[[:upper:]]{1}[[:alpha:]]{4,}');
