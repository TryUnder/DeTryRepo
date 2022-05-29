# nie dziala tak jak bym tego oczekiwał

dialog --title "Program do edycji uprawnien dla plikow #1" \
--menu "Wybierz przedmiot edycji dla pliku $1" 15 50 2 \
Nadaj "Nadaj uprawnienia" \
Odbierz "Odbierz uprawnienia" \
2>$HOME/input1

menuitem1=$(cat $HOME/input1)

if [ $? == 0 ]; then
	dialog --title "Program do edycji uprawnien dla plikow #2" \
	--menu "Wybierz podmiot edycji dla pliku $1" 15 50 3 \
	Autor "Autor" \
	Grupa "Grupa" \
	Inni "Inni" \
	2>$HOME/input2

	menuitem2=$(cat $HOME/input2)

	if [ $? == 0 ]; then
		dialog --title "Program do edycji uprawnien dla plikow #3" \
		--menu "Wybierz co zmienic w pliku $1" 15 50 3 \
		Zapis "Prawo do zapisu" \
		Odczyt "Prawo do odczytu" \
		Wykonywanie "Prawo do wykonywania" \
		2>$HOME/input3

		menuitem3=$(cat $HOME/input3)
		
		if [ $? == 0 ]; then
			case $menuitem1 in
				Nadaj) case $menuitem2 in
					Autor) case $menuitem3 in
						Zapis)       chmod u+w $1 ;;
						Odczyt)      chmod u+r $1 ;;
						Wykonywanie) chmod u+x $1 ;;
					Grupa) case $menuitem3 in
						Zapis)	     chmod g+w $1 ;;
						Odczyt)	     chmod g+r $1 ;;
						Wykonywanie) chmod g+x $1 ;;
					Inni)  case $menuitem3 in
						Zapis)	     chmod o+w $1 ;;
						Odczyt)	     chmod o+r $1 ;;
						Wykonywanie) chmod o+x $1 ;;
				Odbierz) case 
					Autor) case $menuitem3 in
						Zapis)	     chmod u-w $1 ;;
						Odczyt)      chmod u-r $1 ;;
						Wykonywanie) chmod u-x $1 ;;
					Grupa) case $menuitem3 in
						Zapis)	     chmod g-w $1 ;;
						Odczyt)	     chmod g-r $1 ;;
						Wykonywanie) chmod g-x $1 ;;
					Inni) case  $menuitem3 in
						Zapis)	     chmod o-w $1 ;;
						Odczyt)      chmod o-r $1 ;;
						Wykonywanie) chmod o-x $1 ;;
	
		rm $HOME/input3
	rm $HOME/input2
rm $HOME/input1
	

