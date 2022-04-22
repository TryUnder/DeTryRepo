:: PĘTLA PRZY POMOCY GOTO
@echo off
echo PETLA PRZY POMOCY GOTO
echo.
set i=0
:powrot
echo i=%i%
set /A i=%i%+1
if %i% LSS 10 goto powrot
echo.

:: Zadanie 8.
:: Napisać skrypt który będzie sumował wartości liczbowe podawane przez użytkownika (po podaniu wartości
:: należy ją doliczyć do sumy). W przypadku podania wartości równej 0 skrypt powinien zakończyć działanie.

set sum=0
:_GOTO
echo suma=%sum%
set /P toSum=Podaj wartosc do sumowania:
set /A sum=%sum%+%toSum%
if %toSum%==0 (
    echo Koniec pracy
) else (
    GOTO _GOTO
)
