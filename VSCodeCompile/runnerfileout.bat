@echo off
node G:\cptraining\VSCodeCompile\compile.js %1
if not errorlevel 1 G:\cptraining\VSCodeCompile\timecmd "%1.exe" < "%2" > "%1.out.txt"
%1.out.txt