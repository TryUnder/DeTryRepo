# 11. Napisz skrypt, który po 1 minucie od uruchomienia wyświetli napis „Minela jedna
# minuta” (polecenie at)

sudo /etc/init.d/atd start
echo "Minela jedna minuta" | at now + 1 minute