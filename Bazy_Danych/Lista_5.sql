/*
1. W oparciu o dane zgromadzone w tabeli Studenci wyświetl dane związane z najstarszym studentem
(ew. studentami) studiującym na kierunku informatyka
*/

SELECT * FROM studenci
WHERE data_urodzenia >= ALL (SELECT data_urodzenia FROM studenci
   WHERE Upper(kierunek) LIKE('INFORMATYKA'));
