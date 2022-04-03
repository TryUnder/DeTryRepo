function usun_spacje([string]$zmienna){
    [int32]$indeks=0

    Write-Host "Ciąg znaków ma $($zmienna.Length) liter."
    Write-Host "Przed usunięciem nadmiarowych spacji: "
    Write-Host "$zmienna"
    Write-Host "Po usunięciu nadmiarowych spacji: "
    while($indeks -LT $zmienna.Length){
	if($zmienna[$indeks] -LIKE " "){
	    $spacja = $indeks
		while($zmienna[$spacja+1] -LIKE " "){
		    $zmienna = $zmienna.Remove($spacja+1,1)
		}
		$indeks = $spacja
	}
	$indeks++
    }
    return $zmienna
}

usun_spacje $B
