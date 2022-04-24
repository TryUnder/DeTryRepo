[string]$path = Read-Host "Type a path for a directory in which you would like to search the biggest file"
if(Test-Path -LiteralPath "${path}" -IsValid){
    if(("${path}" | Get-Item) -IS [System.IO.DirectoryInfo]){
            $currentObject=""
        foreach($object in Get-ChildItem -Path $path){
            if($object.Length -gt $currentObject.Length){
                $currentObject=$object
            }
        }
        Write-Host "Biggest file: ${currentObject}"
    }else{
        Write-Host "Path doesn't reference to a directory"
    } 
}else{
    Write-Host "Path doesn't exist"
}