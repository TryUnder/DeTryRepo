<#
1. Użyj polecenia Get-Help dla komendy Get-Help, aby dowiedzieć się więcej o
uzyskiwaniu pomocy. (2.2)
#>

Get-Help Get-Help

<#
2. Utwórz strukturę katalogów, stosując polecenia z PowerShella, zawierającą katalog główny
o nazwie {Dom} oraz dwa podkatalogi o nazwach {Drzwi} oraz {Okno}.(Dodatek A)
#>

if(Test-Path -Path $home/Dom){
    Write-Host "Struktura katalogów już istnieje na dysku"
}
else{
    New-Item -Name "Dom" -Path $home -ItemType "directory"
    'Okno','Drzwi' | ForEach-Object { New-Item -Path $home\Dom -Name $_ -ItemType 'Directory' }
}

<#
3. Wewnątrz katalogu {Drzwi} utwórz pliki tekstowe {Klamka.txt} zawierający rodzaj klamki
np.: Mosiężna, Chromowana itp. oraz {Zamek.txt} zawierający rodzaj zamka np.:
Wpuszczany, Nawierzchniowy itp. Do utworzenia pliku użyj strumienia lub przesyłania
potokowego. (2.9)
#>

$file_name_1 = "Zamek.txt"
$file_name_2 = "Klamka.txt"
$content_file_name_1 = "Wpuszczony, nawierzchniowy"
$content_file_name_2 = "Mosiężna, Chromowana"
if(Test-Path -Path $home/Dom){
    if((Test-Path -Path $home/Dom/Drzwi/Klamka.txt) -OR (Test-Path -Path $home/Dom/Drzwi/Zamek.txt)){
        Write-Host "Nie mogę uruchomić skryptu"
    }
    else{ 
        $file_name_1,$file_name_2 | ForEach-Object { New-Item -Path $home/Dom/Drzwi/ -Name $_ -ItemType "File" }
        $content_file_name_1 | Out-File -Path $home/Dom/Drzwi/Zamek.txt
        $content_file_name_2 | Out-File -Path $home/Dom/Drzwi/Klamka.txt
    }
}

<#
4. Ustaw atrybut pliku {Klamka.txt} na ukryty oraz atrybut pliku Zamek.txt na tylko do
odczytu. (3.3)
#>

if((Test-Path -Path $home/Dom/Drzwi/Klamka.txt) -AND (Test-Path -Path $home/Dom/Drzwi/Zamek.txt)){
    attrib +h $home/Dom/Drzwi/Klamka.txt
    attrib +r $home/Dom/Drzwi/Zamek.txt
}else{
    Write-Host "Nie udało się zmienić atrybutów, ponieważ pliki nie istnieją"
}

<#
5. Skopiuj plik {Klamka.txt} do katalogu {Okno}. Kopiując ustaw jego nazwę na {Klamka
okienna.txt}. (Dodatek A)
#>

if((Test-Path -Path "${home}/Dom/Drzwi/Klamka.txt") -AND (-NOT (Test-Path "${home}/Dom/Okno/Klamka okienna.txt"))){
    if($file = Get-Item $home/Dom/Drzwi/Klamka.txt -Force && $file.Attributes -match "Hidden"){
        New-Item -Path "${home}/Dom/" -Name "Okno" -ItemType "Directory"
        New-Item -Path "${home}/Dom/Okno/" -Name "Klamka okienna.txt" -ItemType "file"
        if(Test-Path -Path "${home}/Dom/Okno/Klamka okienna.txt"){
            Copy-Item "${home}/Dom/Drzwi/Klamka.txt" -Destination "${home}/Dom/Okno/Klamka okienna.txt" -Force
        }else{
            Write-Host "Nie udało się skopiować pliku"
        }
    }   
}else{
    Write-Host "Kopiowanie nie powiodło się"
}

<#
6. Wyświetl zawartość pliku {Klamka okienna.txt} wewnątrz konsoli.(2.9)
#>

function Show_Content($file){
    Get-Content $file | Write-Host
}

Show_Content("${home}\Dom\Okno\Klamka okienna.txt")

<#
7. Znajdź sposób na edycję pliku {Klamka okienna.txt}.(3.3)
#>

if(Test-Path -Path "${home}\Dom\Okno\Klamka okienna.txt"){
    $edit_attrib = Get-Item -Path "${home}\Dom\Okno\Klamka okienna.txt" -Force
    $edit_attrib.Attributes = "Archive"
    <# SOME EDITS #>
    $edit_attrib.Attributes = "Hidden"
}else{
    Write-Host "Błąd odczytu"
}

<#
8. Zmień zawartość pliku {Klamka okienna.txt} na Plastikowa. Użyj w tym celu strumienia.
(2.9)
#>

if(Test-Path -Path "${home}\Dom\Okno\Klamka okienna.txt"){
    $edit_attrib = Get-Item -Path "${home}\Dom\Okno\Klamka okienna.txt" -Force
    $edit_attrib.Attributes = "Archive"
    "Plastikowa" > "${home}\Dom\Okno\Klamka okienna.txt"
    $edit_attrib.Attributes = "Hidden"
}else{
    Write-Host "Nie udało się zmienić zawartości"
}

<#
9. Wyświetl zawartość katalogu {Drzwi}. (Dodatek A)
#>

Get-ChildItem -Path "${home}\Dom\Drzwi" -Recurse -Force &&
Get-ChildItem -Path "${home}\Dom\Drzwi" -Recurse -Force | Get-Content

<#
10. Wyświetl pomoc w zewnętrznym oknie na temat polecenia Get-ChildItem. Znajdź
sposób na wyświetlenie plików ukrytych. (2.2)
#>

Get-Help Get-ChildItem -Full <# -Force #>

<#
11. Używając polecenia Get-ChildItem wyświetl zawartość katalogu i podkatalogów
folderu {Dom}. Wyświetl tylko pliki o rozszerzeniu *.txt. Wyświetl pliki ukryte.
#>

Get-ChildItem -Path "${home}\Dom" -Recurse -Force -Name "*.txt"

<#
12. Używając poprzedniego polecenia oraz przetwarzania potokowego i strumieni skonstruuj
polecenie, które odnajdzie wszystkie pliki o rozszerzeniu *.txt, a następnie zapisze ich
nazwy do pliku {Dokumenty.txt} w folderze {Dom}.(2.9)
#>

if(-NOT(Test-Path -Path "${home}\Dom\Dokumenty.txt")){
    New-Item -Path "${home}\Dom" -Name "Dokumenty.txt" -ItemType "file"
    Get-ChildItem -Path "${home}\Dom" -Recurse -Force -Name "*.txt" -Exclude "Dokumenty.txt"
    | Out-File "${home}\Dom\Dokumenty.txt"
}else{
    Write-Host "Plik został już utworzony"
}

<#
13. Utwórz folder {Dokumenty} w katalogu {Dom}.
#>
if(-NOT(Test-Path -Path "${home}\Dom\Dokumenty")){
    New-Item -Path "${home}\Dom\" -Name "Dokumenty" -ItemType "Directory"
}else{
    Write-Host "Folder został już utworzony"
}
<#
14. Wyszukaj wszystkie pliki *.txt w podkatalogach folderu {Dom}, a następnie przenieś je do
katalogu {Dokumenty}. Wykonaj polecenie stosując jeden, ciągły zapis z wykorzystaniem
potoków. (2.9)
#>
if(-NOT(Test-Path -Path "${Home}\Dom\Dokumenty")){
    New-Item -Path "${home}\Dom\" -Name "Dokumenty" -ItemType "Directory"
    Get-ChildItem -Path "${Home}\Dom" -Include *.txt -Recurse -Force
    | Move-Item -Destination "${Home}\Dom\Dokumenty"
}elseif(Test-Path -Path "${Home}\Dom\Dokumenty"){
    Remove-Item -Path "${Home}\Dom\Dokumenty"
}

<#
15. Utwórz foldery {Katalogi} oraz {Parzyste} wewnątrz folderu {Dom}.
#>

if((-NOT(Test-Path -Path "${Home}\Dom\Katalogi")) -AND (-NOT(Test-Path -Path "${Home}\Dom\Parzyste"))){
    New-Item -Path "${Home}\Dom\" -Name "Katalogi" -ItemType "Directory"
    New-Item -Path "${Home}\Dom\" -Name "Parzyste" -ItemType "Directory"
}else{
    Write-Host "Katalogi zostały już utworzone"
}

<#
16. Napisz funkcję UtwórzKatalogi, która utworzy w folderze {Katalogi} 9 folderów o
nazwach {Katalog1},{Katalog2} itd. Użyj w tym celu pętli for. (3.1)
#>

function UtwórzKatalogi([int]$arg){
    for([int]$i=1; $i -LT $arg+1; $i++){
        $dirName = "Katalog" + $i
        if(-NOT(Test-Path -Path "${Home}\Dom\Katalogi\${dirName}")){
            New-Item -Path "${Home}\Dom\Katalogi" -Name "${dirName}" -ItemType "Directory"
        }else{
            Write-Host "Katalog: ${dirName} został już utworzony"  
        }
    }
}

UtwórzKatalogi([int]$arg=9)

<#
17. Skonstruuj polecenie które wyświetli zawartość folderu katalogi, a następnie wybierze te z
parzystą cyfrą na końcu i przeniesie je do katalogu {Parzyste}.
#>

if(Test-Path -Path "${Home}\Dom\Katalogi"){
    Get-ChildItem -Path "${Home}\Dom\Katalogi" -Recurse -Force
    | Where-Object {$_.name -Match "2" -OR $_.name -Match "4" -OR $_.name -Match "6" -OR $_.name -Match "8"}
    | Move-Item -Destination "${Home}\Dom\Parzyste"
}else{
    Write-Host "Exception"
}

<#
Do poprawienia ewentualnie linijka 203, którą mógłby zastąpić bardziej ogólny algorytm do parsowania
#>