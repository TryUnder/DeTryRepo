-- Zad 1
-- Zrealizuj poniższe zadania poprzez utworzenie zapytań zwracających stosowne informacje
-- w oparciu o aktualne dane przechowywane w tabeli Studenci.

-- Zad 1.1
-- Wyświetl informacje o liczbie studentek (pań) studiów stacjonarnych pierwszego stopnia studiujących
-- na 3-im roku informatyki.
SELECT count(*) AS Liczba_Pań
FROM studenci
WHERE imiona LIKE '%a' AND tryb LIKE 'STACJONARNY' AND stopien=1 AND rok=3;

-- Zad 1.2
-- Wyświetl informacje o liczbie Nowakowskich (nazwisko) wśród studentów (pań i panów).
-- W składni zapytania wykorzystaj jedną z funkcji: lower lub upper.

SELECT count(*) AS Liczba_Nowakowskich
FROM studenci
WHERE Upper(nazwisko) LIKE 'NOWAKOWSKI' OR Upper(nazwisko) LIKE 'NOWAKOWSKA';

-- Zad 1.3
-- Wyświetl informacje (w ramach jednego zapytania) na temat ogólnej liczby studentów mężczyzn,
-- których imię rozpoczyna się na literę M oraz ile takich imion (różnych) znajduje się w tabeli.

SELECT count(imiona) AS "Liczba_mezczyzn_na_litere_M",
count(DISTINCT imiona) AS "Liczba_mezczyzn_na_litere_M_nie_powtarzajacych_sie"
FROM studenci
WHERE lower(imiona) NOT LIKE '%a' AND lower(imiona) LIKE('m%');

-- Zad 1.4
-- Wyświetl uporządkowaną alfabetycznie listę zawierającą imiona i nazwiska studentów ostatniego roku
-- (4-ego lub 2-ego roku studiów w przypadku studiów kolejno 1-ego i 2-ego stopnia) w postaci pojedynczych
-- łańcuchów – patrz Rys. 1.4 (min. 2 sposoby w tym zastosuj funkcję concat).

SELECT Concat(Concat(imiona,' '),nazwisko) as "Personalia Studenta"
FROM studenci
WHERE (stopien=1 OR stopien=2) AND (rok=4 OR rok=2)
ORDER BY "Personalia Studenta";

-- Zad 1.5
-- Wyświetl listę, w ramach której jedna z kolumn będzie zwierała pierwsze 3 litery imion a druga kolumna
-- ostatnie 3 litery nazwisk studentów nieposiadających zdefiniowanego zakresu (zakres OGOLNY).

SELECT
Substr(imiona,1,3) AS "3 litery imiona",imiona,
Substr(nazwisko,-3) AS "3 litery nazwiska od konca",nazwisko
FROM studenci
WHERE zakres LIKE 'OGOLNY';

-- Zad 1.6
-- Wyświetl listę zawierającą nazwiska i imiona studentów wraz z ich inicjałami w formie 'A.A.',
-- których łączna liczba liter w imieniu i nazwisku wynosi 9, 11 lub 13.

SELECT Concat(Concat(Concat(Substr(nazwisko,1,1),'.'),Substr(imiona,1,1)),'.') AS "Inicjaly"
FROM studenci
WHERE (Length(imiona)+Length(nazwisko)) IN (9,11,13);

-- Zad 1.7
-- Wyświetl listę zawierającą nazwy kierunków studiów realizowanych na uczelni (bez powtórek) w formie
-- pierwsza litera każdego wyrazu nazwy kierunku będzie duża a pozostałe małe (opcja A) oraz tylko pierwsza
-- litera będzie duża a pozostałe małe (opcja B; patrz Rys. 1.7); zadanie wykonaj na 2 sposoby poprzez
-- zastosowanie funkcji Initcap i Concat.

SELECT DISTINCT Initcap(lower(kierunek))
FROM studenci;
--do dokonczenia


-- Zad 1.8
-- Wyświetl listę, w ramach której pierwsza kolumna będzie zawierać nazwiska studentów bez pierwszych
-- dwóch liter 'Ko' a druga kolumna imiona tych studentów bez dwóch ostatnich liter 'sz' (patrz Rys. 1.8). Oznacza
-- to, że w wyniku należy uwzględnić tylko studentów, których nazwiska rozpoczynają się na 'Ko' a imiona
-- kończą na 'sz' np. Kowalczyk Tomasz. Założenie: w ramach rozwiązania nie można zastosować funkcji substr.

SELECT Rtrim(imiona,'%sz')AS "Imiona bez sz",
Initcap(Ltrim(nazwisko,'Ko%'))AS "Nazwiska bez Ko",
Concat(Concat(imiona,' '),nazwisko) AS "Personalia"
FROM studenci
WHERE nazwisko LIKE ('Ko%')
AND imiona LIKE ('%sz');

-- Zad 1.9
-- Wyświetl listę różnych nazwisk studentów 2-ego roku składająch się od 6 do 9 liter zawierających
-- przynajmniej jedną literę a (ew. A), wraz z informacją o liczbie liter w nazwisku oraz pozycji wystąpienia
-- pierwszej litery a (patrz Rys. 1.9). Lista ma być uporządkowana nierosnąco wg liczby liter w nazwisku.

SELECT nazwisko,
Length(nazwisko)AS "Liczba liter w nazwisku",
Instr(Upper(nazwisko),'A') AS "Pozycja litery 'a' w nazwisku"
FROM studenci
WHERE rok=2
AND Length(nazwisko) BETWEEN 6 AND 9
AND Instr(Upper(nazwisko),'A')>0
ORDER BY Length(nazwisko) DESC;
