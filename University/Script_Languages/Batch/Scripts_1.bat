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

color 3
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

set /P readLine="Podaj nazwe katalogu: "
