@echo off
mkdir build
cd build
cmake -G "Visual Studio 16 2019" -A x64 ..
timeout /t 10