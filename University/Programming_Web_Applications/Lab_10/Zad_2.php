<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>Zad_2</title>
    </head>
 
    <body>
        <?php
            function losuj_string() {
                $i = rand() % 4;
                switch($i) {
                    case 0: return "kamień";
                    case 1: return "papier";
                    case 2: return "nożyce";
                }
            }
            $wybor = losuj_string();
            echo("Wybór przeciwnika: ".$wybor.<br>);
        ?>
    </body>
</html>