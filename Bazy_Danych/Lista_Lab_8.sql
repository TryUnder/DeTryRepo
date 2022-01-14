-- LISTA LAB 8
-- Zad.1

CREATE TABLE Zawodnicy
(
id_zawodnika NUMBER CONSTRAINT zawodnicy_id_zaw_pk PRIMARY KEY,
nazwisko VARCHAR2(30) CONSTRAINT zawodnicy_naz_nn NOT NULL,
imie VARCHAR2(30) CONSTRAINT zawodnicy_imie_nn NOT NULL,
data_ur DATE CONSTRAINT zawodnicy_data_ur_ch CHECK(data_ur>To_date('01.01.1950','DD-MM-YYYY')),
wzrost NUMBER(3) CONSTRAINT zawodnicy_wzrost_ch CHECK(wzrost<250),
waga NUMBER(3,1) CONSTRAINT zawodnicy_waga_ch CHECK(waga<100),
pozycja VARCHAR2(50) CONSTRAINT zawodnicy_pozycja_ch CHECK(Upper(pozycja) IN ('BRAMKARZ','OBRONCA','POMOCNIK','NAPASTNIK')),
klub VARCHAR2(50) DEFAULT 'wolny zawodnik',
liczba_minut NUMBER(3) DEFAULT 0,
placa NUMBER(5) DEFAULT NULL
);

SELECT * FROM zawodnicy;
drop table Zawodnicy CASCADE CONSTRAINTS;

INSERT INTO Zawodnicy VALUES
(1001,'Nowak','Piotr',to_date('10.01.1990','DD.MM.YYYY'),192,81.5,'bramkarz','Warta Czestochowa',360,4000);
INSERT INTO Zawodnicy (id_zawodnika,nazwisko,imie,data_ur,wzrost,waga,pozycja) VALUES
(1007,'Oleksy','Robert',to_date('12.08.1996','DD.MM.YYYY'),185,85,'obronca');

INSERT INTO Zawodnicy VALUES (1002, 'Kowalski', 'Adam', To_date('15-04-1992', 'DD-MM-YYYY'), 194, 83, 'bramkarz', 'Odra Wroclaw', 270, 3500);
INSERT INTO Zawodnicy VALUES (1003, 'Polak', 'Dariusz', To_date('11-06-1998', 'DD-MM-YYYY'), 189, 79.5, 'bramkarz', 'Wisla Warszawa', 450, 5000);

INSERT INTO Zawodnicy VALUES (1004, 'Malinowski', 'Adrian', To_date('21-11-1987', 'DD-MM-YYYY'), 190, 85, 'obronca', 'Warta Czestochowa', 300, 3000);
INSERT INTO Zawodnicy VALUES (1005, 'Czech', 'Piotr', To_date('04-12-1989', 'DD-MM-YYYY'), 187, 83, 'obronca', 'Odra Wroclaw', 200, 2600);
INSERT INTO Zawodnicy VALUES (1006, 'Podolski', 'Krystian', To_date('26-02-1997', 'DD-MM-YYYY'), 186, 89, 'obronca', 'Wisla Warszawa', 350, 3500);

INSERT INTO Zawodnicy VALUES (1008, 'Grzyb', 'Krzysztof', To_date('17-09-1995', 'DD-MM-YYYY'), 173, 75, 'pomocnik', 'Warta Czestochowa', 400, 3200);
INSERT INTO Zawodnicy VALUES (1009, 'Kwasek', 'Artur', To_date('30-10-1991', 'DD-MM-YYYY'), 180, 75, 'pomocnik', 'Odra Wroclaw', 370, 3300);
INSERT INTO Zawodnicy VALUES (1010, 'Kukla', 'Kamil', To_date('01-02-1993', 'DD-MM-YYYY'), 179, 75, 'pomocnik', 'Wisla Warszawa', 250, 3000);
INSERT INTO Zawodnicy (id_zawodnika, nazwisko, imie, data_ur, wzrost, waga, pozycja) VALUES
(1011, 'Drozd', 'Adam', To_date('19-03-1995', 'DD-MM-YYYY'), 182, 77, 'pomocnik');

INSERT INTO Zawodnicy VALUES (1012, 'Jankowski', 'Marek', To_date('23-09-1999', 'DD-MM-YYYY'), 185, 80, 'napastnik', 'Warta Czestochowa', 60, 2000);
INSERT INTO Zawodnicy VALUES (1013, 'Knysak', 'Fabian', To_date('10-10-1994', 'DD-MM-YYYY'), 175, 73, 'napastnik', 'Odra Wroclaw', 250, 4000);
INSERT INTO Zawodnicy VALUES (1014, 'Tyrek', 'Tomasz', To_date('31-01-1998', 'DD-MM-YYYY'), 179, 74, 'napastnik', 'Wisla Warszawa', 200, 6000);
INSERT INTO Zawodnicy VALUES (1015, 'Zachara', 'Mateusz', To_date('09-09-2000', 'DD-MM-YYYY'), 181, 73, 'napastnik', NULL, NULL, NULL);

INSERT INTO Zawodnicy VALUES (1016, 'Jaskola', 'Milosz', To_date('13-09-1997', 'DD-MM-YYYY'), 187, 81, 'napastnik', 'Warta Czestochowa', 160, 2300);
INSERT INTO Zawodnicy VALUES (1017, 'Knus', 'Franciszek', To_date('10-03-1984', 'DD-MM-YYYY'), 177, 71, 'napastnik', 'Odra Wroclaw', NULL, 3700);
INSERT INTO Zawodnicy VALUES (1018, 'Toborek', 'Tomasz', To_date('31-03-1997', 'DD-MM-YYYY'), 183, 72, 'napastnik', 'Wisla Warszawa', 230, 6200);
INSERT INTO Zawodnicy VALUES (1019, 'Zasepa', 'Michal', To_date('19-09-2001', 'DD-MM-YYYY'), 180, 76, 'napastnik', NULL, NULL, NULL);

INSERT INTO Zawodnicy VALUES (1020, 'Borel', 'Jan', To_date('11-02-2002', 'DD-MM-YYYY'), 179, 75, 'pomocnik', 'Warta Czestochowa', NULL, NULL);
INSERT INTO Zawodnicy VALUES (1021, 'Czok', 'Damian', To_date('28-08-1995', 'DD-MM-YYYY'), 190, 82, 'obronca', 'Odra Wroclaw', NULL, NULL);

commit;
savepoint sp1;
-- Zad.2
-- a)
DELETE FROM Zawodnicy WHERE Cast(to_char(sysdate,'YYYY')AS INT)-Cast(to_char(data_ur,'YYYY')AS INT) < 21;
-- b)
DELETE FROM Zawodnicy;
-- c)
SELECT * FROM Zawodnicy;
-- d)
ROLLBACK;
-- e)
SELECT * FROM Zawodnicy;
-- f)
DROP TABLE Zawodnicy CASCADE CONSTRAINTS;
-- g)
ROLLBACK;
-- h)
SELECT * FROM Zawodnicy;
-- i)
rollback to savepoint sp1; -- nie dziala

-- Zad 3
SELECT * FROM Zawodnicy;
commit;
UPDATE Zawodnicy SET liczba_minut=0, placa=0 WHERE klub IS NULL;
rollback;

-- Zad 4
commit;
SELECT * FROM Zawodnicy;
UPDATE Zawodnicy SET liczba_minut=liczba_minut +
(CASE
    WHEN liczba_minut > 100 THEN 90
    WHEN liczba_minut BETWEEN 1 AND 100 THEN 45
    WHEN liczba_minut < 1 OR liczba_minut IS NULL THEN 15
END) WHERE Upper(klub) IN ('WARTA CZESTOCHOWA','ODRA WROCLAW');

-- Zad 5
commit;
rollback;
SELECT Min(liczba_minut) FROM zawodnicy;
UPDATE Zawodnicy SET placa = placa * (CASE
WHEN liczba_minut = (SELECT Max(liczba_minut) FROM Zawodnicy) THEN 1.25
WHEN liczba_minut = (SELECT Min(liczba_minut) FROM Zawodnicy) THEN 0.90
ELSE CAST(1 AS INT)
END);

-- Zad 6
rollback;
UPDATE Zawodnicy SET klub=
(SELECT klub FROM
(SELECT min(count(*))min_liczba FROM Zawodnicy WHERE klub IS NOT NULL AND klub NOT LIKE 'wolny zawodnik'
GROUP BY klub)p1
JOIN
(SELECT klub, count(*)liczba FROM Zawodnicy WHERE klub IS NOT NULL AND klub NOT LIKE('wolny zawodnik')
GROUP BY klub)p2
ON(min_liczba=liczba) WHERE ROWNUM=1), placa=2123 WHERE klub IS NULL OR klub LIKE('wolny zawodnik');

-- Zad 7
UPDATE Zawodnicy SET placa=Nvl(placa,0)+2500, klub='Warta Czestochowa' WHERE id_zawodnika=
(
SELECT id_zawodnika FROM Zawodnicy WHERE klub LIKE ('Odra Wroclaw') AND data_ur=
(SELECT min(data_ur) FROM Zawodnicy WHERE klub LIKE ('Odra Wroclaw')AND ROWNUM=1));

-- Zad 8
SELECT * FROM Zawodnicy;
INSERT INTO Zawodnicy VALUES((SELECT max(id_zawodnika)+1 FROM Zawodnicy),'Tatarkiewicz','Tomasz',to_date('18.04.1991','DD.MM.YYYY'
),185,86,'pomocnik','Orzel Krakow',100,5000);

UPDATE Zawodnicy SET liczba_minut=
(
CASE WHEN Trim(Upper(klub)) LIKE 'Warta Czestochowa' THEN length(imie)+length(nazwisko)*10
     WHEN Trim(Upper(klub)) LIKE 'Odra Wroclaw' THEN length(nazwisko)*20
     WHEN Trim(Upper(klub)) LIKE 'Wisla Warszawa' THEN length(imie)*20
     WHEN Trim(Upper(klub)) LIKE 'Orzel Krakow' AND liczba_minut>1 THEN Cast(to_char(sysdate,'DDD')AS INT)
END);

-- Zad 9

UPDATE Zawodnicy SET klub='wolny zawodnik',placa=0 WHERE liczba_minut !=(
SELECT max(liczba_minut) FROM Zawodnicy WHERE Trim(Upper(klub)) NOT LIKE ('wolny zawodnik'))
AND data_ur=(SELECT max(data_ur) FROM Zawodnicy WHERE Trim(Upper(klub)) NOT LIKE ('wolny zawodnik'));

-- Zad 10

UPDATE Zawodnicy z SET placa=placa*
(CASE WHEN Nvl(liczba_minut,0) < 0.5 * (SELECT avg(liczba_minut) FROM Zawodnicy WHERE klub = z.klub) THEN 0.8
      WHEN Nvl(liczba_minut,0) BETWEEN (SELECT avg(liczba_minut) FROM Zawodnicy WHERE klub = z.klub)*0.5
      AND (SELECT avg(liczba_minut) FROM Zawodnicy WHERE klub = z.klub)*0.8 THEN 0.9
      WHEN Nvl(liczba_minut,0) BETWEEN (SELECT avg(liczba_minut) FROM Zawodnicy WHERE klub = z.klub)*1.2
      AND (SELECT avg(liczba_minut) FROM Zawodnicy WHERE klub = z.klub)*1.5 THEN 1.1
      WHEN Nvl(liczba_minut,0) > (SELECT avg(liczba_minut) FROM Zawodnicy WHERE klub = z.klub)*1.5 THEN 1.2
END) WHERE klub NOT LIKE ('wolny zawodnik') OR klub IS NOT NULL;
