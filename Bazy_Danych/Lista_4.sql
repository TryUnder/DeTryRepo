/*
1. W oparciu o dane zawarte w tabelach Pojazdy i Wlasciciele wyświetl uporządkowaną listę pojazdów
(od najstarszego) wyprodukowanych w 2018 roku wraz z danymi ich właścicieli (
*/

SELECT nr_rejestracyjny, marka, modell, wlasciciel, data_produkcji--Extract(YEAR FROM data_produkcji) as "DATA_PRODUKCJI"
FROM pojazdy JOIN wlasciciele using(id_wlasciciela)
WHERE Extract(YEAR FROM data_produkcji)LIKE '2018'
ORDER BY data_produkcji DESC;

/*
2. W oparciu o dane zawarte w tabelach Pojazdy i Wlasciciele wyświetl listę zawierającą dane pojazdów
starszych od swoich właścicieli mających status osoby fizycznej. Lista poza danymi pojazdów
i ich właścicieli powinna zawierać informację o wielkości różnicy pomiędzy wiekiem pojazdu i wiekiem
jego właściciela, podanej w dniach i pełnych latach (patrz Rys. 2 kolumny dni i lat). Dane uporządkuj
wg różnicy wieku w trybie nierosnącym.
*/

SELECT nr_rejestracyjny, marka, modell, data_produkcji, wlasciciel, data_up AS "DATA_URODZENIA",
Round(Months_between(data_up,data_produkcji)*31) AS "ROZNICA_W_DNIACH",
Abs(Cast(Extract(YEAR FROM data_produkcji)AS INT) - Cast(Extract(YEAR FROM data_up)AS INT)) AS "ROZNICA_W_LATACH"
FROM pojazdy JOIN wlasciciele USING(id_wlasciciela)
WHERE data_produkcji<data_up AND UPPER(status_wlasciciela) LIKE('OSOBA_FIZYCZNA')
ORDER BY ROZNICA_W_LATACH DESC;

/*
3. W oparciu o dane zawarte w tabelach Pracownicy i Stanowiska wyświetl listę pracowników, których płaca
nie mieści się w widełkach wynagrodzeń przewidzianych dla stanowisk, na których aktualnie pracują.
Zawartość listy zgodnie z Rys. 3 (bez analizy okresów zatrudnienia).
*/

SELECT nr_akt, nazwisko, stanowisko, placa, placa_min, placa_max
FROM pracownicy JOIN stanowiska using(stanowisko)
WHERE placa NOT BETWEEN placa_min AND placa_max;

/*
4. W oparciu o dane zawarte w tabelach Rejestry, Wedkarze, Gatunki i Lowiska wyświetl listę wszystkich
udanych połowów ryb (tj. id_gatunku posiada wartość) podając dane wędkarza, nazwy gatunków i łowisk.
Dane wyświetl chronologicznie wg dat zdarzeń połowów (patrz Rys. 4).
*/

SELECT id_gatunku, nazwisko,imiona, gatunki.nazwa, waga, dlugosc,
To_char(czas,'YYYY-MM-DD') AS "DATA POLOWU"
FROM rejestry JOIN wedkarze USING(id_wedkarza) JOIN gatunki USING(id_gatunku) JOIN lowiska USING(id_lowiska)
ORDER BY czas;

/*
5. Zadanie stanowiące rozszerzenie zadania 4. W oparciu o dane zawarte w tabelach Rejestry, Wedkarze,
Gatunki i Lowiska wyświetl informacje o wszystkich próbach połowów ryb na przestrzeni ostatniego roku
(względem aktualnego dnia). W przypadku braku połowu w ramach kolumny gatunek umieść frazę „ brak
polowu” (patrz Rys. 5). Dane wyświetl chronologicznie wg dat zdarzeń połowów.
*/

SELECT * FROM rejestry;
SELECT * FROM wedkarze;
SELECT * FROM gatunki;
SELECT * FROM lowiska;

SELECT id_gatunku, nazwisko,imiona, gatunki.nazwa, waga, dlugosc,
To_char(czas,'YYYY-MM-DD') AS "DATA POLOWU"
FROM rejestry JOIN wedkarze USING(id_wedkarza) LEFT JOIN gatunki USING(id_gatunku) JOIN lowiska USING(id_lowiska)
WHERE To_char(czas,'YYYY') IN ('2020','2021')
ORDER BY id_gatunku;
