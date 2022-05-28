dialog --title "Menu" --backtitle "KIK" --menu "Wybierz" \
15 50 3 \
Data/Czas "Pokaz biezacy czas i date" \
Kalendarz "Pokaz kalendarz" \
Edytor "Edytuj" \
2> $HOME/input

menuitem=$($HOME/input)

if [ $? == 0 ]; then
    case $menuitem in
        Data/Czas) date ;;
        Kalendarz) cal ;;
        Edytor) vi ;;
    esac
fi