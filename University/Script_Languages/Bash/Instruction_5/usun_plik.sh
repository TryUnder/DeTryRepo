dialog --title "Yes-No Alert" --backtitle "KIK" \
--inputbox "Chcesz skasowac plik $1" 7 60

sel=$?

case $sel in
    0) rm $1 ;;
    1) echo "Wcisnales Cancel" ;;
    255) echo "Wcisnales [ESCAPE]" ;;
esac