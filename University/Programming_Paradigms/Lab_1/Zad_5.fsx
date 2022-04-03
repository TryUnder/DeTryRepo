// Zadanie 1.5 Napisz funkcję, która rekurencyjnie oblicza sumę n pierwszych liczb naturalnych.
open System;

let number : int = 10

let rec sum number : int =
    if number = 0 then number
    else number + sum(number-1)

printfn "%i" (sum(number))
  
