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

DESC pracownicy;
SELECT pr1.nr_akt, pr1.nazwisko, pr1.imiona, pr1.placa, pr1.stanowisko,pr2.nr_akt,
Decode(nvl(pr1.przelozony,0),0,'brak',pr1.przelozony) AS "PRZELOZONY",
pr2.nazwisko || ' ' || pr2.imiona szef
FROM pracownicy pr1 LEFT JOIN pracownicy pr2 ON(pr1.przelozony=pr2.nr_akt);

/*
11. W oparciu o dane zawarte w tabeli Studenci wyświetl informację ilu studentów kierunku informatyka
studiuje na danym roku studiów (patrz Rys. 11).
*/

SELECT rok, count(*) AS "LICZBA STUDENTOW" FROM STUDENCI
WHERE UPPER(kierunek) LIKE ('INFORMATYKA')
GROUP BY rok;

/*
12. W oparciu o dane zawarte w tabeli Studenci wyświetl informację ilu studentów studiuje dany kierunek
w danym trybie studiów. W zestawieniu uwzględnij tylko podzbiory składające się z przynajmniej 100-u
studentów (patrz Rys. 12).
*/

SELECT tryb,kierunek, Count(nr_indeksu) AS "LICZBA_STUDENTOW"
FROM studenci
GROUP BY tryb,kierunek
HAVING count(nr_indeksu)>100;

/*
13. W oparciu o dane zawarte w tabeli Studenci wyświetl informację ile studentek (pań) studiuje w ramach
danego stopnia, roku i grupy dziekańskiej na kierunku Matematyka stosowana i technologie informatyczne.
Informację uzupełnij o średnią liczoną z średnich ocen studentek w danej grupie (patrz Rys. 13).
*/
SELECT * FROM studenci;
SELECT rok,stopien,gr_dziekan, count(imiona) AS "LICZBA_STUDENTEK", Round(Avg(srednia),2)
FROM studenci
WHERE imiona LIKE('%a') AND Upper(kierunek) LIKE('MATEMATYKA%')
GROUP BY rok, stopien, gr_dziekan;

/*
14. W oparciu o dane zawarte w tabeli Studenci wyświetl informacje o datach urodzeń najstarszego studenta
i najmłodszego studenta studiujących na danym kierunku danego roku studiów pierwszego stopnia w trybie
stacjonarnym. Listę uporządkuj w trybie nierosnącym wg liczby pełnych miesięcy jakie dzielą daty urodzeń
tych studentów pod warunkiem, że różnica ta wynosi przynajmniej 100 miesięcy (patrz Rys. 14).
*/

SELECT kierunek, rok,
To_char(max(data_urodzenia),'DD-MM-YYYY') AS "NAJMLODSZY STUDENT",
To_char(min(data_urodzenia),'DD-MM-YYYY') AS "NAJSTARSZY STUDENT",
Round(Cast(to_date(max(data_urodzenia))-to_date(min(data_urodzenia))AS INT)/31) AS "LICZBA_MIESIECY"
FROM studenci
WHERE stopien=1 AND Upper(tryb) LIKE('STACJONARNY')
GROUP BY kierunek,rok
HAVING Round(Cast(to_date(max(data_urodzenia))-to_date (min(data_urodzenia))AS INT)/31) > 100
ORDER BY 5 DESC;

/*
15. W oparciu o dane zawarte w tabeli Rejestry wyświetl informacje o liczbie wszystkich prób połowów
oraz o liczbie udanych połowów zrealizowanych w danym dniu tygodnia (słownie) danego roku
kalendarzowego w parzysty dzień miesiąca (2,4, …, 28, ew. 30). Dane wyświetl uporządkowane w trybie
niemalejącym kolejno wg liczby wszystkich prób połowów oraz liczby udanych połowów (patrz Rys. 15).
*/

SELECT count(nvl(id_gatunku,0)) AS "LICZBA WSZYSTKICH POLOWOW",
count(id_gatunku) AS "LICZBA UDANYCH POLOWOW",
To_char(czas,'day'),
Extract(YEAR FROM czas) as "ROK"
FROM rejestry
WHERE Mod(Cast(Extract(DAY FROM czas)AS INT),2)=0
GROUP BY To_char(czas,'day'),Extract(YEAR FROM czas)
ORDER BY count(nvl(id_gatunku,0)) DESC,count(id_gatunku) DESC;
