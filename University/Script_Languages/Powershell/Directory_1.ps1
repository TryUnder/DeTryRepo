[long]$lowerLimit = Read-Host "Minimalny rozmiar pliku (bajty)"
[long]$upperLimit = Read-Host "Maksymalny rozmiar pliku (bajty)"
Get-ChildItem -Recurse | Where-Object { ($_.Length -gt $lowerLimit) -and ($_.Length -lt $upperLimit) }