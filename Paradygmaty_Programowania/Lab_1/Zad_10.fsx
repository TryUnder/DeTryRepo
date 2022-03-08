// Zadanie 1.10 Napisz funkcję, która na podstawie 1000 rzutów kostką do gry określi
// prawdopodobieństwo wyrzucenia szóstki
// do poprawy
open System;

let n : float = 1000.0
let p : float = 0.166666;
let k : float = 1.0;

let rec factorial n : float =
    if n > 1.0 then n*factorial(n-1.0)
    else n

let bernuolli _n _p _k : float =
    (factorial _n)/(factorial _k * factorial(n-k)) * System.Math.Pow(p,k) * System.Math.Pow(1.0-p,n-k);

System.Console.WriteLine(bernuolli n p k);
