:: FORMAT           - Formats a disk for use with Windows
:: /FS:filesystem   - Specifies the type of the file system (FAT, FAT32, exFAT, NTFS)
:: /V:label         - Specifies the volume label
:: /Q               - Perfoms a quick format
:: /C               - NTFS only

:: \                - Main directory on each disk
:: .                - Current directory
:: ..               - Superior directory

:: CHDIR / CD       - Used for changing directory onto the disk
:: /D               - Used in order do change directory between disks
:: cd               - Displays current dicrectory

:: findstr          - Search for data in files

:: chkdsk           - Check disk
:: /F               - Repair
:: /R               - Look for bad sectors (implicitly run /F)

:: subst            - Used for assigning paths to the character of disk
::                  - Can be seen as a "virtual disk"

:: NET ACCOUNTS     - updates and modify requirements for password and logins for all accounts (SERVERS ONLY)
:: /FORCELOGOFF:{minutes | NO}
:: /MINPWLEN:length
:: /MAXPWAGE:{days | UNLIMITED}
:: /MINPWAGE
:: /UNIQUEPW:number
:: /DOMAIN

:: NET COMPUTER     - Deleted or Adds computers from domains
:: \\name_of_the_computer
:: /ADD
:: /DEL 

:: NET CONFIG       - Used for changing server options 
:: [{server | workstation}]

:: NET CONTINUE     - Used for rerun services which were stopped by net pause

:: NET FILE         - Shows all opened file on the server as well as list of blockage for all of the files.
:: NET FILE [ID[/CLOSE]] - Closes opened file and deletes blockages

:: NET GROUP        - Adds, shows and modifies global groups for domains
:: /DOMAIN
:: /ADD
:: /DELETE

:: NET GROUP        - Displays list of all groups

:: NET HELP

:: NET LOCALGROUP   - Adds, shows and modifies local groups.
:: /DOMAIN
:: /ADD
:: /DELETE

:: NET NAME         - Adds, or deletes aliasses
:: /ADD
:: /DELETE

:: NET PAUSE [SERVICE]

:: NET SESSION      - Used for managing computers that are connected to servers.
:: \computer_name
:: /delete          - Ends session for "/computer_name" and closes all opened sessions on that specific computer 

:: NET SHARE        - Used for managing shared resources

:: STOP shared resource which name is 1234
:: NET SHARE 1234 /delete

:: NET START        - Runs the [service]

:: NET STATISTICS   - Displays statistic logs  for local services
:: [{workstation | server}]

:: NET STOP         - Stops the [service]

:: NET TIME         - Synchronise computer clock with the other computer's clock or domain

:: NET USE          - Connects computers with shares resources
::                  - Shows information about connected computers

:: NET USER         

:: NET VIEW         - Displays list of domains, computers and resources shared by specific computer

:: FTP              - Runs the FTP client

:: START            - Starts another CMD console

:: IPCONFIG /ALL

:: AT

:: PUSHD

:: POPD

:: SETLOCAL         - Cause the changes of the environment that were perfomed, will be local 
::                  - Will be spotted only inside the batch file
::                  - EnableDelayedExpansion
::                  - DisableDelayedExpansion
::                  - EnableExtensions
::                  - DisableExtensions

:: ENDLOCAL

:: SET              - Without any parameters shows all environmental variables
:: SET /A           - Numerical expression
:: SET /P           - Ask user to provide the input value

:: MKLINK           
:: /D
:: /H
:: /J

:: 1. Opr????nij zawarto???? pami??ci podr??cznej programu rozpoznawania nazw klient??w DNS.

ipconfig /flushdns

::2. Wy??wietl statystyki dla stacji roboczej, tak aby po zape??nieniu ekranu system oczekiwa?? na
::naci??ni??cie klawisza.

net statistics workstation | more

:: 3. W????cz przywracanie bie????cych po????cze?? przy ka??dym logowaniu, niezale??nie od p????niejszych
:: zmian.

:: 4. Uruchom kalkulator za pomoc?? wiersza polece??.

start calc.exe

:: 6. Wy??wietl zmienne ??rodowiskowe, kt??rych nazwa zaczyna si?? na liter?? D.
:: Klucz: Nie ma zmiennej ??rodowiskowej na liter?? D. Poprawna odpowied?? to P.
echo nie trolluj gamoniu, bo jest. -> driverdata

set > %userprofile%\Desktop\env_var.txt && finstr /B "D" %userprofile%\Desktop\env_var.txt

:: 7. Zamknij zadanie o id =7.

taskkill /F /PID 7

:: 9. Ustaw maksymaln?? d??ugo???? hase?? na 8 znak??w

net accounts /FORCELOGOFF /MINPWLEN:8 ::?

:: 10. Wy??wietl ustawienia stacji roboczej.

net config workstation

:: 11. Dodaj now?? grup?? do listy na serwerze o nazwie nowa.

net group /add nowa

:: 12. Zatrzymaj Harmonogram zada??.

net stop harmonogram zada??

:: 13. Udost??pni zasoby z folderu dom z dysku USB:

net share g:\dom\

