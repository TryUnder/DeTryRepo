class Osoba {
    constructor(imie, nazwisko, rokUrodzenia) {
        this.imie = imie;
        this.nazwisko = nazwisko;
        this.rokUrodzenia = rokUrodzenia;
    }
 
    wypiszInformacje() {
        console.log(`Imie: ${this.imie} Nazwisko: ${this.nazwisko} Rok Urodzenia: ${this.rokUrodzenia}`);
    }
}
 
osoba1 = new Osoba("Jan", "Nowak", 2000);;
osoba2 = new Osoba("Kamil", "Bednarek", 1997);
osoba3 = new Osoba("Jan", "Ostrzewski", 2005);
osoba1.wypiszInformacje()
osoba2.wypiszInformacje()
osoba3.wypiszInformacje()
 
class Pracownik extends Osoba {
    constructor(imie, nazwisko, rokUrodzenia, pensja, premia) {
        super(imie,nazwisko, rokUrodzenia);
        this.pensja = pensja;
        this.premia = premia;
    }
 
    wypiszInformacje() {
        super.wypiszInformacje();
        console.log(`Pensja: ${this.pensja} Premia: ${this.premia}`);
    }
 
    returnTag() {
        return `<tr>
                    <td>${this.imie} ${this.nazwisko[0]}</td>
                    <td>${this.pensja}</td>
                    <td>${this.premia}</td>
                </tr>`;
    }
}
 
pracownik1 = new Pracownik("Artur", "Niewidomy", 2000, 3500, 100);
pracownik2 = new Pracownik("Oskar", "Nowak", 1992, 4500, 750);
pracownik3 = new Pracownik("Hubert", "Lewowicki", 2000, 20000, 1000);
 
pracownik1.wypiszInformacje()
let table = document.getElementById("dane")
table.innerHTML += pracownik1.returnTag()
table.innerHTML += pracownik2.returnTag()
table.innerHTML += pracownik3.returnTag()