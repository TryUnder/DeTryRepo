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

function LoadFont{
    if($TNR.Checked -EQ $true){
        if($italics.Checked -EQ $true){
            $result.Font = New-Object System.Drawing.Font("Times New Roman",18,[System.Drawing.FontStyle]::Italic)
        }else{
            $result.Font = New-Object System.Drawing.Font("Times New Roman",18)
        }
    }
    if($Courier.Checked -EQ $true){
        if($italics.Checked -EQ $true){
            $result.Font = New-Object System.Drawing.Font("Courier",18,[System.Drawing.FontStyle]::Italic)
        }else{
            $result.Font = New-Object System.Drawing.Font("Courier",18)
        }
    }
}

<# 1.1 . 1.2 . 1.3 . 1.4 #>
<# Main window #>
$windowMain = New-Object System.Windows.Forms.Form
$windowMain.Text = "Laboratorium 3.1"
$windowMain.Width = 800
$windowMain.Height = 600
$windowMain.MinimumSize = New-Object System.Drawing.Size(800,600)
$windowMain.MaximumSize = New-Object System.Drawing.Size(800,600)

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

<# 1.7 . 1.8 . 1.13 #>
<# Button Color #>
$buttonCol = New-Object System.Windows.Forms.Button
$buttonCol.Location = New-Object System.Drawing.Size(100,200)
$buttonCol.Width = 150
$buttonCol.Text = "Wybierz kolor"
$buttonCol.Add_Click({
    $colorChoose = New-Object System.Windows.Forms.ColorDialog
    $colorChoose.ShowDialog()
    $result.ForeColor = $colorChoose.Color
})


<# 1.11 . 1.12 . 1.13 #>
$buttonFont = New-Object System.Windows.Forms.Button
$buttonFont.Location = New-Object System.Drawing.Size(250,200)
$buttonFont.Width = 150
$buttonFont.Text = "Wybierz czcionkę"
$buttonFont.Add_Click({

    <# Color #>
    $buttonCol2 = New-Object System.Windows.Forms.Button
    $buttonCol2.Location = New-Object System.Drawing.Size(20,140)
    $buttonCol2.Width = 155
    $buttonCol2.Text = "Wybierz kolor"
    $buttonCol2.Add_Click({
        $colorChoose2 = New-Object System.Windows.Forms.ColorDialog
        $colorChoose2.ShowDialog()
        $result.ForeColor = $colorChoose2.Color
    })

    $windowFont = New-Object System.Windows.Forms.Form
    $windowFont.Width = 400
    $windowFont.Height = 300

    <# GroupBox #>
    $groupBox = New-Object System.Windows.Forms.GroupBox
    $groupBox.Location = New-Object System.Drawing.Size(20,20)
    $groupBox.Width = 155

    <# Italics #>
    $italics = New-Object System.Windows.Forms.CheckBox
    $italics.Location = New-Object System.Drawing.Size(20,180)
    $italics.Text = "Kursywa"
    $italics.Width = 150

    <# TNR #>
    $TNR = New-Object System.Windows.Forms.RadioButton
    $TNR.Location = New-Object System.Drawing.Size(15,20)
    $TNR.Width = 120
    $TNR.Height = 30
    $TNR.Text = "Times New Roman"
    $TNR.Checked = $true

    <# Courier #>
    $Courier = New-Object System.Windows.Forms.RadioButton
    $Courier.Location = New-Object System.Drawing.Size(15,60)
    $Courier.Width = 120
    $Courier.Height = 30
    $Courier.Text = "Courier"
    $Courier.Checked = $false

    $TNR.Add_Click({LoadFont})
    $Courier.Add_Click({LoadFont})
    $groupBox.Controls.Add($TNR)
    $groupBox.Controls.Add($Courier)
    $windowFont.Controls.Add($buttonCol2)
    $windowFont.Controls.Add($groupBox)
    $windowFont.Controls.Add($italics)
    $windowFont.ShowDialog()
})

<# 1.6 #>
<# Label Result #>
$result = New-Object System.Windows.Forms.Label
$result.Location = New-Object System.Drawing.Size(350,150)
$result.Width = 100
[float]$result.Text = 0.0
$result.TextAlign = "MiddleCenter"

<# Controls #>
$windowMain.Controls.Add($textBox1)
$windowMain.Controls.Add($textBox2)
$windowMain.Controls.Add($buttonAdd)
$windowMain.Controls.Add($buttonSub)
$windowMain.Controls.Add($buttonMul)
$windowMain.Controls.Add($buttonDiv)
$windowMain.Controls.Add($buttonCol)
$windowMain.Controls.Add($buttonFont)
$windowMain.Controls.Add($result)
$windowMain.ShowDialog()


