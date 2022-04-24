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
    if "%choice%"=="0" goto _0
    if "%choice%"=="1" goto _1
    if "%choice%"=="2" goto _exit
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
if "%choice%"=="0" (
    attrib +r %userprofile%\Desktop\%1\test.txt
    attrib +r %userprofile%\Desktop\%1\test2.txt
)

if "%choice%"=="1" (
    del C:\temp\*.txt /Q /F
)

echo Koncze dzialanie skryptu

:: FIND is used to search for specific array of characters in files
::  /V - used to display all lines NOT containing ths specific string
::  /C - used to display only the count of lines containing the string
::  /N - Displays line numbers with the displayed lines
::  /I - Ignores the case of characters when searching for the string

:: Pipeline processing is known as directing the output stream from one command to the second command
:: as a stream of input data  

:: more - Displays output one screen at a time
::  /C - Clear screen before displaying page
::  /Tn - Expand tabs to n spaces (default 8)

:: sort
::  /+n - Specifies the character number n to begin each comparison
::  /M  - Specifies the amount of main memory to use for the sort in KB
::  /R  - Reverse the sort order Z to A then 9 to 0
::  /T  - Specifies the file which held the sorting items not to occupy memory
::  /O  - Specifies the file where sorted input is to be stored.

:: Zadanie 7.
:: Wykorzystać przetwarzanie potokowe w celu:
:: Wyświetlenia tylko adresów fizycznych z polecenia ipconfig –all
:: Wyświetlenia tylko poleceń dotyczących plików (lista poleceń: help)
:: Posortowania zawartości dowolnego pliku (wyświetlenie pliku: type plik)

ipconfig /all | find "Physical Address" /I
help | find "file" /I

if exist %userprofile%\Desktop\test.txt (
    del test.txt /Q /F
)
echo.
echo PROJECT MKULTRA, THE CIA'S PROGRAM OF > %userprofile%\Desktop\MK-ULTRA.txt
echo RESEARCH IN BEHAVIORAL MODIFICATION >> %userprofile%\Desktop\MK-ULTRA.txt
echo WEDNESDAY, AUGUST 3, 1977 >> %userprofile%\Desktop\MK-ULTRA.txt
echo U.S. SENATE, >> %userprofile%\Desktop\MK-ULTRA.txt
echo SELECT COMMITTEE ON INTELLIGENCE, >> %userprofile%\Desktop\MK-ULTRA.txt
echo AND SUBCOMIrrTEE ON HEALTH >> %userprofile%\Desktop\MK-ULTRA.txt
echo AND SCIENTIFIC RESEARCH >> %userprofile%\Desktop\MK-ULTRA.txt
echo The committees met, pursuant to notice, at 9:07 a.m. in room 1202, >> %userprofile%\Desktop\MK-ULTRA.txt
echo Dirksen Senate Office Building, Senator Daniel K. Inouye-(chairman - >> %userprofile%\Desktop\MK-ULTRA.txt
echo of the Select Committee on Intelligence) presiding. >> %userprofile%\Desktop\MK-ULTRA.txt
echo Present: Senators Inouye (presiding), Kennedy, Goldwater, Bayh, >> %userprofile%\Desktop\MK-ULTRA.txt
echo Hathaway, Huddleston, Hart, Schweiker, Case, Garn, Chafee, Lugar >> %userprofile%\Desktop\MK-ULTRA.txt
echo and Wallop. >> %userprofile%\Desktop\MK-ULTRA.txt
echo Also present: William G. Miller, staff director, Select Committee on >> %userprofile%\Desktop\MK-ULTRA.txt
echo Intelligence; Dr. Lawrence Horowitz, staff director, Subcommittee >> %userprofile%\Desktop\MK-ULTRA.txt
echo on Health and Scientific Research; and professional staff members of >> %userprofile%\Desktop\MK-ULTRA.txt
echo both committees. >> %userprofile%\Desktop\MK-ULTRA.txt

echo Before sort:
echo.
more %userprofile%\Desktop\MK-ULTRA.txt /C
sort %userprofile%\Desktop\MK-ULTRA.txt /O %userprofile%\Desktop\MK-ULTRA-SORTED.txt /+2
echo.
echo After sort:
if exist %userprofile%\Desktop\MK-ULTRA-SORTED.txt (
    more %userprofile%\Desktop\MK-ULTRA-SORTED.txt
    del %userprofile%\Desktop\MK-ULTRA-SORTED.txt /Q /F
    del %userprofile%\Desktop\MK-ULTRA.txt /Q /F
)

:: data stream
:: keyboard - CON
:: printer - PRN
:: series joints - COM1 -> COM4
:: parralel joints - LPT1 -> LPT3
:: void devices - NUL 

:: >    redirect stream to the input
:: >>   add stream to the input
:: 2>   redirection output errors as a stream to the input
:: 2>>  add output errors as a stream to the input
:: <    redirection streams from the input to the output

:: mkdir test 2> NUL 
:: errors will be redirected to the null device (won't be displayed)

:: Zadanie 8.
:: Zapisać zmienne środowiskowe do pliku zm1.txt
:: Zapisać posortowane zmienne środowiskowe do pliku zm2.txt
:: Porównać oba pliki za pomocą polecenia fc

echo %path% > %userprofile%\Desktop\zm1.txt
echo %os% %systemroot% %homedrive% %homepath% %computername% %username% %userprofile% >> %userprofile%\Desktop\zm1.txt     
sort %userprofile%\Desktop\zm1.txt /O %userprofile%\Desktop\zm2.txt

:: FC - Compares two files or sets of files and displays the differences between them
::  /C  - Disregards the case of letters

fc %userprofile%\Desktop\zm1.txt %userprofile%\Desktop\zm2.txt

:: Zadanie 9.
:: Napisać skrypt który wyszuka wszystkie pliki zawierające w nazwie "readme". Wynik skryptu zapisać do pliku
:: readme.txt

if "%2"=="0" (
    echo C: > %userprofile%\Desktop\readme.txt
    dir C:\ /S /A:-S | find "readme" >> %userprofile%\Desktop\readme.txt
    echo D: >> %userprofile%\Desktop\readme.txt
    dir D:\ /S /A:-S | find "readme" >> %userprofile%\Desktop\readme.txt
)

echo %%~dp0 is "%~dp0"
echo %%0 is "%0"
echo %%~dpnx0 is "%~dpnx0"
echo %%~f1 is "%~f1"
echo %%~dp0%%~1 is "%~dp0%~1"

rem Temporarily change the current working directory, to retrieve a full path 
rem   to the first parameter
pushd .
cd %~dp0
echo batch-relative %%~f1 is "%~f1"
popd

:: https://ss64.com/nt/syntax-args.html
:: https://docs.microsoft.com/en-us/windows-server/administration/windows-commands/call
:: https://stackoverflow.com/questions/1645843/resolve-absolute-path-from-relative-path-and-or-file-name

:: In order to get the file path https://ss64.org/viewtopic.php?t=180
:: or use WHERE

:: Zadanie 10.
:: I.
:: Wykorzystaj polecenie tasklist tak aby wyświetlało tylko procesy zajmujące więcej niż 100MB w
:: pamięci (należy wykorzystać przełącznik /FI z odpowiednim filtrem).
:: II.
:: Posortuj wynik powyższej komendy (polecenie sort) tak aby sortowało wyniki według rozmiaru
:: zajmowanego w pamięci (sortowanie począwszy od znaku nr. 64).
:: III.
:: Napisz skrypt który będzie dopisywał wynik powyższego działania do pliku procesy%data%.txt
:: (wartość %data% powinna zawierać bieżący dzień, miesiąc i rok).

set day=%date:~0,2%
set month=%date:~3,2%
set year=%date:~6,4%
for /F "delims=" %%i in ('tasklist /FI "MEMUSAGE GT 100000" ^| sort /+64 ') do (
    echo %%i >> %userprofile%\Desktop\%day%.%month%.%year%.txt
)

:: Zadanie 11
:: Napisz skrypt zapisujący statystyki połączeń użytkownika (net statistics workstation) do pliku C:\temp\net.txt.
:: Do pliku należy dopisać tylko bieżącą datę, godzinę, oraz informacje o ilości danych nadanych i otrzymanych
:: (w celu ich pozyskania należy wykorzystać komendę find). Skrypt powinien tworzyć katalog C:\temp\ (w
:: przypadku gdy katalog istnieje błędy należy przekierować do strumienia pustego).

mkdir C:\temp 2> NUL
echo %date:~0,2%.%date:~3,2%.%date:~6,4% %time:~0,5% >> C:\temp\net.txt
net statistics workstation | find "Bytes" >> C:\temp\net.txt

:: Zadanie 12
:: Napisz skrypt który wyświetli kolejno wszystkie liczby od 2 do 10 oprócz liczby 7.

SETLOCAL EnableDelayedExpansion
for /L %%i in (2,1,10) do (
    if %%i NEQ 7 (
        echo %%i
    )
)
SETLOCAL DisableDelayedExpansion

:: Windows Registry

::  Is a hierarchical database that stores low-level settings for the Microsoft Windows operating system
::  and for applications that opt to use the registry.
::  The kernel, device drivers, services and User Interfaces can all use the registry.

:: In other words, the registry or Windows Registry contains information, settings, options, and other
:: values for programs and hardware installed on all versions of Microsoft Windows os.

:: Every program that is installed on the OS has to store a subkey containing settings such as program's
:: location, its version, and how to start the program.

:: atomicity + kernel transaction manager

:: The registry contains two basic elements: keys and values. 
:: Registry keys are container objects similar to folders while registry values are non-container
:: objects similar to files.
:: Key may contain values and subkeys.

:: 7 PREDEFINED (HIVE) ROOT KEYS ARE:
:: H - HIVE
::
:: HKEY_CLASSES_ROOT HKCR       - Contains information about registered applications, such as file associations
::                              - Object class IDs
::                              - Windows stores in here information about file types, extensions.  
::                              - Defines default programs which are used to open certain types as well

:: HKEY_CURRENT_USER HKCU       - Stores specific information that are associated with currently logged-in user.
::                              - HKCU is a link to the subkey HKU that coressponds to the user. 
::                              - Same information is accesible in both locations.

:: HKEY_LOCAL_MACHINE HKLM      - Stores settings that are specific to the local computer
::                              - The key located by HKLM is not stored on disk, but maintained in memory by
::                              - the system kernel
::                              - Information about drivers and their settings
::
::      HKLM\HARDWARE                   - Is created during the first start-up of the system and contain 
::                                      - hardware configuration
::  
::      HKLM\SAM                        - (Security Accounts Manager)
::                                      - Stores information about users (database)
::
::      HKLM\SECURITY                   - Information about system security, permissions of currently logged-in
::                                      - user. Cannot be modified
::
::      HKLM\SOFTWARE                   - Stores information about installed software on the OS
::  
::      HKLM\SYSTEM                     - Stores information about specific session.
::                                      - System setup
::                                      - RNG data

:: HKEY_USERS HKU                 - Stores settings of all users associated to the computer

:: HKEY_CURRENT_CONFIG HKCC       - Stores current settings about devices that are connected to the computer



:: Windows 7 Domain
::
:: It is a collection of computers in internet whose resources and security are controlled by determined
:: server called main controler of a domain.
:: Windows 7 embraces from the service Active Directory (ADS - Active Directory Services). In the structure
:: of such type user accounts, groups and computers are grouped together in organization unit which provides
:: administrators with easier maintability of resources.
:: Only servers work as a main controlers of a domain.

:: Working group
::
:: Connection of group of computers that make data share, printer joint-use, and other resources available. 