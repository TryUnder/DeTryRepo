//Zadanie 1.8 Napisz funkcję, która dla dowolnych liczb całkowitych n i k obliczy wartość
//dwumianu Newtona zdefiniowanego w sposób rekurencyjny
// do poprawy
let n : int = 3;
let k : int = 2;

let rec factorial n : int =
    if n>1 then n*factorial(n-1)
    else n

let rec newton_binomial n k : int =
    if k = 0 || k = n then n
    else
        (factorial(n-1)/(factorial(k-1)*factorial(n-1-k-1))) +
        (factorial(n-1)/(factorial(k)*factorial(n-1-k)))   +
        newton_binomial(n-1)(k)

System.Console.WriteLine(newton_binomial n k )
