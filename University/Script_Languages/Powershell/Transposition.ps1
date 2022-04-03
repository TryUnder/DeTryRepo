do{
    Write-Host -NoNewLine "Podaj ilość wierszy: "
	try{
	    [int32]$a = Read-Host
	}catch{
	    "Nieprawidłowy format fanych"
	    $a = $null
	}
}
while($a -Like $null)
    
do{
    Write-Host -NoNewLine "Podaj ilość kolumn: "
	try{
	    [int32]$b = Read-Host
	}catch{
	    "Nieprawidłowy format danych"
	    $b = $null
	}
}
while($b -Like $null)

$tablica = New-Object "Int32[,]" $a,$b
for($i=0;$i -LT $a; $i++){
    for($j=0;$j -LT $b; $j++){
	$tablica[$i,$j] = Get-Random -Min 1 -Max 9
    }
}

function transponowanie([int32[,]]$tab, [int32]$y, [int32]$x){
    $tablica_nowa = New-Object "Int32[,]" $b, $a
	for($i=0;$i -LT $x; $i++){
	    for($j=0;$j -LT $y;$j++){
		$tablica_nowa[$i,$j] = $tab[$j,$i]
	    }
	}
	return ,$tablica_nowa
}

function wyswietl([array]$tab, [int32]$x, [int32]$y){
    for($i=0;$i -LT $x; $i++){
	for($j=0;$j -LT $y; $j++){
	    Write-Host -NoNewLine $tab[$i,$j]" "
	}
	Write-Host 
    }
}

"`nTablica początkowa: `n"
wyswietl $tablica $a $b
$wynik = transponowanie $tablica $a $b
"Tablica transponowana: `n"
wyswietl $wynik $b $a
