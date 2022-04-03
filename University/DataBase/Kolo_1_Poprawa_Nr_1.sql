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
Na podstawie danych zgromadzonych w tabeli Rejestry wyœwietl informacjê o liczbie z³owionych ryb i ich
³¹cznej wadze przez wszystkich wêdkarzy na przestrzeni wszystkich lat. Kolumny: liczb_ryb, laczna_waga i
liczba_wedkarzy (ró¿nych).
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
Na podstawie danych zgromadzonych w tabeli Studenci wyœwietl dane wszystkich studentów pierwszego
stopnia, którzy urodzili siê w nieparzystym roku np. 1997, 2001.
*/
SELECT * FROM studenci
WHERE Mod(Cast(Extract(YEAR FROM data_urodzenia)AS INT),2)=1 
AND stopien=1;
 
-- Zadanie nr 3 
/*
3. Zad. 3 (2 pkt.)
Na podstawie danych zgromadzonych w tabeli Pojazdy wyœwietl datê produkcji najm³odszego pojazdu. W
analizie uwzglêdnij tylko pojazdy marek Ford, Opel i Audi.
*/
SELECT * FROM pojazdy;
Select Extract(YEAR FROM data_produkcji), data_produkcji FROM pojazdy
WHERE (marka LIKE ('OPEL') OR marka LIKE ('FORD') OR marka LIKE  ('AUDI'))
AND data_produkcji > ALL ( SELECT data_produkcji FROM pojazdy WHERE (marka LIKE ('OPEL') OR marka LIKE ('FORD') OR marka LIKE ('AUDI')));

-- Zadanie nr 4 
/*
4. Zad. 4 (2 pkt.)
Zdefinuj sk³adniê obliczaj¹c¹ wynik nastêpuj¹cego wyra¿enia:
?
log1000+1000
0.1233 .
*/
SELECT Sqrt(Ln(1000)+1000)/Power(0.123,3) AS "WYNIK WYRAZENIA" FROM dual;
-- Zadanie nr 5 
/*
5. Zad. 5 (3 pkt.)
W ramach jednej kolumny wyœwietl informacjê w formacie dok³adna data dzieñ (s³ownie) godzina z minutami
o chwili, jaka bêdzie mia³a miejsca dok³adnie za 1579 dni i 13 godzin np. 2021.12.23 czwartek 21:45.
*/
SELECT To_char(Sysdate+Interval '1579 13:00:00' Day(4) to second,'YYYY-MM-DD HH:MM:SS') AS "CZAS_ZA_1579_DNI_13_GODZIN" FROM dual; 
-- Zadanie nr 6 
/*
6. Zad. 6 (3 pkt.)
Na podstawie danych zgromadzonych w tabeli Studenci wyœwietl dane wszystkich mê¿czyzn studiuj¹cych
informatykê, których nazwiska rozpoczynaj¹ siê i koñcz¹ na tak¹ sam¹ literê np. Kowalczyk.
*/
--test
SELECT nazwisko, Substr(Upper(nazwisko),1,1), Substr(Upper(nazwisko),length(nazwisko)) FROM studenci;

SELECT * FROM studenci
WHERE imiona NOT LIKE('%a') AND Upper(kierunek) LIKE ('INFORMATYKA') AND 
Substr(Upper(nazwisko),1,1)) LIKE Substr(Upper(nazwisko,length(nazwisko));
-- Zadanie nr 7 
/*
7. Zad. 7 (3 pkt.)
Na podstawie danych zgromadzonych w tabeli Pojazdy wyœwietl informacjê ile samochodów osobowych (typ)
poszczególnych marek jest zasilanych danym rodzajem paliwa. W zestawieniu uwzglêdnij wy³¹cznie pojazdy
o pojemnoœciach silników zawieraj¹cych siê w przedziale od 1000 do 2000. Kolumny: marka, rodzaj_paliwa,
liczba_samochodow. Dane wyœwietl w formie uporz¹dkowanej kolejno wg kolumn: liczba_samochodow (w
trybie nierosn¹cym) i marka (alfabetycznie).
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
Na podstawie danych zgromadzonych w tabeli Pracownicy wyœwietl informacjê
na jakich stanowiskach aktualnie pracuje przynajmniej jeden pracownik zatrudniony w dziale 30-tym (id_dzialu) a zarazem na których
aktualnie nikt nie pracuje ¿aden pracownik zatrudniony w dziale 40-tym. Kolumna stanowisko.
*/
SELECT * FROM pracownicy;

SELECT stanowisko FROM pracownicy
WHERE data_zwol IS NOT NULL AND data_zwol > sysdate AND
id_dzialu=30 AND id_dzialu!=40;

-- Zadanie nr 9 
/*
9. Zad. 9 (3 pkt.)
Na podstawie danych zgromadzonych w tabeli Studenci wyœwietl personalia (imiê i nazwisko w ramach jednej
kolumny), które posiada przynajmniej dwóch studentów. W zestawieniu uwzglêdnij wy³¹cznie studentów,
których imiona zawieraj¹c wiêcej liter ni¿ nazwiska. Kolumny: personalia i liczba_wystapien np. Krzysztof
Piech, 3.
*/
SELECT imiona || ' ' || nazwisko AS "PERSONALIA" FROM studenci
WHERE Length(imiona)>Length(nazwisko)
GROUP BY;
-- Zadanie nr 10 
/*
10. Zad. 10 (4 pkt.)
Na podstawie danych zgromadzonych w tabeli Studenci wyœwietl dane studentów, w których adresach frazy
(sylaby) PA i KA wystêpuj¹c od 3-ech do 6-ciu razy (³¹cznie, w sumie) a dodatkowo w adresie znajduje siê
fraza (wyraz) sk³adaj¹ca siê z co najmniej 10-ciu liter.
*/

SELECT * FROM studenci
WHERE (Regexp_Count(Regexp_LIKE(Upper(adres),'PA')) BETWEEN 3 AND 6) AND
(Regexp_Count(Regexp_LIKE(Upper(adres),'KA')) BETWEEN 3 AND 6);
;
-- Zadanie nr 11 
/*
11. Zad. 11 (4 pkt.)
Na podstawie danych zgromadzonych w tabelach Rejestry i Wedkarze wyœwietl dane wêdkarzy, którzy
z³owili przynajmniej jedn¹ rybê o d³ugoœci powy¿ej 75 cm. Kolumny: wszystkie z tabeli Wedkarze. Uwaga.
W rozwi¹zaniu nale¿y zastosowaæ podzapytanie oraz zabrania siê stosowania DISTINCT.
*/
SELECT * FROM wedkarze;
SELECT * FROM rejestry;

SELECT id_wedkarza,nazwisko, imiona, data_ur FROM wedkarze JOIN rejestry USING (id_wedkarza)
WHERE 75 > ANY ( SELECT dlugosc FROM rejestry JOIN wedkarze USING (id_wedkarza));


-- Zadanie nr 12 
/*
12. Zad. 12 (4 pkt.)
Na podstawie danych zgromadzonych w tabelach Wlasciciele i Pojazdy wyœwietl informacjê prezentuj¹c¹
dane pojazdów zarejestrowanych w Czêstochowie (numer rejestracyjny rozpoczynaj¹cy siê od SC;
pamiêtaj, ¿e np. SCZ to ju¿ powiat) nale¿¹ce do osób fizycznych. Kolumny: nr_rejestracyjny, marka, modell,
data_produkcji i komentarz. Kolumna komentarz powinna zawieraæ jedn¹ z poni¿szych fraz zwi¹zanych z
dat¹ produkcji pojazdu:
• zimowy pojazd - pojazdy wyprodukowane w grudniu, styczniu i lutym,
• wiosenny pojazd - pojazdy wyprodukowane w marcu, kwietniu i maju,
• letni pojazd - pojazdy wyprodukowane w czerwcu, lipcu i sierpniu,
• jesienny pojazd - pojazdy wyprodukowane we wrzeœniu, paŸdzierniku i listopadzie.
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
Na podstawie danych zgromadzonych w tabelach Rejestry, Wedkarze i Lowiska wyœwietl zestawienie
zawieraj¹ce informacjê z zakresu ile po³owów dany wêdkarz odby³ na danym ³owisku. W ramach zestawienia
nale¿y uwzglêdniæ wszystkie mo¿liwe uk³ady wêdkarz – ³owisko. Kolumny: id_wedkarza, nazwisko, id_lowiska,
nazwa, liczba_polowow (patrz Rys.)
*/

SELECT id_wedkarza, nazwisko, id_lowiska, nazwa FROM rejestry JOIN wedkarze USING (id_wedkarza) JOIN lowiska USING (id_lowiska)




-------------------------------------------------------------------------------------------------------
/*       KONIEC                      */
-------------------------------------------------------------------------------------------------------

/*  "BRUDNOPIS" - zapytania zdefiniowane ponizej nie podlegaja ocenie - nie beda sprawdzane*/





