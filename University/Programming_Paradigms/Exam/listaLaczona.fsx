// Zdefiniuj nowy typ Lista reprezentujący listę łączoną mogącą przechowywać wartości dowolnego typu. 
//Napisz również funkcję wykorzystującą go, która będzie wczytywać z klawiatury dowolne łańcuchy znaków 
//(dopóki użytkownik nie wprowadzi łańcucha pustego). Następnie wyświetli te łańcuchy w odwrotnej kolejności.

type Lista<'a> = 
    | Pusta
    | Element of 'a*Lista<'a>

let a = Element(1, Element(2, Pusta))

let rec wczytaj lista:Lista<string> = 
    let readLine = System.Console.ReadLine()
    match readLine with 
        | "" -> lista
        | _ -> wczytaj (Element(readLine, lista))

let b = wczytaj Pusta

let rec wyswietl_odwr (lista:Lista<string>) (buf:string) = 
    match lista with
        | Pusta -> buf
        | Element (glowa, ogon) -> wyswietl_odwr ogon (buf + glowa)

let c = wyswietl_odwr b ""
printfn $"{c}"