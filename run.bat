@echo off
call compile.bat %1
run.exe < input.in > output.out
echo Run finished ... wait for output window
notepad output.out
echo Output closed