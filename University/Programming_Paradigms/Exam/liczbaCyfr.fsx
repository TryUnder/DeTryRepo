// F#: Napisz funkcję, która określi ile razy w danym łańcuchu znaków wystąpiły dowolne cyfry.
// Przykładowo dla łańcucha "Ala 123 ma k1ota"  funkcja powinna zwrócić 4.

open System;
let rec liczbaCyfr (str:string) (index:int) (suma:int) = 
    let a = str.Chars(index)
    if index <> str.Length
        then match a with
            | '1' | '2' | '3' | '4' | '5' | '6' | '6' | '7' | '8' | '9' | '0' -> liczbaCyfr str (index+1) (suma+1)
            | _ -> liczbaCyfr str (index+1) suma        
    else
        suma

let b = liczbaCyfr "Ala ma 123 kota" 0 0
printfn $"Ilosc liczb: {b}"
