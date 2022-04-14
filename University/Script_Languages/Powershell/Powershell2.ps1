<#
1. Utwórz plik tekstowy, w którym znajdować się będą nazwy kolejnych miesięcy w roku,
każdy miesiąc w nowej linii dokumentu. Skorzystaj w tym celu ze strumieni. (3.1)
#>

Write-Host "Exercise 1"
if(-NOT(Test-Path -Path "D:\P.R.I.V\Uczelnia\Semestr_IV\Systemy_Operacyjne\Spr_Powershell2\Miesiące.txt")){
   New-Item -Name "Miesiące.txt" && "Styczeń`nLuty`nMarzec`nKwiecień`nMaj`nCzerwiec`nLipiec`nSierpień`nWrzesień`nPaździernik`nListopad`nGrudzień" > "Miesiące.txt"
   Write-Host "Pomyślnie utworzono plik"
}else{
    Write-Host "Nie udało się utworzyć pliku"
}
Write-Host " "

<#
2. Pobierz zawartość pliku tekstowego do zmiennej typu string. Zdefiniuj typ zmiennej
przed pobraniem zawartości pliku. (3.1)
#>

Write-Host "Exercise 2"
[string]$file_content = Get-Content D:\P.R.I.V\Uczelnia\Semestr_IV\Systemy_Operacyjne\Spr_Powershell2\Miesiące.txt
Write-Host " "

<#
3. Wyświetl zawartość zmiennej.
#>

Write-Host "Exercise 3"
$file_content
Write-Host " "

<#
4. Znajdź indeks rozpoczynający nazwę drugiego miesiąca, następnie używając metody
substring zapisz ją do drugiego pliku tekstowego o nazwie {Miesiąc roku przestępnego}.
(3.1)
#>

Write-Host "Exercise 4"
if(-NOT(Test-Path -Path "D:\P.R.I.V\Uczelnia\Semestr_IV\Systemy_Operacyjne\Spr_Powershell2\Miesiąc roku przestępnego.txt")){
    if(-NOT($file_content -EQ $null)){
	Remove-Variable file_content
    }
    [string]$file_content = Get-Content "D:\P.R.I.V\Uczelnia\Semestr_IV\Systemy_Operacyjne\Spr_Powershell2\Miesiące.txt"
    $file_content.Substring($file_content.IndexOf("Luty"),4) | Out-File "D:\P.R.I.V\Uczelnia\Semestr_IV\Systemy_Operacyjne\Spr_Powershell2\Miesiąc roku przestępnego.txt"
    Write-Host "Pomyślnie utworzono plik"
}else{
    Write-Host "Plik już istnieje"
}
Write-Host " "

<#
5. Usuń Luty z utworzonej zmiennej. (3.1)
#>

Write-Host "Exercise 5"
if(-NOT($file_content -EQ $null)){
    Remove-Variable file_content
}
[string]$file_content = Get-Content "D:\P.R.I.V\Uczelnia\Semestr_IV\Systemy_Operacyjne\Spr_Powershell2\Miesiące.txt"
$file_content = $file_content.Remove($file_content.IndexOf("Luty"),5)
$file_content
Write-Host " "

<#
6. Napisz funkcję IlośćDni, do której przekażesz wcześniej utworzoną zmienną z zapisem
wszystkich miesięcy. Funkcja ta ma za zadanie wstawiać na końcu nazwy miesiąca dopisek
na temat ilości dni w następującym formacie: Marzec-31dni, Kiecień-30dni itd. zaczynając
od stycznia. Funkcja ma zwracać zmodyfikowany ciąg znaków tak, aby można było go
przypisać do innej zmiennej. (2.11, 3.1)
#>

Remove-Variable file_content
[string]$global:file_content = Get-Content "D:\P.R.I.V\Uczelnia\Semestr_IV\Systemy_Operacyjne\Spr_Powershell2\Miesiące.txt"
Write-Host "Exercise 6"
function IlośćDni($file_content){
    $styczen = "Styczeń-" + [DateTime]::DaysInMonth(2022,1)+"dni"
    $luty = "Luty-" + [DateTime]::DaysInMonth(2022,2)+"dni"
    $marzec = "Marzec-" + [DateTime]::DaysInMonth(2022,3)+"dni"
    $kwiecien = "Kwiecień-" + [DateTime]::DaysInMonth(2022,4)+"dni"
    $maj = "Maj-" + [DateTime]::DaysInMonth(2022,5)+"dni"
    $czerwiec = "Czerwiec-" + [DateTime]::DaysInMonth(2022,6)+"dni"
    $lipiec = "Lipiec-" + [DateTime]::DaysInMonth(2022,7)+"dni"
    $sierpien = "Sierpień-" + [DateTime]::DaysInMonth(2022,8)+"dni"
    $wrzesien = "Wrzesień-" + [DateTime]::DaysInMonth(2022,9)+"dni"
    $pazdziernik = "Październik-" + [DateTime]::DaysInMonth(2022,10)+"dni"
    $listopad = "Listopad-" + [DateTime]::DaysInMonth(2022,11)+"dni"
    $grudzien = "Grudzień-" + [DateTime]::DaysInMonth(2022,12)+"dni"
    $file_content = $file_content -replace "Styczeń", $styczen
    $file_content = $file_content -replace "Luty", $luty
    $file_content = $file_content -replace "Marzec", $marzec
    $file_content = $file_content -replace "Kwiecień", $kwiecien
    $file_content = $file_content -replace "Maj", $maj
    $file_content = $file_content -replace "Czerwiec", $czerwiec
    $file_content = $file_content -replace "Lipiec", $lipiec
    $file_content = $file_content -replace "Sierpień", $sierpien
    $file_content = $file_content -replace "Wrzesień", $wrzesien
    $file_content = $file_content -replace "Październik", $pazdziernik
    $file_content = $file_content -replace "Listopad", $listopad
    $file_content = $file_content -replace "Grudzień", $grudzien
    return $file_content
}

<#
7. Wywołaj wcześniej utworzoną funkcję a następnie przypisz jej wartość zwracaną do nowej
zmiennej
#>

Write-Host "Exercise 7"
$file_content = IlośćDni($file_content)
$file_content
Write-Host " "

<#
8. Zmień zapis wewnątrz zmiennej tak, aby każdy miesiąc z przypisaną mu ilością dni
zapisany był w nowej linii.
#>

Write-Host "Exercise 8"
$file_content.Split(" ")

Write-Host " "

<#
9. Zapisz powstałą zmienną do pliku tekstowego {Miesiące.txt} używając strumienia lub
potoku.
#>

Write-Host "Exercise 9"

$file_content.Split(" ") | Out-File "D:\P.R.I.V\Uczelnia\Semestr_IV\Systemy_Operacyjne\Spr_Powershell2\Miesiące.txt"

Write-Host " "

<#
10. Napisz skrypt, który będzie obsługiwał podanie dwóch nadmiarowych parametrów. Będą
one określać zakres liczb, które należy wypisać na standardowe wyjście za pomocą pętli
for. (2.10, 2.11, 2.13)
#>

Write-Host "Exercise 10"

if(($args[0] -AND $args[1]) -EQ "" -OR ($args[0] -AND $args[1]) -EQ $null){
    Write-Host "Podaj parametry uruchomienia skryptu"
    Write-Host "args[0] = licznik pierwszej pętli"
    Write-Host "args[1] = licznik drugiej pętli"
}
else{
    $temp = $args[0]
    for(; $args[0] -LT $args[1]; $args[0]++){
	if($args[0] -NE $temp){
	    Write-Host $args[0]	
	}
    }
}
Write-Host " "

<#
11. Napisz skrypt, w którym wyświetlisz pory roku jako ponumerowaną listę. Użytkownik po
wybraniu numeru z listy otrzyma informację jakie miesiące należą do danej pory roku. Użyj
do tego instrukcji switch (2.10, 2.11, 2.13)
#>

Write-Host "Exercise 11"

function pory_roku{
    Write-Host "Wybierz porę roku"
    Write-Host "Wiosna - 1"
    Write-Host "Lato   - 2"
    Write-Host "Jesień - 3"
    Write-Host "Zima   - 4"
    try{
	[int32]$choose = Read-Host -Prompt "Podaj wartość" 
    }catch{
	"Nieprawidłowy format danych"
	$choose = $null
    }

    switch($choose){
	1 { Write-Host "Miesiące wiosenne: Marzec, Kwiecień, Maj" }
	2 { Write-Host "Miesiące letnie: Czerwiec, Lipiec, Sierpień" }
	3 { Write-Host "Miesiące jesienne: Wrzesień, Październik, Listopad" }
	4 { Write-Host "Miesiące zimowe: Grudzień, Styczeń, Luty" }
	default { "Nieprawidłowy format danych" }
    }
}

pory_roku

Write-Host " "

<#
12. Napisz skrypt o nazwie Kalkulator. Wartości do skryptu będą podawane jako nadmiarowe
parametry. Skrypt ma za zadanie wykonywać podstawowe działania matematyczne. Jeśli
podane zostaną dwa parametry, skrypt zaproponuje działania takie jak dodawanie,
odejmowanie, mnożenie i dzielenie. Jeżeli do skryptu przekazany zostanie tylko jeden
parametr skrypt za pomocą polecenia switch zaproponuje takie działania jak
pierwiastkowanie, podniesienie do kwadratu i funkcje trygonometryczne Sin, Cos oraz Tan.
W razie większej ilości lub braku parametrów skrypt ma zwracać komunikat błędu
wykorzystując strumień błędów.(2.11, 2.13)
#>

Write-Host "Exercise 12"

Write-Host "Kalkulator"
if($args[0] -EQ $null -OR $args[1] -EQ "" -OR $args[2] -NE $null){
    Write-Host "Podaj parametry uruchomienia programu niezbędne do działania kalkulatora"
    Write-Host "args[0] - pierwszy parametr"
    Write-Host "args[1] - drugi parametr"
}else{
    if($args[1] -EQ $null){
	Write-Host "Wybierz opcje"
	Write-Host "1 - Pierwiastkowanie"
	Write-Host "2 - Podnoszenie do kwadratu"
	Write-Host "3 - Funkcja Sin"
	Write-Host "4 - Funkcja Cos"
    	Write-Host "5 - Funkcja Tan"
	try{
	    [int32]$choose = Read-Host -Prompt "Wybierz opcje"
	}catch{
	    Write-Error "Nieprawidłowy format danych"
	    $choose = $null
	}
	
	switch($choose){
	    1 { $result = [Math]::Sqrt($args[0]) }
	    2 { $result = [Math]::Pow($args[0],2) }
	    3 { $result = [Math]::Sin($args[0]) }
	    4 { $result = [Math]::Cos($args[0]) }
	    5 { $result = [Math]::Tan($args[0]) }
	}
	    Write-Host "Wynik wybranej operacji wynosi: {$result}"
	}else{
	   Write-Host "Wybierz opcje"
	    Write-Host "1 - Dodawanie"
	    Write-Host "2 - Odejmowanie"
	    Write-Host "3 - Mnozenie"
	    Write-Host "4 - Dzielenie"
	try{
	    [int32]$choose = Read-Host -Prompt "Wybierz opcje"
	}catch{
	    Write-Error "Nieprawidłowy format danych"
	    $choose = $null
	}
	
	switch($choose){
	    1 { $result = $args[0] + $args[1] }
	    2 { $result = $args[0] - $args[1] }
	    3 { $result = $args[0] * $args[1] }
	    4 { $result = $args[0] / $args[1] }
	}
	    Write-Host "Wynik wybranej operacji wynosi: {$result}"
	}
}

Write-Host " "
