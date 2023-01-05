<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>Zad_2</title>
    </head>
 
    <body>
        <?php
            function losuj_string() {
                $i = rand() % 3;
                switch($i) {
                    case 0: return "kamień";
                    case 1: return "papier";
                    case 2: return "nożyce";
                }
            }
        ?>
            <form action="Zad_2.php">
                <input name="imie">
                <input name="nazwisko">
                <button onclick="submit()">Prześlij</button>
            </form>
        <?php
            
            if(!empty($_GET)) {
                $wybor = losuj_string();
                echo("Użytkownik: ".$_GET["imie"]." ".$_GET["nazwisko"]." wylosował: ".$wybor."<br>");   
            } else {
                $user = "brak";
                echo($user);
            }
            
        ?>

        <a href="Zad_2.php?jaki=kamień">Kamień</a>
        <a href="Zad_2.php?jaki=papier">Papier</a>
        <a href="Zad_2.php?jaki=nożyce">Nożyce</a>
    </body>
</html>