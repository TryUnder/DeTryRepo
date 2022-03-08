// Zadanie 1.4 Napisz funkcję, która obliczy pole trójkąta, na podstawie długości jego boków.
//             Jeżeli z podanych wartości nie da się zbudować trójkąta, rzuć wyjątek z odpowiednią
//             wiadomością.
open System;
let a : float = 1.0
let b : float = 2.0
let c : float = 2.5

let max (a:float)(b:float)(c:float) : float =
    if a > b && a > c then a
    elif b > c && b > c then b
    elif c > a && c > b then c
    else failwith "bad input values"

let s : float = (a+b+c)/2.0

let sum (a:float)(b:float)(c:float) : float =
    a+b+c

let triangle (a:float)(b:float)(c:float) : bool  =
    if(max (a)(b)(c) < sum (a)(b)(c) - max (a)(b)(c)) then true
    else false

let field_of_triangle (a:float)(b:float)(c:float) : float =
    sqrt(s*(s-a)*(s-b)*(s-c))

if (triangle(a)(b)(c) = true) then
    System.Console.WriteLine("Pole trójkąta wynosi: " + (field_of_triangle(a)(b)(c)).ToString())
else failwith "bad input values"
