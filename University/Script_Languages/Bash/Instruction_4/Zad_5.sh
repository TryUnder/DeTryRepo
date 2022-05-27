# 5. Stwórz skrypt wykonujący działanie na dwóch liczbach. Po podaniu liczb działanie
# powinno być wybrane z listy.

echo "Podaj operacje do wykonania na liczbach"
echo "Dodawanie     - 1"
echo "Odejmowanie   - 2"
echo "Mnożenie      - 3"
echo "Dzielenie     - 4"

read choice
case $choice in 
    "1") echo "$(($1+$2))";;
    "2") echo "$(($1-$2))";;
    "3") echo "$(($1*$2))";;
    "4") if [ $2 != 0 ]; then
            echo "$(($1/$2))"
         else
            echo "Nie dziel przez 0"
         fi;;
    *) echo "Blad";;
esac 