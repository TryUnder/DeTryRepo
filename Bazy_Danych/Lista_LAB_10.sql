-- 1)WIELOTABELOWY INSERT
-- 2)SEKWENCJE
-- 3)PERSPEKTYWY
-- 4)INDEKSY

SELECT * FROM POJAZDY;

CREATE GLOBAL TEMPORARY TABLE Table_A
(
nr_rej VARCHAR(10),
marka VARCHAR(30),
modell VARCHAR(30),
kolor VARCHAR(40),
wartosc NUMBER(8,2),
komentarz VARCHAR(100)
)
ON COMMIT DELETE ROWS;

CREATE GLOBAL TEMPORARY TABLE Table_B
(
nr_rej VARCHAR(10),
marka VARCHAR(30),
kolor VARCHAR(40),
wartosc NUMBER(8,2),
komentarz VARCHAR(100)
)
ON COMMIT DELETE ROWS;

CREATE GLOBAL TEMPORARY TABLE Table_C
(
nr_rej VARCHAR(10),
kolor VARCHAR(40),
wartosc NUMBER(8,2),
komentarz VARCHAR(100)
)
ON COMMIT DELETE ROWS;

-- 1)
-- INSERT ALL

INSERT ALL
    INTO TABLE_A VALUES(nr_rejestracyjny, marka, modell, lower(kolor), DR-DP, Kom||typ)
    INTO TABLE_B VALUES(nr_rejestracyjny, marka, Upper(kolor), Round(pojemnosc/1000,1), Kom||modell)
    INTO TABLE_C VALUES(nr_rejestracyjny, Initcap(kolor), Round(pojemnosc/1000,2), Kom||marka|| ' ' ||modell)
SELECT nr_rejestracyjny, marka, modell, kolor, pojemnosc, data_produkcji DP, data_rejestracji DR, typ,
'Pojazd z Cz-wy 'Kom FROM POJAZDY WHERE nr_rejestracyjny LIKE 'SC %';
commit;

-- INSERT ALL WHEN

INSERT ALL
WHEN Extract(YEAR FROM DP) != Extract(YEAR FROM DR)
    THEN INTO TABLE_A VALUES(nr_rejestracyjny, marka, modell, lower(kolor), DR-DP,
    'DP: '||To_char(DP, 'YYYY')||' DR: '||To_char(DR, 'YYYY'))
WHEN kolor LIKE '%Red%' AND pojemnosc BETWEEN 1000 AND 2000
    THEN INTO TABLE_B VALUES(nr_rejestracyjny, marka, Upper(kolor), Round(pojemnosc/1000,1),Kom)
WHEN typ LIKE 'SAM_OSOBOWY'
    THEN INTO TABLE_C VALUES(nr_rejestracyjny, Initcap(kolor),
    Round(pojemnosc/1000,2), Kom||typ||' '||marka||' '||modell)
SELECT nr_rejestracyjny, marka, modell, kolor, pojemnosc, data_produkcji DP, data_rejestracji DR, typ,
'Pojazd z Cz-wy' Kom FROM POJAZDY WHERE nr_rejestracyjny LIKE 'SC %';

SELECT * FROM TABLE_A;
SELECT * FROM TABLE_B;
SELECT * FROM TABLE_C;

SELECT nr_rej FROM TABLE_A
INTERSECT
SELECT nr_rej FROM TABLE_B
INTERSECT
SELECT nr_rej FROM TABLE_C;

commit;

-- INSERT ALL ELSE

INSERT ALL
WHEN Extract(YEAR FROM DP) != Extract(YEAR FROM DR) THEN
    INTO TABLE_A VALUES(nr_rejestracyjny, marka, modell, lower(kolor), DR-DP,
    'DP: '||To_char(DP, 'YYYY')||' DR: '||To_char(DR, 'YYYY'))
WHEN kolor LIKE '%Red%' AND pojemnosc BETWEEN 1000 AND 2000 THEN
    INTO TABLE_B VALUES(nr_rejestracyjny, marka, Upper(kolor), Round(pojemnosc/1000,1),Kom)
ELSE
    INTO TABLE_C VALUES(nr_rejestracyjny, Initcap(kolor),
    Round(pojemnosc/1000,2), Kom||typ||' '||marka||' '||modell)
    SELECT nr_rejestracyjny, marka, modell, kolor, pojemnosc, data_produkcji DP, data_rejestracji DR, typ,
    'Pojazd z Cz-wy' Kom FROM POJAZDY WHERE nr_rejestracyjny LIKE 'SC %';

SELECT nr_rej FROM TABLE_A
INTERSECT
SELECT nr_rej FROM TABLE_B
INTERSECT
SELECT nr_rej FROM TABLE_C;

commit;

-- INSERT FIRST -- SPRAWDZAMY DO PIERWSZEGO PRAWIDLOWEGO WARUNKU

INSERT FIRST
WHEN Extract(YEAR FROM DP) != Extract(YEAR FROM DR) THEN
    INTO TABLE_A VALUES(nr_rejestracyjny, marka, modell, lower(kolor), DR-DP,
    'DP: '||To_char(DP, 'YYYY')||' DR: '||To_char(DR, 'YYYY'))
WHEN kolor LIKE '%Red%' AND pojemnosc BETWEEN 1000 AND 2000 THEN
    INTO TABLE_B VALUES(nr_rejestracyjny, marka, Upper(kolor), Round(pojemnosc/1000,1),Kom)
WHEN typ LIKE 'SAM_OSOBOWY' THEN
    INTO TABLE_C VALUES(nr_rejestracyjny, Initcap(kolor),
    Round(pojemnosc/1000,2), Kom||typ||' '||marka||' '||modell)
    SELECT nr_rejestracyjny, marka, modell, kolor, pojemnosc, data_produkcji DP, data_rejestracji DR, typ,
    'Pojazd z Cz-wy' Kom FROM POJAZDY WHERE nr_rejestracyjny LIKE 'SC %';

SELECT * FROM TABLE_A;
SELECT * FROM TABLE_B;
SELECT * FROM TABLE_C;

SELECT nr_rej FROM TABLE_A
INTERSECT
SELECT nr_rej FROM TABLE_B
INTERSECT
SELECT nr_rej FROM TABLE_C;

commit;

-- INSERT FIRST ELSE --

INSERT FIRST
WHEN Extract(YEAR FROM DP) != Extract(YEAR FROM DR) THEN
    INTO TABLE_A VALUES(nr_rejestracyjny, marka, modell, lower(kolor), DR-DP,
    'DP: '||To_char(DP, 'YYYY')||' DR: '||To_char(DR, 'YYYY'))
WHEN kolor LIKE '%Red%' AND pojemnosc BETWEEN 1000 AND 2000 THEN
    INTO TABLE_B VALUES(nr_rejestracyjny, marka, Upper(kolor), Round(pojemnosc/1000,1),Kom)
ELSE
    INTO TABLE_C VALUES(nr_rejestracyjny, Initcap(kolor),
    Round(pojemnosc/1000,2), Kom||typ||' '||marka||' '||modell)
    SELECT nr_rejestracyjny, marka, modell, kolor, pojemnosc, data_produkcji DP, data_rejestracji DR, typ,
    'Pojazd z Cz-wy' Kom FROM POJAZDY WHERE nr_rejestracyjny LIKE 'SC %';

SELECT * FROM TABLE_A;
SELECT * FROM TABLE_B;
SELECT * FROM TABLE_C;

SELECT nr_rej FROM TABLE_A
INTERSECT
SELECT nr_rej FROM TABLE_B
INTERSECT
SELECT nr_rej FROM TABLE_C;

commit;

DROP TABLE TABLE_A;
DROP TABLE TABLE_B;
DROP TABLE TABLE_C;

-- 2)SEKWENCJE

CREATE SEQUENCE Seq_name;
SELECT SEQ_NAME.CURRVAL FROM DUAL;
SELECT SEQ_NAME.NEXTVAL FROM DUAL;

DROP SEQUENCE Seq_name;

CREATE SEQUENCE Seq_name
MINVALUE 2000
MAXVALUE 9999
START WITH 9980
NOCYCLE -- CYCLE PRZEKRECA LICZNIK // NO CYCLE TEGO NIE ROBI
INCREMENT BY 9;

SELECT SEQ_NAME.CURRVAL FROM DUAL;
SELECT SEQ_NAME.NEXTVAL FROM DUAL;

ALTER SEQUENCE SEQ_NAME NOCYCLE MAXVALUE 25000;

CREATE TABLE TABLE_D
(
    id_table NUMBER(7),
    kod VARCHAR2(7)
);

CREATE SEQUENCE Seq_name;

INSERT INTO TABLE_D VALUES (SEQ_NAME.NEXTVAL, 'XYZ' || SEQ_NAME.CURRVAL);
SELECT * FROM TABLE_D;

DROP SEQUENCE SEQ_NAME;
DROP TABLE TABLE_D;

-- 3)PERSPEKTYWY PROSTE - WIDOKI NA DANE - OPARTE O ZAPYTANIA SELECT

CREATE GLOBAL TEMPORARY TABLE TABLE_E AS SELECT * FROM PRACOWNICY;
SELECT * FROM TABLE_E;
DROP TABLE TABLE_E;

CREATE TABLE TABLE_E AS SELECT * FROM PRACOWNICY;
SELECT * FROM TABLE_E;

CREATE OR REPLACE VIEW V_aktualni_prac AS
SELECT * FROM TABLE_E WHERE data_zwol IS NULL OR data_zwol>=SYSDATE;

SELECT * FROM V_aktualni_prac;
UPDATE V_AKTUALNI_PRAC SET data_zwol=to_date('01-01-1000','DD-MM-YYYY') WHERE data_zwol IS NOT NULL;
SELECT * FROM V_AKTUALNI_PRAC;

SELECT * FROM TABLE_E AS OF TIMESTAMP (SYSTIMESTAMP - INTERVAL '1' MINUTE);
commit;
DELETE FROM V_AKTUALNI_PRAC WHERE placa BETWEEN 5000 AND 7000;
SELECT * FROM V_AKTUALNI_PRAC;
SELECT * FROM TABLE_E AS OF TIMESTAMP (SYSTIMESTAMP-INTERVAL '5' MINUTE);

INSERT INTO V_AKTUALNI_PRAC (nr_akt,nazwisko, data_zwol) VALUES (1000,'Testowy',SYSDATE+10);
SELECT * FROM TABLE_E;
DROP VIEW V_AKTUALNI_PRAC;

CREATE OR REPLACE VIEW V_aktualni_prac AS
SELECT * FROM TABLE_E WHERE data_zwol IS NULL OR data_zwol>=SYSDATE
WITH CHECK OPTION;

INSERT INTO V_AKTUALNI_PRAC (nr_akt,nazwisko, data_zwol) VALUES (1001,'Testowy',SYSDATE-10);
SELECT * FROM TABLE_E;
INSERT INTO V_AKTUALNI_PRAC (nr_akt,nazwisko, data_zwol) VALUES (1001,'Testowy',NULL);

CREATE OR REPLACE VIEW V_aktualni_prac AS
SELECT * FROM TABLE_E WHERE data_zwol IS NULL OR data_zwol>=SYSDATE
WITH READ ONLY;

INSERT INTO V_AKTUALNI_PRAC (nr_akt,nazwisko, data_zwol) VALUES (1001,'Testowy',NULL);
DROP TABLE TABLE_E;
DROP VIEW V_AKTUALNI_PRAC;

-- PERSPEKTYWY ZLOZONE (ZLACZENIA,AGREGACJE,GRUPOWANIA)
CREATE TABLE TABLE_E AS SELECT * FROM PRACOWNICY;
SELECT * FROM TABLE_E;
SELECT nr_akt, nazwisko, placa+NVL2(dod_funkcyjny, dod_funkcyjny,0)
+placa*dod_staz*0.01-NVL2(koszt_ubezpieczenia,koszt_ubezpieczenia,0)Pensja FROM TABLE_E;

CREATE OR REPLACE VIEW V_ZLOZONA AS SELECT nr_akt, nazwisko, placa+NVL2(dod_funkcyjny, dod_funkcyjny,0)
+placa*dod_staz*0.01-NVL2(koszt_ubezpieczenia,koszt_ubezpieczenia,0)Pensja FROM TABLE_E;
SELECT * FROM V_ZLOZONA;

UPDATE V_ZLOZONA SET Pensja=Pensja*10.2;
UPDATE V_ZLOZONA SET nazwisko=nazwisko||'xd'WHERE nazwisko LIKE 'Michalski';
SELECT * FROM V_ZLOZONA;

CREATE OR REPLACE VIEW V_ZLOZONA AS
SELECT id_dzialu, SUM(placa) SUM_PLACA FROM TABLE_E GROUP BY id_dzialu;
SELECT * FROM V_ZLOZONA;
UPDATE V_ZLOZONA SET SUM_PLACA=SUM_PLACA*1.1;
UPDATE V_ZLOZONA SET id_dzialu=id_dzialu+10;

DROP TABLE TABLE_E;
DROP VIEW V_ZLOZONA;


-- 4)INDEKSY - TWORZONE ZE WZGLEDOW WYDAJNOSCIOWYCH. POZWALAJA NA SZYBKIE ODNAJDYWANIE ELEMENTOW

CREATE TABLE TABLE_F AS SELECT nr_akt, imiona, nazwisko, data_zatr, placa FROM PRACOWNICY;
SELECT * FROM TABLE_F;

CREATE INDEX ind_test ON TABLE_F(nazwisko DESC);
CREATE INDEX ind_test2 ON TABLE_F(imiona, data_zatr, placa);
SELECT * FROM USER_INDEXES WHERE TABLE_NAME LIKE 'TABLE_F';
ALTER INDEX ind_test RENAME TO IND_TF;
DROP INDEX IND_TF;
DROP INDEX ind_test2;

-- INDEKS UNIKATOWY
CREATE UNIQUE INDEX IND_UN ON TABLE_F(imiona);
CREATE UNIQUE INDEX IND_UN ON TABLE_F(nr_akt);
INSERT INTO TABLE_F VALUES(1234,'TEST','TESTOWY',SYSDATE,12345);
INSERT INTO TABLE_F VALUES(1235,'TEST','TESTOWY',SYSDATE,12345);
SELECT * FROM TABLE_F;

DROP TABLE TABLE_F;

--------------------- ORACLE 12 -------------------
CREATE SEQUENCE SEQ_NAME;
CREATE TABLE TABLE_G
(
id_table NUMBER DEFAULT SEQ_NAME.NEXTVAL CONSTRAINT TABLE_G_PK PRIMARY KEY,
wartosc NUMBER GENERATED BY DEFAULT AS IDENTITY (START WITH 111 INCREMENT BY 10),
nazwa VARCHAR(20)
);

INSERT INTO TABLE_G (nazwa) VALUES 'AAA';

----------------------------------------------------------------------------------------
-- Lab 10
-- Zad.1
CREATE GLOBAL TEMPORARY TABLE Min_Ryby_Wedkarzy
(
id_wedkarza NUMBER(5),
nazwisko VARCHAR2(30),
id_gatunku NUMBER(2),
nazwa VARCHAR2(30),
wartosc NUMBER(5,2),
komentarz VARCHAR2(30)
)ON COMMIT DELETE ROWS;

CREATE GLOBAL TEMPORARY TABLE Max_Ryby_Wedkarzy
(
id_wedkarza NUMBER(5),
nazwisko VARCHAR2(30),
id_gatunku NUMBER(2),
nazwa VARCHAR2(30),
wartosc NUMBER(5,2),
komentarz VARCHAR2(30)
)ON COMMIT DELETE ROWS;

-- a)
INSERT ALL
INTO Min_Ryby_Wedkarzy VALUES (id_wedkarza,nazwisko,id_gatunku,nazwa,NAJLZEJSZA,'NAJLZEJSZA')
INTO Max_Ryby_Wedkarzy VALUES (id_wedkarza,nazwisko,id_gatunku,nazwa,NAJCIEZSZA,'NAJCIEZSZA')
SELECT id_wedkarza, nazwisko, id_gatunku, nazwa,
(SELECT NVL(MIN(waga),0) FROM REJESTRY WHERE id_wedkarza=we.id_wedkarza AND id_gatunku=ga.id_gatunku) NAJLZEJSZA,
(SELECT NVL(MAX(waga),0) FROM REJESTRY WHERE id_wedkarza=we.id_wedkarza AND id_gatunku=ga.id_gatunku) NAJCIEZSZA
FROM WEDKARZE WE CROSS JOIN GATUNKI GA;

SELECT * FROM MAX_RYBY_WEDKARZY;
-- b)
SELECT id_wedkarza, T1.nazwisko, id_gatunku, T1.nazwa, T1.komentarz||' '||T1.wartosc MIN, T2.komentarz||' '||
T2.wartosc MAX FROM (SELECT * FROM MIN_RYBY_WEDKARZY) T1 JOIN (SELECT * FROM MAX_RYBY_WEDKARZY)
T2 USING(id_wedkarza,id_gatunku);
commit;
-- c)
INSERT FIRST
WHEN NAJKROTSZA BETWEEN 0 AND 35 THEN
INTO Min_Ryby_Wedkarzy VALUES (id_wedkarza,nazwisko,id_gatunku,nazwa,NAJKROTSZA,'NAJKROTSZA')
WHEN NAJDLUZSZA > 60 THEN
INTO Max_Ryby_Wedkarzy VALUES (id_wedkarza,nazwisko,id_gatunku,nazwa,NAJDLUZSZA,'NAJDLUZSZA')
SELECT id_wedkarza, nazwisko, id_gatunku, nazwa,
(SELECT NVL(MIN(dlugosc),0) FROM REJESTRY WHERE id_gatunku=ga.id_gatunku AND id_wedkarza=we.id_wedkarza)NAJKROTSZA,
(SELECT NVL(MAX(dlugosc),0) FROM REJESTRY WHERE id_gatunku=ga.id_gatunku AND id_wedkarza=we.id_wedkarza)NAJDLUZSZA
FROM WEDKARZE we CROSS JOIN GATUNKI ga;
-- d)
SELECT * FROM MIN_RYBY_WEDKARZY;
SELECT * FROM MAX_RYBY_WEDKARZY;
DROP TABLE MIN_RYBY_WEDKARZY;
DROP TABLE MAX_RYBY_WEDKARZY;

-- Zad.2

CREATE GLOBAL TEMPORARY TABLE NAJNIZSZE_SREDNIE
(
KIERUNEK VARCHAR2(150),
TRYB VARCHAR2(30),
STOPIEN NUMBER(1),
NR_INDEKSU NUMBER(6),
SREDNIA NUMBER(3,2)
)ON COMMIT DELETE ROWS;

CREATE GLOBAL TEMPORARY TABLE NAJWYZSZE_SREDNIE
(
KIERUNEK VARCHAR2(150),
TRYB VARCHAR2(30),
STOPIEN NUMBER(1),
NR_INDEKSU NUMBER(6),
SREDNIA NUMBER(3,2)
)ON COMMIT DELETE ROWS;

INSERT ALL
WHEN SREDNIA=MIN_SREDNIA THEN INTO NAJNIZSZE_SREDNIE VALUES (KIERUNEK, TRYB, STOPIEN, NR_INDEKSU, SREDNIA)
WHEN SREDNIA=MAX_SREDNIA THEN INTO NAJWYZSZE_SREDNIE VALUES (KIERUNEK, TRYB, STOPIEN, NR_INDEKSU, SREDNIA)
SELECT * FROM (
SELECT kierunek, tryb, stopien, MIN(srednia)MIN_SREDNIA, MAX(srednia)MAX_SREDNIA FROM STUDENCI
GROUP BY kierunek, tryb, stopien) t JOIN STUDENCI st USING (kierunek, tryb, stopien);

SELECT * FROM NAJNIZSZE_SREDNIE;
SELECT * FROM NAJWYZSZE_SREDNIE;
DROP TABLE NAJNIZSZE_SREDNIE;
DROP TABLE NAJWYZSZE_SREDNIE;
commit;

-- Zad.3
CREATE TABLE ZAK
(
id_studenta NUMBER(6) CONSTRAINT id_studenta_pk PRIMARY KEY,
nazwisko VARCHAR2(20) CONSTRAINT nazwisko_nn NOT NULL,
imie VARCHAR2(15) CONSTRAINT imie_nn NOT NULL,
pseudonim VARCHAR2(30) CONSTRAINT pseudonim_nn NOT NULL,
kierunek VARCHAR2(20) DEFAULT 'INFORMATYKA',
stopien NUMBER(1) CONSTRAINT stopien_ch CHECK(stopien IN(1,2,3)),
semestr NUMBER(1) CONSTRAINT semestr_ch CHECK(semestr IN(1,2,3,4,5,6,7,8))
);

CREATE SEQUENCE Zak_id_seq
START WITH 99985
MINVALUE 10000
MAXVALUE 99999
CYCLE
INCREMENT BY 10;

insert into zak values(Zak_id_seq.nextval, 'KOWALSKI', 'ROMAN', 'KOWAL',  'INFORMATYKA', 1, 2);
insert into zak values(Zak_id_seq.nextval, 'NOWAK', 'ANNA', 'NOWA', 'INFORMATYKA',  1, 3);
insert into zak values(Zak_id_seq.nextval, 'PIECH', 'EWA', 'PEWA',  'MECHANIKA', 1, 2);
insert into zak values(Zak_id_seq.nextval, 'POLAK', 'IZABELA', 'IZA',  'MECHANIKA', 2, 4);
SELECT * FROM ZAK;

-- Zad.4
ALTER SEQUENCE Zak_id_seq INCREMENT BY 5;
insert into zak values(Zak_id_seq.nextval, 'WAWRZYNIEC', 'DAMIAN','WAWRZYN',  'INFORMATYKA',  2, 3);
insert into zak values(Zak_id_seq.nextval, 'KOSSAK', 'KATARZYNA', 'KOSA', 'INFORMATYKA',  1, 2);
SELECT * FROM ZAK;

-- Zad.5
CREATE INDEX IND_KIERUNEK ON ZAK(kierunek);
CREATE INDEX IND_STOPIEN ON ZAK(stopien, semestr);
CREATE INDEX IND_SEMESTR ON ZAK(pseudonim);

insert into zak values((select max(id_studenta) from zak)+1, 'WAWRZYNIEC', 'JAN','WAWRZYN2',  'MATEMATYKA',  1, 2);
insert into zak values((select max(id_studenta) from zak)+1, 'WAWRZYNIEC', 'ADAM','WAWRZYN2',  'MATEMATYKA',  1, 2);

DROP TABLE ZAK;

-- Zad.6
CREATE TABLE STUDENCI_BIS AS SELECT * FROM STUDENCI;
SELECT * FROM STUDENCI_BIS;

CREATE OR REPLACE VIEW Studentki AS SELECT * FROM STUDENCI WHERE imiona LIKE ('%a') ORDER BY nazwisko, imiona;
SELECT * FROM Studentki;

CREATE OR REPLACE VIEW Zacy AS SELECT * FROM STUDENCI_BIS WHERE IMIONA NOT LIKE('%a') ORDER BY nazwisko, imiona
WITH READ ONLY;
SELECT * FROM ZACY;

insert into Zacy values(123456, 'Testowski', 'Test', to_date('01-01-1995', 'dd-mm-yyyy'), 'adres', 'kierunek', 'tryb', 1, 1, 'specjalnosc', 1, 4);
insert into Studentki values(123456, 'Testowski', 'Test', to_date('01-01-1995', 'dd-mm-yyyy'), 'adres', 'kierunek', 'tryb', 1, 1, 'specjalnosc', 1, 4);
insert into Studentki values(123456, 'Testowski', 'Testa', to_date('01-01-1995', 'dd-mm-yyyy'), 'adres', 'kierunek', 'tryb', 1, 1, 'specjalnosc', 1, 4);
-- NIE WESZLO !!!!!!!!!!!!!!!!!!!!!!!!!

select * from studentki where nazwisko like 'Test%';
select * from zacy where nazwisko like 'Test%';
select * from studenci_bis where nazwisko like 'Test%';

-- Zad.7
CREATE OR REPLACE VIEW S1R1 AS SELECT nr_indeksu, nazwisko, imiona, rok,
SUBSTR(IMIONA,1,1) || SUBSTR(NAZWISKO,1,1) || NR_INDEKSU PSEUDONIM
FROM ZACY WHERE STOPIEN=1 AND ROK=1
WITH CHECK OPTION;
SELECT * FROM S1R1;

INSERT INTO S1R1 VALUES ((SELECT MAX(nr_indeksu)+1 FROM S1R1),'TESTOWY','TEST',1,'XX1');
DROP VIEW S1R1;
DROP VIEW ZACY;
DROP VIEW STUDENTKI;
DROP TABLE STUDENCI_BIS CASCADE CONSTRAINTS;

-- Zad.8
CREATE TABLE PracownicyBis AS SELECT * FROM Pracownicy;
CREATE OR REPLACE VIEW Lista_plac AS SELECT nr_akt, nazwisko, id_dzialu, stanowisko,
placa+NVL(dod_funkcyjny,0)+ placa*dod_staz*0.01- Nvl(koszt_ubezpieczenia,0) PENSJA FROM PRACOWNICYBIS
WHERE (data_zwol IS NULL OR data_zwol >= sysdate) AND nr_akt>=1000 ORDER BY id_dzialu,nazwisko WITH CHECK OPTION;

SELECT * FROM Lista_plac;
INSERT INTO Lista_Plac VALUES(1222, 'TESTOWSKI', 10, 'INFORMATYK', 5000);
-- NIE WESZLO !!!!

SELECT * FROM Lista_plac;
select * from pracownicybis;

-- Zad.9
CREATE OR REPLACE VIEW SZEFOWIE AS SELECT nr_akt,
nazwisko, liczba liczba_podwladnych, data_zatr, placa, id_dzialu FROM
(SELECT przelozony, count(*) liczba FROM PRACOWNICYBIS p1
WHERE data_zwol IS NULL OR data_zwol>=SYSDATE GROUP BY przelozony) s1
JOIN PRACOWNICYBIS p2 ON (p2.nr_akt=s1.przelozony) WHERE p2.data_zwol IS NULL OR p2.data_zwol>=SYSDATE;

SELECT * FROM SZEFOWIE;
SELECT * FROM PRACOWNICYBIS;
INSERT INTO Szefowie VALUES(9999, 'TESTOWSKI', 0, sysdate, 5000,  10);

DROP VIEW SZEFOWIE;
DROP TABLE PRACOWNICYBIS CASCADE CONSTRAINTS;
--
DROP SEQUENCE SEQ_ID_WYK;
DROP SEQUENCE SEQ_NAME;
DROP SEQUENCE ZAK_ID_SEQ;
DROP VIEW LISTA_PLAC;
