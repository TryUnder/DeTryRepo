open System;

[<Measure>] type Fahrenheit
[<Measure>] type Celsius

let temp = 20.0;

let calcfahr temp = (9.0/5.0*temp) + 32.0
    
System.Console.WriteLine(calcfahr temp)
