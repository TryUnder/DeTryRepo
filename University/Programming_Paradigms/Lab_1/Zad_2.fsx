// Zadania 1.2 - Napisz funkcję wyznaczającą wartość pierwiastków równania kwadratowego
open System;
let a : float = 2.0;
let b : float = 6.0;
let c : float = 4.0;

let delta (a:float)(b:float)(c:float) =
    b*b - 4.0*a*c

let denominator (a:float) =
    2.0*a

let radical_square_root_x_1 a b c =
    if delta(a)(b)(c) < 0 || denominator(a) < 0 then
        failwith "bad input values"

    elif delta(a)(b)(c) = 0 then
        let x_0 = -b / denominator(a)
        x_0
    else
        let x_1 = (-b - sqrt(delta(a)(b)(c))) / denominator(a)
        let x_2 = (-b + sqrt(delta(a)(b)(c))) / denominator(a)
        x_1

let radical_square_root_x_2 a b c =
    if delta(a)(b)(c) < 0 || denominator(a) < 0 then
        failwith "bad input values"

    elif delta(a)(b)(c) = 0 then
        let x_0 = -b / denominator(a)
        x_0
    else
        let x_1 = (-b - sqrt(delta(a)(b)(c))) / denominator(a)
        let x_2 = (-b + sqrt(delta(a)(b)(c))) / denominator(a)
        x_2


if delta(a)(b)(c) = 0 then
    System.Console.WriteLine("x0: " + (radical_square_root_x_1 a b c).ToString());
else
    System.Console.WriteLine("x1: " + (radical_square_root_x_1 a b c).ToString());
    System.Console.WriteLine("x2: " + (radical_square_root_x_2 a b c).ToString());
