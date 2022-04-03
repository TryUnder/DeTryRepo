// Zadanie 1.9 Napisz funkcję, która rekurencyjnie sprawdza, czy dana liczba jest liczbą pierwszą
open System;

let number : int = 11
let iterator : int = number;

let rec _is_prime number _iterator : bool =
    if(_iterator = 2) then true
    elif number % (_iterator - 1) <> 0 then _is_prime(number)(_iterator-1)
    else false

System.Console.WriteLine(_is_prime(number)(iterator));
