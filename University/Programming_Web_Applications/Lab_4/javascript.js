let linki = document.querySelectorAll("#tresc, #tresc a")
let kopia = document.cloneNode(true)
let elem = document.getElementById("hiperlacza")
for(let i = 0; i < linki.length; ++i) {
    elem.append(kopia[i])
}