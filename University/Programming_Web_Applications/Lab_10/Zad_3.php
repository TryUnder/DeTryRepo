<?php
    $ile = 100;
    $kat = 0.1;
    if (isset($_GET["ile"])) {
        $ile = (int)$_GET["ile"];
    }
    if (isset($_GET["kat"])) {
        $kat = (float)$_GET["kat"];
    }
?>
<!DOCTYPE html>
<html>
    <head>
        <script src="p5.min.js"></script>
    </head>
    <body>
        <main></main>
        <script>
            let tex = null;

            class Plat {
                constructor() {
                    this.bx = -400 + Math.random() * 800;
                    this.x = this.bx;
                    this.z = +100 - Math.random() * 400;
                    this.y = -400 + Math.random() * 800;
                    this.s = 0.5 + Math.random();
                    this.kx = -0.5 + Math.random();
                    this.ky = -0.5 + Math.random();
                    this.kz = -0.5 + Math.random();
                }
                move() {
                    if (this.y > 400) {
                        this.y = -400;
                        this.bx = -400 + Math.random() * 800;
                    }
                    this.y += this.s;
                    this.x = this.bx + 50 * Math.sin(this.y / 30);
                }
            }

            const pltk = <?php echo($ile); ?>;
            let pl = [];
            for (let i = 0; i < pltk; i++) {
                pl.push(new Plat());
            }
             
            function preload() {
                tex = loadImage("/snlk.png");
            }

            function setup() {
                createCanvas(640, 480, WEBGL);
            }
            
            let kat = 0;
            function draw() {
                background(200, 50, 20);                
                noStroke();
                lights();
                pointLight(255, 255, 255, 0, 0, 150);
                ambientLight(50);
                
                for (let i = 0; i < pltk; i++) {
                    pl[i].move();
                    push();
                    fill(0, 0, 0, 0);
                    translate(pl[i].x, pl[i].y, pl[i].z);
                    rotateX(kat * pl[i].kx);
                    rotateY(kat * pl[i].ky);
                    rotateZ(kat * pl[i].kz);
                    texture(tex, 0, 0);
                    plane(30, 30);
                    pop();
                }
                kat += <?php echo($kat); ?>;          
            }
        </script>
    </body>
</html>
