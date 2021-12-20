/*
1. W oparciu o dane zawarte w tabelach Pojazdy i Wlasciciele wyświetl uporządkowaną listę pojazdów
(od najstarszego) wyprodukowanych w 2018 roku wraz z danymi ich właścicieli (
*/

SELECT nr_rejestracyjny, marka, modell, wlasciciel, data_produkcji--Extract(YEAR FROM data_produkcji) as "DATA_PRODUKCJI"
FROM pojazdy JOIN wlasciciele using(id_wlasciciela)
WHERE Extract(YEAR FROM data_produkcji)LIKE '2018'
ORDER BY data_produkcji DESC;

/*x
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

/*
16. W oparciu o dane zawarte w tabelach Pojazdy i Wlasciciele wyświetl informację o właścicielach,
którzy posiadają do 7-miu do 16-tu pojazdów ciężarowych. Dane uzupełnij o informację z zakresu liczby
marek posiadanych przez danego właściciela a wyniki wyświetl uporządkowane w trybie nierosnącym
kolejno wg liczby posiadanych pojazdów oraz liczby marek (patrz Rys. 16).
*/

SELECT id_wlasciciela,wlasciciel,
count (id_wlasciciela) AS "LICZBA_POJAZDOW",
count (DISTINCT marka) AS "LICZBA_MAREK"
FROM pojazdy JOIN wlasciciele using(id_wlasciciela)
WHERE Upper(typ) LIKE ('SAM_CIEZAROWY')
GROUP BY wlasciciel, id_wlasciciela
HAVING count(id_wlasciciela) BETWEEN 7 AND 16
ORDER BY count(id_wlasciciela) DESC, count(DISTINCT marka) DESC;

/*
17. W oparciu o dane zawarte w tabelach Pracownicy i Dzialy wyświetl informację o średnich wartościach płac
(kolumna placa) pracowników aktualnie pracujących w poszczególnych działach firmy z uwzględnieniem
grupy pracowników nieposiadających przynależności do żadnego działu. Dane wyświetl uporządkowane
w trybie nierosnącym wg średniej płacy
*/

SELECT id_dzialu, nazwa,
Round(Avg(placa)) AS "SREDNIA_PLACA"
FROM pracownicy x LEFT JOIN dzialy USING (id_dzialu)
GROUP BY id_dzialu, nazwa
ORDER BY avg(placa) DESC;

/*
18. W oparciu o dane zawarte w tabelach Pracownicy i Dzialy wyświetl informacje o kosztach jakie ponosi
firma w poszczególnych miastach (z adresu działu) z tytułu wypłacania miesięcznej pensji swoim aktualnym
pracownikom (płaca+dodatki). Informację uzupełnij o dane w zakresie liczby wszystkich pracowników
pracujących w danym mieście oraz ilu z nich posiada ubezpieczenie. W zestawieniu uwzględnij
pracowników „nieposiadających działu” a dane wyświetl w trybie nierosnącym wg kosztów pracowniczych
*/

SELECT REGEXP_SUBSTR(adres,'Czestochowa|Radomsko|Katowice|Warszawa') AS "LOKALIZACJA",
Count(REGEXP_SUBSTR(nvl(adres,0),'Czestochowa|Radomsko|Katowice|Warszawa|0')) AS "LICZBA_PRACOWNIKOW",
Count(koszt_ubezpieczenia) AS "LICZBA_UBEZPIECZONYCH",
Round(Sum(placa+placa*dod_staz/100+Nvl(dod_funkcyjny,0)-Nvl(koszt_ubezpieczenia,0))) AS "KOSZTY_PRACOWNICZE"
FROM pracownicy x LEFT JOIN dzialy USING (id_dzialu)
GROUP BY REGEXP_SUBSTR(adres,'Czestochowa|Radomsko|Katowice|Warszawa')
ORDER BY Round(Sum(placa+placa*dod_staz/100+Nvl(dod_funkcyjny,0)-Nvl(koszt_ubezpieczenia,0))) DESC;

/*
19. W oparciu o dane zawarte w tabelach Pracownicy i Stanowiska wyświetl informacje w zakresie ilu
aktualnie pracowników pracuje na danym stanowisku (z uwzględnieniem nieobsadzonych stanowisk),
ile wynosi średnia, najniższa i najwyższa płaca pracownika pracującego na danym stanowisku.
Dane wyświetl uporządkowane w trybie niemalejącym kolejno wg liczy pracowników oraz średniej płacy
*/

SELECT pr.stanowisko,
Count(pr.stanowisko) AS "LICZBA_PRACOWNIKOW",
Round(Avg(placa),2) AS "SREDNIA PLACA",
Min(pr.placa+pr.placa*pr.dod_staz/100+Nvl(pr.dod_funkcyjny,0)-Nvl(pr.koszt_ubezpieczenia,0)) AS "NAJNIZSZA PLACA",
Max(pr.placa+pr.placa*pr.dod_staz/100+Nvl(pr.dod_funkcyjny,0)-Nvl(pr.koszt_ubezpieczenia,0)) AS "NAJWYZSZA PLACA"
FROM pracownicy pr RIGHT JOIN stanowiska st ON (pr.stanowisko=st.stanowisko)
WHERE data_zwol>sysdate OR data_zwol IS NULL
GROUP BY(pr.stanowisko)
ORDER BY Count(pr.stanowisko) DESC, Round(Avg(placa),2) DESC;

/*
20. W oparciu o dane zawarte w tabelach Rejestry i Gatunki wyświetl statystyki połowów poszczególnych
gatunków (włącznie z tym, które nigdy nie zostały nigdy złowione) w zakresie liczby złowionych sztuk,
łącznej i średniej ich wagi (z dokładnością do 1 grama) oraz średniej długości (z dokładnością do 0.1 cm.).
W zestawieniu uwzględnij również połowy nieudane wstawiając w kolumny id_gatunku i nazwa kolejno
frazy brak i brak połowu (patrz Rys. 20). Dane wyświetl uporządkowane w trybie nierosnącym wg liczby
złowionych ryb oraz wg nazwy gatunku (alfabetycznie).
*/
SELECT * FROM rejestry;
SELECT * FROM gatunki;

SELECT DISTINCT Decode(re.id_gatunku,NULL,'brak',re.id_gatunku) AS "ID_GATUNKU",
--Decode(re.id_gatunku,NULL,'brak_polowu',nazwa) AS "NAZWA",
nazwa,
Count(re.id_gatunku) AS "SZTUK",
Round(Sum(Nvl(re.waga,0)),3) AS "LACZNA_WAGA",
Round(Avg(Nvl(re.waga,0)),3) AS "SREDNIA_WAGA",
Round(Avg(Nvl(re.dlugosc,0)),1) AS "SREDNIA_DLUGOSC"
FROM rejestry re FULL JOIN gatunki ga ON(re.id_gatunku=ga.id_gatunku)
GROUP BY re.id_gatunku, nazwa
ORDER BY Count(re.id_gatunku)DESC, nazwa;

/*
21.W oparciu o dane zawarte w tabelach Rejestry i Lowiska wyświetl informacje o łowiskach, na których
złowiono przynajmniej 6 ryb i odnotowano przynajmniej 2 nieudane połowy w okresie trwającym 2 lata
21 dni 19 godzin i 28 sekund poczynając od godz. 7:05 w dniu 14.07.2018. Informację uzupełnij o liczbę
wędkarzy, którzy przynajmniej raz odwiedzili dane łowisko w rozpatrywanym okresie
*/

SELECT id_lowiska, nazwa,
Count(Nvl(id_gatunku,0)) AS "LICZBA_POLOWOW",
Count(id_gatunku) AS "LICZBA_RYB",
Count(DISTINCT id_wedkarza) AS "LICZBA_WEDKARZY"
FROM rejestry JOIN lowiska USING(id_lowiska)
WHERE (czas BETWEEN to_date('14-07-2018','DD-MM-YYYY') AND
to_date('14-07-2018','DD-MM-YYYY') + Interval '2-00' YEAR TO MONTH + Interval '21 19:00:28' DAY TO SECOND)
GROUP BY id_lowiska, nazwa
HAVING Count(id_gatunku)>=6 AND Count(Nvl(id_gatunku,0))>=2 AND Count(DISTINCT id_wedkarza)>=1
ORDER BY Count(id_gatunku) DESC;

/*
22. W oparciu o dane zawarte w tabelach Okregi, Oplaty i Licencje wyświetl informacje ile licencji przez ilu
wędkarzy (różnych) zostało wykupionych w danym roku u danego zarządcy wód. W zestawieniu uwzględnij
wszystkie oferty z poszczególnych lat (dane w tabeli Oplaty) włącznie z tymi, z których nie skorzystał żaden
wędkarz. Dane wyświetl uporządkowane kolejno wg roku i identyfikatora okręgu
*/

SELECT * FROM okregi;
SELECT * FROM oplaty;
SELECT * FROM licencje;

SELECT li.rok,li.id_okregu,
Count(li.id_licencji) AS "LICZBA_LICENCJI",
Count(DISTINCT li.id_wedkarza) AS "LICZBA_WEDKARZY"
FROM okregi ok LEFT JOIN oplaty op ON (ok.id_okregu = op.id_okregu) LEFT JOIN licencje li ON (op.id_okregu = li.id_okregu)
GROUP BY li.id_okregu,li.rok
ORDER BY li.rok, li.id_okregu DESC;

/*
23.W oparciu o dane zawarte w tabelach Studenci i Oceny wyświetl listę studentów, którzy posiadają
przynajmniej 2 braki (tzn. min. z 2-óch przedmiotów nie uzyskali jeszcze oceny). Listę wyświetl w formie
uporządkowanej kolejno wg liczby braków (w trybie nierosnącym) i nazwisk
*/

SELECT * FROM studenci;
SELECT * FROM oceny;
SELECT nr_indeksu, nazwisko, imiona, kierunek, stopien,
Count(Nvl(ocena,0))-Count(ocena) AS "LICZBA_BRAKOW"
FROM studenci JOIN oceny using (nr_indeksu)
GROUP BY nr_indeksu, nazwisko, imiona, kierunek, stopien, srednia
HAVING Count(Nvl(ocena,0))-Count(ocena)>=2
ORDER BY LICZBA_BRAKOW DESC, nazwisko;

/*
24. Na podstawie danych zwartych w tabelach Pojazdy i Wlasciciele wyświetl listę właścicieli posiadajacych
status osoby fizycznej, którzy nie posiadają żadnego pojazdu lub posiadają dokładnie 3 pojazdy 3-ech
różnych marek. Dane wyświetl uporządkowane kolejno wg liczby posiadanych pojazdów (w trybie
niemalejącym), nazwisk i imion
*/

SELECT id_wlasciciela, wlasciciel,
Count(id_wlasciciela) AS "LICZBA_POJAZDOW",
Count(marka) AS "LICZBA_MAREK"
FROM pojazdy JOIN wlasciciele USING (id_wlasciciela)
WHERE Upper(status_wlasciciela) LIKE('OSOBA_FIZYCZNA')
GROUP by id_wlasciciela,wlasciciel
HAVING (Count(id_wlasciciela)=0) OR (Count(id_wlasciciela)=3 AND Count(marka)=3)
ORDER BY LICZBA_POJAZDOW DESC, REGEXP_SUBSTR(wlasciciel,'[[:alpha:]]{1,}'),
REGEXP_SUBSTR(wlasciciel,'\s[[:alpha:]]{1,}');
