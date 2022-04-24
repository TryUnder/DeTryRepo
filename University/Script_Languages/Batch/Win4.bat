:: equal                EQU
:: not equal            NEQ
:: greater than         GTR
:: less than            LSS
:: greater or equal     GEQ
:: lesser or equal      LEQ  

:: 1. Przetestuj wszystkie przykładowe skrypty zawarte w ćwiczeniu.

@echo off
set _path=%userprofile%\Desktop\dni1.txt
type NUL > %_path%
echo aPoniedziałek >> %_path%
echo aWtorek >> %_path%
echo aŚroda >> %_path%
echo aCzwartek >> %_path%
echo aPiątek >> %_path%
echo aSobota >> %_path%
echo aCzwartek >> %_path%
echo aNiedziela >> %_path%
echo aCzwartek >> %_path%
echo aPiątek >> %_path%
echo aPoniedziałek >> %_path%

:: 2. Zapisz w pliku aczwartek.txt numery wierszy i wiersze w których występuje aCzwartek.

type NUL > %userprofile%\Desktop\aczwartek.txt
find /N "aCzwartek" %_path% > %userprofile%\Desktop\aczwartek.txt

:: 3. Napisz skrypt, który posortuje pliki alfabetycznie w katalogu bieżącym

dir /B /O:N

:: 4. Napisz skrypt, który zlokalizuje uszkodzone woluminy.

:: chkdsk /R /SCAN 

:: 6. Napisz skrypt, który zatrzymuje bufor wydruku czyści go i ponownie go uruchamia.

:: net stop spooler
:: del /q /f /s "%systemroot%\system32\spool\PRINTERS\*.*"
:: net start spooler

:: 7. Napisz skrypt, który kopiuje pliki z jednego folderu do drugiego

if not exist %2\kopia ( mkdir %2\kopia ) 
copy %1\*.* %2\kopia\copied.txt

:: 8. Napisz skrypt, który będzie zakładał katalogi o nazwie : 1,2,3,4,5,6 oraz wyświetli czy zostały
:: utworzone.

for /L %%i in (1,1,6) do (
    if not exist %%i ( 
        mkdir %%i
        echo Sucesfully created catalog %%i
    ) else (
        echo Error
    )
)

:: 9. Napisz program, który będzie usuwał z dysku usb wszystkie pliki i foldery.

:: rmdir /S /R G:\

:: 10. Napisz skrypt, który będzie wyświetlał informację o wersji systemu operacyjnego.

:: systeminfo | find "OS"

:: 12. Napisz skrypt, który zmienia system plików z Fat na NTFS

:: :convert %1 /FAT:NTFS

:: 13. Napisz skrypt, który będzie wyświetlał mac karty sieciowej oraz konfigurację Ip.

:: ipconfig /all 
:: lub ipconfig /all | find "Physical Address" && ipconfig /all | find "IPv4" && ipconfig /all | find "IPv6"

:: 14. Napisz skrypt, który wyświetla informacje o serwerze, stacji roboczej, grupach

:: net config server
:: net config workstation
:: net group

:: 16. Napisz skrypt kolejnosc.bat, który wypisze liczby w kolejności 5,4,3,2,1 oraz 75,50,25,0
:: (zastosuj instrukcję pętli for).

echo.
for /L %%i in (5,-1,1) do (
    echo %%i
)

echo.
for /L %%i in (75,-25,0) do (
    echo %%i
)

:: 17. Napisz skrypt o nazwie laboratorium.bat, który wyświetli 5 razy słowo laboratorium.

echo.
for /L %%i in (1,1,5) do (
    echo laboratorium
)

:: 18. Napisz skrypt, który wyświetli nazwę bieżąco zalogowanego użytkownika, literę dysku i
:: ścieżkę na której znajduje się katalog macierzysty bieżącego użytkownika, wyświetl
:: producenta procesora zainstalowanego w systemie.

echo.
echo %username%
echo %systemdrive%
echo %userprofile%
echo %PROCESSOR_IDENTIFIER%

:: 19. Napisz skrypt o nazwie stare.bat, który wyświetli listę wszystkich nazw plików z
:: rozszerzeniem txt we wszystkich katalogach na dysku C, następnie znajdzie pliki mające
:: nazwę Readme, posortuje je od drugiego znaku i wynik zapisze do pliku stare.txt. Następnie
:: wywołaj skrypt laboratorium (z pkt.4). Wyświetl bieżącą datę bez wyświetlenia monitu o
:: nową datę i również zapisz ją do pliku stare.txt. Na końcu wyświetl napis ”koniec
:: poszukiwań“.

:: dir C:\ /S /B | find ".txt"
:: dir C:\ /S /B | find "readme" > %userprofile%\Desktop\stare.txt
:: call laboratorium.bat
:: date /T >> %userprofile%\Desktop\stare.bat
:: echo koniec poszukiwań

:: 20. Napisz skrypt o nazwie przypisz.bat, który pod zmienną b przypisze słowo” blok“ a pod
:: zmienną d słowo” krok“ jeśli zmienne nie mają różnych ciągów znaków to wyświetl napis”
:: różne ciągi znaków. Natomiast jeśli pierwszy ciąg znaków (przypisany zmiennej b) jest
:: leksykalnie mniejszy niż drugi (przypisany zmiennej d) to wyświetl napis ”pierwszy jest
:: mniejszy“.

echo.
set b= blok
set d= krok

if /I %b% EQU %d% (
    echo Rozne ciagi znakow
) else (
    echo else
)

if /I %b% LSS %d% (
    echo Pierwszy jest mniejszy
)

:: 21. Utwórz plik plik.txt z dowolną zawartością. Następnie napisz procedurę wyszukaj.bat, która
:: ma za zadanie znaleźć ciąg znaków z plik.txt określony jako pierwszy parametr wywołania
:: procedury, wynik zapisz do pliku o nazwie będącej drugim parametrem wywołania procedury
:: (np. wynik.txt).

echo.
if not exist %userprofile%\Desktop\plik.txt (
    type NUL > %userprofile%\Desktop\plik.txt
)

echo Lorem ipsum dolor sit amet, consectetur adipiscing elit. >> %userprofile%\Desktop\plik.txt
echo Aenean fringilla ipsum quis nisi iaculis feugiat >> %userprofile%\Desktop\plik.txt
echo id at felis. Phasellus tempor, ex eu malesuada mattis, >> %userprofile%\Desktop\plik.txt
echo est neque lacinia ligula, nec molestie libero >> %userprofile%\Desktop\plik.txt

:: call wyszukaj.bat
:: wyszukaj.bat 

if not exist %userprofile%\Desktop\%2.txt (
    findstr %1 %userprofile%\Desktop\plik.txt > %userprofile%\Desktop\%2.txt )

:: 22. Napisz procedurę sortowanie.bat, która posortuje plik podany jako pierwszy parametr
:: wywołania procedury według drugiego znaku w każdym wierszu i wynik zapisze do pliku
:: podanego jako drugi parametr wywołania procedury.

sort %1 /+2 > %2