// Zadanie 1.7 Napisz funkcję, wyznaczającą wartość n-tego elementu ciągu fibbonaciego

let number : int = 0
let n : int = 4

let rec fib (n:int) : int =
    if n = 0 then number
    elif n = 1 then number+1
    else fib(n-1) + fib(n-2)

System.Console.WriteLine(fib(n));
