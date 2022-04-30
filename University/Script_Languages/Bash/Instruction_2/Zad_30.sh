# 30. Utwórz plik o dowolnej nazwie i nadaj mu uprawnienia do wykonywania. Uruchom
# go. Jaki efekt?

echo "echo test" > $HOME/run.sh
chmod 100 $HOME/run.sh
$HOME/run.sh
