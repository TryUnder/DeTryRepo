dialog --title "InputBox" --backtitle "KIK" \
--inputbox "Wprowadz login" 8 60 2> $HOME/input

sel=$?
login=$(cat $HOME/input)
case $sel in
    0) echo "Witaj $login" ;;
    1) echo "Wcisnales Cancel" ;;
    255) echo "Wcisnales [ESCAPE]" ;;
esac

rm -f $HOME/input