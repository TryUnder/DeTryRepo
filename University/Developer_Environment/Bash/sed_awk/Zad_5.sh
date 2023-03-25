#!/usr/bin/awk -f

BEGIN {
  FS = "[\n=]"
  RS = "\nstudent"
}

{
  print $2";"$4";"$6
}
