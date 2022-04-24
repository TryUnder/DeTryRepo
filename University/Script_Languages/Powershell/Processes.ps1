$procesy = Get-Process
foreach($proces in $procesy){
    Write-Host Out-GridView ID: $proces.Id 
    Write-Host Name: $proces.Name
    Write-Host Memory: $proces.PagedMemorySize64
}
Get-Process | Select-Object -Property Id, Name, PagedMemorySize64 | Out-GridView