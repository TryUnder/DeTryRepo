$Window = New-Object System.Windows.Forms.Form
$Window.Text = "Rise"
$Window.Width = 400
$Window.Height = 250

$Question = New-Object System.Windows.Forms.Label
$Question.Location = New-Object System.Drawing.Size(100,30)
$Question.Width = 200
$Question.Text = "Do you want a rise in salary ?"
$Window.Controls.Add($Question)

$Not = New-Object System.Windows.Forms.Button
$Not.Location = New-Object System.Drawing.Size(200,100)
$Not.Width = 80
$Not.Text = "Not"
$Not.Add_Click({$Window.Close()})
$Window.Controls.Add($Not)

$Yes = New-Object System.Windows.Forms.Button
$Yes.Location = New-Object System.Drawing.Size(100,100)
$Yes.Width = 80
$Yes.Text = "Yes"
$Yes.Add_Click({
    $X = Get-Random -Min 0 -Max 300
    $Y = Get-Random -Min 0 -Max 180;
    $Yes.Location = New-Object System.Drawing.Size($X,$Y)
})
$Window.Controls.Add($Yes)

$Window.ShowDialog()
