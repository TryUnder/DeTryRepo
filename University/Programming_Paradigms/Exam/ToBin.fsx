// Napisz funkcję rekurencyjną zamieniającą liczbę całkowitą dziesiętną na
// łańcuch znaków reprezentujący liczbę binarną np. binarna 8 -> "1000"

let rec toBin (str:string) (liczba:int) = 
    let a = liczba % 2
    let b = liczba / 2
    match (a,b) with
    |   (1,0) -> str.Insert(0,"1")
    |   (0,0) -> str.Insert(0,"0")
    |   (1,_) -> toBin(str.Insert(0,"1")) b
    |   (0,_) -> toBin(str.Insert(0,"0")) b
    |   (_,_) -> "Błąd"

let a = toBin "" 93 