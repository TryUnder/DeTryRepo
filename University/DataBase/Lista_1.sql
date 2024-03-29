-- Zad1 
-- Poka� atrybuty tabeli Studenci.
DESC studenci;

-- Zad2
-- Wy�wietl wszystkie wiersze znajduj�ce si� w tabeli Studenci
SELECT * FROM studenci;

-- Zad 3
-- Na podstawie danych znajduj�cych si� w tabeli Studenci.
-- Zad 3.1
-- Wy�wietl list� zawieraj�c� nazwiska i imiona wszystkich student�w.
SELECT nazwisko, imiona 
FROM studenci;

-- Zad 3.2
-- Wy�wietl informacje dotycz�c� kierunk�w (bez powt�rze�) na jakich studiuj� studenci, kt�rych dane
-- znajd� si� w tabeli
SELECT DISTINCT kierunek
FROM studenci;

-- Zad 3.3
--Wy�wietl list� prezentuj�c� dane wszystkich student�w studiuj�cych na kierunku informatyka w zakresie
--ich nazwisk, imion, trybu studi�w, roku, grupy dzieka�skiej i zakresu. Dane uporz�dkuj wg. roku w formie
--niemalej�cej (od 1) i nazwiska w formie �od � do A�
DESC studenci;
SELECT imiona, nazwisko, tryb, rok, gr_dziekan, zakres
FROM studenci
ORDER BY 4, 2 DESC;

-- Zad 3.4
-- Wy�wietl dane student�w studiuj�cych na 3-im roku i przynale��cych do 2-ej grupy dzieka�skiej
SELECT * FROM studenci
WHERE ROK LIKE 3 AND gr_dziekan LIKE 2;

-- Zad 3.5
-- Wy�wietl dane student�w, kt�rzy nie maj� obliczonej sredniej (brak warto�ci w ramach kolumny srednia).
SELECT * FROM studenci
WHERE NVL(srednia,0) LIKE 0;

-- Zad 3.6
-- Wy�wietl nazwiska, imiona i roczniki student�w (rok) pierwszego stopnia studi�w stacjonarnych z lat (rok):
-- 2, 3, 4 (warunek zbuduj na kilka sposob�w). Dane wy�wietl uporz�dkowane w kolejno�ci alfabetycznej
-- wg nazwisk student�w
SELECT nazwisko, imiona, rok
FROM studenci
WHERE stopien LIKE 1 AND rok IN(2,3,4)
ORDER BY nazwisko;

-- Zad 3.7
-- Wy�wietl imiona i nazwiska studentek (pa�) � kolumny imiona i nazwisko.
SELECT imiona, nazwisko
FROM studenci
WHERE imiona LIKE '%a';

-- Zad 3.8
-- Wy�wietl imiona i nazwiska student�w (pan�w).
SELECT imiona, nazwisko
FROM studenci
WHERE imiona NOT LIKE '%a';

-- Zad 3.9
-- Wy�wietl dane wszystkich Adam�w, Konrad�w i Magdalen
SELECT * FROM studenci
WHERE Upper(imiona) IN('ADAM','KONRAD','MAGDALENA');

-- Zad 3.10
-- Wy�wietl dane wszystkich Kowalskich oraz Nowak�w pa� i pan�w
SELECT * FROM studenci
WHERE Upper(nazwisko) IN('KOWALSKI','NOWAK');

-- Zad 3.11
-- Wy�wietl alfabetycznie uporz�dkowan� list� imion student�w, kt�rych dwie pierwsze litery mieszcz� si�
-- w przedziale alfabetycznym od DO do MI (np. Dorota, Helena, Jan, Marcin)
SELECT imiona
FROM studenci
WHERE Upper(imiona) BETWEEN 'DO%' AND 'MI%'
ORDER BY 1;

-- Zad 4
-- Poka� atrybuty tabeli Pracownicy.
DESC pracownicy;

-- Zad 5
-- Na podstawie danych znajduj�cych si� w tabeli Pracownicy
-- Zad 5.1
-- Wy�wietl list� zawieraj�c� nazwiska pracownik�w i ich p�ac� (kolumny nazwisko i placa).
SELECT nazwisko, placa
FROM pracownicy;

-- Zad 5.2
-- Wy�wietl list� zawieraj�c� nazwiska pracownik�w wraz z warto�ciami ich tzw. �dni�wek� obliczonych
-- na podstawie warto�ci znajduj�cych si� w ramach kolumny placa (Rys. 9). W ramach zadania nale�y przyj��
-- za�o�enie, �e w ka�dym miesi�cu wyst�puje 20 dni roboczych.
SELECT nazwisko, placa/20 AS "DNI�WKA"
FROM pracownicy;

-- Zad 5.3
-- Wy�wietl list� miesi�cznych ca�kowitych pensji aktualnych pracownik�w (nazwisko, nr_akt) pracuj�cych
-- w ramach umowy na czas nieokre�lony (nieokre�lona warto�� kolumny data_zwol); lista ma by�
-- uporz�dkowan� po kolumnie pensja w trybie niemalej�cym (od najgorzej do najlepiej zarabiaj�cego
-- pracownika; patrz Rys. 10); uwaga w ramach pensji nale�y uwzgl�dni� warto�ci z kolumn placa,
-- dod_funkcyjny, dod_staz i koszt_ubezpieczenia (dododatek sta�owy to procentowa warto��; sam dodatek
-- obliczany jest w oparciu o wysoko�� p�acy podstawowej).
SELECT nazwisko, nr_akt, placa+0.19*placa+Nvl(dod_funkcyjny,0)-Nvl(koszt_ubezpieczenia,0) "PENSJA", data_zwol
FROM pracownicy
WHERE data_zwol is NULL
ORDER BY PENSJA;

-- Zad 5.4
-- Wy�wietl list� zawierajac� roczne pensje aktualnych pracownik�w posiadaj�cych umowy na czas
-- nieokre�lony, niepe�ni�cych funkcji prezesa oraz dyrektora. Lista ma by� uporz�dkowana od najlepiej
-- do najgorzej zarabiaj�cego pracownika
SELECT nazwisko, stanowisko, nr_akt, placa*12 as "ROCZNA PLACA"
FROM pracownicy
WHERE (data_zwol is NULL) AND (UPPER(stanowisko)NOT IN('PREZES','DYREKTOR'))
ORDER BY 4 DESC;

-- Zad 5.5
-- Wy�wietl pod postaci� jednej kolumny informuj�c� w jakich dzia�ach i na jakich stanowiskach pracuj�
-- aktualni pracownicy firmy zatrudnieni ma umowy na czas nieokre�lony
DESC pracownicy;
SELECT nazwisko ||' '|| imiona ||' '||'pracuje w dziale: '|| id_dzialu ||' na stanowisku '||stanowisko
AS "Pracownik"
FROM pracownicy
WHERE data_zwol IS NULL;

-- Zad 6
DESC pojazdy;

-- Zad 7
-- Na podstawie danych znajduj�cych si� w tabeli Pojazdy wy�wietl list� zawieraj�c� informacje
-- o samochodach osobowych kt�rych (Rys. 13):
-- � numer rejestracyjny rozpoczyna si� na 'SC' a ko�czy cyfr� 5,
-- � warto�� pojemno�ci silnika nie nale�y do przedzia�u od 1500 do 2000,
-- � nazwa koloru jest ustalona w formie jednego wyrazu, w kt�rym wyst�puje co najmniej jedna litera r
-- (ew. R).
SELECT * FROM pojazdy;

SELECT kolor FROM pojazdy
WHERE (nr_rejestracyjny LIKE 'SC%') AND (nr_rejestracyjny LIKE '%5')
    AND (pojemnosc NOT BETWEEN 1500 AND 2000) AND (kolor LIKE '%r%' OR kolor LIKE '%R%');