// Zadanie 1.3 Napisz funkcję, która sprawdzi, czy z trzech podanych wartości można zbudować trójkąt
open System;
let a : float = 1.0
let b : float = 2.0
let c : float = 3.0

let max (a:float)(b:float)(c:float) =
    if a > b && a > c then a
    elif b > c && b > c then b
    elif c > a && c > b then c
    else failwith "bad input values"

let sum (a:float)(b:float)(c:float) =
    a+b+c
let triangle (a:float)(b:float)(c:float)  =
    if(max (a)(b)(c) < sum (a)(b)(c) - max (a)(b)(c)) then true
    else false

if triangle(a)(b)(c) = true then System.Console.WriteLine("a = " + a.ToString() + "\nb = " + b.ToString()
                                                          + "\nc = " + c.ToString()
                                                          + "\nZ tych wartości można zbudować trójkąt");
else System.Console.WriteLine("a = " + a.ToString() + "\nb = " + b.ToString()
                                                          + "\nc = " + c.ToString()
                                                          + "\nZ tych wartości nie można zbudować trójkąta");
