// Zadanie 1.6 Napisz funkcję, która rekurencyjnie wyznaczy wartość x^n, gdzie x i n są dowolnymi
//             liczbami naturalnymi

let _base : int = 2
let _index : int = 5

let rec _pow (_base:int) (_index:int) : int = 
    if _index = 1 then _base
    else _base * _pow(_base)(_index-1)

System.Console.WriteLine(_pow _base _index);