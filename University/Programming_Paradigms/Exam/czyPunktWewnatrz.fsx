// F#: Napisz program, który utworzy listę 100 dwuwymiarowych punktów losowych z przedziału od -20 do 20. 
// Następnie napisz program, który podzieli te punkty na dwie grupy. 
// Pierwsza powinna zawierać punkty wewnątrz okręgu o r=5 i środku w początku układu współrzędnych,
// a druga na zewnątrz tego okręgu. Wykorzystaj funkcje modułu List.

// 1) Generacja listy punktów

let a = new System.Random()
let b = [for i in 1..10 -> (a.Next(-20, 20), a.Next(-20, 20))]
// 2) Funkcja pokaz generująca string dla list punktów

let rec pokaz (buf:string) (lista:List<'a*'a>) = 
    match lista with
        | [] -> buf
        | x::xs -> pokaz (buf+"("+(fst x).ToString()+", "+(snd x).ToString()+"); ") xs

let c = pokaz "" b
printfn $"{c}"

// 3) Dzielimy na (nie) wchodzące do okręgu, g1 i g2 podajemy puste do wypełnienia

let rec podziel_na_2_gr (lista:List<int*int>) (gr1:List<int*int>) (gr2:List<int*int>) = 
    match lista with 
        | [] -> (gr1, gr2)
        | x::xs when sqrt(double(fst x * fst x + snd x * snd x)) > 5 -> podziel_na_2_gr xs gr1 (x::gr2)
        | x::xs -> podziel_na_2_gr xs (x::gr1) gr2

let d = podziel_na_2_gr b [] []
let e =  fst d 
let f = snd d

// 4) - Wyświetlamy otrzymane grupy punktów

let wewnatrz = pokaz "" e
let zewnatrz = pokaz "" f

printfn $"Wewnatrz: {wewnatrz}, Zewnatrz: {zewnatrz}"