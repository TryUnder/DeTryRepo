$Window = New-Object System.Windows.Forms.Form
$Window.Text = "Colors"
$Window.Width = 400
$Window.Height = 250

$Color_Choose = New-Object System.Windows.Forms.ColorDialog

$String = New-Object System.Windows.Forms.Label
$String.Location = New-Object System.Drawing.Size(180,50)
$String.Width = 300
$String.Height = 200
$String.Text = "Text"
$String.Font = New-Object System.Drawing.Font("Times New Roman", 18)

$Italics = New-Object System.Windows.Forms.CheckBox
$Italics.Location = New-Object System.Drawing.Size(20,135)
$Italics.Text = "Italics"
$Italics.Width = 150

$TNR = New-Object System.Windows.Forms.RadioButton
$TNR.Text = "Times New Roman"
$TNR.Location = New-Object System.Drawing.Size(10,15)
$TNR.Width = 120
$TNR.Checked = $true

$Courier = New-Object System.Windows.Forms.RadioButton
$Courier.Text = "Courier New"
$Courier.Location = New-Object System.Drawing.Size(10,35)
$Courier.Width = 120

$Choose = New-Object System.Windows.Forms.GroupBox
$Choose.Location = New-Object System.Drawing.Size(20,20)
$Choose.Size = New-Object System.Drawing.Size(140,65)
$Choose.Text = "Choose fount: "
$Choose.Controls.Add($Courier)
$Choose.Controls.Add($TNR)

$Button = New-Object System.Windows.Forms.Button
$Button.Location = New-Object System.Drawing.Size(20,100)
$Button.Width = 140
$Button.Text = "Choose color"
$Button.Add_Click({
    $Color_Choose.ShowDialog();
    $String.ForeColor = $Color_Choose.Color
})

Function Load{
    if($TNR.Checked -EQ $True){
	if($Italics.Checked -EQ $True){
	    $String.Font = New-Object System.Drawing.Font("Times New Roman", 18, [System.Drawing.FontStyle]::Italic)
	}
	else{
	    $String.Font = New-Object System.Drawing.Font("Times New Roman", 18)
	}
    }
    if($Courier.Checked -EQ $true){
	if($Italics.Checked -EQ $True){
	    $String.Font = New-Object System.Drawing.Font("Courier New", 18, [System.Drawing.FontStyle]::Italic)
	}
	else{
	    $String.Font = New-Object System.Drawing.Font("Courier New", 18)
	}
    }
}

$TNR.Add_Click({Load})
$Courier.Add_Click({Load})
$Italics.Add_Click({Load})
$Window.Controls.Add($Button)
$Window.Controls.Add($Choose)
$Window.Controls.Add($Italics)
$Window.Controls.Add($String)
$Window.Controls.Add($Choose)
$Window.ShowDialog()
