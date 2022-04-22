:: Non-intuitive work of loops
@echo off
set suma=0
for /L %%i in (1,1,5) do (
    set /A suma=%suma%+%%i
    echo Wartosc:%suma%
)
echo Suma:%suma%

:: (conditional statements?) and loops are expressions that global variables inside them are evaluated 
:: and reassigned at the end of loops/CS work.

:: Global variables inside loops can be expanded by the use SETLOCAL EnableDelayedExpansion 
echo.
SETLOCAL EnableDelayedExpansion
set suma=0
for /L %%i in (1,1,5) do (
    set /A suma=!suma!+%%i
    echo Wartosc:!suma!
)
echo Suma Koncowa:%suma%
SETLOCAL DisableDelayedExpansion

:: Zadanie 10.
:: Napisać skrypt wykonujący pętle wyświetlającą wartości parzyste: 10 8 6 4 2 0.

for /L %%i IN (10,-2,0) do (
    echo %%i
)

:: Zadanie 11. * (rozwiązanie zadań oznaczonych * należy umieścić w sprawozdaniu lub pokazać podczas zajęć).
:: Napisać pętlę przechodzącą po nazwach wszystkich procesów wyświetlanych za pomocą polecenia tasklist.
:: Pętla powinna dodatkowo zliczać wystąpienia procesu o nazwie svchost.exe oraz notepad.exe.
SETLOCAL EnableDelayedExpansion
echo.
set /A sumaProc=0
for /F "delims=%TAB%" %%i in ('tasklist') do (
    echo %%i
    if !sumaProc!==0 (
        tasklist | find "svchost.exe" /C > %appdata%\svctemp.txt
        tasklist | find "Notepad.exe" /C > %appdata%\notetemp.txt
        set /P numberOfSvchost=<%appdata%\svctemp.txt
        set /P numberOfNotepad=<%appdata%\notetemp.txt
        echo Number of svchost.exe: !numberOfSvchost!
        echo Number of notepad.exe: !numberOfNotepad!
        if exist %appdata%\svctemp.txt (del %appdata%\svctemp.txt)
        if exist %appdata%\notetemp.txt (del %appdata%\notetemp.txt)
        set /A sumaProc=!sumaProc!+1
    )
)
SETLOCAL DisableDelayedExpansion

:: Zadanie 12.
:: Napisać skrypt oparty na pętli for tworzący następujące katalogi: kat1 kat3 kat5 kat7 kat9

echo.
for /L %%i in (1,2,9) do (
    if exist %appdata%\kat%%i (
        del %appdata%\kat%%i /S /Q
    ) else (
        mkdir %appdata%\kat%%i
    )
    del %appdata%\kat%%i /S /Q
)

:: Zadanie 13.
:: Napisać skrypt pobierający od użytkownika 3 zmienne (działanie, x, y), w zależności od podanego numeru
:: działania skrypt powinien:
:: działanie == 1 – zsumować wartość x i y
:: działanie == 2 – odjąć x od y
:: działanie == 3 – odjąć y od x
:: działanie == 4 – pomnożyć x przez y

SETLOCAL EnableDelayedExpansion
echo.
set /P action=Podaj numer dzialania:
set /P x=Podaj x:
set /P y=Podaj y:
if %action%==1 (
    set /A result=%x%+%y%
) else if %action%==2 (
    set /A result=%y%-%x%
) else if %action%==3 (
    set /A result=%x%-%y%
) else if %action%==4 (
    set /A result=%x%*%y%
)   
echo %result%
SETLOCAL DisableDelayedExpansion

:: Zadanie 14
:: Napisać skrypt przyjmujący dwa argumenty:
:: liczbę liczb losowych które mają zostać wygenerowane (od 1 do 10)
:: maksymalną wartość jaka ma zostać wygenerowana (parametr opcjonalny)

SETLOCAL EnableDelayedExpansion
echo.
if %1 LSS 1 (
    goto _BADINPUT_
)
if %1 GTR 10 (
    goto _BADINPUT_
)

:_FOR
for /L %%i in (1,1,%1) do (
    set a[%%i]=%RANDOM%
    :: same time, same instance of cmd produce the same seed
    if !a[%%i]! GTR %2 (
        goto _FOR
    )
)

for /L %%i in (1,1,%1) do (
    echo !a[%%i]!
)
goto _EXIT_

:_BADINPUT_
echo Bad input parameters
:_EXIT_
echo Exit
SETLOCAL DisableDelayedExpansion

:: Zadanie 15.
:: Napisać skrypt wyświetlający informacje o systemie operacyjnym i procesorze (na podstawie zmiennych
:: środowiskowych).

echo.
echo My Processor:
echo %PROCESSOR_IDENTIFIER% %PROCESSOR_REVISION%

:: Zadanie 16.
:: Napisać skrypt zliczający liczbę parametrów podanych jako argumenty.

echo.
set arg_count=0
for %%i in (%*) do (
    set /A arg_count +=1
)
echo Number of arguments: %arg_count%