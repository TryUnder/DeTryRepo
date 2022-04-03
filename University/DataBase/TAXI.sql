-- TAXI

-- Zadanie.1
CREATE TABLE KCennik
(
segment_pojazdu CHAR CONSTRAINT segment_pojazdu_ch 
CHECK (segment_pojazdu IN ('A','B','C','D','E','F','J','M','S'))
CONSTRAINT segment_pojazdu_PK PRIMARY KEY,
okres NUMBER(4) CONSTRAINT okres_ch CHECK (okres > 2010),
oplata_stala NUMBER(4,2) DEFAULT 5 CONSTRAINT oplata_stala_ch CHECK (oplata_stala BETWEEN 3 AND 1500),
cena_km NUMBER(3) CONSTRAINT cena_km_ch CHECK (cena_km>0),
oplata_postojowa_min NUMBER(3,2),
oplata_weekendowa NUMBER(4,2) DEFAULT 0 CONSTRAINT oplata_weekendowa_ch 
CHECK (MOD(oplata_weekendowa,2)=0 OR MOD(oplata_weekendowa,2) = 1 OR MOD(oplata_weekendowa,2) = 1.5
OR MOD(oplata_weekendowa,2) = 0.5)
);

-- Zadanie.2
CREATE TABLE KPojazdy
(
nr_rejestracyjny VARCHAR(10) CONSTRAINT nr_rejestracyjny_pk PRIMARY KEY CONSTRAINT nr_rejestracyjny_ch
CHECK(INSTR(nr_rejestracyjny,'')=2 OR INSTR(nr_rejestracyjny,'')=3),
marka VARCHAR2(30) CONSTRAINT marka_nn NOT NULL,
modell VARCHAR2(30) CONSTRAINT modell_nn NOT NULL,
data_produkcji DATE,
wlasciciel VARCHAR2(50),
segment_pojazdu CHAR CONSTRAINT segment_pojazdu2_ch CHECK (segment_pojazdu IN ('A','B','C','D','E','F','J','M','S'))
);


-- Zad.3
CREATE TABLE KPasazerowie
(
id_pasazera NUMBER(5) CONSTRAINT id_pasazera_un UNIQUE,
nazwisko VARCHAR2(40) CONSTRAINT nazwisko_nn NOT NULL,
imiona VARCHAR2(30) CONSTRAINT imiona_nn NOT NULL,
adres VARCHAR2(200) CONSTRAINT adres_nn NOT NULL,
data_urodzenia DATE CONSTRAINT data_urodzenia_ch CHECK (data_urodzenia >= TO_DATE('01-01-1945','DD-MM-YYYY')),
klient_od DATE CONSTRAINT klient_od_ch CHECK (klient_od >= TO_DATE('01-01-2015','DD-MM-YYYY'))
);


-- Zad.4
CREATE TABLE KKursy
(
nr_rejestracyjny VARCHAR2(10), CONSTRAINT nr_rejestracyjny_fk FOREIGN KEY
(nr_rejestracyjny) REFERENCES KPojazdy(nr_rejestracyjny) ON DELETE CASCADE,
id_pasazera NUMBER(5) CONSTRAINT id_pasazera_nn NOT NULL,
CONSTRAINT id_pasazera_fk2 FOREIGN KEY(id_pasazera) REFERENCES KPasazerowie(id_pasazera) ON DELETE SET NULL,
data_kursu TIMESTAMP,
dystans NUMBER(5,1) CONSTRAINT dystans_ch CHECK (dystans>=0),
czas_postoju NUMBER(4) DEFAULT 0 CONSTRAINT czas_postoju_nn NOT NULL,
rachunek NUMBER(5,2),
PRIMARY KEY(nr_rejestracyjny,data_kursu)
);

-- Zad.5
ALTER TABLE KCennik RENAME COLUMN okres TO rok;
SELECT * FROM KCennik;

-- Zad.6
ALTER TABLE Kcennik MODIFY (oplata_postojowa_min DEFAULT 0.1);

-- Zad.7
ALTER TABLE KCENNIK MODIFY cena_km NUMBER(3,2) DEFAULT 1.8;
ALTER TABLE KCENNIK DROP CONSTRAINT cena_km_ch;
ALTER TABLE KCENNIK ADD CONSTRAINT cena_km_ch CHECK(cena_km>=1.5);

-- Zad.8
ALTER TABLE KCENNIK DROP CONSTRAINT segment_pojazdu_pk;
ALTER TABLE KCENNIK ADD CONSTRAINT segment_pojazdu_rok_pk PRIMARY KEY(segment_pojazdu,rok);

-- Zad.9
ALTER TABLE KPOJAZDY DROP COLUMN wlasciciel;

-- Zad.10
ALTER TABLE KPASAZEROWIE ADD (liczba_kursow NUMBER(4) DEFAULT 0 CONSTRAINT liczba_kursow_nn NOT NULL);

-- Zad.11
ALTER TABLE KPASAZEROWIE ADD(dane_adresowe AS  (imiona||' '|| nazwisko||' '|| adres));

-- Zad.12
ALTER TABLE KPASAZEROWIE DROP CONSTRAINT id_pasazera_un;
ALTER TABLE KKURSY DROP CONSTRAINT id_pasazera_nn;
ALTER TABLE KKURSY DROP CONSTRAINT id_pasazera_fk2;
ALTER TABLE KPASAZEROWIE DROP CONSTRAINT id_pasazera_un;
ALTER TABLE KPASAZEROWIE ADD CONSTRAINT id_pasazera_pk PRIMARY KEY(id_pasazera);

-- Zad.13
ALTER TABLE KKURSY MODIFY data_kursu DATE;

-- Zad.14
CREATE INDEX Index_test ON KCENNIK(oplata_stala,cena_km,oplata_postojowa_min,oplata_weekendowa);

-- Zad.15
CREATE SEQUENCE seq_id_pasazera
MAXVALUE 99999
START WITH 10
NOCYCLE
INCREMENT BY 10;

INSERT INTO KCennik VALUES('A', 2020, 4, 1.5, 0.25, 5);
INSERT INTO KCennik VALUES('B', 2020, 4.5, 1.80, 0.25, 6);
INSERT INTO KCennik VALUES('C', 2020, 5.5, 1.95, 0.30, 7);
INSERT INTO KCennik VALUES('D', 2020, 6.5, 2.15, 0.35, 10);
INSERT INTO KCennik VALUES('E', 2020, 7.5, 2.20, 0.45, 13);
INSERT INTO KCennik VALUES('F', 2020,  10, 2.75, 0.52, 20);
INSERT INTO KCennik VALUES('J', 2020,   7, 2.05, 0.32, 10);
INSERT INTO KCennik VALUES('M', 2020, 6.5, 2.00, 0.30, 11);
INSERT INTO KCennik VALUES('A', 2021, 4.4, 1.55, 0.27, 5);
INSERT INTO KCennik VALUES('B', 2021, 4.9, 1.85, 0.27, 7);
INSERT INTO KCennik VALUES('C', 2021, 5.9, 2.05, 0.35, 8);
INSERT INTO KCennik VALUES('D', 2021, 7.1, 2.35, 0.40, 10);
INSERT INTO KCennik VALUES('E', 2021, 8.2, 2.50, 0.48, 15);
INSERT INTO KCennik VALUES('F', 2021,  12, 3.05, 0.56, 22);
INSERT INTO KCennik VALUES('J', 2021,   8, 2.35, 0.36, 12);
INSERT INTO KCennik VALUES('M', 2021, 7.8, 2.40, 0.34, 12);

-----------------------
INSERT INTO KPojazdy VALUES('SC 0533L', 'MERCEDES-BENZ', 'KLASA C', to_date('09-11-2018', 'dd-mm-yyyy'), 'C');
INSERT INTO KPojazdy VALUES('WY 4977V', 'RENAULT', 'MEGANE', to_date('26-12-2018', 'dd-mm-yyyy'), 'C');
INSERT INTO KPojazdy VALUES('SC 8675J', 'FORD', 'MONDEO', to_date('12-04-2018', 'dd-mm-yyyy'), 'D');
INSERT INTO KPojazdy VALUES('SC 88526', 'FORD', 'S-MAX', to_date('20-11-2014', 'dd-mm-yyyy'), 'M');
INSERT INTO KPojazdy VALUES('SC 2550B', 'BMW', '3', to_date('02-12-2018', 'dd-mm-yyyy'), 'C');
INSERT INTO KPojazdy VALUES('SC 81277', 'OPEL', 'CORSA', to_date('28-04-2019', 'dd-mm-yyyy'), 'B');
INSERT INTO KPojazdy VALUES('WA 20272', 'BMW', '5', to_date('05-02-2019', 'dd-mm-yyyy'), 'E');
INSERT INTO KPojazdy VALUES('SC 123MM', 'BMW', '7', to_date('01-07-2014', 'dd-mm-yyyy'), 'F');
INSERT INTO KPojazdy VALUES('WD 98308', 'SKODA', 'OCTAVIA', to_date('21-04-2019', 'dd-mm-yyyy'), 'D');
INSERT INTO KPojazdy VALUES('SC 52811', 'BMW', '7', to_date('16-02-2019', 'dd-mm-yyyy'), 'F');
INSERT INTO KPojazdy VALUES('WD 7486B', 'BMW', '3', to_date('15-07-2017', 'dd-mm-yyyy'), 'C');
INSERT INTO KPojazdy VALUES('WY 20666', 'BMW', '7', to_date('17-11-2019', 'dd-mm-yyyy'), 'F');
INSERT INTO KPojazdy VALUES('SC 850BU', 'VOLKSWAGEN', 'TOUAREG', to_date('01-05-2019', 'dd-mm-yyyy'), 'M');
INSERT INTO KPojazdy VALUES('WD 20616', 'BENTLEY', 'BENTAYGA', to_date('06-02-2018', 'dd-mm-yyyy'), 'F');

-----------------------

INSERT INTO KPasazerowie (id_pasazera, nazwisko, imiona, adres, data_urodzenia) 
 VALUES (seq_id_pasazera.nextval, 'Stefan', 'Ciesielski' ,'ul. Zlota 297 80-126 Gdansk', to_date('03-09-1945', 'dd-mm-yyyy'));
INSERT INTO KPasazerowie (id_pasazera, nazwisko, imiona, adres, data_urodzenia) 
 VALUES (seq_id_pasazera.nextval, 'Zdzislaw', 'Jasinski' ,'al. Armii Krajowej 147H 42-270 Rzeki Male', to_date('11-12-1979', 'dd-mm-yyyy'));
INSERT INTO KPasazerowie (id_pasazera, nazwisko, imiona, adres, data_urodzenia) 
 VALUES (seq_id_pasazera.nextval, 'Konrad', 'Szczesny' ,'al. Wojska Polskiego 279/178 42-230 Koniecpol', to_date('09-11-1982', 'dd-mm-yyyy'));
INSERT INTO KPasazerowie (id_pasazera, nazwisko, imiona, adres, data_urodzenia) 
 VALUES (seq_id_pasazera.nextval, 'Damian', 'Cieslak' ,'ul. Dworcowa 61-76/68 42-300 Myszkow', to_date('13-02-1950', 'dd-mm-yyyy'));
INSERT INTO KPasazerowie (id_pasazera, nazwisko, imiona, adres, data_urodzenia) 
 VALUES (seq_id_pasazera.nextval, 'Karol', 'Walczak' ,'ul. Kolejowa 154 42-242 Rudniki', to_date('04-04-1946', 'dd-mm-yyyy'));
INSERT INTO KPasazerowie (id_pasazera, nazwisko, imiona, adres, data_urodzenia)
 VALUES (seq_id_pasazera.nextval, 'Blazej', 'Owczarek' ,'ul. Karola Olszewskiego 41 97-532 Pagow', to_date('15-03-1993', 'dd-mm-yyyy'));
INSERT INTO KPasazerowie (id_pasazera, nazwisko, imiona, adres, data_urodzenia) 
 VALUES (seq_id_pasazera.nextval, 'Alojzy', 'Konieczny' ,'ul. Katedralna 151/8 42-211 Czestochowa', to_date('09-01-1993', 'dd-mm-yyyy'));
INSERT INTO KPasazerowie (id_pasazera, nazwisko, imiona, adres, data_urodzenia) 
 VALUES (seq_id_pasazera.nextval, 'Franciszek', 'Laskowski' ,'al. Wojska Polskiego 101 42-265 Lesniczowka Knieja', to_date('24-03-1996', 'dd-mm-yyyy'));
INSERT INTO KPasazerowie (id_pasazera, nazwisko, imiona, adres, data_urodzenia) 
 VALUES (seq_id_pasazera.nextval, 'Sergiusz', 'Nowicki' ,'ul. Polnocna 177 42-290 Blachowania', to_date('25-02-1952', 'dd-mm-yyyy'));
INSERT INTO KPasazerowie (id_pasazera, nazwisko, imiona, adres, data_urodzenia) 
 VALUES (seq_id_pasazera.nextval, 'Karina', 'Markowska' ,'ul. Mlynska 274/146 42-350 Kozieglowy', to_date('14-06-1973', 'dd-mm-yyyy'));
INSERT INTO KPasazerowie (id_pasazera, nazwisko, imiona, adres, data_urodzenia) 
 VALUES (seq_id_pasazera.nextval, 'Anna', 'Bugaj' ,'ul. Akacjowa 12/3 42-214 Czestochowa', to_date('22-04-1995', 'dd-mm-yyyy'));

-------------------------------------


INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 0533L', 10, to_date('2020.09.03 12.10', 'yyyy.mm.dd hh24.mi'), 12.5, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 0533L', 10, to_date('2020.09.18 15.10', 'yyyy.mm.dd hh24.mi'), 10, 5);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 0533L', 20, to_date('2020.09.23 9.00', 'yyyy.mm.dd hh24.mi'), 12, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 0533L', 30, to_date('2020.10.01 11.10', 'yyyy.mm.dd hh24.mi'), 17.5, 11);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 0533L', 10, to_date('2020.10.15 17.30', 'yyyy.mm.dd hh24.mi'), 4.5, 1);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 0533L', 90, to_date('2020.10.30 13.23', 'yyyy.mm.dd hh24.mi'), 7.2, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 0533L', 100, to_date('2020.11.16 09.19', 'yyyy.mm.dd hh24.mi'), 22.2, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 0533L', 80, to_date('2020.12.03 14.54', 'yyyy.mm.dd hh24.mi'), 2.4, 5);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 0533L', 100, to_date('2020.12.13 08.09', 'yyyy.mm.dd hh24.mi'), 32, 18);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WY 4977V', 20, to_date('2020.09.12 11.10', 'yyyy.mm.dd hh24.mi'), 6.6, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WY 4977V', 70, to_date('2020.10.06 14.01', 'yyyy.mm.dd hh24.mi'), 14.5, 12);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WY 4977V', 40, to_date('2020.10.23 9.14', 'yyyy.mm.dd hh24.mi'), 3.1, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WY 4977V', 50, to_date('2020.12.14 15.19', 'yyyy.mm.dd hh24.mi'), 9.9, 3);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WY 4977V', 70, to_date('2021.01.10 6.12', 'yyyy.mm.dd hh24.mi'), 10.3, 16); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 8675J', 90, to_date('2020.10.02 7.21', 'yyyy.mm.dd hh24.mi'), 1.4, 0); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 8675J', 90, to_date('2020.10.13 13.10', 'yyyy.mm.dd hh24.mi'), 19.9, 4); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 8675J', 10, to_date('2020.10.23 13.13', 'yyyy.mm.dd hh24.mi'), 17.3, 1); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 8675J', 30, to_date('2020.12.24 7.01', 'yyyy.mm.dd hh24.mi'), 13, 0); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 8675J', 100, to_date('2021.01.07 10.05', 'yyyy.mm.dd hh24.mi'), 4.5, 0); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 8675J', 90, to_date('2020.01.18 7.19', 'yyyy.mm.dd hh24.mi'), 11.9, 2); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 88526', 70, to_date('2020.11.02 5.58', 'yyyy.mm.dd hh24.mi'), 20, 0);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 88526', 80, to_date('2020.11.24 19.19', 'yyyy.mm.dd hh24.mi'), 8.4, 3);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 88526', 80, to_date('2020.12.01 07.26', 'yyyy.mm.dd hh24.mi'), 15.5, 6);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 88526', 100, to_date('2021.01.02 11.14', 'yyyy.mm.dd hh24.mi'), 10, 3);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 88526', 90, to_date('2021.01.08 14.01', 'yyyy.mm.dd hh24.mi'), 8.7, 0);   
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 88526', 10, to_date('2021.01.18 9.12', 'yyyy.mm.dd hh24.mi'), 11, 0);   
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 2550B', 100, to_date('2020.09.02 11.10', 'yyyy.mm.dd hh24.mi'), 12.6, 0);   
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 2550B', 90, to_date('2020.09.11 09.13', 'yyyy.mm.dd hh24.mi'), 6.5, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 2550B', 80, to_date('2020.09.28 11.18', 'yyyy.mm.dd hh24.mi'), 7.6, 5);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 2550B', 10, to_date('2020.10.13 08.01', 'yyyy.mm.dd hh24.mi'), 9.3, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 2550B', 30, to_date('2020.10.17 13.15', 'yyyy.mm.dd hh24.mi'), 21.2, 15);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 2550B', 40, to_date('2020.10.19 14.01', 'yyyy.mm.dd hh24.mi'), 17.8, 0); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 2550B', 40, to_date('2020.10.29 16.08', 'yyyy.mm.dd hh24.mi'), 25.6,  0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 2550B', 60, to_date('2020.11.03 06.01', 'yyyy.mm.dd hh24.mi'), 5.2, 2);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 2550B', 60, to_date('2020.11.06 12.14', 'yyyy.mm.dd hh24.mi'), 26.1, 3); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 2550B', 60, to_date('2020.11.13 09.54', 'yyyy.mm.dd hh24.mi'), 14.5, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 2550B', 60, to_date('2020.11.21 16.16', 'yyyy.mm.dd hh24.mi'), 6.3, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 2550B', 80, to_date('2020.11.23 10.18', 'yyyy.mm.dd hh24.mi'), 7.9, 10);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 2550B', 10, to_date('2020.11.24 16.12', 'yyyy.mm.dd hh24.mi'), 4.9, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 2550B', 20, to_date('2020.11.27 07.36', 'yyyy.mm.dd hh24.mi'), 19.2, 0); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 81277', 20, to_date('2021.01.02 12.10', 'yyyy.mm.dd hh24.mi'), 11.2, 5); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 81277', 80, to_date('2021.01.04 11.15', 'yyyy.mm.dd hh24.mi'), 8.9, 0); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 81277', 60, to_date('2021.01.08 15.10', 'yyyy.mm.dd hh24.mi'), 3.9, 0); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 81277', 60, to_date('2021.01.12 07.31', 'yyyy.mm.dd hh24.mi'), 8.7, 0);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WA 20272', 80, to_date('2020.09.21 14.10', 'yyyy.mm.dd hh24.mi'), 18.9, 0); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WA 20272', 70, to_date('2020.10.10 10.13', 'yyyy.mm.dd hh24.mi'), 17.6, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WA 20272', 70, to_date('2020.11.21 13.14', 'yyyy.mm.dd hh24.mi'), 15.2, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WA 20272', 60, to_date('2020.12.24 13.11', 'yyyy.mm.dd hh24.mi'), 8.3, 5);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WA 20272', 20, to_date('2021.01.12 21.15', 'yyyy.mm.dd hh24.mi'), 9.9, 1); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 123MM', 20, to_date('2020.12.21 11.10', 'yyyy.mm.dd hh24.mi'), 18.5, 2); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 123MM', 20, to_date('2021.01.12 13.19', 'yyyy.mm.dd hh24.mi'), 56.2, 25); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 123MM', 100, to_date('2020.01.17 20.10', 'yyyy.mm.dd hh24.mi'), 98.2, 35);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 30, to_date('2020.09.01 11.10', 'yyyy.mm.dd hh24.mi'), 17.4, 21);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 20, to_date('2020.09.23 17.10', 'yyyy.mm.dd hh24.mi'), 9.3, 0);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 20, to_date('2020.10.02 07.21', 'yyyy.mm.dd hh24.mi'), 6.6, 0);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 10, to_date('2020.10.09 14.51', 'yyyy.mm.dd hh24.mi'), 9.5, 0);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 70, to_date('2020.11.02 09.12', 'yyyy.mm.dd hh24.mi'), 21.5, 7);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 80, to_date('2020.11.08 18.38', 'yyyy.mm.dd hh24.mi'), 4.6, 0);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 90, to_date('2020.11.15 18.16', 'yyyy.mm.dd hh24.mi'), 4.9, 0);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 100, to_date('2020.11.27 06.48', 'yyyy.mm.dd hh24.mi'), 6.2, 3);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 100, to_date('2020.12.05 13.41', 'yyyy.mm.dd hh24.mi'), 7.9, 7);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 10, to_date('2020.12.08 10.24', 'yyyy.mm.dd hh24.mi'), 11.3, 0);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 20, to_date('2020.12.18 15.42', 'yyyy.mm.dd hh24.mi'), 12.5, 4);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 20, to_date('2020.12.27 18.48', 'yyyy.mm.dd hh24.mi'), 31, 20);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 10, to_date('2021.01.02 11.53', 'yyyy.mm.dd hh24.mi'), 2.6, 0);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 30, to_date('2021.01.07 08.47', 'yyyy.mm.dd hh24.mi'), 21.2, 0);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 30, to_date('2021.01.14 15.26', 'yyyy.mm.dd hh24.mi'), 20, 12);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 98308', 40, to_date('2021.01.18 16.54', 'yyyy.mm.dd hh24.mi'), 5, 2);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 52811', 60, to_date('2021.01.10 12.46', 'yyyy.mm.dd hh24.mi'), 123, 24);   
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('SC 52811', 60, to_date('2021.01.15 08.51', 'yyyy.mm.dd hh24.mi'), 69.2, 15);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 7486B', 70, to_date('2020.09.30 16.01', 'yyyy.mm.dd hh24.mi'), 10, 0);  
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 7486B', 60, to_date('2020.10.06 15.38', 'yyyy.mm.dd hh24.mi'), 21,  21);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 7486B', 100, to_date('2020.10.13 16.12', 'yyyy.mm.dd hh24.mi'), 19.2, 57);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 7486B', 90, to_date('2020.11.12 14.13', 'yyyy.mm.dd hh24.mi'), 8.7, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 7486B', 100, to_date('2020.12.17 12.16', 'yyyy.mm.dd hh24.mi'), 9.3, 3);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 7486B', 10, to_date('2021.01.10 11.43', 'yyyy.mm.dd hh24.mi'), 9.3, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WY 20666', 70, to_date('2020.11.06 05.10', 'yyyy.mm.dd hh24.mi'), 10, 0); 
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WY 20666', 60, to_date('2020.11.09 12.11', 'yyyy.mm.dd hh24.mi'), 78.9, 15);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WY 20666', 60, to_date('2020.11.19 07.01', 'yyyy.mm.dd hh24.mi'), 56.2, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WY 20666', 100, to_date('2020.12.23 06.15', 'yyyy.mm.dd hh24.mi'), 21.5, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WY 20666', 50, to_date('2021.01.02 06.45', 'yyyy.mm.dd hh24.mi'), 7.3, 2);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 20616', 70, to_date('2020.09.15 13.14', 'yyyy.mm.dd hh24.mi'), 145, 75);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 20616', 60, to_date('2020.10.31 16.13', 'yyyy.mm.dd hh24.mi'), 68.2, 0);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 20616', 100, to_date('2020.11.10 17.51', 'yyyy.mm.dd hh24.mi'), 34.1, 38);
INSERT INTO KKursy(nr_rejestracyjny, id_pasazera, data_kursu, dystans, czas_postoju) VALUES
 ('WD 20616', 60, to_date('2020.12.06 09.18', 'yyyy.mm.dd hh24.mi'), 24.1, 42); 
 
 
 -- Zad.16
 SELECT * FROM KPASAZEROWIE;
 INSERT INTO KPASAZEROWIE (imiona,nazwisko, adres,data_urodzenia)
 VALUES('Roman','Testowy','ul. Testowa 1 42-212','01.04.1935');
 ALTER TABLE KPASAZEROWIE DISABLE CONSTRAINT id_pasazera_pk;
 INSERT INTO KPASAZEROWIE (imiona,nazwisko, adres,data_urodzenia)
 VALUES('Roman','Testowy','ul. Testowa 1 42-212',TO_DATE('01.04.1935','DD.MM.YYYY'));
 ALTER TABLE KPASAZEROWIE DISABLE CONSTRAINT data_urodzenia_ch;
  INSERT INTO KPASAZEROWIE (imiona,nazwisko, adres,data_urodzenia)
 VALUES('Roman','Testowy','ul. Testowa 1 42-212',TO_DATE('01.04.1935','DD.MM.YYYY'));
 ALTER TABLE KPASAZEROWIE ENABLE NOVALIDATE CONSTRAINT data_urodzenia_ch;
 ALTER TABLE KPASAZEROWIE ENABLE NOVALIDATE CONSTRAINT id_pasazera_pk;
 
 -- Zad.17
 commit;
 SAVEPOINT SAVEPOINT_1;
 ROLLBACK TO SAVEPOINT SAVEPOINT_1;
 
 -- Zad.18
 UPDATE KPASAZEROWIE SET klient_od=(SELECT MIN(to_char(data_kursu,'DD')) FROM KKURSY GROUP BY id_pasazera),
 liczba_kursow=(SELECT COUNT(*) FROM KKURSY GROUP BY ID_PASAZERA);
 SELECT Min(EXTRACT(DAY FROM DATA_KURSU)) FROM KKURSY GROUP BY id_pasazera;
 SELECT * FROM KPASAZEROWIE;
 SELECT data_kursu, extract(day from data_kursu),id_pasazera FROM KKursy ORDER BY id_pasazera;
 SELECT COUNT(*) FROM KKURSY GROUP BY ID_PASAZERA;
 SELECT id_pasazera,MIN(to_char(data_kursu,'DD')) FROM KKURSY GROUP BY id_pasazera ORDER BY id_pasazera;