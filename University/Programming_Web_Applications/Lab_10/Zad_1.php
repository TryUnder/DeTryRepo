<?php
 
?>
 
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>Zad_1</title>
    </head>
 
    <body>
        <?php
            $owoce = ["jabłko", "banan", "gruszka", "kaki", "śliwka", "pomarańcza", "mandarynka", "cytryna"];
            for($i = 0; $i < count($owoce); $i++) {
                echo($owoce[$i].", ");
            }
 
            sort($owoce);
        ?>
        <ol>
            <?php
                for($i = 0; $i < count($owoce); $i++) {
                    echo("<li>$owoce[$i]</li>");
                }
            ?>
        </ol>
    </body>
</html>