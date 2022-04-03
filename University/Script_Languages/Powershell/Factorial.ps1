$Window = New-Object System.Windows.Forms.Form
$Window.Text = "Graphical script interface"
$Window.Width = 400
$Window.Height = 250

$Text = New-Object System.Windows.Forms.TextBox
$Text.Location = New-Object System.Drawing.Size(100,50)
$Text.Width = 200

$Get = New-Object System.Windows.Forms.Label
$Get.Location = New-Object System.Drawing.Size(100,27)
$Get.Width = 200
$Get.Text = "Type integral number: "

$Result = New-Object System.Windows.Forms.Label
$Result.Location = New-Object System.Drawing.Size(100,150)
$Result.Width = 50
$Result.Text = "Wynik: "

$Display = New-Object System.Windows.Forms.Label
$Display.Location = New-Object System.Drawing.Size(150,150)
$Display.Text = "0"

Function Calculate{
    $Variable = [System.Convert]::ToInt32($Text.Text)
    [int32]$result = 1
    for($i=$Variable; $i -GT 0; $i--){
	$result *= $i;
    }
    return $result
}

$Button = New-Object System.Windows.Forms.Button
$Button.Location = New-Object System.Drawing.Size(100,100)
$Button.Width = 200
$Button.Text = "Calculate factorial"
$Button.Add_Click({
    Try{
	$Display.Text = Calculate
    }
    Catch{$Display.Text = "Error";}  
})

$Window.Controls.Add($Button)
$Window.Controls.Add($Text)
$Window.Controls.Add($Result)
$Window.Controls.Add($Get)
$Window.Controls.Add($Display)
$Window.ShowDialog()
