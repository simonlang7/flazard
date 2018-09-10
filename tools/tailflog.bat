If Not Exist "flazard.log" (
  copy NUL flazard.log
)
start "Flazardlog" C:\msys64\usr\bin\tail.exe -f flazard.log