 /*
                           BAZY DANYCH
                           KOLOKWIUM nr 1
                           Poprawa nr 1
                           data:  23.12.2021                          
   
   nazwisko: Lewowicki 
   imie: Hubert
   numer indeksu: 133507
   grupa laboratoryjna: 2
   
*/

  -------------------------------------------------------------------------------------------------------
 /*                           
                                 Rozwiazania zadan  
 */
  -------------------------------------------------------------------------------------------------------


-- *********
--     JOKER   (akt. przy min. 75%; tylko do 20 pkt.)  ---
-- zglaszam zadanie nr: 7
-- *********


-- Zadanie nr 1 
/*
1. Zad. 1 (2 pkt.)
Na podstawie danych zgromadzonych w tabeli Rejestry wy�wietl informacj� o liczbie z�owionych ryb i ich
��cznej wadze przez wszystkich w�dkarzy na przestrzeni wszystkich lat. Kolumny: liczb_ryb, laczna_waga i
liczba_wedkarzy (r�nych).
*/
SELECT * FROM wedkarze;
SELECT * FROM rejestry;

SELECT 
Count(id_gatunku) AS "LICZBA_RYB",
Count(DISTINCT id_wedkarza) AS "LICZBA_WEDKARZY",
Sum(waga) AS "LACZNA_WAGA"  FROM rejestry;
-- Zadanie nr 2 
/*
2. Zad. 2 (2 pkt.)
Na podstawie danych zgromadzonych w tabeli Studenci wy�wietl dane wszystkich student�w pierwszego
stopnia, kt�rzy urodzili si� w nieparzystym roku np. 1997, 2001.
*/
SELECT * FROM studenci
WHERE Mod(Cast(Extract(YEAR FROM data_urodzenia)AS INT),2)=1 
AND stopien=1;
 
-- Zadanie nr 3 
/*
3. Zad. 3 (2 pkt.)
Na podstawie danych zgromadzonych w tabeli Pojazdy wy�wietl dat� produkcji najm�odszego pojazdu. W
analizie uwzgl�dnij tylko pojazdy marek Ford, Opel i Audi.
*/
SELECT * FROM pojazdy;
Select Extract(YEAR FROM data_produkcji), data_produkcji FROM pojazdy
WHERE (marka LIKE ('OPEL') OR marka LIKE ('FORD') OR marka LIKE  ('AUDI'))
AND data_produkcji > ALL ( SELECT data_produkcji FROM pojazdy WHERE (marka LIKE ('OPEL') OR marka LIKE ('FORD') OR marka LIKE ('AUDI')));

-- Zadanie nr 4 
/*
4. Zad. 4 (2 pkt.)
Zdefinuj sk�adni� obliczaj�c� wynik nast�puj�cego wyra�enia:
?
log1000+1000
0.1233 .
*/
SELECT Sqrt(Ln(1000)+1000)/Power(0.123,3) AS "WYNIK WYRAZENIA" FROM dual;
-- Zadanie nr 5 
/*
5. Zad. 5 (3 pkt.)
W ramach jednej kolumny wy�wietl informacj� w formacie dok�adna data dzie� (s�ownie) godzina z minutami
o chwili, jaka b�dzie mia�a miejsca dok�adnie za 1579 dni i 13 godzin np. 2021.12.23 czwartek 21:45.
*/
SELECT To_char(Sysdate+Interval '1579 13:00:00' Day(4) to second,'YYYY-MM-DD HH:MM:SS') AS "CZAS_ZA_1579_DNI_13_GODZIN" FROM dual; 
-- Zadanie nr 6 
/*
6. Zad. 6 (3 pkt.)
Na podstawie danych zgromadzonych w tabeli Studenci wy�wietl dane wszystkich m�czyzn studiuj�cych
informatyk�, kt�rych nazwiska rozpoczynaj� si� i ko�cz� na tak� sam� liter� np. Kowalczyk.
*/
--test
SELECT nazwisko, Substr(Upper(nazwisko),1,1), Substr(Upper(nazwisko),length(nazwisko)) FROM studenci;

SELECT * FROM studenci
WHERE imiona NOT LIKE('%a') AND Upper(kierunek) LIKE ('INFORMATYKA') AND 
Substr(Upper(nazwisko),1,1)) LIKE Substr(Upper(nazwisko,length(nazwisko));
-- Zadanie nr 7 
/*
7. Zad. 7 (3 pkt.)
Na podstawie danych zgromadzonych w tabeli Pojazdy wy�wietl informacj� ile samochod�w osobowych (typ)
poszczeg�lnych marek jest zasilanych danym rodzajem paliwa. W zestawieniu uwzgl�dnij wy��cznie pojazdy
o pojemno�ciach silnik�w zawieraj�cych si� w przedziale od 1000 do 2000. Kolumny: marka, rodzaj_paliwa,
liczba_samochodow. Dane wy�wietl w formie uporz�dkowanej kolejno wg kolumn: liczba_samochodow (w
trybie nierosn�cym) i marka (alfabetycznie).
*/
SELECT * FROM pojazdy;

SELECT marka,
rodzaj_paliwa,
Count(*) AS "LICZBA_SAMOCHODOW"
FROM pojazdy
WHERE Upper(typ) LIKE ('SAM_OSOBOWY')
AND pojemnosc BETWEEN 1000 AND 2000
GROUP BY marka,rodzaj_paliwa
ORDER BY "LICZBA_SAMOCHODOW" DESC, marka;

-- Zadanie nr 8 
/*
8. Zad. 8 (3 pkt.)
Na podstawie danych zgromadzonych w tabeli Pracownicy wy�wietl informacj�
na jakich stanowiskach aktualnie pracuje przynajmniej jeden pracownik zatrudniony w dziale 30-tym (id_dzialu) a zarazem na kt�rych
aktualnie nikt nie pracuje �aden pracownik zatrudniony w dziale 40-tym. Kolumna stanowisko.
*/
SELECT * FROM pracownicy;

SELECT stanowisko FROM pracownicy
WHERE data_zwol IS NOT NULL AND data_zwol > sysdate AND
id_dzialu=30 AND id_dzialu!=40;

-- Zadanie nr 9 
/*
9. Zad. 9 (3 pkt.)
Na podstawie danych zgromadzonych w tabeli Studenci wy�wietl personalia (imi� i nazwisko w ramach jednej
kolumny), kt�re posiada przynajmniej dw�ch student�w. W zestawieniu uwzgl�dnij wy��cznie student�w,
kt�rych imiona zawieraj�c wi�cej liter ni� nazwiska. Kolumny: personalia i liczba_wystapien np. Krzysztof
Piech, 3.
*/
SELECT imiona || ' ' || nazwisko AS "PERSONALIA" FROM studenci
WHERE Length(imiona)>Length(nazwisko)
GROUP BY;
-- Zadanie nr 10 
/*
10. Zad. 10 (4 pkt.)
Na podstawie danych zgromadzonych w tabeli Studenci wy�wietl dane student�w, w kt�rych adresach frazy
(sylaby) PA i KA wyst�puj�c od 3-ech do 6-ciu razy (��cznie, w sumie) a dodatkowo w adresie znajduje si�
fraza (wyraz) sk�adaj�ca si� z co najmniej 10-ciu liter.
*/

SELECT * FROM studenci
WHERE (Regexp_Count(Regexp_LIKE(Upper(adres),'PA')) BETWEEN 3 AND 6) AND
(Regexp_Count(Regexp_LIKE(Upper(adres),'KA')) BETWEEN 3 AND 6);
;
-- Zadanie nr 11 
/*
11. Zad. 11 (4 pkt.)
Na podstawie danych zgromadzonych w tabelach Rejestry i Wedkarze wy�wietl dane w�dkarzy, kt�rzy
z�owili przynajmniej jedn� ryb� o d�ugo�ci powy�ej 75 cm. Kolumny: wszystkie z tabeli Wedkarze. Uwaga.
W rozwi�zaniu nale�y zastosowa� podzapytanie oraz zabrania si� stosowania DISTINCT.
*/
SELECT * FROM wedkarze;
SELECT * FROM rejestry;

SELECT id_wedkarza,nazwisko, imiona, data_ur FROM wedkarze JOIN rejestry USING (id_wedkarza)
WHERE 75 > ANY ( SELECT dlugosc FROM rejestry JOIN wedkarze USING (id_wedkarza));


-- Zadanie nr 12 
/*
12. Zad. 12 (4 pkt.)
Na podstawie danych zgromadzonych w tabelach Wlasciciele i Pojazdy wy�wietl informacj� prezentuj�c�
dane pojazd�w zarejestrowanych w Cz�stochowie (numer rejestracyjny rozpoczynaj�cy si� od SC;
pami�taj, �e np. SCZ to ju� powiat) nale��ce do os�b fizycznych. Kolumny: nr_rejestracyjny, marka, modell,
data_produkcji i komentarz. Kolumna komentarz powinna zawiera� jedn� z poni�szych fraz zwi�zanych z
dat� produkcji pojazdu:
� zimowy pojazd - pojazdy wyprodukowane w grudniu, styczniu i lutym,
� wiosenny pojazd - pojazdy wyprodukowane w marcu, kwietniu i maju,
� letni pojazd - pojazdy wyprodukowane w czerwcu, lipcu i sierpniu,
� jesienny pojazd - pojazdy wyprodukowane we wrze�niu, pa�dzierniku i listopadzie.
*/
SELECT * FROM pojazdy;
SELECT * FROM wlasciciele;

SELECT nr_rejestracyjny,marka, modell, data_produkcji,
(
SELECT 
CASE WHEN Cast(Extract(MONTH FROM data_produkcji)AS INT) IN (1,2,12) THEN 'ZIMOWY_POJAZD'
WHEN Cast(Extract(MONTH FROM data_produkcji)AS INT) IN (4,5) THEN 'WIOSENNY_POJAZD'
WHEN Cast(Extract(MONTH FROM data_produkcji)AS INT) IN (6,7,8) THEN 'LETNI_POJAZD'
WHEN Cast(Extract(MONTH FROM data_produkcji)AS INT) IN (9,10,11) THEN 'JESIENNY_POJAZD'
END
FROM pojazdy JOIN wlasciciele using (id_wlasciciela)
WHERE REGEXP_LIKE(nr_rejestracyjny,'SC') 
AND NOT REGEXP_LIKE(nr_rejestracyjny,'SCZ') 
AND Upper(status_wlasciciela) LIKE ('OSOBA_FIZYCZNA')
)
FROM pojazdy JOIN wlasciciele USING (id_wlasciciela)
WHERE REGEXP_LIKE(nr_rejestracyjny,'SC') 
AND NOT REGEXP_LIKE(nr_rejestracyjny,'SCZ') 
AND Upper(status_wlasciciela) LIKE ('OSOBA_FIZYCZNA');



-- Zadanie nr 13 
/*
13. Zad. 13 (5 pkt.)
Na podstawie danych zgromadzonych w tabelach Rejestry, Wedkarze i Lowiska wy�wietl zestawienie
zawieraj�ce informacj� z zakresu ile po�ow�w dany w�dkarz odby� na danym �owisku. W ramach zestawienia
nale�y uwzgl�dni� wszystkie mo�liwe uk�ady w�dkarz � �owisko. Kolumny: id_wedkarza, nazwisko, id_lowiska,
nazwa, liczba_polowow (patrz Rys.)
*/

SELECT id_wedkarza, nazwisko, id_lowiska, nazwa FROM rejestry JOIN wedkarze USING (id_wedkarza) JOIN lowiska USING (id_lowiska)




-------------------------------------------------------------------------------------------------------
/*       KONIEC                      */
-------------------------------------------------------------------------------------------------------

/*  "BRUDNOPIS" - zapytania zdefiniowane ponizej nie podlegaja ocenie - nie beda sprawdzane*/





