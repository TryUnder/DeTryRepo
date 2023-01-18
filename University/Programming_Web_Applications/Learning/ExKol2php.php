<!DOCTYPE html>
<html>
    <head>

    </head>

    <body>
        <?php
            function isPrime($liczba) {
                if ($liczba == 2 || $liczba == 3)
                    return true;
                
                if ($liczba <= 1 || $liczba % 2 == 0 || $liczba % 3 == 0)
                    return false;

                for ($i = 5; $i * $i <= $liczba; $i += 6) {
                    if ($liczba % $i == 0 || $liczba % ($i + 2) == 0)
                        return false;
                }
                return true;
            }
            $liczba = 15;
            $prime = isPrime($_GET["liczba"]);
            if ($prime == 1) 
                echo($_GET["liczba"]." jest liczbą pierwszą.");
            else 
                echo($_GET["liczba"]." nie jest liczbą pierwszą.");
        ?>

        <?php
            $plik = fopen("doZapisu.txt", "a");

            function wordPermutate($array1, $array2, $plik) {
                for ($i = 0; $i < count($array1); $i++) {
                    for ($j = 0; $j < count($array2); $j++) {
                        echo($array1[$i].$array2[$j]."<br>");
                        fputs($plik, $array1[$i].$array2[$j]."\r\n");
                    }
                }
            }

            $array1 = ["admin", "123", "root", "!@#", "zaqwsx", "password", "pwd"];
            $array2 = ["admin", "123", "root", "!@#", "zaqwsx", "password", "pwd"];

            wordPermutate($array1, $array2, $plik);
        ?>
    </body>
</html>