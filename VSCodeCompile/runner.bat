@echo off
node D:\cptraining\VSCodeCompile\compile.js %1
if not errorlevel 1 D:\cptraining\VSCodeCompile\timecmd "%1.exe"