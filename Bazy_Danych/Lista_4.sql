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
to_date(data_up)-to_date(data_produkcji) AS "ROZNICA_W_DNIACH",
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
DESC gatunki;
SELECT id_gatunku, nazwisko,imiona,
CASE WHEN gatunki.nazwa IS NULL THEN 'BRAK_POLOWU' ELSE gatunki.nazwa END AS "GATUNEK",
waga, dlugosc,
To_char(czas,'YYYY-MM-DD') AS "DATA POLOWU"
FROM rejestry JOIN wedkarze USING(id_wedkarza) LEFT JOIN gatunki USING(id_gatunku) JOIN lowiska USING(id_lowiska)
WHERE czas BETWEEN sysdate-Interval '1-00' YEAR TO MONTH and sysdate
ORDER BY id_gatunku;

/*
6.W oparciu o dane zawarte w tabelach Licencje i Wedkarze wyświetl listę wędkarzy, którzy w aktualnym roku
kalendarzowym opłacili już roczną składkę podstawową na rzecz dowolnego okręgu PZW (Rys. 6).
*/

SELECT * FROM licencje JOIN wedkarze using(id_wedkarza)
WHERE ROK LIKE Extract(YEAR FROM sysdate) AND OD_DNIA LIKE '01-01' AND DO_DNIA LIKE '31-12'
AND REGEXP_LIKE(id_okregu,'PZW') AND rodzaj='podstawowa';

/*
7 i 8. W oparciu o dane zawarte w tabelach Licencje i Wedkarze wyświetl listę wszystkich wniesionych opłat
okresowych (dziennych) w 2019 roku. Struktura listy jak na Rys. 7.
Zadanie stanowiące rozszerzenie zadania 7. W oparciu o dane zawarte w tabelach Licencje, Oplaty
i Wedkarze wyświetl listę wszystkich wniesionych opłat okresowych (dziennych) w 2019 roku. W ramach
prezentowanej informacji podaj liczbę dni obowiązywania danej licencji oraz jej koszt (patrz Rys. 8;
uwaga, licencja obowiązuje na dany dzień co oznacza, że np. rozpoczęcie połowu o godz. 23:00
a zakończenie po 2-óch godzinach (tj. o godz. 1:00) wymaga zakupu licencji na 2 dni.
*/

SELECT id_wedkarza, nazwisko, id_okregu, id_licencji, oplaty.rok, od_dnia, do_dnia,
to_date(do_dnia,'DD-MM')-to_date(od_dnia,'DD-MM') AS "LICZBA_DNI",
(to_date(do_dnia,'DD-MM')-to_date(od_dnia,'DD-MM'))*dzienna_oplata AS "OPLATA"
FROM licencje JOIN wedkarze using(id_wedkarza) JOIN oplaty using(id_okregu)
WHERE licencje.rok LIKE '2019' AND oplaty.rok LIKE '2019' AND rodzaj='dodatkowa';

/*
9.W oparciu o dane zawarte w tabeli Pracownicy wyświetl listę porównującą parami (tj. każdy z każdym)
płace pracowników działu 20-ego z płacami pracowników działu 30-ego (bez analizy okresu zatrudnienia;
patrz Rys. 9).
*/

SELECT * FROM pracownicy;
select p1.nr_akt, p1.id_dzialu, p1.placa, p2.nr_akt, p2.id_dzialu, p2.placa
FROM pracownicy p1 CROSS JOIN pracownicy p2
WHERE p1.id_dzialu=20 AND p2.id_dzialu=30;

/*
10. W oparciu o dane zawarte w tabeli Pracownicy wyświetl listę pracowników i ich przełożonych (Rys. 10).
W przypadku braku przełożonego w ramach kolumny przełożony zastosuj frazę „ Brak” (bez analizy okresu
zatrudnienia).
*/
DESC przelozony;
SELECT pr1.nr_akt, pr1.nazwisko, pr1.imiona, pr1.przelozony

FROM pracownicy pr1 CROSS JOIN pracownicy pr2
WHERE pr1.nr_akt LIKE pr2.nr_akt;
