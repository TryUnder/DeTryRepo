CREATE TABLE firmy
(
id_firmy NUMBER(6) CONSTRAINT firmy_pk PRIMARY KEY,
nazwa VARCHAR2(200), --dod NN
adres VARCHAR2(250) CONSTRAINT firmy_adres_nn NOT NULL,
koszt_km DATE, -- zmiana typu, zmiana nazwy cena_km
oplata_stala NUMBER(3) -- zmiana precyzji i zakresu
);

CREATE TABLE taxi
(
nr_rejestracyjny VARCHAR(10) CONSTRAINT taxi_pk PRIMARY KEY,
id_wlasciciela NUMBER(6) CONSTRAINT taxi_wlasciciel_UN UNIQUE,
marka VARCHAR(30) CONSTRAINT taxi_marka_nn NOT NULL,
modell VARCHAR(30) CONSTRAINT taxi_modell_nn NOT NULL,
data_prod DATE,
-- dodac kolumne kolor
CONSTRAINT taxi_wlasciciel_FK FOREIGN KEY(id_wlasciciela) REFERENCES firmy(id_firmy) ON DELETE SET NULL
);

CREATE TABLE klienci
(
id_klienta NUMBER(6),  -- PK
personalia VARCHAR(70)CONSTRAINT klienci_personalia_nn NOT NULL CONSTRAINT klienci_pk PRIMARY KEY, -- usuniecie PK
adres VARCHAR(250),
wiek NUMBER(2), --usuniecie
waga NUMBER(5,2) --usuniecie
);

CREATE TABLE przewozy
(
id_przewozu NUMBER(7) CONSTRAINT przewozy_pk PRIMARY KEY,
id_taxi VARCHAR(10),
id_klienta VARCHAR(70), --zmiana typu
dystans NUMBER(5,1),
data_kursu DATE,
rachunek NUMBER(7,2) DEFAULT 0,
CONSTRAINT Przewozy_id_taxi_FK FOREIGN KEY(id_taxi) REFERENCES taxi(nr_rejestracyjny) ON DELETE SET NULL,
CONSTRAINT Przwozy_id_klienta_FK FOREIGN KEY(id_klienta) REFERENCES klienci(personalia) ON DELETE CASCADE 
);

SELECT * FROM user_tables;
SELECT * FROM user_constraints;


-- Tabela Firmy
-- Ograniczenie NOT NULL dla nazwa
ALTER TABLE firmy MODIFY nazwa CONSTRAINT firmy_nazwa_nn NOT NULL;

-- Kolumna koszt_km -> zmiana nazwy na cena_km
ALTER TABLE Firmy RENAME COLUMN koszt_km to cena_km;
SELECT * FROM Firmy;

-- Kolumna cena_km zmiana typu na Number, oraz cena_km>=1
ALTER TABLE Firmy MODIFY(
cena_km NUMBER(7,2) CONSTRAINT Firmy_cena_km_ch CHECK(cena_km>=1),-- Nie moze byc zadnych rekordow, lub musza miec wartosci puste
oplata_stala NUMBER(6,2) CONSTRAINT Firmy_plata_stala_ch CHECK(oplata_stala>=0)
);

SELECT * FROM user_constraints WHERE table_name LIKE 'FIRMY';

-- Tabela Taxi
-- Kolumna id_wlasciciela -> usuniecie unikatowosci
ALTER TABLE TAXI DROP CONSTRAINT taxi_wlasciciel_un;

-- Dodanie kolumny kolor, warto�� domy�lna RED
ALTER TABLE TAXI ADD KOLOR VARCHAR(30) DEFAULT 'RED'; -- W przypadku dodawania kilku kolumn, to w nawiasie, po przecinku
DESC TAXI;

-- Tabela Klienci
-- Zmiana klucza glownego z personalia na id_klienta(+ stosowne zmiany w Przewozach)
SELECT * FROM USER_CONSTRAINTS WHERE TABLE_NAME LIKE 'KLIENCI';
ALTER TABLE KLIENCI DROP CONSTRAINT KLIENCI_PK;
-- WAZNE --
-- OPERACJA SIE NIE POWIODLA, PONIEWAZ TABELA PRZEWOZY ODWOLUJE SIE DO TABELI KLIENCI.
-- KLUCZ OBCY TABELI KLIENCI NIE MOZE BYC PRZYPISANY DO NIE UNIKATOWEGO *POLA*. 
-- TAKA UNIKATOWOSC GWARANTUJE PRIMARY KEY
-- NAJPIERW NALEZY ROZCIAC TO ZEWNETRZNE POWIAZANIE
ALTER TABLE PRZEWOZY DROP CONSTRAINT Przewozy_id_klienta_FK;
ALTER TABLE KLIENCI DROP CONSTRAINT KLIENCI_PK;
ALTER TABLE KLIENCI ADD CONSTRAINT KLIENCI_PK PRIMARY KEY(id_klienta);
-- ID_KLIENTA W PRZEWOZACH TO VARCHAR. NALEZY ZMIENIC NA NUMBER
ALTER TABLE PRZEWOZY MODIFY id_klienta NUMBER(6);
-- PRZYKLAD DEFINIOWANIA KLUCZY OBCYCH Z POZA TABELI
ALTER TABLE PRZEWOZY ADD CONSTRAINT Przewozy_id_klienta_FK FOREIGN KEY(id_klienta) 
REFERENCES KLIENCI(id_klienta) ON DELETE CASCADE;

-- Usuniecie kolumn wiek oraz waga
ALTER TABLE KLIENCI DROP COLUMN wiek;
ALTER TABLE KLIENCI DROP COLUMN waga;

--DANE
SELECT * FROM FIRMY;

INSERT INTO FIRMY
SELECT ROWNUM, wlasciciel, adres, 2+Mod(id_wlasciciela,100)/100,
EXTRACT(DAY FROM data_up) FROM WLASCICIELE WHERE wlasciciel LIKE 'Firma%' AND ROWNUM < 11;

-- TAXI
SELECT * FROM TAXI;
INSERT INTO TAXI SELECT nr_rejestracyjny,
Trunc(DBMS_Random.value(1,(SELECT count(*)+1 FROM FIRMY))), marka, modell, data_produkcji, kolor 
FROM pojazdy WHERE typ LIKE 'SAM_OSOBOWY' AND nr_rejestracyjny IS NOT NULL AND ROWNUM<45;

-- JAK ZDEFINIOWAC LOSOWOSC
SELECT Trunc(DBMS_Random.value(1,(SELECT count(*)+1 FROM FIRMY))) FROM DUAL;

--KLIENCI
INSERT INTO KLIENCI SELECT rownum, nazwisko|| ' ' || imiona, adres FROM STUDENCI WHERE rownum<61;

--PRZEWOZY
SELECT * FROM TAXI;
SELECT * FROM PRZEWOZY;

INSERT INTO PRZEWOZY
SELECT id_przewozu, nr_rejestracyjny, klient, dystans, dzien, NULL FROM
(
SELECT ROWNUM AS id_przewozu,
Trunc(DBMS_Random.value(1,(SELECT Count(*)+1 FROM KLIENCI))) klient,
Trunc(DBMS_Random.value(1,(SELECT Count(*)+1 FROM TAXI))) pojazd,
SYSDATE - TRUNC(DBMS_RANDOM.VALUE(1,1001)) dzien,
ROUND(DBMS_RANDOM.VALUE(1, 501),1) dystans
FROM DS.POJAZDY WHERE ROWNUM<501
) T1 JOIN
(
SELECT nr_rejestracyjny, ROWNUM poz FROM TAXI
) T2 ON (T1.pojazd=T2.poz);

-- I TERAZ MOZNA Z TEGO KORZYSTAC

SELECT * FROM PRZEWOZY JOIN KLIENCI USING (id_klienta) JOIN TAXI ON(przewozy.id_taxi=taxi.nr_rejestracyjny);
----------------------------------------------------------------------------------------------------------------
-- TWORZENIE SKRYPTOW --
-- FIRMY
--------------------------
SELECT * FROM FIRMY;
SELECT 'INSERT INTO FIRMY VALUES
('|| nazwa ||''','''|| adres ||''',' || 
REPLACE(to_char(cena_km),',','.')||','||replace(to_char(oplata_stala),',','.')||');' FROM FIRMY;

-- PRZEWOZY
SELECT 'INSERT INTO PRZEWOZY VALUES(' ||id_przewozu||','''||TRIM(id_taxi)||''','||id_klienta||','||
REPLACE(TO_CHAR(dystans),',','.')||',TO_DATE('''||TO_CHAR(data_kursu,'YYYY-MM-DD')||''',''YYYY-MM-DD''),NULL);'
FROM przewozy ORDER BY id_przewozu;
 
SELECT * FROM PRZEWOZY;

UPDATE PRZEWOZY pr SET rachunek=
(SELECT ROUND(dystans*cena_km,2)+oplata_stala FROM przewozy JOIN TAXI ON(id_taxi=nr_rejestracyjny) JOIN FIRMY
ON (id_wlasciciela=id_firmy)
WHERE id_przewozu=pr.id_przewozu
)WHERE rachunek IS NULL;

-- USUNIECIE WYBRANYCH REKORDOW Z TABELI KLIENCI, ORAZ TAXI. WERYFIKACJA TABELI PRZEWOZY
commit;
rollback;
SELECT * FROM TAXI;
DELETE FROM KLIENCI WHERE id_klienta=27;
DELETE FROM TAXI WHERE nr_rejestracyjny LIKE 'EWI 8737M';

-- OGRANICZENIA
SELECT * FROM USER_CONSTRAINTS WHERE TABLE_NAME LIKE ('FIRMY');

INSERT INTO FIRMY VALUES(1234,'Testowa','gdzies',0.99,-1);
ALTER TABLE FIRMY ENABLE CONSTRAINT FIRMY_PLATA_STALA_CH;
ALTER TABLE FIRMY RENAME CONSTRAINT FIRMY_PLATA_STALA_CH TO FIRMY_OPLATA_STALA_CH;
ALTER TABLE FIRMY DISABLE CONSTRAINT FIRMY_OPLATA_STALA_CH;
INSERT INTO FIRMY VALUES(1234,'Testowa','gdzies',0.99,-1);
ALTER TABLE FIRMY DISABLE CONSTRAINT FIRMY_CENA_KM_CH;
INSERT INTO FIRMY VALUES(1234,'Testowa','gdzies',0.99,-1);
SELECT * FROM FIRMY;
ALTER TABLE FIRMY ENABLE CONSTRAINT FIRMY_OPLATA_STALA_CH;
-- ALBO AKTUALIZUJEMY WIERSZ TAK ABY SPELNIAL WARUNEK NARZUCONY PRZEZ OGRANICZENIE
-- ZMIENIC SAMO OGRANICZENIE POPRZEZ JEGO USUNIECIE I NA NOWO JEGO ZDEFINIOWANIE
-- LUB NOVALIDATE (OGRANICZENIE ZOSTAJE AKTYWOWANE BEZ SPRAWDZANIA WERYFIKACJI DOTYCHCZASOWYCH REKORDOW)
ALTER TABLE FIRMY ENABLE NOVALIDATE CONSTRAINT FIRMY_OPLATA_STALA_CH;
ALTER TABLE FIRMY ENABLE NOVALIDATE CONSTRAINT FIRMY_CENA_KM_CH;
INSERT INTO FIRMY VALUES(4444,'AAATestowa','gdzies',0.99,-1);

-- KOLUMNA WIRTUALNA
SELECT * FROM PRZEWOZY;
DESC PRZEWOZY;
ALTER TABLE PRZEWOZY ADD(avg_km AS (ROUND(rachunek/dystans,2)));

COMMENT ON TABLE PRZEWOZY IS'ZAWIERA WIRTUALNA KOLUMNE AVG_KM';
SELECT * FROM USER_TAB_COMMENTS;
COMMENT ON COLUMN PRZEWOZY.avg_km IS 'WIRTUALNA KOLUMNA';
SELECT * FROM USER_COL_COMMENTS;

DROP TABLE PRZEWOZY CASCADE CONSTRAINTS;
DROP TABLE TAXI CASCADE CONSTRAINTS;
DROP TABLE FIRMY CASCADE CONSTRAINTS;
DROP TABLE KLIENCI CASCADE CONSTRAINTS;

-------------------------------------------------------------------------------------------------------------
----------------------------------------------------LISTA 9--------------------------------------------------
-------------------------------------------------------------------------------------------------------------

-- Zad 1
CREATE TABLE Produkty 
(
id_produktu NUMBER(4) CONSTRAINT id_produktu_un UNIQUE,
nazwa VARCHAR2(40) CONSTRAINT nazwa_nn NOT NULL,
stan NUMBER(6,2) DEFAULT 0,
cena  NUMBER(6,2) DEFAULT 1.23,
wartosc AS (stan*cena) 
);

-- Zad 2
CREATE TABLE Kasjerzy
(
id_kasjera NUMBER(5) CONSTRAINT kasjerzy_id_kasjera_PK PRIMARY KEY,
nazwisko VARCHAR2(20),
data_zatrudnienia DATE CONSTRAINT data_zatrudnienia_nn NOT NULL,
placa NUMBER(7,2)
);

-- Zad 3
CREATE TABLE Transakcje
(
id_transakcji NUMBER(8) CONSTRAINT id_transakcji_PK PRIMARY KEY,
id_produktu NUMBER(4) CONSTRAINT transakcje_id_produktu_NN NOT NULL,
CONSTRAINT id_produktu_FK FOREIGN KEY(id_produktu) REFERENCES Produkty(id_produktu),
id_sprzedawcy NUMBER(5) CONSTRAINT id_sprzedawcy_NN NOT NULL,
CONSTRAINT id_sprzedawcy_FK FOREIGN KEY(id_sprzedawcy) REFERENCES Kasjerzy(id_kasjera),
miara NUMBER(6,2) DEFAULT 1,
czas_transakcji timestamp
);

-- Zad 4
ALTER TABLE Kasjerzy MODIFY (placa DEFAULT 3200);