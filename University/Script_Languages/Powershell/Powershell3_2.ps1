<#
Zadanie 2:
2.1 Utwórz nowy skrypt.
2.2 Utwórz w nim okno programu o wymiarach 640x480.
2.3 Ustaw tytuł okna na Laboratorium 3.2.
2.4 Wewnątrz okna stwórz przycisk Wybierz, który wywoła okno dialogowe wyboru folderu.
2.5 Utwórz pole tekstowe.
2.6 Utwórz kolejny przycisk. Nazwij go Utwórz. Po naciśnięciu klawisza ma się utworzyć
folder o nazwie pobranej z pola tekstowego w lokalizacji pobranej z okna dialogowego
wyboru katalogu.
2.7 Dodaj okno zaznaczenia o nazwie Ukryty. Każdorazowo po zaznaczeniu/odznaczeniu go
ma następować zmiana atrybutu ukryty utworzonego wcześniej folderu.
#>

Add-Type -AssemblyName System.Windows.Forms

function Hide{

}

<# Main Window #>
$window = New-Object System.Windows.Forms.Form
$window.Location = New-Object System.Drawing.Size(640,480)
$window.MinimumSize = New-Object System.Drawing.Size(640,480)
$window.MaximumSize = New-Object System.Drawing.Size(640,480)
$window.Text = "Laboratorium 3.2"

<# Button #>
$buttonFolder = New-Object System.Windows.Forms.Button
$buttonFolder.Location = New-Object System.Drawing.Size(320,72)
$buttonFolder.Width = 128
$buttonFolder.Height = 24
$buttonFolder.Text = "Wybierz..."
$buttonFolder.Add_Click({
    $openFileDialog = New-Object System.Windows.Forms.FolderBrowserDialog
    $openFileDialog.ShowDialog()
    if(Test-Path -Path $openFileDialog.SelectedPath){
        $file = Get-Item -Path $openFileDialog.SelectedPath -Force
        if($checkBox.Checked -EQ $true){
            $file.Attributes = "Hidden"
        }else{
            $file.Attributes = "Archive"
        }
    }else{
        Write-Host "Error"
    }
})

<# Folder Label #>
$label = New-Object System.Windows.Forms.Label
$label.Location = New-Object System.Drawing.Size(160, 75)
$label.Width = 128
$label.Height = 24
$label.Text = "Wybierz folder: "
$label.Font = New-Object System.Drawing.Font("Times New Roman",12, [System.Drawing.FontStyle]::Bold)

<# CheckBox #>
$checkBox = New-Object System.Windows.Forms.CheckBox
$checkBox.Location = New-Object System.Drawing.Size(320, 115)
$checkBox.Width = 128
$checkBox.Height = 24

<# CheckBox Label #>
$checkBoxLabel = New-Object System.Windows.Forms.Label
$checkBoxLabel.Location = New-Object System.Drawing.Size(160,115)
$checkBoxLabel.Width = 128
$checkBoxLabel.Height = 24
$checkBoxLabel.Text = "Ukryj folder: "
$checkBoxLabel.Font = New-Object System.Drawing.Font("Times New Roman",12,[System.Drawing.FontStyle]::Bold)

<# Load #>
$window.Controls.Add($buttonFolder)
$window.Controls.Add($label)
$window.Controls.Add($checkBox)
$window.Controls.Add($checkBoxLabel)
$window.ShowDialog()