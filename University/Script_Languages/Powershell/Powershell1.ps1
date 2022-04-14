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
