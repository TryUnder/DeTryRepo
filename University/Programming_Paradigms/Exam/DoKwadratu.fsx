open System;

let x = -2,3


let wynik ((x1,y1): int*int) = 
    if x1 > y1 
        then x1
    else
        y1

let podniesDoKwadratu liczba:int =
    liczba * liczba

podniesDoKwadratu (wynik x)