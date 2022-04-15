<#
Zadanie 1:
1.1 Utwórz skrypt, w którym zostanie stworzony interfejs graficzny dla programu.
1.2 Utwórz okno programu o wymiarach 800x600.
1.3 Ustaw tytuł okna na Laboratorium 3.1.
1.4 Wyłącz możliwość skalowania okna.
1.5 Wewnątrz okna stwórz 2 pola tekstowe, do których będzie można wprowadzać wartości.
1.6 Stwórz etykietę która będzie wyświetlała wynik działania, na początku wyświetlana ma
być wartość 0.
1.7 Utwórz przycisk Kolor.
1.8 Wciśniecie przycisku ma wywoływać okno dialogowe wyboru koloru, który po wybraniu
zostanie zastosowany do okna programu.
1.9 Stwórz 4 przyciski: Suma, Różnica, Iloczyn oraz Iloraz. Każdy z nich będzie odpowiadał
za inne działanie w oparciu o podane dwie wartości.
1.10 Po naciśnięciu klawisza ma nastąpić wykonanie odpowiedniego działania. W przypadku
gdy jedno z pól tekstowych będzie puste należy zmienić tekst etykiety na „Błąd”. Taki sam
komunikat musi zostać wyświetlony w przypadku, gdy nastąpi próba dzielenia przez zero.
Obsługę błędów można zrealizować poprzez instrukcję try{} catch{}.
1.11 Dodaj kolejny przycisk o nazwie Czcionka.
1.12 Kliknięcie przycisku ma wywoływać okno wyboru czcionki. W oknie wyboru czcionki
należy włączyć możliwość wyboru koloru.
1.13 Wybrana czcionka wraz z kolorem ma stosować się do etykiety wyświetlającej wynik.
#>

Add-Type -AssemblyName System.Windows.Forms

<# 1.1 . 1.2 . 1.3 . 1.4 #>
<# Main window #>
$window = New-Object System.Windows.Forms.Form
$window.Text = "Laboratorium 3.1"
$window.Width = 800
$window.Height = 600
$window.MinimumSize = New-Object System.Drawing.Size(800,600)
$window.MaximumSize = New-Object System.Drawing.Size(800,600)

<# 1.5 #>
<# Text box 1 #>
$textBox1 = New-Object System.Windows.Forms.TextBox
$textBox1.Location = New-Object System.Drawing.Size(80,60)
$textBox1.Width = 200

<# 1.5 #>
<# Text box 2 #>
$textBox2 = New-Object System.Windows.Forms.TextBox
$textBox2.Location = New-Object System.Drawing.Size(520,60)
$textBox2.Width = 200

<# 1.9 . 1.10 #>
<# Button Add #>
$buttonAdd = New-Object System.Windows.Forms.Button
$buttonAdd.Location = New-Object System.Drawing.Size(100,100)
$buttonAdd.Width = 150
$buttonAdd.Text = "Dodaj"
$buttonAdd.Add_Click({
    [float]$result.Text = [float]$textBox1.Text + [float]$textBox2.Text
})

<# 1.9 . 1.10 #>
<# Button Subtract #>
$buttonSub = New-Object System.Windows.Forms.Button
$buttonSub.Location = New-Object System.Drawing.Size(250,100)
$buttonSub.Width = 150
$buttonSub.Text = "Odejmij"
$buttonSub.Add_Click({
    [float]$result.Text = [float]$textBox1.Text - [float]$textBox2.Text
})

<# 1.9 . 1.10 #>
<# Button Multiply #>
$buttonMul = New-Object System.Windows.Forms.Button
$buttonMul.Location = New-Object System.Drawing.Size(400,100)
$buttonMul.Width = 150
$buttonMul.Text = "Pomnóż"
$buttonMul.Add_Click({
    [float]$result.Text = [float]$textBox1.Text * [float]$textBox2.Text
})

<# 1.9 . 1.10 #>
<# Button Divide #>
$buttonDiv = New-Object System.Windows.Forms.Button
$buttonDiv.Location = New-Object System.Drawing.Size(550,100)
$buttonDiv.Width = 150
$buttonDiv.Text = "Podziel"
$buttonDiv.Add_Click({
    if($textBox2.Text -EQ 0){
        $result.Text = "Error"
    }else{
        [float]$result.Text = [float]$textBox1.Text / [float]$textBox2.Text
    }
})

<# 1.7 #>
<# Button Color #>


<# 1.6 #>
<# Label Result #>
$result = New-Object System.Windows.Forms.Label
$result.Location = New-Object System.Drawing.Size(365,150)
$result.Width = 70
[float]$result.Text = 0
$result.TextAlign = "MiddleCenter"

<# Controls #>
$window.Controls.Add($textBox1)
$window.Controls.Add($textBox2)
$window.Controls.Add($buttonAdd)
$window.Controls.Add($buttonSub)
$window.Controls.Add($buttonMul)
$window.Controls.Add($buttonDiv)
$window.Controls.Add($result)
$window.ShowDialog()