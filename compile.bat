@echo off
g++ -Wl,--stack,4194304 -std=c++11 -Ofast %1 -o run.exe
echo Compile finished