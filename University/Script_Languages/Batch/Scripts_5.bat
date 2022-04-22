:: Zadanie 1.
:: Utworzyć dowolny plik tekstowy. Zaszyfrować go za pomocą polecenia cipher. Sprawdzić czy plik jest
:: poprawnie zaszyfrowany (polecenie cipher bez przełączników). Spróbować otworzyć zaszyfrowany plik. Kto
:: może otwierać takie pliki?

:: CIPHER /E to encrypt
:: CIPHER /D to decrypt

:: CIPHER without parameters will list files' status
:: copy - used for copying and concatenating files excluding directories
:: xcopy - for files and directories
::  /A - Copies only files with the archive attribute set
::  /M - Copies only files with the archive attribute set, turns off the archive attribute
::  /P - Prompts you before creating each destination file
::  /S - Copies directories and subdirectories except empty ones
::  /E - Copies directories and subdirectories including empty ones
::  /I - Assuming that the destination is directory
::  /Q - Does not display file names while copying
::  /F - Display full source and destination file name while copying
::  /H - Copies hidden and system files
::  /R - Overwrites read-only files

:: robocopy - newer version of scopy
::  /S - Copy subdirectories but not empty ones
::  /E - Copy subdirectories including empty ones
::  /MOV - MOVe files (delete from source after copying)
::  /MOVE - Move files and dirs (delete from source after copying)
::  /A+ 
::  /A-

:: Zadanie 4
:: Napisać skrypt, który:
:: Przyjmuje parametr – katalog
:: Wyświetla wszystkie pliki tylko do odczytu z danego katalogu (wykorzystać polecenie dir)
:: Pyta użytkownika czy:
:: 0 – usunąć atrybut tylko do odczytu z wszystkich plików w tym folderze
:: 1  stworzyć kopię tych plików w folderze C:\temp\ (polecenie robocopy)
:: 2  zakończyć działanie skryptu

@echo off
:_START
if not exist %userprofile%\Desktop\%1 (
    mkdir %userprofile%\Desktop\%1
    type nul > %userprofile%\Desktop\%1\test.txt
    type nul > %userprofile%\Desktop\%1\test2.txt
    type nul > %userprofile%\Desktop\%1\test3.txt
    attrib +r %userprofile%\Desktop\%1\test.txt
    attrib +r %userprofile%\Desktop\%1\test2.txt
    dir %userprofile%\Desktop\%1 /A:R
    echo Wpisz:
    echo 0 - Usuwa atrybut tylko do odczytu z wszystkich plikow w tym folderze
    echo 1 - Tworzy kopie plikow w folderze C:\temp\
    echo 2 - Konczy dzialanie skryptu
    set /P choice=Wybierz opcje:
    if %choice%==0 goto _0
    if %choice%==1 goto _1
    if %choice%==2 goto _exit
) else (
    rmdir %userprofile%\Desktop\%1 /S /Q 
    goto _START
)

:_0
attrib -r %userprofile%\Desktop\%1\*
goto _exit

:_1
robocopy %userprofile%\Desktop\%1 C:\temp
goto _exit

:_exit
if %choice%==0 (
    attrib +r %userprofile%\Desktop\%1\test.txt
    attrib +r %userprofile%\Desktop\%1\test2.txt
)

if %choice%==1 (
    del C:\temp\*.txt /Q /F
)

echo Koncze dzialanie skryptu
