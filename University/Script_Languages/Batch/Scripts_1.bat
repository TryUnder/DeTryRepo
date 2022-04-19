:: Zadanie 1.
:: Utworzyć skrypt o treści z powyższego zrzutu ekranu i uruchomić (klikając na ikonę skrypt.bat). Usunąć
:: pierwszą linijkę skryptu i spróbować uruchomić ponownie. Następnie usunąć ostatnią linijkę i uruchomić.

:: Zadanie 2.
:: Uruchomić wiersz poleceń i za jego pomocą wywołać skrypt utworzony w zadaniu 1. Sprawdzić różnice w
:: wywołaniu skryptu wpisując jego nazwę i wykorzystując komendę call.

@echo off
echo Hello world
PAUSE

:: " 'call' does execute the other Batch file in the same context of the caller program, so they share
:: the same variable and other status (like echo ON/OFF) or delayed expansion
::
:: whereas cmd /C execute the other Batch file in an entirelt separated context, so any change made in the
:: called Batch file is not reflected in the original file "

:: Zadanie 3.
:: Wyświetlić informacje o przedstawionych powyżej komendach. Wywołać komendę dir w taki sposób aby
:: wyświetlała za pomocą małych liter tylko nazwy plików i folderów ukrytych z katalogu C:\Windows.

:: help (commands)

:: TIME - Is used to display information about the current time as to change it
:: /T   - with the only purpose for displaying

:: DATE - Is used to display information about the current date as to change it
:: /T   - with the only purpose for displaying

:: EXIT - Quits the command interpreter or the current batch script
:: /B   - Inside the script, exits from script. Outside of the script, will quit CMD.EXE

:: VOL  - Display information about specific Volumes

:: chdir (cd) - 
::  1)Without any parameters CHDIR displays the current drive and directory
::  2)In order to change the drive /D is needed

:: COPY - Copies one or more files to another location.
:: COPY source destination

:: CLS - Clears the screen

:: DEL - Deletes one or more files
::  1) /P Prompt for confirmation
::  2) /F Force delete read-only files
::  3) /S Delete specified files from all subdirectories.
::  4) /Q Quiet mode
::  5) /A Select files to delete based on attributes
::      /A[:D/H/S/R]

:: MKDIR (MD) - Creates a directory

:: RENAME (REN) - This command is responsible for changing name of the files
:: RENAME BEFORE-CHANGE-NAME AFTER-CHANGE-NAME

:: RMDIR (RD) - Used to remove directories
::  1) /S Removes all directories and files in the specified directory
::  2) /Q Quiet mode

:: TYPE - Displays the contents of a text file or files

:: TITLE - Change title of the window console command 

:: PROMPT - Is used to change the command prompt

:: FINDSTR - Searches for strings in files
::  1) /S Searches for matching files in the current directory and all subdirectories
::  2) /I Case sensitivity disabled
::  3) /R Regular expression ENABLED

:: ATTRIB - Displays or change file attributes
::  1) + Sets an attribute
::  2) - Clears an attribute
::  R/A/S/H

:: DIR - Displays a list of files and subdirectories in a directory
:: Switch
:: /A Displays files with specified attributes.
:: 	D - Directories
:: 	H - Hidden files
:: 	S - System files
:: 	R - Read-only files

:: /C Display the thousand separator in file sizes.. 
:: /-C is used to disable the display separator
:: /D Display by columns
:: /L Display by lowercase
:: /O Display files by specific order
:: 	N - By name (alphabetically)
:: 	E - By extension
:: 	G - Group directories first
:: 	S - By size (smallest first)
::	D - By date/time (oldest first)
::	- - Used to reverse order
::
:: /P Pauses after each screenful of information
:: /Q Display ownership
:: /S Display files in specified directory and all subdirectories

dir C:\Windows /L /A:H

set zm1 = 10
set zm2=40
set zm3=test
set zm4=drugi test
set zm5="trzeci test"
echo %zm1% - %zm2% - %zm3% - %zm4% - %zm5%

set zm1=5
set zm2=10
set zm3=%zm1%+%zm2%
set /A zm4=%zm1%+%zm2%
echo %zm3% - %zm4%

:: /A switch needs to be used in order to assign expression value to the variable
:: %CD%    	   - bieżący katalog
:: %DATE%    	   - bieżąca data
:: %TIME%    	   - bieżący czas
:: %RANDOM%        - wartość losowa z zakresu od 0 do 32767
:: %ERRORLEVEL%    - wartość błędu (0 gdy brak)

:: Zadanie 5* (rozwiązanie zadań oznaczonych * należy umieścić w sprawozdaniu lub pokazać podczas zajęć).
:: Napisać skrypt który zmieni kolor konsoli (polecenie color), zmieni tytuł okna (polecenie title) oraz tryb
:: zgłoszenia (polecenie prompt), wyświetli tekst powitania zawierający nazwę użytkownika (należy ją odnaleźć w
:: zmiennych środowiskowych), bieżącą datę oraz jedną liczbę losową.

:: color 3
title "MyTitle"
prompt 
echo Witaj %USERNAME%
echo %DATE%
echo %TIME%
echo %RANDOM%

:: Zadanie 7* (rozwiązanie zadań oznaczonych * należy umieścić w sprawozdaniu lub pokazać podczas zajęć).
:: Wykorzystując przełącznik /P polecenia set pobrać od użytkownika nazwę katalogu jaki ma zostać utworzony.
:: Jeżeli dany katalog istnieje, zmienić jego nazwę na nazwa.old (lub zapytać użytkownika co zrobić – np. czy
:: usunąć dany katalog). Przykład wczytania danych od użytkownika: set /P katalog="Podaj nazwe katalogu: "


:START_
SETLOCAL
set /P readLine=type a name of a catalog
mkdir %TEMP%\%readLine%
if %ERRORLEVEL%==0 (
    echo Directory was created succesfully
) else (
    echo Directory was already created
    set /P readLine2=do you want to delete that directory?:
    if %readLine2%==Y (
        rd %TEMP%\%readLine%
        echo Directory was deleted succesfully
        set /P readLine3=would you like to create a directory?:
        if %readLine3%==Y (
            ENDLOCAL
            goto START_
        ) else (
            echo exit from the program
        )
    ) else (
        echo Exit from the program
    )
)
::DOESNT WORK