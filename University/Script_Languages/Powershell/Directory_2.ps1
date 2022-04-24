#Napisz skrypt który zapyta użytkownika czy chce:
    #1 stworzyć nowy katalog
    #2 stworzyć nowy plik
    #3 usunąć plik
    #4 skrypt powinien obsłużyć wybór użytkownika

Write-Host "1 - Create new folder"
Write-Host "2 - Create new txt file"
Write-Host "3 - Delete file"
[int]$choose = Read-Host "Make a choose"
switch($choose){
    1 { 
        [string]$name = Read-Host "Type folder name"
        if(-NOT(Test-Path -Path "${home}\Desktop\${name}")){
            New-Item -Path "${home}\Desktop\${name}" -ItemType "Directory"
            Write-Host "Succesfully created folder"
        }else{
            Write-Host "Folder already exist on the disk"
        }
    }

    2 {
        [string]$name = Read-Host "Type file name"
        if(-NOT(Test-Path -Path "${home}\Desktop\${name}")){
            New-Item -Path "${home}\Desktop\${name}" -ItemType "File"
            Write-Host "Succesfully created file"
        }else{
            Write-Host "File already exist on the disk"
        }
    }

    3 {
        [string]$name = Read-Host "Type path to the file which you want to be deleted"
        if((Test-Path "${name}")){
            Remove-Item -Path "${name}" -Confirm
            if(-NOT(Test-Path "${name}")){
                Write-Host "File was deleted succesfully"
            }else{
                Write-Host "File was not deleted"
            }
        }else{
            Write-Host "Appropriate file with Path ${name} doesn't exist"
        }
    }
}