Write-Host -NoNewLine "Podaj nazwę: "
[String]$Obiekt = Read-Host
$Wynik = @{}

Start-Job -Name Wyszukiwanie {param($Nazwa) Get-ChildItem -Path C:\ -Recurse -Filter "*$Nazwa*"} -Arg $Obiekt|Out-Null
Write-Host -NoNewLine "Trwa wyszukiwanie."
do{
    Write-Host -NoNewLine "."
    sleep -Seconds 1
}
while($(Get-Job -name Wyszukiwanie).JobStateInfo -NotLike "Completed")

$Efekt = Receive-Job -name Wyszukiwanie
Remove-Job -name Wyszukiwanie

foreach($Linijka in $Efekt){
    $Wynik.Add($Linijka.FullName, $Linijka.Name)
}
switch($Wynik.Count){
    1 {"`nZnaleziono $($Wynik.Count) plik: "; break}
      {($_ -EQ "2") -OR ($_ -EQ "3") -OR ($_ -EQ "4")}
      {"`nZnaleziono $($Wynik.Count) pliki: "; break}
      {($_ -LIKE "*2") -OR ($_ -LIKE "*3") -OR ($_ -LIKE "*4")}
      {"`nZnaleziono $($Wynik.Count) pliki: "; break}
      default {"`nZnaleziono $($Wynik.Count) plików: "; break}
}

$Wynik | Format-Table Value,Name
