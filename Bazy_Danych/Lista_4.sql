/*
1. W oparciu o dane zawarte w tabelach Pojazdy i Wlasciciele wyświetl uporządkowaną listę pojazdów
(od najstarszego) wyprodukowanych w 2018 roku wraz z danymi ich właścicieli (
*/

SELECT nr_rejestracyjny, marka, modell, wlasciciel, data_produkcji--Extract(YEAR FROM data_produkcji) as "DATA_PRODUKCJI"
FROM pojazdy JOIN wlasciciele using(id_wlasciciela)
WHERE Extract(YEAR FROM data_produkcji)LIKE '2018'
ORDER BY data_produkcji DESC;
