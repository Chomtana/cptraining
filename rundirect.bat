@echo off
del run.exe
call compile.bat %1
run.exe < input.in
echo Run finished